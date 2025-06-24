#pragma once
#include <Windows.h>
#include <algorithm>
#include <Hw.h>
#include <sys.h>

extern void FreeMemory(void* block, int a2);

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

            SharedCoreImplBase()
            {
                ((void(__thiscall*)(SharedCoreImplBase*))(shared::base + 0x1310))(this);
            }

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
                FreeMemory(this->m_AllocatorProxy, 0);
            }

            virtual void shutdown()
            {
                this->~SharedCoreImpl();
                FreeMemory(this, 0);
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

                Core()
                {
                    ((void(__thiscall*)(Core*))(shared::base + 0x13C0))(this);
                }

                virtual ~Core() {};

                virtual void* allocate(size_t size) = 0;
                virtual void free(void* block) = 0;
            };

            template <typename allocator>
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
                    return this->m_Allocator->AllocateMemory(size, 32, 0, 0);
                }

                virtual void free(void* block)
                {
                    FreeMemory(block, 0);
                }
            };
        };

        template <typename deallocator>
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

        template <typename allocator>
        struct AllocatorHelper
        {
            lib::helper::AllocatorProxy::CoreT<allocator>* m_Allocator;
            lib::detail::SharedCoreImpl<lib::helper::AllocatorProxy::CoreT<allocator>, DeleterByAllocator<allocator>, allocator> *m_Core;

            AllocatorHelper(allocator* pAllocator) : m_Allocator(nullptr), m_Core(nullptr)
			{

			}

            bool create(allocator* pAllocator)
            {
                return ((bool(__thiscall *)(AllocatorHelper<allocator>*, allocator))(shared::base + 0x20E0))(this, pAllocator); // A bit too complex to recreate
            }

            AllocatorHelper<allocator>& operator=(const AllocatorHelper<allocator>& other)
            {
                ((void(__thiscall*)(AllocatorHelper<allocator>*, const AllocatorHelper<allocator>&))(shared::base + 0x1F90))(this, other);
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
};

template <typename T>
class lib::Array
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;

    T *m_array;
    size_t m_size;
    size_t m_capacity;

    Array()
    {
        m_array = nullptr;
        m_size = 0u;
        m_capacity = 0u;
    }

    Array(const Array<T>& other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
    }

    Array(std::initializer_list<T> &&list)
    {
        for (const T& item : list)
            this->push_back(item);
    }

    Array(Array<T> &&from) : m_array(from.m_array), m_size(from.m_size), m_capacity(from.m_capacity)
    {
        from.m_array = nullptr;
        from.m_size = 0u;
        from.m_capacity = 0u;
    }

    virtual ~Array() 
    {
        if (m_array)
            m_size = 0u;
        m_array = nullptr;
        m_capacity = 0u;
    };

    virtual size_t getCapacity() 
    {
        return m_capacity;
    };

    virtual bool push_back(const T &element) 
    {
        if (!m_array)
            return false;

        if (m_size >= m_capacity)
            return false;

        m_array[m_size++] = element;
        return true;
    };

    virtual void insert(T &position, const T &element)
    {
        if (m_size >= m_capacity)
            return;

        size_t insertIndex = &position - m_array;
        if (insertIndex > m_size)
            return;

        for (size_t i = m_size; i > insertIndex; --i)
            m_array[i] = m_array[i - 1];

        m_array[insertIndex] = element;
        ++m_size;
    };

    virtual void swap(lib::Array<T> &array) 
    {
        std::swap(m_array, array.m_array);
        std::swap(m_capacity, array.m_capacity);
        std::swap(m_size, array.m_size);
    };

    virtual void reallocate(size_t newSize) 
    {

    };

    bool push_front(const T& element)
    {
        insert(m_array[0], element);
        return true;
    }

    iterator begin()
    {
        return m_array;
    }
    iterator begin() const
    {
        return m_array;
    }

    iterator end()
    {
        return m_array + m_size;
    }
    iterator end() const
    {
        return m_array + m_size;
    }
    
    iterator rbegin()
    {
        return m_array + m_size - 1;
    }
    iterator rbegin() const
    {
        return m_array + m_size - 1;
    }

    iterator rend()
    {
        return m_array;
    }
    iterator rend() const
    {
        return m_array;
    }

    void remove(T& element)
    {
        if (!m_array)
            return;

        if ((unsigned int)(&element - m_array) >= m_size)
            return;

        for (T* elem = &element; elem != end() - 1; elem++)
            *elem = elem[1];

        --m_size;
    }

    void move(T& where, T& element)
    {
        size_t elementFrom = &element - m_array;
        size_t elementTo = &where - m_array;
        if (elementFrom >= m_size || elementTo >= m_size)
            return;

        T temp = element;
        if (elementFrom < elementTo)
        {
            for (size_t i = elementFrom; i < elementTo; ++i)
                m_array[i] = m_array[i + 1];
        }
        else if (elementFrom > elementTo)
        {
            for (size_t i = elementFrom; i > elementTo; --i)
                m_array[i] = m_array[i - 1];
        }
        m_array[elementTo] = temp;
    }

    void swap(T& lhs, T& rhs)
    {
        std::swap(lhs, rhs);
    }

    T& get(size_t at)
    {
        return m_array[at];
    }

    T& operator [](size_t index)
    {
        return get(index);
    }

    T& operator [](size_t index) const
    {
        return get(index);
    }

    void clear()
    {
        if (m_array)
            m_size = 0;
    }

    T& front()
    {
        return m_array[0];
    }

    T& back()
    {
        return m_size ? m_array[m_size - 1] : *m_array;
    }

    void pop_front()
    {
        remove(front());
    }

    void pop_back()
    {
        remove(back());
    }

    bool empty()
    {
        return m_size == 0;
    }

    size_t size()
    {
        return m_size;
    }

    Array<T> copy()
    {
        return Array<T>(*this);
    }

    // Bubble sort: Sorts the array using the bubble sort algorithm
    void bubbleSort(bool(*callback)(T& current, T& next)) // do not let the user modify the array
    {
        for (size_t i = 0; i < m_size - 1; ++i)
        {
            for (size_t j = 0; j < m_size - i - 1; ++j)
            {
                if (callback(m_array[j], m_array[j + 1]))
                    std::swap(m_array[j], m_array[j + 1]);
            }
        }
    }

    // Quick sort: Sorts the array using the quick sort algorithm
    void quickSort(bool(*callback)(T& current, T& next))
    {
        quickSortRecursive(0, m_size - 1, callback);
    }

    int partition(int low, int high, bool(*callback)(T& current, T& next))
    {
        T &pivot = m_array[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (callback(m_array[j], pivot))
            {
                i++;
                std::swap(m_array[i], m_array[j]);
            }
        }

        std::swap(m_array[i + 1], m_array[high]);
        return (i + 1);
    }

    void quickSortRecursive(int low, int high, bool(*callback)(T& current, T& next))
    {
        if (low < high)
        {
            int pivotIndex = partition(low, high, callback);
            quickSortRecursive(low, pivotIndex - 1, callback);
            quickSortRecursive(pivotIndex + 1, high, callback);
        }
    }

    // Selection sort: Sorts the array using the selection sort algorithm
    void selectionSort(bool(*callback)(T& current, T& next))
    {
        for (int i = 0; i < m_size - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < m_size; j++)
            {
                if (callback(m_array[j], m_array[minIndex]))
                    minIndex = j;
            }
            std::swap(m_array[i], m_array[minIndex]);
        }
    }

    // Insertion sort: Sorts the array using the insertion sort algorithm
    void insertionSort(bool(*callback)(T& current, T& next))
    {
        for (int i = 1; i < m_size; i++)
        {
            T &key = m_array[i];
            int j = i - 1;

            while (j >= 0 && callback(m_array[j], key))
            {
                m_array[j + 1] = m_array[j];
                j--;
            }

            m_array[j + 1] = key;
        }
    }
};

template <typename T, unsigned int Size>
class lib::StaticArray : public lib::Array<T>
{
public:
    T m_storage[Size];

    StaticArray() : Array<T>()
    {
        this->m_array = this->m_storage;
        this->m_capacity = Size;
    }

    StaticArray(const StaticArray<T, Size>& other) : Array<T>(other)
    {
        this->m_array = m_storage;
        this->m_capacity = Size;

        memcpy(m_storage, other.m_storage, sizeof(T) * Size);
    }

    StaticArray(std::initializer_list<T> &&list)
    {
        this->m_array = m_storage;

        for (const T& it : list)
            this->m_array[this->m_size++] = it;

        this->m_capacity = Size;
    };

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
        if (create(other.m_capacity, other.m_Helper.m_Allocator->m_Allocator))
            memcpy(this->m_array, other.m_array, sizeof(T) * other.m_capacity);
    }

    template <typename Allocator>
    bool create(size_t capacity, Allocator *allocator)
    {
        cleanup();
        helper::AllocatorHelper<Allocator> helpa(allocator);
        if (helpa.create(*allocator) && helpa.m_Allocator)
        {
            if (T* mem = (T*)helpa.m_Allocator->allocate(sizeof(T) * capacity); mem)
            {
                m_Helper = helpa;
                if (this->m_array)
                    this->m_size = 0;
                this->m_capacity = sizeof(T) * capacity / sizeof(T);
                this->m_array = mem;
                helpa.cleanup();
                return 1;
            }
            else
            {
                helpa.cleanup();
                return 0;
            }
        }
        else
        {
            helpa.cleanup();
            return 0;
        }
    }

    void cleanup()
    {
        if (this->m_array)
        {
            this->m_size = 0;
            this->m_capacity = 0;
            if (m_Helper.m_Allocator)
                m_Helper.m_Allocator->free(this->m_array);
            this->m_array = nullptr;
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

/// TODO: Fix allocator binding
/// EDIT: It already contains the allocator member in the game, so it's all good
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
        if (this->m_array)
        {
            operator delete(this->m_array, (Hw::cHeap*)m_Allocator);
            this->m_array = nullptr;
        }

        this->Array<T>::~Array();
    }

    DynamicArray(allocator* allocator) : Array<T>(), m_Allocator(allocator) {};

    DynamicArray(const DynamicArray<T, allocator>& other) : Array<T>(other)
    {
        m_Allocator = other.m_Allocator;
        resize(other.m_capacity);

        memcpy(this->m_array, other.m_array, sizeof(T) * other.m_capacity);
    }

    bool push_back(const T& element)
    {
        if (this->m_size > this->m_capacity)
            return false;

        if (this->m_capacity)
        {
            if (this->m_size == this->m_capacity)
                reallocate(2 * this->m_capacity);
        }
        else
        {
            reallocate(32u);
        }

        if (!this->m_array)
            return false;

        if (this->m_size >= this->m_capacity)
            return false;

        this->m_array[this->m_size++] = element;

        return true;
    }

    void insert(T& position, const T& element)
    {
        if (!this->m_array)
            return; // Just to be safe

        size_t memPos = &position - this->m_array;

        if (memPos <= this->m_size)
        {
            if (this->m_size == this->m_capacity)
            {
                if (this->m_capacity)
                    reallocate(2 * this->m_capacity);
                else
                    reallocate(32u);

                this->lib::Array<T>::insert(this->m_array[memPos], element);
            }
            this->lib::Array<T>::insert(position, element);
        }
    }

    size_t getCapacity() // And why we return -1?
    {
        return -1;
    }

    void reallocate(size_t newSize)
    {
       if (this->m_capacity < newSize)
       {
           if (newSize <= 0x20) // Minimum for 32? Why?
               newSize = 0x20;

           T* newArray = (T*)m_Allocator->AllocateMemory(sizeof(T) * newSize, 32, 0, 0);

           if (newArray)
           {
               if (this->m_size && this->m_array)
               {
                   memcpy(newArray, this->m_array, sizeof(T) * this->m_size);
               }

               if (this->m_array)
               {
                   operator delete(this->m_array, m_Allocator);
                   this->m_array = 0;
                   this->m_capacity = 0;
               }

               this->clear();

               this->m_array = newArray;
               this->m_capacity = sizeof(T) * newSize / sizeof(T);
           }
       }
    }

    virtual void _swap(lib::DynamicArray<T, allocator>& other) // duplicate?
    {
        std::swap(this->m_array, other.m_array);
        std::swap(this->m_size, other.m_size);
        std::swap(this->m_capacity, other.m_capacity);
        std::swap(m_Allocator, other.m_Allocator);
    }

    void resize(size_t size)
    {
        if (size > this->m_capacity)
        {
            reallocate(size);
        }
        else
        {
            if (size <= this->m_size) // new size of array cannot hold old elements
                return;

            T* newArray = (T*)m_Allocator->AllocateMemory(sizeof(T) * size, 32, 0, 0);
            if (newArray)
            {
                if (this->m_size && this->m_array)
                    memcpy(newArray, this->m_array, sizeof(T) * this->m_size);

                if (this->m_array)
                {
                    operator delete(this->m_array, this->m_Allocator);

                    this->m_array = nullptr;
                    this->m_capacity = 0;
                }

                this->clear();

                this->m_array = newArray;
                this->m_capacity = sizeof(T) * size / sizeof(T);
            }
        }
    }

    DynamicArray<T, allocator> copy()
    {
        return DynamicArray<T, allocator>(*this);
    }
};