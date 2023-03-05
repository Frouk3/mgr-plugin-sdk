#pragma once

namespace lib
{
    template <class T> class Array;
    template <class T, int size> class StaticArray;
};

template <class T>
class lib::Array
{
public:
    T *m_pArrayStart[m_nMaxElements];
    int m_nCurrentElements;
    int m_nMaxElements;

    virtual ~Array() {};
    virtual T* GetObjects() {};
    virtual bool ReplaceObject(T pObject) {};
    virtual T AppendObject(T pObject, T pAppendObject) {};
    virtual void Copy(lib::Array *lib) {};
};

template <class T, int size>
class lib::StaticArray : public lib::Array {};