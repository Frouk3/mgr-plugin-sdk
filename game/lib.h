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
    int m_nSize = 0;
    int m_nCapacity = 0;
    T m_Array[1];

    Array()
    {
        this->m_pArrayStart = &this->m_Array;
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
    virtual bool PushBack(T *pObject) {};
    /// @brief Pushes/replaces object after pObject with pPushedObject
    /// @param[in, out] pObject Object in array 
    /// @param[in] pPushedObject Object to push after 
    virtual void PushWith(T *pObject, T *pPushedObject) {};
    /// @brief Switches members with another array
    /// @param[in, out] array To switch with 
    virtual void Switch(lib::Array<T> *array) {};
    virtual void unused(void *) {};
};

template <typename T, int size>
class lib::StaticArray : public lib::Array<T>
{
public:

    StaticArray()
    {
        this->m_nCapacity = size;
    }
};

template <typename T>
class lib::AllocatedArray : public lib::Array<T>
{
public:
    int field_14;

    AllocatedArray() : Array()
    {
        this->field_14 = 0;
    }
};