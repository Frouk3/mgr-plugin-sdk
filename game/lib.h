#pragma once
#include <Windows.h>
#include <algorithm>
#include "Hw.h"
#include "sys.h"

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

    T *m_pBegin;
    size_t m_nSize;
    size_t m_nCapacity;

    Array()
    {
        m_pBegin = nullptr;
        m_nSize = 0;
        m_nCapacity = 0;
    }

    Array(const Array<T>& other)
    {
        m_nSize = other.m_nSize;
        m_nCapacity = other.m_nCapacity;
    }

    virtual ~Array() 
    {
        if (m_pBegin)
            m_nSize = 0;
        m_pBegin = nullptr;
        m_nCapacity = 0;
    };

    virtual size_t getCapacity() 
    {
        return m_nCapacity;
    };

    virtual bool push_back(const T &element) 
    {
        if (!m_pBegin)
            return false;

        if (m_nSize >= m_nCapacity)
            return false;

        m_pBegin[m_nSize++] = element;
        return true;
    };

    virtual void insert(T &position, const T &element)
    {
        if (m_nSize >= m_nCapacity)
            return;

        size_t insertIndex = &position - m_pBegin;
        if (insertIndex > m_nSize)
            return;

        for (size_t i = m_nSize; i > insertIndex; --i)
            m_pBegin[i] = m_pBegin[i - 1];

        m_pBegin[insertIndex] = element;
        ++m_nSize;
    };

    virtual void swap(lib::Array<T> &array) 
    {
        std::swap(m_pBegin, array.m_pBegin);
        std::swap(m_nCapacity, array.m_nCapacity);
        std::swap(m_nSize, array.m_nSize);
    };

    virtual void reallocate(size_t newSize) 
    {

    };

    bool push_front(const T& element)
    {
        insert(m_pBegin[0], element);
        return true;
    }

    iterator begin()
    {
        return m_pBegin;
    }
    iterator begin() const
    {
        return m_pBegin;
    }

    iterator end()
    {
        return m_pBegin + m_nSize;
    }
    iterator end() const
    {
        return m_pBegin + m_nSize;
    }
    
    iterator rbegin()
    {
        return m_pBegin + m_nSize - 1;
    }
    iterator rbegin() const
    {
        return m_pBegin + m_nSize - 1;
    }

    iterator rend()
    {
        return m_pBegin;
    }
    iterator rend() const
    {
        return m_pBegin;
    }

    void remove(T& element)
    {
        if (!m_pBegin)
            return;

        if ((unsigned int)(&element - m_pBegin) >= m_nSize)
            return;

        for (T* elem = &element; elem != end() - 1; elem++)
            *elem = elem[1];

        --m_nSize;
    }

    void move(T& where, T& element)
    {
        size_t elementFrom = &element - m_pBegin;
        size_t elementTo = &where - m_pBegin;
        if (elementFrom >= m_nSize || elementTo >= m_nSize)
            return;

        T temp = element;
        if (elementFrom < elementTo)
        {
            for (size_t i = elementFrom; i < elementTo; ++i)
                m_pBegin[i] = m_pBegin[i + 1];
        }
        else if (elementFrom > elementTo)
        {
            for (size_t i = elementFrom; i > elementTo; --i)
                m_pBegin[i] = m_pBegin[i - 1];
        }
        m_pBegin[elementTo] = temp;
    }

    void swap(T& lhs, T& rhs)
    {
        std::swap(lhs, rhs);
    }

    T& get(size_t at)
    {
        return m_pBegin[at];
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
        if (m_pBegin)
            m_nSize = 0;
    }

    T& front()
    {
        return m_pBegin[0];
    }

    T& back()
    {
        return m_nSize ? m_pBegin[m_nSize - 1] : *m_pBegin;
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
        return m_nSize == 0;
    }

    size_t size()
    {
        return m_nSize;
    }

    Array<T> copy()
    {
        return Array<T>(*this);
    }

    // Bubble sort: Sorts the array using the bubble sort algorithm
    void bubbleSort(bool(*callback)(T& current, T& next)) // do not let the user modify the array
    {
        for (size_t i = 0; i < m_nSize - 1; ++i)
        {
            for (size_t j = 0; j < m_nSize - i - 1; ++j)
            {
                if (callback(m_pBegin[j], m_pBegin[j + 1])
                    std::swap(m_pBegin[j], m_pBegin[j + 1]);
            }
        }
    }

    // Quick sort: Sorts the array using the quick sort algorithm
    void quickSort(bool(*callback)(T& current, T& next))
    {
        quickSortRecursive(0, m_nSize - 1, callback);
    }

    int partition(int low, int high, bool(*callback)(T& current, T& next))
    {
        T &pivot = m_pBegin[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (callback(m_pBegin[j], pivot))
            {
                i++;
                std::swap(m_pBegin[i], m_pBegin[j]);
            }
        }

        std::swap(m_pBegin[i + 1], m_pBegin[high]);
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
        for (int i = 0; i < m_nSize - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < m_nSize; j++)
            {
                if (callback(m_pBegin[j], m_pBegin[minIndex]))
                    minIndex = j;
            }
            std::swap(m_pBegin[i], m_pBegin[minIndex]);
        }
    }

    // Insertion sort: Sorts the array using the insertion sort algorithm
    void insertionSort(bool(*callback)(T& current, T& next))
    {
        for (int i = 1; i < m_nSize; i++)
        {
            T &key = m_pBegin[i];
            int j = i - 1;

            while (j >= 0 && callback(m_pBegin[j], key))
            {
                m_pBegin[j + 1] = m_pBegin[j];
                j--;
            }

            m_pBegin[j + 1] = key;
        }
    }
};

template <typename T, unsigned int Size>
class lib::StaticArray : public lib::Array<T>
{
public:
    T m_Array[Size];

    StaticArray() : Array<T>()
    {
        this->m_pBegin = this->m_Array;
        this->m_nCapacity = Size;
    }

    StaticArray(const StaticArray<T, Size>& other) : Array<T>(other)
    {
        this->m_pBegin = m_Array;
        this->m_nCapacity = Size;

        memcpy(m_Array, other.m_Array, sizeof(T) * Size);
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
        if (create(other.m_nCapacity, other.m_Helper.m_Allocator->m_Allocator))
            memcpy(this->m_pBegin, other.m_pBegin, sizeof(T) * other.m_nCapacity);
    }

    template <typename Allocator>
    bool create(size_t capacity, Allocator *allocator)
    {
        this->cleanup();
        helper::AllocatorHelper<Allocator> helpa(allocator);
        if (helpa.create(*allocator) && helpa.m_Allocator)
        {
            if (auto mem = helpa.m_Allocator->allocate(sizeof(T) * capacity); mem)
            {
                this->m_Helper = helpa;
                if (this->m_pBegin)
                    this->m_nSize = 0;
                this->m_nCapacity = sizeof(T) * capacity / sizeof(T);
                this->m_pBegin = (T*)mem;
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
        if (this->m_pBegin)
        {
            this->m_nSize = 0;
            this->m_nCapacity = 0;
            if (this->m_Helper.m_Allocator)
                this->m_Helper.m_Allocator->free(this->m_pBegin);
            this->m_pBegin = nullptr;
            this->m_Helper.cleanup();
            this->m_Helper.m_Allocator = nullptr;
            this->m_Helper.m_Core = nullptr;
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
        if (this->m_pBegin)
        {
            operator delete(this->m_pBegin, (Hw::cHeap*)m_Allocator);
            this->m_pBegin = nullptr;
        }

        this->Array<T>::~Array();
    }

    DynamicArray(allocator* allocator) : Array<T>(), m_Allocator(allocator) {};

    DynamicArray(const DynamicArray<T, allocator>& other) : Array<T>(other)
    {
        this->m_Allocator = other.m_Allocator;
        resize(other.m_nCapacity);

        memcpy(this->m_pBegin, other.m_pBegin, sizeof(T) * other.m_nCapacity);
    }

    bool push_back(const T& element)
    {
        if (this->m_nSize > this->m_nCapacity)
            return false;

        if (this->m_nCapacity)
        {
            if (this->m_nSize == this->m_nCapacity)
                this->reallocate(2 * this->m_nCapacity);
        }
        else
        {
            this->reallocate(32u);
        }

        if (!this->m_pBegin)
            return false;

        if (this->m_nSize >= this->m_nCapacity)
            return false;

        this->m_pBegin[this->m_nSize++] = element;

        return true;
    }

    void insert(T& position, const T& element)
    {
        if (!this->m_pBegin)
            return; // Just to be safe

        size_t memPos = &position - this->m_pBegin;

        if (memPos <= this->m_nSize)
        {
            if (this->m_nSize == this->m_nCapacity)
            {
                if (this->m_nCapacity)
                    this->reallocate(2 * this->m_nCapacity);
                else
                    this->reallocate(32u);

                this->lib::Array<T>::insert(this->m_pBegin[memPos], element);
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
       if (this->m_nCapacity < newSize)
       {
           if (newSize <= 0x20) // Minimum for 32? Why?
               newSize = 0x20;

           auto newArray = (T*)this->m_Allocator->AllocateMemory(sizeof(T) * newSize, 32, 0, 0);

           if (newArray)
           {
               if (this->m_nSize && this->m_pBegin)
               {
                   memcpy(newArray, this->m_pBegin, sizeof(T) * this->m_nSize);
               }

               if (this->m_pBegin)
               {
                   operator delete(this->m_pBegin, m_Allocator);
                   this->m_pBegin = 0;
                   this->m_nCapacity = 0;
               }

               this->clear();

               this->m_pBegin = newArray;
               this->m_nCapacity = sizeof(T) * newSize / sizeof(T);
           }
       }
    }

    virtual void _swap(lib::DynamicArray<T, allocator>& other) // duplicate?
    {
        std::swap(this->m_pBegin, other.m_pBegin);
        std::swap(this->m_nSize, other.m_nSize);
        std::swap(this->m_nCapacity, other.m_nCapacity);
    }

    void resize(size_t size)
    {
        if (size > this->m_nCapacity)
        {
            reallocate(size);
        }
        else
        {
            if (size <= this->m_nSize) // new size of array cannot hold old elements
                return;

            auto newArray = (T*)this->m_Allocator->AllocateMemory(sizeof(T) * size, 32, 0, 0);
            if (newArray)
            {
                if (this->m_nSize && this->m_pBegin)
                    memcpy(newArray, this->m_pBegin, sizeof(T) * this->m_nSize);

                if (this->m_pBegin)
                {
                    operator delete(this->m_pBegin, this->m_Allocator);

                    this->m_pBegin = nullptr;
                    this->m_nCapacity = 0;
                }

                this->clear();

                this->m_pBegin = newArray;
                this->m_nCapacity = sizeof(T) * size / sizeof(T);
            }
        }
    }

    DynamicArray<T, allocator> copy()
    {
        return DynamicArray<T, allocator>(*this);
    }
};