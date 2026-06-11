#pragma once
#include <Windows.h>

#if defined(_M_X64) || defined(__x86_64__) || defined(__amd64__)
#define SAFEHOOK_X64 1
#define SAFEHOOK_X86 0
#else
#define SAFEHOOK_X86 1
#define SAFEHOOK_X64 0
#endif

#if SAFEHOOK_X64
#include "hde/hde64.h"
#else
#include "hde/hde32.h"
#endif
#include <assert.h>
#include <new>
#include <stdio.h>
#include <Psapi.h>
#include <ProcessSnapshot.h>
#include <processthreadsapi.h>
#include <TlHelp32.h>

// All credits for function hooks goes to DarkByte

#if SAFEHOOK_X64
typedef hde64s hde_s;
#define HDE_DISASM(ptr, disasm) hde64_disasm(ptr, disasm)
#else
typedef hde32s hde_s;
#define HDE_DISASM(ptr, disasm) hde32_disasm(ptr, disasm)
#endif

namespace SafeHook
{
#if SAFEHOOK_X64
	static inline unsigned char asm_data[] =
	{
		0x9C,											// pushfq
		0x50,											// push rax
		0x48, 0x89, 0xE0,								// mov rax, rsp
		0x48, 0x83, 0xE4, 0xF0,							// and rsp, 0xFFFFFFFFFFFFFFF0
		0x48, 0x81, 0xEC, 0xA0, 0x02, 0x00, 0x00,		// sub rsp, 0x2A0
		0x0F, 0xAE, 0x44, 0x24, 0x20,					// fxsave [rsp + 0x20]
		0x48, 0x89, 0x9C, 0x24, 0x20, 0x02, 0x00, 0x00, // mov [rsp + 0x220], rbx
		0x48, 0x89, 0x8C, 0x24, 0x28, 0x02, 0x00, 0x00, // mov [rsp + 0x228], rcx
		0x48, 0x89, 0x94, 0x24, 0x30, 0x02, 0x00, 0x00, // mov [rsp + 0x230], rdx
		0x48, 0x89, 0xB4, 0x24, 0x38, 0x02, 0x00, 0x00, // mov [rsp + 0x238], rsi
		0x48, 0x89, 0xBC, 0x24, 0x40, 0x02, 0x00, 0x00, // mov [rsp + 0x240], rdi 
		0x48, 0x89, 0x84, 0x24, 0x48, 0x02, 0x00, 0x00, // mov [rsp + 0x248], rax
		0x48, 0x89, 0xAC, 0x24, 0x50, 0x02, 0x00, 0x00, // mov [rsp + 0x250], rbp
		0x4C, 0x89, 0x84, 0x24, 0x58, 0x02, 0x00, 0x00, // mov [rsp + 0x258], r8
		0x4C, 0x89, 0x8C, 0x24, 0x60, 0x02, 0x00, 0x00, // mov [rsp + 0x260], r9
		0x4C, 0x89, 0x94, 0x24, 0x68, 0x02, 0x00, 0x00, // mov [rsp + 0x268], r10
		0x4C, 0x89, 0x9C, 0x24, 0x70, 0x02, 0x00, 0x00, // mov [rsp + 0x270], r11
		0x4C, 0x89, 0xA4, 0x24, 0x78, 0x02, 0x00, 0x00, // mov [rsp + 0x278], r12
		0x4C, 0x89, 0xAC, 0x24, 0x80, 0x02, 0x00, 0x00, // mov [rsp + 0x280], r13
		0x4C, 0x89, 0xB4, 0x24, 0x88, 0x02, 0x00, 0x00, // mov [rsp + 0x288], r14
		0x4C, 0x89, 0xBC, 0x24, 0x90, 0x02, 0x00, 0x00, // mov [rsp + 0x290], r15
		0x48, 0x8D, 0x4C, 0x24, 0x20,					// lea rcx, [rsp + 0x20]
		0xE8, 0x80, 0x00, 0x00, 0x00,					// call $+0x80
		0x4C, 0x8B, 0xBC, 0x24, 0x90, 0x02, 0x00, 0x00, // mov r15, [rsp + 0x290]
		0x4C, 0x8B, 0xB4, 0x24, 0x88, 0x02, 0x00, 0x00, // mov r14, [rsp + 0x288]
		0x4C, 0x8B, 0xAC, 0x24, 0x80, 0x02, 0x00, 0x00, // mov r13, [rsp + 0x280]
		0x4C, 0x8B, 0xA4, 0x24, 0x78, 0x02, 0x00, 0x00, // mov r12, [rsp + 0x278]
		0x4C, 0x8B, 0x9C, 0x24, 0x70, 0x02, 0x00, 0x00, // mov r11, [rsp + 0x270]
		0x4C, 0x8B, 0x94, 0x24, 0x68, 0x02, 0x00, 0x00, // mov r10, [rsp + 0x268]
		0x4C, 0x8B, 0x8C, 0x24, 0x60, 0x02, 0x00, 0x00, // mov r9, [rsp + 0x260]
		0x4C, 0x8B, 0x84, 0x24, 0x58, 0x02, 0x00, 0x00, // mov r8, [rsp + 0x258]
		0x48, 0x8B, 0xAC, 0x24, 0x50, 0x02, 0x00, 0x00, // mov rbp, [rsp + 0x250]
		0x48, 0x8B, 0xBC, 0x24, 0x40, 0x02, 0x00, 0x00, // mov rdi, [rsp + 0x240]
		0x48, 0x8B, 0xB4, 0x24, 0x38, 0x02, 0x00, 0x00, // mov rsi, [rsp + 0x238]
		0x48, 0x8B, 0x94, 0x24, 0x30, 0x02, 0x00, 0x00, // mov rdx, [rsp + 0x230]
		0x48, 0x8B, 0x8C, 0x24, 0x28, 0x02, 0x00, 0x00, // mov rcx, [rsp + 0x228]
		0x48, 0x8B, 0x9C, 0x24, 0x20, 0x02, 0x00, 0x00, // mov rbx, [rsp + 0x220]
		0x0F, 0xAE, 0x4C, 0x24, 0x20,					// fxrstor [rsp + 0x20]
		0x48, 0x8B, 0xA4, 0x24, 0x48, 0x02, 0x00, 0x00, // mov rsp, [rsp + 0x248]
		0x58,											// pop rax
		0x9D,											// popfq
		0xC3,											// ret
	};

#else
	static inline unsigned char asm_data[] =
	{
		0x9C,										// pushfd
		0x50,										// push eax
		0x89, 0xE0,									// mov eax, esp
		0x83, 0xE4, 0xF0,							// and esp, 0xFFFFFFF0
		0x81, 0xEC, 0x20, 0x02, 0x00, 0x00,			// sub esp, 0x220
		0x0F, 0xAE, 0x04, 0x24,						// fxsave [esp] 
		0x89, 0x9C, 0x24, 0x00, 0x02, 0x00, 0x00,	// mov [esp + 0x200], ebx
		0x89, 0x8C, 0x24, 0x04, 0x02, 0x00, 0x00,	// mov [esp + 0x204], ecx
		0x89, 0x94, 0x24, 0x08, 0x02, 0x00, 0x00,	// mov [esp + 0x208], edx
		0x89, 0xB4, 0x24, 0x0C, 0x02, 0x00, 0x00,	// mov [esp + 0x20C], esi
		0x89, 0xBC, 0x24, 0x10, 0x02, 0x00, 0x00,	// mov [esp + 0x210], edi
		0x89, 0x84, 0x24, 0x14, 0x02, 0x00, 0x00,	// mov [esp + 0x214], eax
		0x89, 0xAC, 0x24, 0x18, 0x02, 0x00, 0x00,	// mov [esp + 0x218], ebp
		0x89, 0xE0,									// mov eax, esp
		0x50,										// push eax
		0xE8, 0x3B, 0x00, 0x00, 0x00,				// call $+0x3B
		0x83, 0xC4, 0x04,							// add esp, 4
		0x8B, 0xAC, 0x24, 0x18, 0x02, 0x00, 0x00,	// mov ebp, [esp + 0x218]
		0x8B, 0xBC, 0x24, 0x10, 0x02, 0x00, 0x00,	// mov edi, [esp + 0x210]
		0x8B, 0xB4, 0x24, 0x0C, 0x02, 0x00, 0x00,	// mov esi, [esp + 0x20C]
		0x8B, 0x94, 0x24, 0x08, 0x02, 0x00, 0x00,	// mov edx, [esp + 0x208]
		0x8B, 0x8C, 0x24, 0x04, 0x02, 0x00, 0x00,	// mov ecx, [esp + 0x204]
		0x8B, 0x9C, 0x24, 0x00, 0x02, 0x00, 0x00,	// mov ebx, [esp + 0x200] 
		0x0F, 0xAE, 0x0C, 0x24,						// fxrstor [esp]
		0x8B, 0xA4, 0x24, 0x14, 0x02, 0x00, 0x00,	// mov esp, [esp + 0x214]
		0x58,										// pop eax
		0x9D,										// popfd
		0xC3										// ret
	};
#endif
	class Exception
	{
		char* m_msg;
		const char* m_file;
		unsigned int m_line;

		void AllocateString(const char* msg)
		{
			size_t len = strlen(msg) + 1;
			m_msg = new char[len];
			strcpy_s(m_msg, len, msg);
		}

		void FreeString()
		{
			if (m_msg)
			{
				delete[] m_msg;
				m_msg = nullptr;
			}
		}

		void CopyFrom(const Exception& other)
		{
			m_line = other.m_line;
			AllocateString(other.m_msg);
		}

		void MoveFrom(Exception&& other) noexcept
		{
			m_line = other.m_line;
			m_msg = other.m_msg;
			other.m_msg = nullptr;
		}

		void MoveFrom(Exception& other) noexcept
		{
			m_line = other.m_line;
			m_msg = other.m_msg;
			other.m_msg = nullptr;
		}

		void FormatMsg(const char* fmt, va_list va)
		{
			int length = _vscprintf(fmt, va) + 1;
			m_msg = new char[length];

			vsnprintf_s(m_msg, length, length - 1, fmt, va);
		}
	public:
		Exception(const char* msg, const char* file, unsigned int line) : m_line(line), m_file(file)
		{
			if (msg)
				AllocateString(msg);
		}

		Exception(const Exception& other)
		{
			CopyFrom(other);
		}

		Exception(Exception&& other) noexcept
		{
			MoveFrom(std::move(other));
		}

		~Exception()
		{
			FreeString();
		}

		Exception& operator=(const Exception& other)
		{
			if (this != &other)
			{
				FreeString();
				CopyFrom(other);
			}
			return *this;
		}

		Exception& operator=(Exception&& other) noexcept
		{
			if (this != &other)
			{
				FreeString();
				MoveFrom(std::move(other));
			}
			return *this;
		}

		const char* what() const { return m_msg; }
		int line() const { return m_line; }
		const char* file() const { return m_file; }

		static inline char ExceptionBuffer[512];

		void DoFormat(const char* format, ...)
		{
			va_list va;
			va_start(va, format);

			FormatMsg(format, va);

			va_end(va);
		}
	};

	inline void ReportException(const Exception& e)
	{
		Exception::ExceptionBuffer[0] = 0;
		sprintf_s(Exception::ExceptionBuffer, "SafeHook Exception in %s: %s (line %d)", e.file(), e.what(), e.line());
		MessageBoxA(nullptr, Exception::ExceptionBuffer, "SafeHook", MB_ICONERROR | MB_OK);

		OutputDebugStringA(Exception::ExceptionBuffer);
	}

#define SAFEHOOK_THROW(msg) throw SafeHook::Exception(msg, __FILE__, __LINE__)
#define SAFEHOOK_THROW_FORMAT(msg, ...) do { SafeHook::Exception except(nullptr, __FILE__, __LINE__); except.DoFormat(msg, __VA_ARGS__); throw except; } while(0)

#define CHECK_ERROR(disasm) if (disasm.flags & F_ERROR) \
	{													\
		if (disasm.flags & F_ERROR_LENGTH) SAFEHOOK_THROW("Disasm: Length Error!");	\
		else if (disasm.flags & F_ERROR_OPCODE) SAFEHOOK_THROW("Disasm: Opcode Error!");	\
		else if (disasm.flags & F_ERROR_OPERAND) SAFEHOOK_THROW("Disasm: Operand Error!");	\
		else if (disasm.flags & F_ERROR_LOCK) SAFEHOOK_THROW("Disasm: Lock Error!");	\
		else SAFEHOOK_THROW("Disasm: Unknown Error!");	\
	}													

	inline size_t align(size_t length, size_t alignment)
	{
		return (length + alignment - 1) & ~(alignment - 1);
	}

	inline size_t getAllocationGranularity()
	{
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);

		return sysInfo.dwAllocationGranularity;
	}

#if SAFEHOOK_X86
	inline constexpr size_t g_JmpInstructionSize = 5;
#else
	inline constexpr size_t g_JmpInstructionSize = 14; // 14 bytes for the mov rax, imm64 + jmp rax instructions
#endif
	inline constexpr size_t g_RelativeJmpInstructionSize = 5;

	class SafeAddress
	{
		uintptr_t m_address;
	public:
		constexpr SafeAddress() : m_address(0) {}
		constexpr SafeAddress(uintptr_t address) : m_address(address) {}
		constexpr SafeAddress(const void* address) : m_address((uintptr_t)address) {}

		const uintptr_t get() const { return m_address; }
		void add(size_t offset) { m_address += offset; }

		void set(uintptr_t address) { m_address = address; }
		void set(const void* address) { m_address = (uintptr_t)address; }

		uintptr_t operator+(size_t offset) const { return m_address + offset; }
		uintptr_t operator-(size_t offset) const { return m_address - offset; }
		uintptr_t operator-(const SafeAddress& other) const { return m_address - other.m_address; }
		uintptr_t operator+(const SafeAddress& other) const { return m_address + other.m_address; }

		SafeAddress& operator+=(size_t offset) { m_address += offset; return *this; }
		SafeAddress& operator-=(size_t offset) { m_address -= offset; return *this; }
		SafeAddress& operator+=(const SafeAddress& other) { m_address += other.m_address; return *this; }
		SafeAddress& operator-=(const SafeAddress& other) { m_address -= other.m_address; return *this; }

		SafeAddress& operator=(const uintptr_t& address) { m_address = address; return *this; }
		SafeAddress& operator=(const void* address) { m_address = (uintptr_t)address; return *this; }
		SafeAddress& operator=(const SafeAddress& other) { m_address = other.m_address; return *this; }
	};

	inline bool CheckValidAddress(SafeAddress address)
	{
		MEMORY_BASIC_INFORMATION mbi;
		if (VirtualQuery((LPCVOID)address.get(), &mbi, sizeof(mbi)) == 0)
			return false;

		return (mbi.State == MEM_COMMIT) && ((mbi.Protect & PAGE_NOACCESS) == 0);
	}

	inline void ThreadRedirect(SafeAddress target, size_t size, SafeAddress trampoline)
	{
		DWORD curThreadId = GetCurrentThreadId();
		DWORD curProcessId = GetCurrentProcessId();

		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
		if (hSnapshot == INVALID_HANDLE_VALUE)
			SAFEHOOK_THROW("Failed to create thread snapshot!");

		THREADENTRY32 te;
		te.dwSize = sizeof(THREADENTRY32);

		if (Thread32First(hSnapshot, &te))
		{
			do
			{
				if (te.th32OwnerProcessID == curProcessId && te.th32ThreadID != curThreadId)
				{
					HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME | THREAD_GET_CONTEXT | THREAD_SET_CONTEXT, FALSE, te.th32ThreadID);
					if (hThread)
					{
						SuspendThread(hThread);

						CONTEXT ctx;
						ctx.ContextFlags = CONTEXT_CONTROL;
						if (GetThreadContext(hThread, &ctx))
						{
#if SAFEHOOK_X64
							uintptr_t& ip = ctx.Rip;
#else
							DWORD& ip = ctx.Eip;
#endif
							// If a thread is suspended mid-prologue, recalculate its instruction pointer offset inside the trampoline
							if (ip >= target.get() && ip < (target + size))
							{
								uintptr_t offset = ip - target.get();
								ip = trampoline + offset;
								SetThreadContext(hThread, &ctx);
							}
						}
						ResumeThread(hThread);
						CloseHandle(hThread);
					}
				}
			} while (Thread32Next(hSnapshot, &te));
		}
		CloseHandle(hSnapshot);
	}

	template <int num>
	class PageController
	{
		class PageBlock
		{
			void* m_base;
			size_t m_size;
			size_t m_alignment;

			PageBlock* m_pNext, * m_pPrev;

			void unchain()
			{
				if (m_pPrev)
					m_pPrev->m_pNext = m_pNext;

				if (m_pNext)
					m_pNext->m_pPrev = m_pPrev;

				m_pNext = nullptr;
				m_pPrev = nullptr;
			}

			void init(void* base, size_t size, size_t alignment)
			{
				m_base = base;
				m_size = size;
				m_alignment = alignment;
			}

			void deinit()
			{
				if (m_base)
				{
					memset(m_base, 0, align(m_size, m_alignment));

					m_base = nullptr;
					m_size = 0;
					m_alignment = 0;
				}

				unchain();
			}
		public:
			PageBlock() : m_base(nullptr), m_size(0), m_alignment(0) {}
			PageBlock(void* base, size_t size, size_t align) : m_base(base), m_size(size), m_alignment(align) {}
			~PageBlock() { deinit(); }

			friend class Page;
			friend class PageController;
		};

		class Page
		{
			void* m_baseptr;
			size_t m_size;

			PageBlock* m_block;
			PageBlock* m_pLast;

			void* m_pFreeSpace;

			void init(size_t size)
			{
				m_baseptr = VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
				if (!m_baseptr)
					SAFEHOOK_THROW("Failed to allocate page!");

				m_pFreeSpace = m_baseptr;
				m_pLast = nullptr;

				m_size = size;
			}

			void init(void* base, size_t size)
			{
				m_baseptr = base;
				m_pFreeSpace = m_baseptr;
				m_pLast = nullptr;

				m_size = size;
			}

			bool initNear(void* base, size_t size)
			{
				size_t granularity = SafeHook::getAllocationGranularity();

				uintptr_t start = (uintptr_t)base > 0x7FFFFFFF ? (uintptr_t)base - 0x7FFFFFFF : 0;
				uintptr_t end = (uintptr_t)base + 0x7FFFFFFF;

				while (start < end)
				{
					MEMORY_BASIC_INFORMATION mbi;
					if (VirtualQuery((LPCVOID)start, &mbi, sizeof(mbi)) == 0)
						break;

					if (mbi.State == MEM_FREE && mbi.RegionSize >= size)
					{
						void* ptr = VirtualAlloc((LPVOID)start, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
						if (ptr)
						{
							init(ptr, size);
							return true;
						}
					}

					start = align(start + mbi.RegionSize, granularity);
				}
				return false;
			}

			void* alloc(size_t size, size_t align)
			{
				if (!m_baseptr)
					SAFEHOOK_THROW("Page is not initialized!");

				if ((size_t)m_pFreeSpace - (size_t)m_baseptr > m_size) // out of bounds check
					return nullptr;

				PageBlock* block = new PageBlock(m_pFreeSpace, size, align);
				if (!m_block)
					m_block = block;

				if (m_pLast)
					chain(m_pLast, block);

				m_pLast = block;

				m_pFreeSpace = (void*)((uintptr_t)SafeHook::align((size_t)m_pFreeSpace + size, align));

				return block->m_base;
			}

			void chain(PageBlock* what, PageBlock* it)
			{
				PageBlock* prev = what;
				PageBlock* next = prev->m_pNext;

				it->m_pPrev = prev;
				it->m_pNext = next;

				if (prev)
					prev->m_pNext = it;

				if (next)
					next->m_pPrev = it;
			}
		public:
			Page() : m_baseptr(nullptr), m_block(nullptr), m_size(0) {}

			~Page()
			{
				if (m_block)
				{
					PageBlock* curr = m_block;
					while (curr)
					{
						PageBlock* next = curr->m_pNext;
						delete curr;
						curr = next;
					}
				}

				if (m_baseptr)
				{
					VirtualFree(m_baseptr, 0, MEM_RELEASE);
					m_baseptr = nullptr;
				}

				m_pLast = nullptr;
				m_pFreeSpace = nullptr;

				m_size = 0;
			}

			friend class PageController;
		};

		size_t m_pageCount;
		size_t m_pageNearCount;
		Page m_pages[num] = {};
		Page m_nearPages[num] = {};

		void CheckOutOfSlotNearPage()
		{
			if (m_pageNearCount >= num)
				SAFEHOOK_THROW("Out of near page slots!");
		}

		void CheckOutOfSlotPage()
		{
			if (m_pageCount >= num)
				SAFEHOOK_THROW("Out of page slots!");
		}
	public:
		PageController() : m_pageCount(0) {}
		~PageController()
		{
			m_pageCount = 0;
		}

		void* allocate(size_t size, size_t align = 32)
		{
			CheckOutOfSlotPage();
			for (size_t i = 0; i < m_pageCount; i++)
			{
				void* ptr = m_pages[i].alloc(size, align);
				if (ptr)
					return ptr;
			}
			m_pages[m_pageCount].init(0x10000);

			return m_pages[m_pageCount++].alloc(size, align);
		}

		void* allocateNear(void* base, size_t size, size_t align = 32)
		{
			CheckOutOfSlotNearPage();
			for (size_t i = 0; i < m_pageNearCount; i++)
			{
				void* ptr = m_nearPages[i].alloc(size, align);
				if (ptr)
					return ptr;
			}
			if (m_nearPages[m_pageNearCount].initNear(base, 0x10000))
				return m_nearPages[m_pageNearCount++].alloc(size, align);
			else
				SAFEHOOK_THROW("Failed to allocate near page!");

			return nullptr;
		}
	};

	inline PageController<16> g_pageController; // 16 pages should be enough for most use cases, you can increase this if you need more

	class scoped_unprotect
	{
		DWORD old_protect;
		size_t address;
		size_t size;
	public:
		scoped_unprotect() : old_protect(0), address(0), size(0) {}

		void protect(size_t address, size_t size)
		{
			if (!address || !size)
			{
				if (!address) SAFEHOOK_THROW("Cannot operate on null address!");
				else if (!size) SAFEHOOK_THROW("Cannot operate on zero size!");
			}

			if (this->address && this->size)
				VirtualProtect((LPVOID)this->address, this->size, old_protect, &old_protect);

			this->address = address;
			this->size = size;
			VirtualProtect((LPVOID)address, size, PAGE_EXECUTE_READWRITE, &old_protect);
		}

		void unprotect()
		{
			if (this->address && this->size)
				VirtualProtect((LPVOID)this->address, this->size, old_protect, &old_protect);

			this->address = 0;
			this->size = 0;
		}

		scoped_unprotect(size_t address, size_t size)
		{
			protect(address, size);
		}

		~scoped_unprotect()
		{
			unprotect();
		}
	};

	inline unsigned int GetDistanceTypeSize(SafeAddress from, SafeAddress to)
	{
		size_t distance = to.get() > from.get() ? to.get() - from.get() : from.get() - to.get(); // absolute distance
		if (distance <= 0x7F)
			return sizeof(uint8_t);
		else if (distance <= 0x7FFFFFFF)
			return sizeof(uint32_t);
		else
			return sizeof(uint64_t);
	}

	inline void MemoryFill(SafeAddress address, unsigned char value, size_t size)
	{
		scoped_unprotect unprotect(address.get(), size);

		memset((void*)address.get(), value, size);
	}

	template <typename T>
	inline void WriteObject(SafeAddress address, const T& object)
	{
		scoped_unprotect unprotect(address.get(), sizeof(T));

		*(T*)address.get() = object;
	}

	template <typename T>
	inline void WriteMemory(SafeAddress address, T value, bool vp = true)
	{
		scoped_unprotect x;

		if (vp)
			x.protect(address.get(), sizeof(T));

		*(T*)address.get() = value;
	}

	inline void WriteMemoryRaw(SafeAddress address, const void* data, size_t size)
	{
		scoped_unprotect unprotect(address.get(), size);

		memcpy((void*)address.get(), data, size);
	}

	inline uintptr_t GetBranchDestination(SafeAddress address)
	{
		hde_s disasm = { 0 };
		HDE_DISASM((unsigned char*)(address.get()), &disasm);
		CHECK_ERROR(disasm);

		if (disasm.flags & F_RELATIVE)
		{
			if (disasm.flags & F_IMM8)
				return (uintptr_t)(address + disasm.len + (char)disasm.imm.imm8);
			else if (disasm.flags & F_IMM16)
				return (uintptr_t)(address + disasm.len + disasm.imm.imm16);
			else if (disasm.flags & F_IMM32)
				return (uintptr_t)(address + disasm.len + disasm.imm.imm32);
#if SAFEHOOK_X64
			else if (disasm.flags & F_IMM64)
				return (uintptr_t)(address + disasm.len + disasm.imm.imm64);
#endif
			else
				return 0;
		}
		else
		{
			if (disasm.flags & F_IMM8)
				return (uintptr_t)(disasm.imm.imm8);
			else if (disasm.flags & F_IMM16)
				return (uintptr_t)(disasm.imm.imm16);
			else if (disasm.flags & F_IMM32)
				return (uintptr_t)(disasm.imm.imm32);
#if SAFEHOOK_X64
			else if (disasm.flags & F_IMM64)
				return (uintptr_t)(disasm.imm.imm64);
#endif
			else
				return 0;
		}

		return 0;
	}

#if SAFEHOOK_X64
	inline unsigned long long MakeRelativeOffsetIMM64(SafeAddress src, SafeAddress dst)
	{
		return dst - src - 14; // 14 bytes for the mov rax, imm64 + jmp rax instructions
	}
#endif

	inline unsigned int MakeRelativeOffsetIMM32(SafeAddress src, SafeAddress dst)
	{
		return dst - src - 5; // 5 bytes for the jmp instruction
	}

	inline unsigned char MakeRelativeOffsetIMM8(SafeAddress src, SafeAddress dst)
	{
		return dst - src - 2;
	}

	inline uintptr_t MakeRelativeOffset(SafeAddress src, SafeAddress dst)
	{
		size_t size = GetDistanceTypeSize(src, dst);

		if (size == sizeof(uint8_t))
			return MakeRelativeOffsetIMM8(src, dst);
		else if (size == sizeof(uint32_t))
			return MakeRelativeOffsetIMM32(src, dst);
#if SAFEHOOK_X64
		else
			return MakeRelativeOffsetIMM64(src, dst);
#endif
		return 0;
	}

	inline uintptr_t MakeJMP(SafeAddress src, SafeAddress dst)
	{
		uintptr_t prev = GetBranchDestination(src);
		size_t typeSize = GetDistanceTypeSize(src, dst);

		switch (typeSize)
		{
			case sizeof(uint8_t) :
			{
				WriteMemory<unsigned char>(src, 0xEB);
				WriteMemory<unsigned char>(src + 1, MakeRelativeOffsetIMM8(src, dst));
				break;
			}
			case sizeof(uint32_t) :
			{
				WriteMemory<unsigned char>(src, 0xE9);
				WriteMemory<unsigned int>(src + 1, MakeRelativeOffsetIMM32(src, dst));
				break;
			}
#if SAFEHOOK_X64
			case sizeof(uint64_t) :
			{
				WriteMemory<unsigned char>(src, 0xFF);
				WriteMemory<unsigned char>(src + 1, 0x25);
				WriteMemory<unsigned int>(src + 2, 0);

				WriteMemory<uint64_t>(src + 6, MakeRelativeOffsetIMM64(src, dst));
				break;
			}
#endif
			default:
				SAFEHOOK_THROW("Invalid distance for JMP instruction!"); // this should never happen since we check the distance type size beforehand
				break;
		}

		return prev;
	}

	inline uintptr_t MakeCALL(SafeAddress src, SafeAddress dst)
	{
		uintptr_t prev = GetBranchDestination(src);
		size_t typeSize = GetDistanceTypeSize(src, dst);

		switch (typeSize)
		{
			case sizeof(uint8_t) :
				case sizeof(uint32_t) :
			{
				WriteMemory<unsigned char>(src, 0xE8);
				WriteMemory<unsigned int>(src + 1, MakeRelativeOffsetIMM32(src, dst));
				break;
			}
#if SAFEHOOK_X64
			case sizeof(uint64_t) :
			{
				WriteMemory<unsigned char>(src, 0xFF);
				WriteMemory<unsigned char>(src + 1, 0x15);
				WriteMemory<unsigned int>(src + 2, 0); // CALL [RIP+0]

				WriteMemory<uint64_t>(src + 6, MakeRelativeOffsetIMM64(src, dst));

				break;
			}
#endif
			default:
				SAFEHOOK_THROW("Invalid distance for CALL instruction!");
				break;
		}

		return prev;
	}

	inline void MakeNOP(SafeAddress address, size_t size)
	{
		MemoryFill(address, 0x90, size);
	}

	inline void MakeRangedNOP(SafeAddress src, SafeAddress dst)
	{
		MakeNOP(src, dst - src);
	}

	inline void MakeRET(SafeAddress address, int pop = 0)
	{
		scoped_unprotect unprotect(address.get(), 1 + (pop ? 2 : 0));
		if (pop)
		{
			WriteMemory<unsigned char>(address, 0xC2, false);
			WriteMemory<unsigned short>(address + 1, pop, false);
		}
		else
		{
			WriteMemory<unsigned char>(address, 0xC3, false);
		}
	}

	// Used to make a trampoline in dst, if the dst is null it will calculate how much bytes is the src
	inline size_t CreateTrampoline(unsigned char* src, unsigned char* dst = nullptr, size_t* tramp_size = nullptr)
	{
		hde_s disasm = { 0 };
		size_t writeOffs = 0;
		size_t readOffs = 0;

		scoped_unprotect unprotect((size_t)src, 32); // unprotect the source memory so we can read and write to it safely

		size_t jmpInstruction = 0;
		switch (GetDistanceTypeSize(src, dst))
		{
			case sizeof(uint8_t) :
			{
				jmpInstruction = 2; // 1 byte for opcode + 1 byte for offset
				break;
			}
			case sizeof(uint32_t) :
			{
				jmpInstruction = 5; // 1 byte for opcode + 4 bytes for offset
				break;
			}
			case sizeof(uint64_t) :
			{
				jmpInstruction = 14; // 2 bytes for opcode + 4 bytes for offset + 8 bytes for absolute address
				break;
			}
			default:
				SAFEHOOK_THROW("Invalid distance for trampoline!");
				break;
		};

		if (!dst)
		{
			while (writeOffs < jmpInstruction)
			{
				HDE_DISASM(src + readOffs, &disasm);
				CHECK_ERROR(disasm);

				writeOffs += disasm.len;
				readOffs += disasm.len;
			}
			return writeOffs;
		}
		else
		{
			while (readOffs < jmpInstruction)
			{
				HDE_DISASM(src + readOffs, &disasm);
				CHECK_ERROR(disasm);

				unsigned char* p = src + readOffs;
				unsigned char* q = dst + writeOffs;
#if SAFEHOOK_X64
				size_t typeSize = GetDistanceTypeSize(p, dst + writeOffs);
				if ((*p >= 0x70 && *p <= 0x7F) || (*p == 0x0F && (*(p + 1) >= 0x80 && *(p + 1) <= 0x8F)))
				{
					uintptr_t dest = GetBranchDestination(p);
					if (typeSize == sizeof(uint64_t))
						SAFEHOOK_THROW("Jcc does not support 64-bit relative offsets!");

					if (*p == 0x0F)
					{
						WriteMemory<unsigned char>(q, 0x0F);
						WriteMemory<unsigned char>(q + 1, p[1]);
						WriteMemory<unsigned int>(q + 2, MakeRelativeOffsetIMM32(dst + writeOffs, dest));

						writeOffs += 6;
					}
					else
					{
						WriteMemory<unsigned char>(q, 0x0F);
						WriteMemory<unsigned char>(q + 1, *p + 0x10);
						WriteMemory<unsigned int>(q + 2, MakeRelativeOffsetIMM32(dst + writeOffs, dest));

						writeOffs += 6;
					}
				}
				else if (*p == 0xE9 || *p == 0xE8) // jmp or call
				{
					uintptr_t dest = GetBranchDestination(p);

					if (*p == 0xE9)
						MakeJMP(q, dest);
					else
						MakeCALL(q, dest);

					if (typeSize == sizeof(uint64_t))
						writeOffs += 14;
					else
						writeOffs += 5;
				}
				else if (*p == 0xEB)
				{
					uintptr_t branchDest = GetBranchDestination(p);

					MakeJMP(q, branchDest);
					if (typeSize == sizeof(uint64_t))
						writeOffs += 14;
					else
						writeOffs += 5;
				}
				else
				{
					memcpy(dst + writeOffs, src + readOffs, disasm.len);
					writeOffs += disasm.len;
				}
#else
				if ((*p >= 0x70 && *p <= 0x7F) || (*p == 0x0F && (*(p + 1) >= 0x80 && *(p + 1) <= 0x8F)))
				{
					WriteMemory<unsigned char>(dst + writeOffs, (unsigned char)0x0F);
					WriteMemory<unsigned char>(dst + writeOffs + 1, *p != 0x0F ? *p + 0x10 : *(p + 1));

					uintptr_t branchDest = GetBranchDestination(p);
					WriteMemory<uintptr_t>(dst + writeOffs + 2, MakeRelativeOffsetIMM32(dst + writeOffs, branchDest));

					writeOffs += 6;
				}
				else if (*p == 0xE9 || *p == 0xE8) // jmp or call
				{
					uintptr_t branchDest = GetBranchDestination(p);

					WriteMemory<unsigned char>(dst + writeOffs, *p); // copy the jmp/call opcode
					WriteMemory<unsigned int>(dst + writeOffs + 1, MakeRelativeOffsetIMM32(dst + writeOffs, branchDest));

					writeOffs += 5;
				}
				else if (*p == 0xEB) // since it's a trampoline, we will upgrade it into imm32
				{
					uintptr_t branchDest = GetBranchDestination(p);

					MakeJMP(dst + writeOffs, branchDest);
					writeOffs += 5;
				}
				else
				{
					memcpy(dst + writeOffs, src + readOffs, disasm.len);
					writeOffs += disasm.len;
				}
#endif
				readOffs += disasm.len;
			}
		}

		MakeJMP(dst + writeOffs, src + readOffs); // jmp back to the original routine after the overwritten bytes

		if (tramp_size)
			*tramp_size = writeOffs;

		return readOffs;
	}

	class Hook
	{
		unsigned char* m_target;
		unsigned char* m_hook;
		size_t m_trampolineSize;

		struct
		{
			union
			{
				struct
				{
					unsigned int bEnabled : 1;
					unsigned int bTrampolineCreated : 1;
					unsigned int bTrampolineLinked : 1;
				};
				unsigned int i32;
			};
		} m_state;
		unsigned char* m_trampoline;
		unsigned char* m_originalBytes;
		size_t m_originalSize;

		void CreateTrampoline()
		{
			if (!m_state.bTrampolineCreated)
			{
				size_t size = SafeHook::CreateTrampoline(m_target, nullptr);
				m_originalSize = size;

				void* pPage = g_pageController.allocate(size + g_JmpInstructionSize, 32);
				m_originalBytes = (unsigned char*)g_pageController.allocate(size, 32);

				if (m_originalBytes) memcpy(m_originalBytes, m_target, size);

				if (pPage && m_originalBytes)
				{
					m_trampoline = (unsigned char*)pPage;
					SafeHook::CreateTrampoline(m_target, m_trampoline, &m_trampolineSize);

					m_state.bTrampolineCreated = true;
				}
				else
				{
					SAFEHOOK_THROW("Failed to allocate memory for trampoline!");
				}
			}
		}
	public:
		Hook()
		{
			m_target = m_hook = m_trampoline = m_originalBytes = nullptr;
			m_trampolineSize = m_originalSize = m_state.i32 = 0;
		}

		Hook(void* pTarget, void* pHook, bool bEnable = true, void** pOriginal = nullptr)
		{
			try
			{
				if (!pTarget || !pHook)
					SAFEHOOK_THROW("Target and hook addresses cannot be null!");

				m_target = (unsigned char*)pTarget;
				m_hook = (unsigned char*)pHook;
				CreateTrampoline();

				if (pOriginal)
					*pOriginal = m_trampoline;

				if (bEnable)
					Enable();
			}
			catch (const Exception& e)
			{
				ReportException(e);
			}
		}

		Hook(void* pTarget, void* pHook, void** pOriginal)
		{
			try
			{
				if (!pTarget || !pHook)
					SAFEHOOK_THROW("Target and hook addresses cannot be null!");

				m_target = (unsigned char*)pTarget;
				m_hook = (unsigned char*)pHook;
				CreateTrampoline();
				if (pOriginal)
					*pOriginal = m_trampoline;

				Enable();
			}
			catch (const Exception& e)
			{
				ReportException(e);
			}
		}

		void Enable()
		{
			m_state.bEnabled = true;
			if (m_state.bTrampolineCreated && !m_state.bTrampolineLinked)
			{
				ThreadRedirect(m_target, m_originalSize, m_hook);
				scoped_unprotect unprotect((size_t)m_target, m_originalSize);

				memset(m_target, 0x90, m_originalSize);

				MakeJMP((size_t)m_target, (size_t)m_hook);

				m_state.bTrampolineLinked = true;
			}
		}

		void Disable()
		{
			m_state.bEnabled = false;
			if (m_state.bTrampolineCreated && m_state.bTrampolineLinked)
			{
				scoped_unprotect unprotect((size_t)m_target, m_originalSize);

				if (m_originalBytes) memcpy((void*)m_target, m_originalBytes, m_originalSize);

				m_state.bTrampolineLinked = false;
			}
		}

		~Hook()
		{
			if (CheckValidAddress(m_target)) // Sometimes the target might be already unloaded by the time the destructor is called, so we check if it's a valid address before trying to restore it
				Disable(); // just to be safe, make sure to restore the original bytes before freeing the trampoline and original bytes memory

			m_trampoline = m_originalBytes = nullptr;
			m_target = m_hook = nullptr;
			m_trampolineSize = m_originalSize = 0;
			m_state.i32 = 0;
		}
	};

#if SAFEHOOK_X64
	typedef union
	{
		unsigned __int64 i64;
		unsigned int i32;
		unsigned short i16;
		unsigned char i8;
		float f32;
		double f64;
	} REG;
#else
	typedef union
	{
		unsigned int i32;
		unsigned short i16;
		unsigned char i8;

		float f32;
	} REG;
#endif

	typedef union
	{
		struct
		{
			unsigned int CF : 1;
			unsigned int BRKI : 1;
			unsigned int PF : 1;
			unsigned int Reserved1 : 1;
			unsigned int AF : 1;
			unsigned int Reserved2 : 1;
			unsigned int ZF : 1;
			unsigned int SF : 1;

			unsigned int TF : 1;
			unsigned int IF : 1;
			unsigned int DF : 1;
			unsigned int OF : 1;
			unsigned int IOPL : 2;
			unsigned int NT : 1;
			unsigned int MD : 1;
		}; // no more flags since pushfd only stores the lower 16 bits of EFLAGS
		unsigned int i32;
	} EFLAGS;

#if SAFEHOOK_X64
	typedef union
	{
		struct
		{
			unsigned __int64 CF : 1;
			unsigned __int64 BRKI : 1;
			unsigned __int64 PF : 1;
			unsigned __int64 Reserved1 : 1;
			unsigned __int64 AF : 1;
			unsigned __int64 Reserved2 : 1;
			unsigned __int64 ZF : 1;
			unsigned __int64 SF : 1;

			unsigned __int64 TF : 1;
			unsigned __int64 IF : 1;
			unsigned __int64 DF : 1;
			unsigned __int64 OF : 1;
			unsigned __int64 IOPL : 2;
			unsigned __int64 NT : 1;
			unsigned __int64 MD : 1;
		};
		unsigned __int64 i64;
	} RFLAGS;
#endif

	typedef struct FPUREG
	{
	private: // we shouldn't be really exposed to "internals" so let's just hide it and provide a way to convert to/from double, which is what most people would want to use
		unsigned long long Mantissa;
		unsigned short ExponentSign;
		char Reserved[6];

	private:
		double toDouble() const
		{
			unsigned short exp = ExponentSign & 0x7FFF;
			int sign = ExponentSign & 0x8000 ? -1 : 1;
			unsigned long long mantissa = Mantissa;

			if (exp == 0 && mantissa == 0)
				return 0.0 * sign;

			int realExp = exp - 16383; // 16383 is the bias for 80-bit extended precision

			double fraction = (double)mantissa / (double)(1ULL << 63); // The mantissa is effectively a fixed-point number with an implicit leading 1, so we divide by 2^63 to get the fractional part

			return sign * ldexp(fraction, realExp); // ldexp is used to compute fraction * 2^realExp efficiently and accurately
		}

		void setDouble(double x)
		{
			memset(this, 0, sizeof(FPUREG));

			if (x == 0.0)
			{
				if (signbit(x))
					ExponentSign = 0x8000;

				return;
			}

			int exp;

			double frac = frexp(abs(x), &exp); // breaks x into its binary significand (frac) and an integral exponent for 2 (exp), such that x = frac * 2^exp

			frac *= 2.0;
			exp -= 1;

			uint16_t sign = signbit(x) ? 0x8000 : 0;
			uint16_t biasedExp = (uint16_t)(exp + 16383); // add the bias for 80-bit extended precision
			ExponentSign = sign | biasedExp;

			Mantissa = (unsigned long long)(frac * (double)(1ULL << 63)); // convert the fractional part to the fixed-point representation used in the mantissa
		}
	public:
		operator double() const { return toDouble(); }
		// operator float() const { return (float)toDouble(); } // let's prefer it double for better precision, but you can add this if you want

		FPUREG() : Mantissa(0), ExponentSign(0) {}
		FPUREG(double x) { setDouble(x); }

		FPUREG& operator=(double x) { setDouble(x); return *this; }
		FPUREG& operator*=(double x) { setDouble(toDouble() * x); return *this; }
		FPUREG& operator/=(double x) { setDouble(toDouble() / x); return *this; }
		FPUREG& operator+=(double x) { setDouble(toDouble() + x); return *this; }
		FPUREG& operator-=(double x) { setDouble(toDouble() - x); return *this; }

		FPUREG operator*(double x) const { FPUREG result; result.setDouble(toDouble() * x); return result; }
		FPUREG operator/(double x) const { FPUREG result; result.setDouble(toDouble() / x); return result; }
		FPUREG operator+(double x) const { FPUREG result; result.setDouble(toDouble() + x); return result; }
		FPUREG operator-(double x) const { FPUREG result; result.setDouble(toDouble() - x); return result; }
	} FPUREG;

	typedef union
	{
		unsigned __int64 i64[2];
		unsigned int i32[4];
		unsigned short i16[8];
		unsigned char i8[16];

		float f32[4];
		double f64[2];
	} XMMREG;

	typedef struct
	{
		struct FPUUnit
		{
			unsigned short FCW;
			unsigned short FSW;
			unsigned char FTW;
			unsigned char Reserved1;
			unsigned short FOP;
			unsigned int FIP;
			unsigned int FCS;
			unsigned int FDP;
			unsigned int FDS;
			unsigned int MXSCR;
			unsigned int MXSCR_MASK;

			FPUREG st[8];
		} FPU;

		XMMREG xmm[16];

		static_assert(sizeof(FPUUnit) == 0xA0, "FPUUnit size mismatch!");

		char _padding[512 - 0xA0 - 16 * 16];
	} FPUx87SSE;

	static_assert(sizeof(FPUx87SSE) == 512, "FPUx87SSE size mismatch!");

#if SAFEHOOK_X86
	typedef struct CTX
	{
		FPUx87SSE FPUandSSE;

		REG ebx;
		REG ecx;
		REG edx;
		REG esi;
		REG edi;
		REG saved_esp;
		REG ebp;

		REG& eax() { return *(REG*)(saved_esp.i32); }
		EFLAGS& eflags() { return *(EFLAGS*)(saved_esp.i32 + 4); }
		const REG& esp() const { return (REG)(saved_esp.i32 + 0xC); } // you are not allowed to modify stack pointer

		XMMREG& xmm(int i _In_range_(0, 7)) { return FPUandSSE.xmm[i]; }
		FPUREG& st(int i _In_range_(0, 7)) { return FPUandSSE.FPU.st[i]; }
	} CTX;
#else
	typedef struct CTX
	{
		FPUx87SSE FPUandSSE;

		REG rbx;
		REG rcx;
		REG rdx;
		REG rsi;
		REG rdi;
		REG saved_rsp;
		REG rbp;
		REG r8;
		REG r9;
		REG r10;
		REG r11;
		REG r12;
		REG r13;
		REG r14;
		REG r15;

		REG& rax() { return *(REG*)(saved_rsp.i64); }
		RFLAGS& rflags() { return *(RFLAGS*)(saved_rsp.i64 + 8); }

		XMMREG& xmm(int i _In_range_(0, 15)) { return FPUandSSE.xmm[i]; }
		FPUREG& st(int i _In_range_(0, 7)) { return FPUandSSE.FPU.st[i]; }
	};
#endif
	// @brief Can be used in cave or in mid-function hooking
	// @brief If you can place it in instead of the opcode with 5 bytes length you won't need to use MidAsmHook(which uses trampoline for safety)
	class MidAsmHookUnsafe
	{
	private:
		uintptr_t address_of_hook = 0;

		unsigned char* hook_bytes = nullptr;
		uintptr_t cave_address = 0;
		unsigned char original_cave_bytes[g_JmpInstructionSize + 8] = { 0 }; // to store the original bytes of the cave, we will restore them in the destructor. 16 bytes should be enough for most hooks, you can increase this if you need more
	public:
		MidAsmHookUnsafe() = default;

		MidAsmHookUnsafe(SafeAddress address_of_cave, void(__cdecl* hook_func)(CTX&))
		{
			address_of_hook = (uintptr_t)hook_func;
			cave_address = address_of_cave.get();
			hook_bytes = (unsigned char*)g_pageController.allocate(sizeof(asm_data) + g_JmpInstructionSize, 32); // allocate memory for the hook code and the jump back to the original function
			if (!hook_bytes)
				SAFEHOOK_THROW("Failed to allocate memory for hook bytes!");

			{
				scoped_unprotect unprotect(cave_address, sizeof(original_cave_bytes));
				memcpy(original_cave_bytes, (void*)cave_address, sizeof(original_cave_bytes)); // save the original bytes of the cave so we can restore them later
			}

			memcpy(hook_bytes, asm_data, sizeof(asm_data));
			MakeJMP(hook_bytes + sizeof(asm_data), address_of_hook);

			MakeCALL(cave_address, hook_bytes);
		}

		~MidAsmHookUnsafe()
		{
			if (cave_address && CheckValidAddress(cave_address) && hook_bytes)
			{
				scoped_unprotect unprotect(cave_address, sizeof(original_cave_bytes));
				memcpy((void*)cave_address, original_cave_bytes, sizeof(original_cave_bytes));
			}

			if (hook_bytes)
				hook_bytes = nullptr; // we won't free the memory, but at least we won't leave a dangling pointer. The memory will be freed when the process exits, so it shouldn't be a problem.

			cave_address = 0;
		}

		friend class MidAsmHook;
	};

	// @brief Safer version, but actually a simple wrapper
	class MidAsmHook
	{
	private:
		MidAsmHookUnsafe unsafe_hook;
		unsigned char* trampoline = nullptr;

		// Try to find a place to inject the trampoline
		// You cannot just put a trampoline in the middle of instruction and expect it to work
		void handleTrampoline(uintptr_t _address, size_t& orig_size, bool bTryAllocNear = false)
		{
			size_t orignal_size = CreateTrampoline((unsigned char*)_address, nullptr);

			if (SAFEHOOK_X86)
				bTryAllocNear = false; // for x86 there's no need for allocating near, since the relative jump can reach anywhere in the 4GB address space

			if (bTryAllocNear)
			{
				trampoline = (unsigned char*)g_pageController.allocateNear((void*)_address, orignal_size + g_JmpInstructionSize * 2, 32);
				if (!trampoline)
					trampoline = (unsigned char*)g_pageController.allocate(orignal_size + g_JmpInstructionSize * 2, 32);
			}
			else
			{
				trampoline = (unsigned char*)g_pageController.allocate(orignal_size + g_JmpInstructionSize * 2, 32);
			}
			if (!this->trampoline)
			{
				SAFEHOOK_THROW_FORMAT("Failed to allocate memory for %p!", (void*)_address);
			}
			size_t typeSize = GetDistanceTypeSize(trampoline, _address + orignal_size);
			size_t jmpSize = 0;
			switch (typeSize)
			{
			case 1:
				jmpSize = 2;
				break;
			case 4:
				jmpSize = 5;
				break;
			case 8:
				jmpSize = 14;
				break;
			default:
				break;
			}

			MakeNOP(trampoline, jmpSize);

			orig_size = CreateTrampoline((unsigned char*)_address, this->trampoline + jmpSize, nullptr);
		}
	public:
		MidAsmHook() = default;

		MidAsmHook(SafeAddress _address, void(__cdecl* hook_func)(CTX&))
		{
			size_t orig_size = 0;
			try
			{
				handleTrampoline(_address.get(), orig_size);
			}
			catch (const SafeHook::Exception& e)
			{
				ReportException(e);
				return;
			}

			if (!trampoline)
				return;

			try
			{
				new (&unsafe_hook) MidAsmHookUnsafe(trampoline, hook_func);
			}
			catch (const SafeHook::Exception& e)
			{
				ReportException(e);
				return;
			}
			// we need to proceed with the "MidAsmHookUnsafe" before it is connected to the main routine, if we do it after, we might run into unhandled exception

			scoped_unprotect unprotect(_address.get(), orig_size);
			{
				ThreadRedirect(_address, orig_size, trampoline); // make sure no other thread is executing the original code while we are modifying it, this will prevent crashes and undefined behavior
				// we got the trampoline ready for executing hook_func along with original instructions, so redirection logically must continue executing in the trampoline along with calling our hook immediately

				memset((void*)_address.get(), 0x90, orig_size);

				MakeJMP(_address, trampoline);
			}

			// basically
			// call hook_wrapper
			// [original instructions]
			// jmp original_func + original_instructions_size
		}

		~MidAsmHook()
		{
			if (unsafe_hook.cave_address)
				unsafe_hook.cave_address = 0; // avoid restoring original bytes, so it won't crash if the hook is called after this destructor

			if (trampoline)
				trampoline = nullptr; // everything handled by page controller

			// unsafe_hook will automatically destruct itself
		}
	};
#undef CHECK_ERROR
}