#pragma once
#include <hkBase.h>
#include <hkArrayUtil.h>

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

	enum
	{
		CAPACITY_MASK = int(0x3FFFFFFF),
		FLAG_MASK = int(0xC0000000),
		DONT_DEALLOCATE_FLAG = int(0x80000000), // Indicates that the storage is not the array's to delete
		FORCE_SIGNED = -1
	};

	hkArrayBase()
	{
		m_data = nullptr;
		m_size = 0;
		m_capacityAndFlags = DONT_DEALLOCATE_FLAG;
	}

	hkArrayBase(T* buffer, int size, int capacity)
	{
		m_data = buffer;
		m_size = size;
		m_capacityAndFlags = capacity | DONT_DEALLOCATE_FLAG;
	}

	~hkArrayBase()
	{

	}

	T& operator[](int i)
	{
		return m_data[i];
	}

	T& back()
	{
		return m_data[m_size - 1];
	}

	const T& back() const
	{
		return m_data[m_size - 1];
	}

	int getSize() const
	{
		return m_size;
	}

	int getCapacity() const
	{
		return (m_capacityAndFlags & ~CAPACITY_MASK);
	}

	hkBool isEmpty() const
	{
		return m_size == 0;
	}

	void clear()
	{
		hkArrayUtil::destruct(m_data, m_size, typename hkIsPodType<T>::type());
	}

	iterator begin()
	{
		return m_data;
	}

	iterator begin() const
	{
		return m_data;
	}

	iterator end()
	{
		return m_data + m_size;
	}

	iterator end() const
	{
		return m_data + m_size;
	}
};

template <typename T>
class hkArray : public hkArrayBase<T>
{
public:

};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
public:
	int field_C;

	T m_storage[N];
};