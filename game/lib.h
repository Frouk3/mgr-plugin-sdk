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
    int m_nCurrentElements = 0;
    int m_nMaxElements = 0;
    T m_Array[1];

    Array()
    {
        this->m_pArrayStart = &this->m_Array;
        this->m_nCurrentElemetns = 0;
        this->m_nMaxElements = 0;
    }

    virtual ~Array() {};
    virtual T* GetObjects() {};
    virtual bool PushBack(T *pObject) {};
    virtual T PushWith(T *pObject, T *pPushedObject) {};
    virtual void Copy(lib::Array<T> *lib) {};
};

template <typename T, int size>
class lib::StaticArray : public lib::Array<T>
{
public:

    StaticArray()
    {
        this->m_nMaxElements = size;
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