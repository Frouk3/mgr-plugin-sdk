#pragma once

template <typename TYPE>
class hkRefNew
{
public:

	hkRefNew(TYPE* t) : m_pntr(t) {}

	TYPE* stealOwnership() { TYPE* t = m_pntr; m_pntr = HK_NULL; return t; }

public:
	TYPE* m_pntr;
};

template <typename TYPE>
class hkRefLoan
{
public:

	hkRefLoan(TYPE* t) : m_pntr(t) {}
	operator TYPE*() const { return m_pntr; }

public:
	TYPE* m_pntr;
};

template <class TYPE>
class hkRefPtr
{
public:

	typedef hkRefPtr<TYPE> ThisType;
	//	HK_DECLARE_PLACEMENT_ALLOCATOR();

    hkRefPtr(TYPE *t) : m_pntr(t) {};
    operator TYPE*() const { return m_pntr; };

private:

	TYPE* m_pntr;
};
