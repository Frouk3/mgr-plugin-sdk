#pragma once

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
    T *m_pArrayStart;
    int m_nSize;
    int m_nCapacity;

    Array()
    {
        this->m_pArrayStart = 0;
        this->m_nSize = 0;
        this->m_nCapacity = 0;
    }

    virtual ~Array() {};
    /// @brief How much array can hold
    /// @return Number of maximum objects array can hold
    virtual int getCapacity() {};
    /// @brief Pushes object into the back of array, after the last object
    /// @param[in] pObject Object that will be pushed
    /// @return false on fail, true on success
    virtual bool pushBack(const T &element) {};
    /// @brief Inserts element after position
    /// @param[in] position Where to insert 
    /// @param[in] element Element that will be inserted
    virtual void insert(const T &position, const T &element) {};
    /// @brief Swaps members with another array
    /// @param[in, out] array To switch with 
    virtual void swap(lib::Array<T> *array) {};
    virtual void unused(void *) {};

    auto begin()
    {
        return &this->m_pArrayStart[0];
    }
    auto begin() const
    {
        return &this->m_pArrayStart[0];
    }

    auto end()
    {
        return &this->m_pArrayStart[this->m_nSize];
    }
    auto end() const
    {
        return &this->m_pArrayStart[this->m_nSize];
    }

    void remove(T& element)
    {
        if (!this->m_pArrayStart)
            return;

        if (&element - this->m_pArrayStart >= this->m_nSize) // if element is out of our array, do not proceed further
            return;
        
        for (auto i = &element; i != &this->m_pArrayStart[this->m_nSize - 1]; ++i)
            *i = i[1]; // remove element by inserting elements that are in front of it
        
        --this->m_nSize; // compensate the loss
    }
};

template <typename T, int size>
class lib::StaticArray : public lib::Array<T>
{
public:
    T m_Array[size];

    StaticArray() : Array()
    {
        
    }
};

template <typename T>
class lib::AllocatedArray : public lib::Array<T>
{
public:
    int field_10;
    int field_14;

    AllocatedArray() : Array()
    {
        this->field_14 = 0;
    }
};