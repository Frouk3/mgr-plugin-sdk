#pragma once
#include <Windows.h>
#include <algorithm>
#include "Hw.h"
#include "sys.h"

extern void FreeMemory(void* block, int a2);

namespace lib
{
    template <typename T> class Array;
    template <typename T, int size> class StaticArray;
    template <typename T> class AllocatedArray;
    template <typename T, class allocator> class DynamicArray;
    struct Noncopyable {}; // undefined

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

            SharedCoreImpl(allocatorProxy allocatorProxy, deallocator dealloc, allocator alloc) : SharedCoreImplBase(), m_AllocatorProxy(*allocatorProxy), m_Deallocator(dealloc), m_Allocator(alloc)
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

            bool create(allocator pAllocator)
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
    T *m_pBegin;
    unsigned int m_nSize;
    unsigned int m_nCapacity;

    Array()
    {
        this->m_pBegin = nullptr;
        this->m_nSize = 0;
        this->m_nCapacity = 0;
    }

    virtual ~Array() 
    {
        if (this->m_pBegin)
            this->m_nSize = 0;
        this->m_pBegin = nullptr;
        this->m_nCapacity = 0;
    };
    /// @brief How much array can hold
    /// @return Number of maximum objects array can hold
    virtual unsigned int getCapacity() 
    {
        return this->m_nCapacity;
    };
    /// @brief Pushes object into the back of array, after the last object
    /// @param[in] pObject Object that will be pushed
    /// @return false on fail, true on success
    virtual bool push_back(const T &element) 
    {
        if (!this->m_pBegin)
            return false;

        if (this->m_nSize >= this->m_nCapacity)
            return false;

        this->m_pBegin[this->m_nSize++] = element;
        return true;
    };
    /// @brief Inserts element after position
    /// @param[in] position Where to insert 
    /// @param[in] element Element that will be inserted
    virtual void insert(T &position, const T &element)
    {
        if (this->m_nSize >= this->m_nCapacity)
            return;

        size_t insertIndex = ((char*)&position - (char*)&this->m_pBegin) / sizeof(T);
        if (insertIndex > this->m_nSize)
            return;

        for (auto i = this->m_nSize; i > insertIndex; --i)
            this->m_pBegin[i] = this->m_pBegin[i - 1];

        this->m_pBegin[insertIndex] = element;
        ++this->m_nSize;
    };

    bool push_front(const T& element)
    {
        insert(this->m_pBegin[0], element);
        return true;
    }
    /// @brief Swaps members with another array
    /// @param[in, out] array To switch with 
    virtual void swap(lib::Array<T> *array) 
    {
        std::swap(this->m_pBegin, array->m_pBegin);
        std::swap(this->m_nCapacity, array->m_nCapacity);
        std::swap(this->m_nSize, array->m_nSize);
    };

    virtual void reallocate(size_t newSize) 
    {

    };

    auto begin()
    {
        return &this->m_pBegin[0];
    }
    auto begin() const
    {
        return &this->m_pBegin[0];
    }

    auto end()
    {
        return &this->m_pBegin[this->m_nSize];
    }
    auto end() const
    {
        return &this->m_pBegin[this->m_nSize];
    }

    void remove(T& element)
    {
        if (!this->m_pBegin)
            return;

        if (&element - this->m_pBegin >= this->m_nSize) // if element is out of our array, do not proceed further
            return;
        
        for (auto i = &element; i != &this->m_pBegin[this->m_nSize - 1]; ++i)
            *i = i[1]; // remove element by inserting elements that are in front of it
        
        --this->m_nSize; // compensate the loss
    }

    auto& get(size_t at)
    {
        return this->m_pBegin[at];
    }

    auto& operator [](size_t index)
    {
        return this->get(index);
    }

    auto& operator [](size_t index) const
    {
        return this->get(index);
    }

    void clear()
    {
        if (this->m_pBegin)
            this->m_nSize = 0;
    }

    void pop_front()
    {
        this->remove(*this->m_pBegin);
    }

    void pop_back()
    {
        this->remove(this->m_pBegin[this->m_nSize - 1]);
    }
};

template <typename T, int Size>
class lib::StaticArray : public lib::Array<T>
{
public:
    T m_Array[Size];

    StaticArray() : Array<T>()
    {
        this->m_pBegin = this->m_Array;
        this->m_nCapacity = Size;
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
};

template <typename T, typename allocator>
class lib::DynamicArray : public lib::Array<T>
{
public:
    allocator m_Allocator;

    DynamicArray() : Array<T>()
    {

    }

    DynamicArray(allocator* allocator) : Array<T>(), m_Allocator(allocator) {};

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

        size_t memPos = ((char*)&position - (char*)this->m_pBegin) / sizeof(T);

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

    int getCapacity() // And why we return -1?
    {
        return -1;
    }

    void reallocate(size_t newSize)
    {
       if (this->m_nCapacity < newSize)
       {
           auto previousSize = this->m_nSize;

           if (newSize <= 0x20) // Minimum for 32? Why?
               newSize = 0x20;

           auto newArray = (T*)this->m_Allocator->AllocateMemory(sizeof(T) * newSize, 32, 0, 0);

           if (newArray)
           {
               if (this->m_nSize)
               {
                   for (int i = 0; i < this->m_nSize; i++)
                       newArray[i] = this->m_pBegin[i];
               }

               if (this->m_pBegin)
               {
                   this->m_nSize = 0;
                   FreeMemory(this->m_pBegin, 0);
                   this->m_pBegin = 0;
                   this->m_nCapacity = 0;
               }

               this->clear();

               this->m_nSize = previousSize;
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
};