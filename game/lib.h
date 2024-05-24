#pragma once
#include <Windows.h>
#include <algorithm>

namespace lib
{
    template <typename T> class Array;
    template <typename T, int size> class StaticArray;
    template <typename T> class AllocatedArray;
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
    virtual bool pushBack(const T &element) 
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

        size_t insertIndex = *(char**)&position - (char*)this->m_pStart; // FIXME: Not sure what size is
        if ((insertIndex >> 2) > this->m_nSize)
            return;

        for (int i = this->m_nSize; i > insertIndex; --i)
            this->m_pStart[i] = this->m_pStart[i - 1];

        this->m_pStart[insertIndex] = element;
        ++this->m_nSize;
    };

    bool pushFront(const T& element)
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

    auto& operator [](size_t index)
    {
        return this->m_pStart[index];
    }

    auto& operator [](size_t index) const
    {
        return this->m_pStart[index];
    }

    void clear()
    {
        this->m_nSize = 0;
        ZeroMemory(this->m_pStart, sizeof(T) * this->m_nSize);
    }
};

template <typename T, int Size>
class lib::StaticArray : public lib::Array<T>
{
public:
    T m_Array[Size] = {};

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
    void* m_pAllocator;
    void *m_pDeallocator;

    AllocatedArray() : Array<T>()
    {
        this->m_pAllocator = nullptr;
        this->m_pDeallocator = nullptr;
    }
};