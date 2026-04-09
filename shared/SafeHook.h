#pragma once
#include <Windows.h>
#if defined(_M_X64) || defined(__x86_64__)
#include "hde/hde64.h"
#else
#include "hde/hde32.h"
#endif
#include <assert.h>
#include <new>

// All credits for function hooks goes to DarkByte

namespace SafeHook
{
	template <int num>
	class PageController
	{
		struct Page
		{
			void* m_pPage;
			int m_size;
			int m_alignment;

			void* m_pNextFree;

			void* getNextFree() const
			{
				return m_pNextFree;
			}

			Page() : m_pPage(nullptr), m_size(0), m_alignment(0) {}
			~Page()
			{
				if (m_pPage)
					VirtualFree(m_pPage, 0, MEM_RELEASE);

				m_pNextFree = nullptr;
				m_size = 0;
				m_alignment = 0;
			}

			void* allocate(int size)
			{
				if (!m_pPage || (char*)m_pNextFree + size > (char*)m_pPage + m_size)
					return nullptr;

				if (!m_pNextFree)
					m_pNextFree = m_pPage;

				void* p = m_pNextFree;
				m_pNextFree = (void*)(~(m_alignment - 1) & (((unsigned int)m_pNextFree + size) + m_alignment - 1)); // make sure to align the next free address
				return p;
			}
		};
		int m_pageCount;
		Page m_pages[num] = {};

		Page* allocatePage(int size, int alignment = 0x1000)
		{
			if (m_pageCount >= num)
				return nullptr;

			Page& page = m_pages[m_pageCount++];
			page.m_size = size;
			page.m_alignment = alignment;
			page.m_pPage = VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

			return &page;
		}
	public:
		PageController()
		{
			m_pageCount = 0;
		}

		~PageController()
		{
			// Pages will automatically free their memory in their destructor
		}

		void* allocate(int size, int alignment = 0x1000)
		{
			for (int i = 0; i < m_pageCount; i++)
			{
				if (void* p = m_pages[i].allocate(size); p)
					return p;
			}

			Page* newPage = allocatePage(0x10000, alignment); // MEM_COMMIT | MEM_RESERVE, 64KB page size, you can adjust this if you need more or less space per page, less size would hardly matter due to page granularity, but more size would reduce the chance of running out of pages, so it depends on your use case
			if (!newPage)
				return nullptr;

			return newPage->allocate(size);
		}

		// No deallocation function, so bear in mind to use this wisely
	};

	static inline PageController<16> g_pageController; // 16 pages should be enough for most use cases, you can increase this if you need more

	class scoped_unprotect
	{
		DWORD old_protect;
		size_t address;
		size_t size;
	public:
		scoped_unprotect(size_t address, size_t size)
		{
			this->address = address;
			this->size = size;
			VirtualProtect((LPVOID)address, size, PAGE_EXECUTE_READWRITE, &old_protect);
		}

		~scoped_unprotect()
		{
			VirtualProtect((LPVOID)address, size, old_protect, &old_protect);
		}
	};

#define MAKE_RELATIVE_OFFSET(src, dst) ((unsigned int)(dst) - (unsigned int)(src) - 5)
#define GET_BRANCH_DESTINATION(src) ((size_t)(src) + 5 + *(DWORD*)((size_t)(src) + 1))

#define MAKE_JMP(src, dst) \
{ \
	scoped_unprotect unprotect(src, 5); \
	*(BYTE*)(src) = 0xE9; \
	*(DWORD*)((src) + 1) = MAKE_RELATIVE_OFFSET(src, dst); \
}

#define MAKE_CALL(src, dst) \
{ \
	scoped_unprotect unprotect(src, 5); \
	*(BYTE*)(src) = 0xE8; \
	*(DWORD*)((src) + 1) = MAKE_RELATIVE_OFFSET(src, dst); \
}

#define MAKE_NOP(src, size) \
{ \
	scoped_unprotect unprotect(src, size); \
	memset((void*)src, 0x90, size); \
}

#define MAKE_RANGED_NOP(src, dst) MAKE_NOP(src, dst - src)

#if defined(_M_X64) || defined(__x86_64__)
	typedef union
	{
		unsigned __int64 i64;
		unsigned int i32;
		unsigned short i16;
		unsigned char i8;
		float f32;
		double f64;
	} REG;

	typedef struct
	{
		double f;
		short tag;
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

	typedef struct CTX
	{
		char FPUandSSE[512];
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

		REG& rax() { return *(REG*)(saved_rsp.i32); }
		REG& rflags() { return *(REG*)(saved_rsp.i32 + 4); }
		XMMREG& xmm(int i _In_range_(0, 15)) { return *(XMMREG*)(FPUandSSE + (0xA0 + 0x20) + i * 16); }
		FPUREG& st(int i _In_range_(0, 7)) { return *(FPUREG*)(FPUandSSE + 0x20 + i * 16); }
	} CTX;

	static inline unsigned char SafeHookBytes[] = {
		0x9C, 0x50, 0x48, 0x8B, 0xC4, 0x48, 0x83, 0xE4, 0xF0, 0x48, 0x81, 0xEC, 0xA0, 0x02, 0x00, 0x00,
		0x0F, 0xAE, 0x44, 0x24, 0x20, 0x48, 0x89, 0x9C, 0x24, 0x20, 0x02, 0x00, 0x00, 0x48, 0x89, 0x8C,
		0x24, 0x28, 0x02, 0x00, 0x00, 0x48, 0x89, 0x94, 0x24, 0x30, 0x02, 0x00, 0x00, 0x48, 0x89, 0xB4,
		0x24, 0x38, 0x02, 0x00, 0x00, 0x48, 0x89, 0xBC, 0x24, 0x40, 0x02, 0x00, 0x00, 0x48, 0x89, 0x84,
		0x24, 0x48, 0x02, 0x00, 0x00, 0x48, 0x89, 0xAC, 0x24, 0x50, 0x02, 0x00, 0x00, 0x4C, 0x89, 0x84,
		0x24, 0x58, 0x02, 0x00, 0x00, 0x4C, 0x89, 0x8C, 0x24, 0x60, 0x02, 0x00, 0x00, 0x4C, 0x89, 0x94,
		0x24, 0x68, 0x02, 0x00, 0x00, 0x4C, 0x89, 0x9C, 0x24, 0x70, 0x02, 0x00, 0x00, 0x4C, 0x89, 0xA4,
		0x24, 0x78, 0x02, 0x00, 0x00, 0x4C, 0x89, 0xAC, 0x24, 0x80, 0x02, 0x00, 0x00, 0x4C, 0x89, 0xB4,
		0x24, 0x88, 0x02, 0x00, 0x00, 0x4C, 0x89, 0xBC, 0x24, 0x90, 0x02, 0x00, 0x00, 0x48, 0x8D, 0x4C,
		0x24, 0x20, 0xFF, 0x15, 0x78, 0x1E, 0x00, 0x00, 0x4C, 0x8B, 0xBC, 0x24, 0x90, 0x02, 0x00, 0x00,
		0x4C, 0x8B, 0xB4, 0x24, 0x88, 0x02, 0x00, 0x00, 0x4C, 0x8B, 0xAC, 0x24, 0x80, 0x02, 0x00, 0x00,
		0x4C, 0x8B, 0xA4, 0x24, 0x78, 0x02, 0x00, 0x00, 0x4C, 0x8B, 0x9C, 0x24, 0x70, 0x02, 0x00, 0x00,
		0x4C, 0x8B, 0x94, 0x24, 0x68, 0x02, 0x00, 0x00, 0x4C, 0x8B, 0x8C, 0x24, 0x60, 0x02, 0x00, 0x00,
		0x4C, 0x8B, 0x84, 0x24, 0x58, 0x02, 0x00, 0x00, 0x48, 0x8B, 0xAC, 0x24, 0x50, 0x02, 0x00, 0x00,
		0x48, 0x8B, 0xBC, 0x24, 0x40, 0x02, 0x00, 0x00, 0x48, 0x8B, 0xB4, 0x24, 0x38, 0x02, 0x00, 0x00,
		0x48, 0x8B, 0x94, 0x24, 0x30, 0x02, 0x00, 0x00, 0x48, 0x8B, 0x8C, 0x24, 0x28, 0x02, 0x00, 0x00,
		0x48, 0x8B, 0x9C, 0x24, 0x20, 0x02, 0x00, 0x00, 0x0F, 0xAE, 0x4C, 0x24, 0x20, 0x48, 0x8B, 0xA4,
		0x24, 0x48, 0x02, 0x00, 0x00, 0x58, 0x9D, 0xC3,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // 16 bytes for jmp
	};
#else
	typedef union
	{
		unsigned int i32;
		unsigned short i16;
		unsigned char i8;

		float f32;
	} REG;

	typedef struct
	{
		double f;
		short tag;
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

	typedef struct CTX
	{
		char FPUandSSE[512];

		REG ebx;
		REG ecx;
		REG edx;
		REG esi;
		REG edi;
		REG saved_esp;
		REG ebp;

		REG& eax() { return *(REG*)(saved_esp.i32); }
		REG& eflags() { return *(REG*)(saved_esp.i32 + 4); }

		XMMREG& xmm(int i _In_range_(0, 7)) { return *(XMMREG*)(FPUandSSE + 0xA0 + i * 16); }
		FPUREG& st(int i _In_range_(0, 7)) { return *(FPUREG*)(FPUandSSE + i * 16); }
	} CTX;

	void __declspec(naked) naked_hook()
	{
		__asm
		{
			pushfd
			push eax
			mov eax, esp
			and esp, 0xFFFFFFF0
			sub esp, 0x220
			fxsave[esp]
			mov[esp + 0x200], ebx
			mov[esp + 0x204], ecx
			mov[esp + 0x208], edx
			mov[esp + 0x20C], esi
			mov[esp + 0x210], edi
			mov[esp + 0x214], eax
			mov[esp + 0x218], ebp
			mov eax, esp
			push eax
			call far dword ptr ds : [trampoline]
			add esp, 04
			mov ebp, [esp + 0x218]
			mov edi, [esp + 0x210]
			mov esi, [esp + 0x20C]
			mov edx, [esp + 0x208]
			mov ecx, [esp + 0x204]
			mov ebx, [esp + 0x200]
			fxrstor[esp]
			mov esp, [esp + 0x214]
			pop eax
			popfd
			ret

			trampoline :
			add[eax], al
			add[eax], al // two instructions for zero's
		}
	}
#endif
	// @brief Can be used in cave or in mid-function hooking. The address template parameter is used to ensure that each hook has its own unique hook function, which is necessary for mid-function hooking.
	class MidAsmHookUnsafe
	{
	private:
		unsigned int address_of_hook = 0;

		unsigned char* hook_bytes = nullptr;
		size_t cave_address = 0;
#define MAX_BYTES 5
#if defined(_M_X64) || defined(__x86_64__)
#undef MAX_BYTES
#define MAX_BYTES 24
#endif
		unsigned char original_cave_bytes[MAX_BYTES] = { 0 };
	public:
		MidAsmHookUnsafe() = default;

		MidAsmHookUnsafe(size_t address_of_cave, void(*hook_func)(CTX&))
		{
#if defined(_M_X64) || defined(__x86_64__)
			address_of_hook = (unsigned int)hook_func;
			cave_address = address_of_cave;
			size_t fncsize = 0;
			{
				for (unsigned char* p = (unsigned char*)naked_hook; ; p++)
				{
					if (*p == 0xC3) // ret
					{
						fncsize = p - (unsigned char*)naked_hook + 1;
						fncsize += 32;
						break;
					}
				}
			}
			hook_bytes = (unsigned char*)VirtualAlloc(nullptr, fncsize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
			if (!hook_bytes)
				return;

			memcpy(hook_bytes, (void*)SafeHookBytes, fncsize);
			{
				char* ptr = (char*)hook_bytes + fncsize - 32;

				*((unsigned short*)ptr)++ = 0xB848;
				*((unsigned long long*)ptr)++ = address_of_hook;
				*((unsigned short*)ptr) = 0xFFE0; // jmp rax
			}

			{
				scoped_unprotect unprotect(address_of_cave, sizeof(original_cave_bytes));
				char* ptr = (char*)address_of_cave;

				*((unsigned short*)ptr)++ = 0xFF15;
				*((unsigned long long*)ptr) = MAKE_RELATIVE_OFFSET(address_of_cave, hook_bytes); // I hope it works
			}
#else
			address_of_hook = (unsigned int)hook_func;
			cave_address = address_of_cave;
			size_t fncsize = 0;
			{
				for (unsigned char* p = (unsigned char*)naked_hook; ; p++)
				{
					if (*p == 0xC3) // ret
					{
						fncsize = p - (unsigned char*)naked_hook + 1;
						fncsize += 5; // for the trampoline address, 4 + 1, 1 is for reservation
						break;
					}
				}
			}
			hook_bytes = (unsigned char*)g_pageController.allocate(fncsize, 0x100); // up to 256 bytes for each hook, hooks generally shouldn't eat up that much space
			if (!hook_bytes)
				return;

			memcpy(hook_bytes, (void*)naked_hook, fncsize);

			MAKE_JMP((size_t)hook_bytes + fncsize - 5, address_of_hook);
			memcpy(original_cave_bytes, (void*)address_of_cave, sizeof(original_cave_bytes));

			MAKE_CALL(address_of_cave, hook_bytes);
#endif
		}

		~MidAsmHookUnsafe()
		{
			if (cave_address && hook_bytes)
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
		void handleTrampoline(size_t _address, size_t &orig_size)
		{
			do
			{
				unsigned char* opcode = (unsigned char*)_address;
				switch (*opcode)
				{
				case 0xEB: // short jmp
				case 0x74: // jz
				case 0x75: // jnz
				case 0x70: // jo
				case 0x71: // jno
				case 0x72: // jc
				case 0x73: // jnc
				case 0x7C: // jl
				case 0x7D: // jge
				case 0x7E: // jle
				case 0x7F: // jg
				case 0xE9: // near jmp
					throw "Jump opcodes with rel32, rel16 and rel8 are not supported by a default. Find a proper place to make injection."; 
					// not supported because we can't actually do shit here, the time we create a trampoline, the time it will literally ignore the trampoline itself
					// Or unless we just put it after our trampoline, then maybe it'll be something good
					// TODO: Add support for JMP instructions
				default:
					break;
				}
			} while (0);
			size_t orig_bytes_coverup = 0;

			hde32s disasm = { 0 };

			while (orig_bytes_coverup < 5) // we need at least 5 bytes to place a jmp instruction, so if the first instruction is smaller than 5 bytes, we need to cover the next instruction(s) until we have enough bytes
			{
				orig_bytes_coverup += hde32_disasm((void*)(_address + orig_bytes_coverup), &disasm);
				if (disasm.flags & F_ERROR) // just make sure to inform
				{
					if (disasm.flags & F_ERROR_OPCODE)
						throw "Opcode error occured!";
					else if (disasm.flags & F_ERROR_LENGTH)
						throw "Length error occured!";
					else if (disasm.flags & F_ERROR_LOCK)
						throw "Lock error occured!";
					else if (disasm.flags & F_ERROR_OPERAND)
						throw "Operand error occured!";
					else
						throw "Unknown error occured during disassembly!";
				}
			}

			scoped_unprotect unprotect(_address, orig_bytes_coverup);

			trampoline = (unsigned char*)g_pageController.allocate(orig_bytes_coverup + 5, 0x100); // the trampoline will contain the original bytes and a jmp back to the original function, so we need orig_bytes_coverup + 5 bytes of space

			if (trampoline)
			{
				for (int i = 0; i < orig_bytes_coverup; i++)
				{
					unsigned char* opcode = (unsigned char*)_address + i;
					switch (*opcode)
					{
					case 0xE8: // sizeof - 5, already satisfies copy and fix for call instruction
					{
						size_t dest = GET_BRANCH_DESTINATION(opcode);
						trampoline[i] = 0xE8;
						*(DWORD*)(trampoline + i + 1) = MAKE_RELATIVE_OFFSET((size_t)(trampoline + i), dest);
						return;
					}
					case 0xE9: // sizeof - 5, already satisfies copy and fix for jmp instruction
					{
						size_t dest = GET_BRANCH_DESTINATION(opcode);

						trampoline[i] = 0xE9;
						*(DWORD*)(trampoline + i + 1) = MAKE_RELATIVE_OFFSET((size_t)(trampoline + i), dest);
						return; // Not even sure if our mid hook gonna execute from here, leads to a dead end
					}
					default:
						trampoline[i] = *opcode;
						break;
					}
				}
			}
			orig_size = orig_bytes_coverup;
		}
	public:
		MidAsmHook(size_t _address, void(*hook_func)(CTX&))
		{
#if defined(_M_X64) || defined(__x86_64__)

#else
			size_t orig_bytes_coverup = 0;
			try
			{
				handleTrampoline(_address, orig_bytes_coverup);
			}
			catch (const char* err)
			{
				MessageBoxA(nullptr, err, "SafeHook Error", MB_ICONERROR | MB_OK);
			}

			if (!trampoline)
				return;

			scoped_unprotect unprotect(_address, orig_bytes_coverup);

			{
				unsigned char* ptr = (unsigned char*)_address;
				*ptr = 0xE9;
				*(DWORD*)(ptr + 1) = MAKE_RELATIVE_OFFSET(_address, (size_t)trampoline);
			}

			new(&unsafe_hook) MidAsmHookUnsafe((size_t)(trampoline + orig_bytes_coverup), hook_func); // the cave is right after the original bytes

			{
				unsigned char* ptr = (unsigned char*)trampoline + orig_bytes_coverup + 5;

				*ptr = 0xE9;
				*(DWORD*)(ptr + 1) = MAKE_RELATIVE_OFFSET((size_t)ptr, _address + orig_bytes_coverup);
			}

			// basically
			// [original instructions]
			// call hook_wrapper
			// jmp original_func + original_instructions_size
#endif
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
}

#undef MAX_BYTES