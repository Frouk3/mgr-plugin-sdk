#pragma once

template <typename T>
class hkArrayBase
{
public:
	friend class hkArrayUtil;
	friend class hkArraySpuUtil;
	friend class hkTrackerArrayLayoutHandler;
	friend class hkaiArrayUtil;
	template<typename TYPE> friend class hkArraySpu;

	typedef T* iterator;
	typedef const T* const_iterator;
	typedef hkArrayBase<T> ThisType;

	T* m_data;
	int m_size;
	int m_capacityAndFlags;
};

template <typename T>
class hkArray : public hkArrayBase<T>
{
public:

};

template <typename T, unsigned N>
class hkInplaceArray : public hkArrayBase<T>
{
public:
	int field_C;

	T m_storage[N];
};