#pragma once

namespace lib
{
    template <class T> class Array;
    template <class T, int size> class StaticArray;
    template <class T> class AllocatedArray;
};

template <class T>
class lib::Array
{
public:
    T *m_pArrayStart[];
    int m_nCurrentElements;
    int m_nMaxElements;

    Array()
    {

    }

    virtual ~Array() {};
    virtual T* GetObjects() {};
    virtual bool ReplaceObject(T pObject) {};
    virtual T AppendObject(T pObject, T pAppendObject) {};
    virtual void Copy(lib::Array<T> *lib) {};
};

template <class T, int size>
class lib::StaticArray : public lib::Array<T> 
{
public:

    StaticArray()
    {
        m_nMaxElements = size;
    }
};

template <class T>
class lib::AllocatedArray : public lib::Array<T>
{
public:
    int field_14;

    AllocatedArray()
    {
        
    }
};