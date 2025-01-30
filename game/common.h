#pragma once
#include <Windows.h>
#include <shared.h>
#include <Hw.h>

template <typename tC>
class sHandle
{
public:
	unsigned int m_Handle;
public:
	sHandle()
	{
		m_Handle = 0;
	}

	~sHandle()
	{
		m_Handle = 0;
	}

	sHandle& operator=(unsigned int handle)
	{
		m_Handle = handle;
		return *this;
	}

	sHandle &operator=(const sHandle &handle)
	{
		m_Handle = handle.m_Handle;
	}

	void reset()
	{
		m_Handle = 0;
	}

	operator tC*(); // Make sure we assure the user to add the operator for the handle they're constructing 
};

template <typename tC>
struct HandleManager
{
	size_t m_capacity;
	size_t m_size;
	unsigned int m_lastPreshiftIndex;
	unsigned int m_lastPreshift;
	struct HandleHolder
	{
		sHandle<tC> m_Handle;
		tC *m_value;
	} *m_HandleArrayValue;
	int field_14;
	Hw::CriticalSection m_ArraySection;

	unsigned int add(tC *value)
	{
		m_ArraySection.enter();

		if (m_size == m_capacity)
		{
			m_ArraySection.leave();
			return 0;
		}

		unsigned int preshiftIndex = m_lastPreshiftIndex;
		unsigned int preshift = m_lastPreshift; 

		for (size_t i = 0; i < m_capacity; ++i)
		{
			if (preshiftIndex >= m_capacity)
			{
				++preshift;
				preshiftIndex = 0;
				if (preshift >= 0x100)
					preshift = 0;
			}
			if (!m_HandleArrayValue[preshiftIndex].m_Handle.m_Handle)
				break;
			++preshiftIndex;
		}

		unsigned int j = (preshiftIndex | (preshift << 16)) << 8;
		while (!j)
		{
			if (++preshift >= 0x100)
				preshift = 0;
			j = (preshiftIndex | (preshift << 16)) << 8;
		}

		m_HandleArrayValue[preshiftIndex].m_Handle.m_Handle = j;
		m_HandleArrayValue[preshiftIndex].m_value = value;
		++m_size;
		m_lastPreshiftIndex = preshiftIndex + 1;
		m_lastPreshift = preshift;

		m_ArraySection.leave();

		return j;
	}
};

struct ContextInstance
{
	ContextInstance *m_inheritance;

	BOOL hasInheritance(const ContextInstance &other)
	{
		return ((BOOL(__thiscall*)(ContextInstance*, const ContextInstance&))(shared::base + 0x9D6D80))(this, other);
	}

	bool operator==(const ContextInstance& other)
	{
		return this == &other;
	}

	ContextInstance(ContextInstance *inheritance)
	{
		((void(__thiscall *)(ContextInstance *, ContextInstance *))(shared::base + 0x9D6D50))(this, inheritance); // second parameter is actually a pointer??
	}

	ContextInstance() : ContextInstance(nullptr)
	{

	}

	~ContextInstance()
	{
		((void(__thiscall *)(ContextInstance *))(shared::base + 0x9D6D60))(this); // Empty destructor, still reference this destructor for SDK
	}
};

// e prefix is indicated that it is used by the engine

inline void Core_PlaySound(const char* se, int unused)
{
	((void(__cdecl*)(const char*, int))(shared::base + 0xA5E050))(se, unused);
}

inline void __declspec(naked) PrintfLog(const char* fmt, ...)
{
	__asm
	{
		mov eax, shared::base
		add eax, 0x9D5650
		jmp eax
	}
}

inline unsigned int stringhash32(const char* str, size_t length) // then later used for function that doesn't uses length
{
	return ((unsigned int (__cdecl *)(const char *, size_t))(shared::base + 0xA03D20))(str, length);
}

inline unsigned int stringhash32(const char* str)
{
	return ((unsigned int (__cdecl *)(const char*))(shared::base + 0xA03EA0))(str);
}

inline void * __cdecl eFree(void *block)
{
	return ((void *(__cdecl *)(void *))(shared::base + 0x9D4920))(block);
}

inline void *__cdecl AllocateMemory(size_t size)
{
	void *mem = Hw::cHeapGlobal::get()->allocate(size, 32u, 0, 0);
	if (mem)
		memset(mem, 0, size);
	return mem;
}

inline void __cdecl FreeMemory(void *block, int a2)
{
	((void(__cdecl*)(void*, int))(shared::base + 0x61D3D0))(block, a2); // most cases, deleted memory always has value of 0xEEEEEEEE
}

inline bool &bIsForegroundWindow = *(bool*)(shared::base + 0x19D509C);