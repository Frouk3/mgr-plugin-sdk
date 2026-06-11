#pragma once
#include <Windows.h>
#include <algorithm>
#include <Hw.h>
#include <sys.h>

namespace lib
{
    template <typename T> class Array;
    template <typename T, unsigned int size> class StaticArray;
    template <typename T> class AllocatedArray;
    template <typename T, class allocator> class DynamicArray;

    struct Noncopyable
    {
        Noncopyable() = default;
        ~Noncopyable() = default;

        Noncopyable(const Noncopyable&) = delete;
        Noncopyable& operator=(const Noncopyable&) = delete;
    };

    namespace detail
    {
        class SharedCoreImplBase
        {
        public:
            int field_4;
            int field_8;
            // ^^ these two represent reference count, but for what exactly?

            SharedCoreImplBase() { MAKE_CALL(shared::base + 0x1310, void(__thiscall *)(SharedCoreImplBase *), this); }

            virtual ~SharedCoreImplBase() {};
            virtual void destroyAllocator() = 0;
            virtual void shutdown() = 0;
        };

        template <typename allocatorProxy, typename deallocator, typename allocator>
        class SharedCoreImpl : public SharedCoreImplBase
        {
        public:
            allocatorProxy *m_AllocatorProxy;
            deallocator m_Deallocator;
            allocator m_Allocator;

            SharedCoreImpl() : SharedCoreImplBase()
			{
                m_AllocatorProxy = nullptr;
			}

            SharedCoreImpl(allocatorProxy *allocatorProxy, deallocator dealloc, allocator alloc) : SharedCoreImplBase(), m_AllocatorProxy(allocatorProxy), m_Deallocator(dealloc), m_Allocator(alloc)
            {
                
            }

            virtual void destroyAllocator()
            {
                operator delete(m_AllocatorProxy, (Hw::cHeap*)m_Allocator);
                m_AllocatorProxy = nullptr;
            }

            virtual void shutdown()
            {
                operator delete(this, (Hw::cHeap*)m_Allocator); // Oh no
                // I wonder how Platinum Games just made this mistake, original code also replicates this
            }
        };

    }

    namespace helper
    {
        namespace AllocatorProxy
        {
            class Core : public Noncopyable
            {
            public:

                Core() { MAKE_CALL(shared::base + 0x13C0, void(__thiscall *)(Core *), this); }

                virtual ~Core() {};

                virtual void* allocate(size_t size) = 0;
                virtual void free(void* block) = 0;
            };

            template <typename allocator = Hw::cHeap*>
            class CoreT : public Core
            {
            public:
                allocator m_Allocator;

                CoreT(allocator* Allocator) : Core()
                {
                    this->m_Allocator = *Allocator;
                }

                virtual void* allocate(size_t size)
                {
                    return this->m_Allocator->alloc(size, 32, Hw::HW_ALLOC_VIRTUAL, 0);
                }

                virtual void free(void* block)
                {
                    operator delete(block, (Hw::cHeap*)m_Allocator);
                }
            };
        };

        template <typename deallocator = Hw::cHeap*>
        struct DeleterByAllocator
        {
            deallocator m_Deallocator;

            DeleterByAllocator(deallocator* deallocator) : m_Deallocator(*deallocator)
            {

            }

            DeleterByAllocator() : m_Deallocator(nullptr)
			{

			}
        };

        template <typename allocator = Hw::cHeap*>
        struct AllocatorHelper
        {
            lib::helper::AllocatorProxy::CoreT<allocator>* m_Allocator;
            lib::detail::SharedCoreImpl<lib::helper::AllocatorProxy::CoreT<allocator>, DeleterByAllocator<allocator>, allocator> *m_Core;

            AllocatorHelper(allocator* pAllocator) : m_Allocator(nullptr), m_Core(nullptr)
			{

			}

            bool create(allocator& pAllocator)
            {
                return ReturnCallMethod<bool, 0x20E0, AllocatorHelper<allocator>*, allocator&>(this, pAllocator); // A bit too complex to recreate
            }

            AllocatorHelper<allocator>& operator=(const AllocatorHelper<allocator>& other)
            {
                CallMethod<0x1F90, AllocatorHelper<allocator>*, const AllocatorHelper<allocator>&>(this, other);
                return *this;
            }

            AllocatorHelper()
            {
                this->m_Allocator = nullptr;
                this->m_Core = nullptr;
            }

            void cleanup()
            {
                if (this->m_Core && !InterlockedDecrement((LONG*)&this->m_Core->field_4))
                {
                    this->m_Core->destroyAllocator();
                    if (!InterlockedDecrement((LONG*)&this->m_Core->field_8))
                        this->m_Core->shutdown();
                }
            }
        };
    }

    class Archive
    {
    public:
        int field_4;

        Archive() { *(void***)this = (void**)(shared::base + 0x12A785C); field_4 = 0; }

        Archive(int a2) { MAKE_CALL(shared::base + 0x8677F0, void(__thiscall *)(Archive *, int), this, a2); }

        ~Archive() { MAKE_CALL(shared::base + 0x867920, void(__thiscall *)(Archive *), this); }

        virtual bool dummy() {return false;}
    };

    class InputArchive : public Archive
    {
    public:

        InputArchive() { *(void***)this = (void**)(shared::base + 0x12A78DC); field_4 = 0; }
        InputArchive(int a2) { MAKE_CALL(shared::base + 0x867950, void(__thiscall *)(InputArchive *, int), this, a2); }
        ~InputArchive() { MAKE_CALL(shared::base + 0x867980, void(__thiscall *)(InputArchive *), this); }
    };
};

template <typename T>
class lib::Array
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;

    T *m_pArray;
    int m_Size;
    int m_Capacity;

    Array()
    {
        m_pArray = nullptr;
        m_Size = 0u;
        m_Capacity = 0u;
    }

    // pass capacity of an array in bytes into memCap
    Array(T *pArray, int memCap)
    {
        m_pArray = pArray;
        m_Size = 0u;
        m_Capacity = memCap / sizeof(T);
    }

    Array(const Array<T>& other)
    {
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
    }

    Array(Array<T> &&from) : m_pArray(from.m_pArray), m_Size(from.m_Size), m_Capacity(from.m_Capacity)
    {
        from.m_pArray = nullptr;
        from.m_Size = 0u;
        from.m_Capacity = 0u;
    }

    virtual ~Array() // virtual ~Array() -> `scalar deleting destructor'
    {
        clear();
        m_pArray = nullptr;
        m_Capacity = 0u;
    }

    virtual int getCapacity() 
    {
        return m_Capacity;
    }

    virtual bool pushBack(const T &element) 
    {
        if (!m_pArray)
            return false;

        if (m_Size >= m_Capacity)
            return false;

        m_pArray[m_Size++] = element;
        return true;
    };

    virtual void insert(T *dst, const T &value)
    {
        if (m_Size >= m_Capacity)
            return;

        if (dst > end())
            return;

        if (dst == end())
        {
            m_pArray[m_Size++] = value;
            return;
        }
        else
        {
            for (T *it = end(); it != dst; --it)
                *it = *(it - 1);

            *dst = value;
        }
        ++m_Size; // I have no idea why they put it like this
    }

    virtual void swap(lib::Array<T> &array) 
    {
        std::swap(m_pArray, array.m_pArray);
        std::swap(m_Capacity, array.m_Capacity);
        std::swap(m_Size, array.m_Size);
    }

    virtual void reallocate(unsigned int newSize)  {}

    int getSize() { return m_Size; /* perhaps fields are private or protected? */}

    bool pushFront(const T& element)
    {
        insert(m_pArray, element);
        return true;
    }

    iterator begin()
    {
        return m_pArray;
    }
    iterator begin() const
    {
        return m_pArray;
    }

    iterator end()
    {
        return m_pArray + m_Size;
    }
    iterator end() const
    {
        return m_pArray + m_Size;
    }
    
    iterator rbegin()
    {
        return m_pArray + m_Size - 1;
    }
    iterator rbegin() const
    {
        return m_pArray + m_Size - 1;
    }

    iterator rend()
    {
        return m_pArray;
    }
    iterator rend() const
    {
        return m_pArray;
    }

    void erase(T* element) // pass the existing element from array
    {
        if (!m_pArray)
            return;

        if (element - m_pArray >= m_Size)
            return;

        for (T* elem = element; elem != end() - 1; elem++)
            *elem = elem[1];

        --m_Size;
    }

    void move(T& where, T& element)
    {
        size_t elementFrom = &element - m_pArray;
        size_t elementTo = &where - m_pArray;
        if (elementFrom >= m_Size || elementTo >= m_Size)
            return;

        T temp = element;
        if (elementFrom < elementTo)
        {
            for (size_t i = elementFrom; i < elementTo; ++i)
                m_pArray[i] = m_pArray[i + 1];
        }
        else if (elementFrom > elementTo)
        {
            for (size_t i = elementFrom; i > elementTo; --i)
                m_pArray[i] = m_pArray[i - 1];
        }
        m_pArray[elementTo] = temp;
    }

    T& at(int at)
    {
        return m_pArray[at];
    }

    T& operator [](int index)
    {
        return at(index);
    }

    T& operator [](int index) const
    {
        return at(index);
    }

    bool canAdd()
    {
        return m_Size < m_Capacity;
    }

    void clear()
    {
        if (m_pArray)
            m_Size = 0;
    }

    T& front()
    {
        return m_pArray[0];
    }

    T& back()
    {
        return m_Size ? m_pArray[m_Size - 1] : *m_pArray;
    }

    void pop_front()
    {
        erase(front());
    }

    void pop_back()
    {
        erase(back());
    }

    bool empty()
    {
        return m_Size == 0;
    }

    Array<T> copy()
    {
        return Array<T>(*this);
    }

    bool copy(T* pBegin, T* pEnd)
    {
        clear();
        for (T* it = pBegin; it != pEnd; ++it)
        {
            if (!pushBack(*it))
                return false;
        }
        return true;
    }

    // Bubble sort: Sorts the array using the bubble sort algorithm
    void bubbleSort(const bool(*callback)(T* current, T* next)) // do not let the user modify the array
    {
        if (m_Size < 2) return;

        for (int i = 0; i < m_Size - 1; ++i)
        {
            bool swapped = false; // to prevent unnecessary iterations
            for (int j = 0; j < m_Size - i - 1; ++j)
            {
                if (callback(&m_pArray[j], &m_pArray[j + 1]))
                {
                    std::swap(m_pArray[j], m_pArray[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }

    // Quick sort: Sorts the array using the quick sort algorithm
    void quickSort(const bool(*callback)(T* current, T* next))
    {
        // using lambdas to avoid user poking around class methods

        auto partition = [this, &callback](int low, int high) -> int
        {
            T *pivot = &m_pArray[high];
            int i = low - 1;

            for (int j = low; j <= high - 1; j++)
            {
                if (callback(&m_pArray[j], pivot))
                {
                    i++;
                    std::swap(m_pArray[i], m_pArray[j]);
                }
            }

            std::swap(m_pArray[i + 1], m_pArray[high]);
            return (i + 1);
        };
        auto quickSortRecursive = [this, &callback, &partition](int low, int high, auto&& quickSortRef) -> void
        {
            if (low < high)
            {
                int pivotIndex = partition(low, high);
                quickSortRef(low, pivotIndex - 1, quickSortRef);
                quickSortRef(pivotIndex + 1, high, quickSortRef);
            }
        };
        quickSortRecursive(0, m_Size - 1, quickSortRecursive);
    }

    // Selection sort: Sorts the array using the selection sort algorithm
    void selectionSort(bool(*callback)(T& current, T& next))
    {
        for (int i = 0; i < m_Size - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < m_Size; j++)
            {
                if (callback(m_pArray[j], m_pArray[minIndex]))
                    minIndex = j;
            }
            std::swap(m_pArray[i], m_pArray[minIndex]);
        }
    }

    // Insertion sort: Sorts the array using the insertion sort algorithm
    void insertionSort(bool(*callback)(T& current, T& next))
    {
        for (int i = 1; i < m_Size; i++)
        {
            T &key = m_pArray[i];
            int j = i - 1;

            while (j >= 0 && callback(m_pArray[j], key))
            {
                m_pArray[j + 1] = m_pArray[j];
                j--;
            }

            m_pArray[j + 1] = key;
        }
    }
};

template <typename T, unsigned int Size>
class lib::StaticArray : public lib::Array<T>
{
public:
    T m_Storage[Size];

    StaticArray() : Array<T>()
    {
        this->m_pArray = m_Storage;
        this->m_Size = 0;
        this->m_Capacity = Size;
    }

    // default constructor and destructors are confirmed by the game's code analysis

    StaticArray(const StaticArray<T, Size>& other) : Array<T>(other)
    {
        this->m_pArray = m_Storage;
        this->m_Capacity = Size;

        memcpy(m_Storage, other.m_Storage, sizeof(T) * Size);
    }

    StaticArray<T, Size> copy()
    {
        return StaticArray<T, Size>(*this);
    }
};

template <typename T>
class lib::AllocatedArray : public lib::Array<T>
{
public:
    helper::AllocatorHelper<sys::AllocatorByHeap> m_Helper;

    AllocatedArray() : Array<T>()
    {
        
    }

    ~AllocatedArray()
    {
        cleanup();
    }

    AllocatedArray(const AllocatedArray<T> &other) : Array<T>(other)
    {
        if (create(other.m_Capacity, other.m_Helper.m_Allocator->m_Allocator))
            memcpy(this->m_pArray, other.m_pArray, sizeof(T) * other.m_Capacity);
    }

    bool create(size_t capacity, Hw::cHeap*& pHeap)
    {
        cleanup();
        helper::AllocatorHelper<Hw::cHeap> helpa(pHeap);
        if (helpa.create(*pHeap) && helpa.m_Allocator)
        {
            if (T* mem = new(*helpa.m_Allocator) T[capacity]; mem)
            {
                m_Helper = helpa;
                if (this->m_pArray)
                    this->m_Size = 0;
                this->m_Capacity = sizeof(T) * capacity / sizeof(T);
                this->m_pArray = mem;
                helpa.cleanup();
                return true;
            }
            else
            {
                helpa.cleanup();
                return false;
            }
        }
        else
        {
            helpa.cleanup();
            return false;
        }

        return false; // if we ever get to this point, unless it'll be optimized for better performance
    }

    void cleanup()
    {
        if (this->m_pArray)
        {
            this->m_Size = 0;
            this->m_Capacity = 0;
            if (m_Helper.m_Allocator)
                m_Helper.m_Allocator->free(this->m_pArray);
            this->m_pArray = nullptr;
            m_Helper.cleanup();
            m_Helper.m_Allocator = nullptr;
            m_Helper.m_Core = nullptr;
        }
    }

    AllocatedArray<T> copy()
    {
        return AllocatedArray<T>(*this);
    }
};

template <typename T, typename allocator = Hw::cHeap>
class lib::DynamicArray : public lib::Array<T>
{
public:
    allocator *m_Allocator;

    DynamicArray() : Array<T>()
    {

    }

    ~DynamicArray()
    {
        if (this->m_pArray)
        {
			delete[] this->m_pArray;
            this->m_pArray = nullptr;
        }

        this->Array<T>::~Array();
    }

    DynamicArray(allocator* allocator) : Array<T>(), m_Allocator(allocator) {};

    DynamicArray(const DynamicArray<T, allocator>& other) : Array<T>(other)
    {
        m_Allocator = other.m_Allocator;
        resize(other.m_Capacity);

        memcpy(this->m_pArray, other.m_pArray, sizeof(T) * other.m_Capacity);
    }

    bool pushBack(const T& element)
    {
        if (this->m_Size > this->m_Capacity)
            return false;

        if (this->m_Capacity)
        {
            if (this->m_Size == this->m_Capacity)
                reallocate(2 * this->m_Capacity);
        }
        else
        {
            reallocate(32u);
        }

        if (!this->m_pArray)
            return false;

        if (this->m_Size >= this->m_Capacity)
            return false;

        this->m_pArray[this->m_Size++] = element;

        return true;
    }

    void insert(T& position, const T& element)
    {
        if (!this->m_pArray)
            return; // Just to be safe

        size_t memPos = &position - this->m_pArray;

        if (memPos <= this->m_Size)
        {
            if (this->m_Size == this->m_Capacity)
            {
                if (this->m_Capacity)
                    reallocate(2 * this->m_Capacity);
                else
                    reallocate(32u);

                this->lib::Array<T>::insert(this->m_pArray[memPos], element);
            }
            this->lib::Array<T>::insert(position, element);
        }
    }

    int getCapacity() // And why we return -1?
    {
        return -1;
    }

    void reallocate(unsigned int newSize)
    {
       if (this->m_Capacity < (signed)newSize)
       {
           if (newSize <= 0x20) // Minimum for 32? Why?
               newSize = 0x20;

           T* newArray = new(m_Allocator) T[newSize];

           if (newArray)
           {
               if (this->m_Size && this->m_pArray)
               {
                   memcpy(newArray, this->m_pArray, sizeof(T) * this->m_Size);
               }

               if (this->m_pArray)
               {
                   delete[] this->m_pArray;
                   this->m_pArray = 0;
                   this->m_Capacity = 0;
               }

               this->clear();

               this->m_pArray = newArray;
               this->m_Capacity = sizeof(T) * newSize / sizeof(T);
           }
       }
    }

    virtual void swap(lib::DynamicArray<T, allocator>& other) // more like of a different type of swap for dynamic arrays
    {
        std::swap(this->m_pArray, other.m_pArray);
        std::swap(this->m_Size, other.m_Size);
        std::swap(this->m_Capacity, other.m_Capacity);
        // std::swap(this->m_Allocator, other.m_Allocator); // for clearence // I'm not sure if this is actually in the Engine's code
    }

    void resize(size_t size)
    {
        if (size > this->m_Capacity)
        {
            reallocate(size);
        }
        else
        {
            if (size <= this->m_Size) // new size of array cannot hold old elements
                return;

            T* newArray = new(m_Allocator) T[size];
            if (newArray)
            {
                if (this->m_Size && this->m_pArray)
                    memcpy(newArray, this->m_pArray, sizeof(T) * this->m_Size);

                if (this->m_pArray)
                {
					delete[] this->m_pArray;

                    this->m_pArray = nullptr;
                    this->m_Capacity = 0;
                }

                this->clear();

                this->m_pArray = newArray;
                this->m_Capacity = sizeof(T) * size / sizeof(T);
            }
        }
    }

    DynamicArray<T, allocator> copy()
    {
        return DynamicArray<T, allocator>(*this);
    }
};