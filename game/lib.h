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
    virtual int GetCapacity() {};
    /// @brief Pushes object into the back of array, after the last object
    /// @param[in] pObject Object that will be pushed
    /// @return false on fail, true on success
    virtual bool push_back(T *pObject) {};
    /// @brief Pushes/replaces object after pObject with pPushedObject
    /// @param[in, out] pObject Object in array 
    /// @param[in] pPushedObject Object to push after 
    virtual void PushWith(T *pObject, T *pPushedObject) {};
    /// @brief Switches members with another array
    /// @param[in, out] array To switch with 
    virtual void Switch(lib::Array<T> *array) {};
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

    AllocatedArray() : Array()
    {
        this->field_14 = 0;
    }
};