#pragma once
#include <Windows.h>
#include <algorithm>
#include "Hw.h"
#include "sys.h"

namespace lib
{
    template <typename T> class Array;
    template <typename T, int size> class StaticArray;
    template <typename T> class AllocatedArray;
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

            void destroyAllocator()
            {
                CallVMTFunc<1, SharedCoreImplBase*>(this);
            }

            void shutdown()
            {
                CallVMTFunc<2, SharedCoreImplBase*>(this);
            }
        };

        template <typename allocatorProxy, typename deallocator, typename allocator>
        class SharedCoreImpl : public SharedCoreImplBase
        {
        public:
            allocatorProxy *m_pAllocatorProxy;
            deallocator m_Deallocator;
            allocator m_pAllocator;

            SharedCoreImpl()
            {
                this->m_pAllocatorProxy = &allocatorProxy;
                this->m_Deallocator = deallocator;
                this->m_pAllocator = allocator;
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
                Hw::cHeap* m_pAllocator;

                Core()
                {
                    ((void(__thiscall*)(Core*))(shared::base + 0x13C0))(this);
                }

                virtual ~Core() {};

                void* allocate(size_t size)
                {
                    return ReturnCallVMTFunc<void*, 1, Core*, size_t>(this, size);
                }

                void free(void* block)
                {
                    CallVMTFunc<2, Core*, void*>(this, block);
                }
            };

            template <Hw::cHeap* allocator>
            class CoreT : public Core
            {
            public:
                CoreT(Hw::cHeap** Allocator) : Core()
                {
                    this->m_pAllocator = *Allocator;
                }

                CoreT()
                {
                    this->m_pAllocator = allocator;
                }
            };
        };

        template <Hw::cHeap *deallocator>
        struct DeleterByAllocator
        {
            Hw::cHeap *m_pDeallocator = deallocator;
        };

        struct AllocatorHelper
        {
            lib::helper::AllocatorProxy::Core* m_pAllocator;
            lib::detail::SharedCoreImplBase* m_pCoreImpl;

            bool create(const Hw::cHeap* allocator)
            {
                return ((bool(__thiscall*)(AllocatorHelper*, const Hw::cHeap*))(shared::base + 0x20E0))(this, allocator);
            }

            AllocatorHelper& operator=(AllocatorHelper& other)
            {
                ((void(__thiscall*)(AllocatorHelper*, AllocatorHelper*))(shared::base + 0x1F90))(this, &other);
                return *this;
            }

            AllocatorHelper()
            {
                this->m_pAllocator = nullptr;
                this->m_pCoreImpl = nullptr;
            }

            void cleanup()
            {
                if (this->m_pCoreImpl && !InterlockedDecrement((LONG*)&this->m_pCoreImpl->field_4))
                {
                    this->m_pCoreImpl->destroyAllocator();
                    if (!InterlockedDecrement((LONG*)&this->m_pCoreImpl->field_8))
                        this->m_pCoreImpl->shutdown();
                }
            }
        };
    }
};

template <typename T>
class lib::Array
{
public:
    T *m_pStart;
    unsigned int m_nSize;
    unsigned int m_nCapacity;

    Array()
    {
        this->m_pStart = nullptr;
        this->m_nSize = 0;
        this->m_nCapacity = 0;
    }

    virtual ~Array() 
    {
        if (this->m_pStart)
            this->m_nSize = 0;
        this->m_pStart = nullptr;
        this->m_nCapacity = 0;
    };
    /// @brief How much array can hold
    /// @return Number of maximum objects array can hold
    virtual int getCapacity() 
    {
        return this->m_nCapacity;
    };
    /// @brief Pushes object into the back of array, after the last object
    /// @param[in] pObject Object that will be pushed
    /// @return false on fail, true on success
    virtual bool push_back(const T &element) 
    {
        if (!this->m_pStart)
            return false;

        if (this->m_nSize >= this->m_nCapacity)
            return false;

        this->m_pStart[this->m_nSize++] = element;
        return true;
    };
    /// @brief Inserts element after position
    /// @param[in] position Where to insert 
    /// @param[in] element Element that will be inserted
    virtual void insert(T &position, const T &element)
    {
        if (this->m_nSize >= this->m_nCapacity)
            return;

        size_t insertIndex = &position - this->m_pStart;
        if (insertIndex > this->m_nSize)
            return;

        for (int i = this->m_nSize; i > insertIndex; --i)
            this->m_pStart[i] = this->m_pStart[i - 1];

        this->m_pStart[insertIndex] = element;
        ++this->m_nSize;
    };

    bool push_front(const T& element)
    {
        if (!this->m_pStart)
            return false;

        if (this->m_nSize >= this->m_nCapacity)
            return false;

        for (auto size = this->m_nSize; size > 0; --size)
            this->m_pStart[size] = this->m_pStart[size - 1];

        this->m_pStart[0] = element;

        ++this->m_nSize;
        return true;
    }
    /// @brief Swaps members with another array
    /// @param[in, out] array To switch with 
    virtual void swap(lib::Array<T> *array) 
    {
        std::swap(this->m_pStart, array->m_pStart);
        std::swap(this->m_nCapacity, array->m_nCapacity);
        std::swap(this->m_nSize, array->m_nSize);
    };
    virtual void unused(void *) {};

    auto begin()
    {
        return &this->m_pStart[0];
    }
    auto begin() const
    {
        return &this->m_pStart[0];
    }

    auto end()
    {
        return &this->m_pStart[this->m_nSize];
    }
    auto end() const
    {
        return &this->m_pStart[this->m_nSize];
    }

    void remove(T& element)
    {
        if (!this->m_pStart)
            return;

        if (&element - this->m_pStart >= this->m_nSize) // if element is out of our array, do not proceed further
            return;
        
        for (auto i = &element; i != &this->m_pStart[this->m_nSize - 1]; ++i)
            *i = i[1]; // remove element by inserting elements that are in front of it
        
        --this->m_nSize; // compensate the loss
    }

    auto& get(size_t at)
    {
        return this->m_pStart[at];
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
        if (this->m_pStart)
            this->m_nSize = 0;
    }

    void pop_front()
    {
        this->remove(*this->m_pStart);
    }

    void pop_back()
    {
        this->remove(this->m_pStart[this->m_nSize - 1]);
    }
};

template <typename T, int Size>
class lib::StaticArray : public lib::Array<T>
{
public:
    T m_Array[Size];

    StaticArray() : Array<T>()
    {
        this->m_pStart = this->m_Array;
        this->m_nCapacity = Size;
    }
};

template <typename T>
class lib::AllocatedArray : public lib::Array<T>
{
public:
    helper::AllocatorHelper m_Helper;

    AllocatedArray() : Array<T>()
    {
        
    }

    bool create(size_t capacity, Hw::cHeap const *&allocator)
    {
        this->cleanup();
        helper::AllocatorHelper helpa;
        if (helpa.create(allocator) && helpa.m_pAllocator)
        {
            if (auto mem = helpa.m_pAllocator->allocate(sizeof(T) * capacity); mem)
            {
                this->m_Helper = helpa;
                if (this->m_pStart)
                    this->m_nSize = 0;
                this->m_nCapacity = sizeof(T) * capacity / sizeof(T);
                this->m_pStart = (T*)mem;
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
        if (this->m_pStart)
        {
            this->m_nSize = 0;
            this->m_nCapacity = 0;
            if (this->m_Helper.m_pAllocator)
                this->m_Helper.m_pAllocator->free(this->m_pStart);
            this->m_pStart = nullptr;
            this->m_Helper.cleanup();
            this->m_Helper.m_pAllocator = nullptr;
            this->m_Helper.m_pCoreImpl = nullptr;
        }
    }
};