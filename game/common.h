#pragma once
#include <Windows.h>
#include <shared.h>
#include <Hw.h>
#include <HwDebug.h>

template <typename tC>
class sHandle
{
public:
	unsigned int m_Handle;
public:
	sHandle() { m_Handle = 0; }
	~sHandle() { m_Handle = 0; }

	sHandle& operator=(unsigned int handle) { m_Handle = handle; return *this; }
	sHandle& operator=(const sHandle &handle) { m_Handle = handle.m_Handle; return *this; }

	void reset() { m_Handle = 0; }

	operator tC*(); // Make sure we assure the user to add the operator for the handle they're constructing 
};

struct cString // incomplete class, needs further research
{
	Hw::cHeapVariable *m_pAllocator;
	char *m_pData;
	char *m_pEnd;
	char *m_pCapacityEnd;
	Hw::cHeapVariable *m_pDeleter;
	int field_14;
	int field_18;
	int field_1C;

	cString(const char *str, Hw::cHeapVariable *allocator) { MAKE_CALL(shared::base + 0xA09060, void(__thiscall *)(cString *, const char *, Hw::cHeapVariable *), this, str, allocator); }

	char *scanForChar(const char *str) { return MAKE_CALL(shared::base + 0xA04370, char*(__thiscall *)(cString *, const char *), this, str); }

	char *findFistOfExcluding(const char *toFind, const char *toExclude) { return MAKE_CALL(shared::base + 0xA043C0, char*(__thiscall *)(cString *, const char *, const char *), this, toFind, toExclude); }

	void trimLeadingWhitespaces() { MAKE_CALL(shared::base + 0xA04440, void(__thiscall *)(cString *), this); }
	bool startsWithN(const char *str, size_t length) { return MAKE_CALL(shared::base + 0xA056F0, bool(__thiscall *)(cString *, const char *, size_t), this, str, length); }

	size_t length() { return MAKE_CALL(shared::base + 0xA13C00, size_t(__thiscall *)(cString *), this); }

	~cString() { MAKE_CALL(shared::base + 0xA18EA0, void(__thiscall *)(cString *), this); }
};

template <typename tC>
class HandleManager
{
public:
	unsigned int m_Capacity;
	unsigned int m_Size;
	unsigned int m_LastPreshiftIndex;
	unsigned int m_LastPreshift;
	struct HandleHolder
	{
		sHandle<tC> m_Handle;
		tC *m_value;
	} *m_pHandleArrayValue;
	int field_14;
	Hw::cCriticalSection m_CriticalSection;


	BOOL startup(int capacity, Hw::cHeap &allocator)
	{
		if (m_pHandleArrayValue)
			return FALSE;

		if (capacity >= 8192 * sizeof(HandleHolder))
			return FALSE;

		m_pHandleArrayValue = new(allocator) HandleHolder[capacity];
		if (!m_pHandleArrayValue)
			return FALSE;

		for (int i = 0; i < capacity; i++)
		{
			m_pHandleArrayValue[i].m_Handle.m_Handle = -1;
			m_pHandleArrayValue[i].m_value = nullptr;
		}

		m_Capacity = capacity;
		m_Size = 0u;
		m_LastPreshiftIndex = 0;
		m_LastPreshift = 0;
		m_CriticalSection.startup();
		return TRUE;
	}

	unsigned int add(tC *value)
	{
		m_CriticalSection.enter();

		if (m_Size == m_Capacity)
		{
			m_CriticalSection.leave();
			return 0;
		}

		unsigned int preshiftIndex = m_LastPreshiftIndex;
		unsigned int preshift = m_LastPreshift; 

		for (size_t i = 0; i < m_Capacity; ++i)
		{
			if (preshiftIndex >= m_Capacity)
			{
				++preshift;
				preshiftIndex = 0;
				if (preshift >= 0x100)
					preshift = 0;
			}
			if (!m_pHandleArrayValue[preshiftIndex].m_Handle.m_Handle)
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

		m_pHandleArrayValue[preshiftIndex].m_Handle.m_Handle = j;
		m_pHandleArrayValue[preshiftIndex].m_value = value;
		++m_Size;
		m_LastPreshiftIndex = preshiftIndex + 1;
		m_LastPreshift = preshift;

		m_CriticalSection.leave();

		return j;
	}

	void release(unsigned int handle)
	{
		m_CriticalSection.enter();
		if (handle & 0xFFFFFF00)
		{
			unsigned int index = (unsigned short)(handle >> 8);
			if (index >= m_Capacity)
			{
				Hw::DebugSystem::Report("[HandleManage] Handle release error: Invalid handle");
				m_CriticalSection.leave();
				return;
			}

			if (HandleHolder *holder = &m_pHandleArrayValue[index]; holder->m_Handle.m_Handle & 0xFFFFFF00)
			{
				if ((holder->m_Handle.m_Handle & 0xFFFFFF00) == (handle & 0xFFFFFF00))
				{
					holder->m_Handle.m_Handle = 0;
					holder->m_value = nullptr;
					--m_Size;
					m_CriticalSection.leave();
					return;
				}
				else
				{
					Hw::DebugSystem::Report("[HandleManage] Handle release error: Handle mismatch");
					m_CriticalSection.leave();
					return;
				}
			}
			else
			{
				Hw::DebugSystem::Report("[HandleManage] Handle release error: Invalid work");
				m_CriticalSection.leave();
				return;
			}
		}
		m_CriticalSection.leave();
	}

	tC* get(unsigned int handle)
	{
		size_t index = (unsigned short)(handle >> 8);

		if (index >= m_Capacity)
		{
			Hw::DebugSystem::Report("[HandleManage] Handle error: Invalid handle");
			return nullptr;
		}

		if (((handle ^ m_pHandleArrayValue[index].m_Handle.m_Handle) & 0xFFFFFF00) != 0)
			return nullptr;

		return m_pHandleArrayValue[index].m_value;
	}
};

// Most usable class in the game engine context system

struct ContextInstance
{
	ContextInstance *m_inheritance;

	BOOL hasInheritance(const ContextInstance &other) { return MAKE_CALL(shared::base + 0x9D6D80, BOOL(__thiscall*)(ContextInstance *, const ContextInstance&), this, other); }

	bool operator==(const ContextInstance& other) { return this == &other; }

	ContextInstance(ContextInstance *inheritance) { MAKE_CALL(shared::base + 0x9D6D50, void(__thiscall*)(ContextInstance *, ContextInstance *), this, inheritance); }
	ContextInstance() : ContextInstance(nullptr) {}

	~ContextInstance() { MAKE_CALL(shared::base + 0x9D6D60, void(__thiscall*)(ContextInstance *), this); }
};

// e prefix is indicated that it is used by the engine

inline void Core_PlaySound(const char* se, int unused) { MAKE_CALL(shared::base + 0xA5E050, void(__cdecl*)(const char*, int), se, unused); }

// inline void __declspec(naked) PrintfLog(const char* fmt, ...) -> Hw::cDebugLog::addMess
// {
// 	__asm
// 	{
// 		mov eax, shared::base
// 		add eax, 0x9D5650
// 		jmp eax
// 	}
// }

inline unsigned int crc32lower(const char* str, size_t length) { return MAKE_CALL(shared::base + 0xA03D20, unsigned int(__cdecl*)(const char *, size_t), str, length); }
inline unsigned int crc32lower(const char* str) { return MAKE_CALL(shared::base + 0xA03EA0, unsigned int(__cdecl*)(const char *), str); }

// inline void * __cdecl eFree(void *block) -> Hw::cHeap::free
// {
// 	return ((void *(__cdecl *)(void *))(shared::base + 0x9D4920))(block);
// }

inline void *__cdecl AllocateMemory(size_t size)
{
	void *mem = Hw::cHeapGlobal::GetInstance()->allocImpl(size, 32u, Hw::HW_ALLOC_VIRTUAL, 0);
	if (mem)
		memset(mem, 0, size);
	return mem;
}

inline void __cdecl FreeMemory(void *block, int a2) { MAKE_CALL(shared::base + 0x61D3D0, void(__cdecl*)(void *, int), block, a2); }

inline bool &bIsForegroundWindow = *(bool*)(shared::base + 0x19D509C);