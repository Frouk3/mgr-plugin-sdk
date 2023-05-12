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
    T *m_pArrayStart[];
    int m_nCurrentElements = 0;
    int m_nMaxElements = 0;
    T m_Array;

    Array()
    {
        this->m_pArrayStart = &this->m_Array;
        this->m_nCurrentElemetns = 0;
        this->m_nMaxElements = 0;
    }

    virtual ~Array() {};
    virtual T* GetObjects() {};
    virtual bool ReplaceObject(T pObject) {};
    virtual T AppendObject(T pObject, T pAppendObject) {};
    virtual void Copy(lib::Array<T> *lib) {};
};

template <typename T, int size>
class lib::StaticArray : public lib::Array<T> 
{
public:

    StaticArray() : Array()
    {
        this->m_nMaxElements = size;
    }
};

template <typename T>
class lib::AllocatedArray : public lib::Array<T>
{
public:
    int field_14;

    AllocatedArray()
    {
        this->field_14 = 0;
    }
};