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

#if defined(_M_X64) || defined(__x86_64__)
typedef hde64s hde_s;
#define HDE_DISASM(ptr, disasm) hde64_disasm(ptr, disasm)
#else
typedef hde32s hde_s;
#define HDE_DISASM(ptr, disasm) hde32_disasm(ptr, disasm)
#endif

namespace SafeHook
{
#if defined(_M_X64) || defined(__x86_64__)
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
do { \
	scoped_unprotect unprotect(size_t(src), 5); \
	*(BYTE*)(src) = 0xE9; \
	*(DWORD*)((src) + 1) = MAKE_RELATIVE_OFFSET(src, dst); \
} while(0)

#define MAKE_CALL(src, dst) \
do { \
	scoped_unprotect unprotect(size_t(src), 5); \
	*(BYTE*)(src) = 0xE8; \
	*(DWORD*)((src) + 1) = MAKE_RELATIVE_OFFSET(src, dst); \
} while(0)

#define MAKE_NOP(src, size) \
do { \
	scoped_unprotect unprotect(size_t(src), size); \
	memset((void*)src, 0x90, size); \
} while(0)

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
		XMMREG& xmm(int i _In_range_(0, 15)) { return *(XMMREG*)(FPUandSSE + 0xA0 + i * 16); }
		FPUREG& st(int i _In_range_(0, 7)) { return *(FPUREG*)(FPUandSSE + i * 16); }
	} CTX;
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
#endif
	// @brief Can be used in cave or in mid-function hooking.
	class MidAsmHookUnsafe
	{
	private:
		size_t address_of_hook = 0;

		unsigned char* hook_bytes = nullptr;
		size_t cave_address = 0;
#if defined(_M_X64) || defined(__x86_64__)
		unsigned char original_cave_bytes[14] = { 0 }; // we need 14 bytes for an absolute jmp, so we need to store that much for restoration
#else
		unsigned char original_cave_bytes[5] = { 0 };
#endif
	public:
		MidAsmHookUnsafe() = default;

		MidAsmHookUnsafe(size_t address_of_cave, void(*hook_func)(CTX&))
		{
			address_of_hook = (size_t)hook_func;
			cave_address = address_of_cave;
#if defined(_M_X64) || defined(__x86_64__)
			hook_bytes = (unsigned char*)g_pageController.allocate(sizeof(asm_data) + 14, 0x100); // 14 bytes for the absolute indirect jmp
			if (!hook_bytes)
				throw "Failed to allocate memory for hook bytes!";

			memcpy(hook_bytes, (void*)asm_data, sizeof(asm_data));
			{
				unsigned char* ptr = hook_bytes + sizeof(asm_data); // the trampoline will be right after the original function, so we can just place it at the end of the hook bytes

				*(ptr++) = 0xFF;
				*(ptr++) = 0x2C;
				*(ptr++) = 0x25;
				*(DWORD*)ptr = (DWORD)(address_of_hook);
			}
			{
				scoped_unprotect unprotect(cave_address, sizeof(original_cave_bytes)); // just so we could read it

				memcpy(original_cave_bytes, (void*)cave_address, sizeof(original_cave_bytes)); // address_of_cave may act as a ptr to in a function
			}
			if ((size_t)hook_bytes - cave_address >= 0x7FFFFFFF) // >= 2GB distance
			{
				scoped_unprotect unprotect(cave_address, 14); // we need 14 bytes for an absolute indirect call, so we need to unprotect that much
				unsigned char* ptr = (unsigned char*)cave_address; // the trampoline will be right after the original function, so we can just place it at the end of the hook bytes

				*(ptr++) = 0xFF;
				*(ptr++) = 0x1C;
				*(ptr++) = 0x25; // make a call
				*(DWORD*)ptr = (DWORD)(address_of_hook);
			}
			else
			{
				MAKE_CALL(cave_address, (size_t)hook_bytes);
			}
#else
			size_t fncsize = sizeof(asm_data) + 8;
			hook_bytes = (unsigned char*)g_pageController.allocate(fncsize, 0x100);
			if (!hook_bytes)
				throw "Failed to allocate memory for hook bytes!";

			memcpy(hook_bytes, (void*)asm_data, fncsize);
			MAKE_JMP((size_t)hook_bytes + sizeof(asm_data), address_of_hook);

			{
				scoped_unprotect unprotect(cave_address, sizeof(original_cave_bytes)); // just so we could read it

				memcpy(original_cave_bytes, (void*)cave_address, sizeof(original_cave_bytes)); // address_of_cave may act as a ptr to in a function
			}
			MAKE_CALL(cave_address, (size_t)hook_bytes);
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

#define CHECK_ERROR(disasm) if (disasm.flags & F_ERROR) { if (disasm.flags & F_ERROR_LENGTH) throw "Length error occurred!"; else if (disasm.flags & F_ERROR_OPCODE) throw "Invalid opcode error occurred!"; else if (disasm.flags & F_ERROR_LOCK) throw "Lock error occurred!"; else if (disasm.flags & F_ERROR_OPERAND) throw "Operand error occurred!"; else throw "Unknown disassembly error occurred!"; }

		size_t getBranchDestinationForJmp(size_t address) // all types of jmps
		{
			unsigned char* opcode = (unsigned char*)address;
			bool isJmpIndeed = false;
			switch (*opcode)
			{
#if defined(_M_X64) || defined(__x86_64__)
			case 0xFF:
			{
				switch (opcode[1])
				{
				case 0x15:  // call dword ptr [addr]
				case 0x25: // jmp dword ptr [addr]
					isJmpIndeed = true;
					break;
				default:
					break;
				}
			}
			case 0xE9: // jmp
			case 0xE8: // call
				isJmpIndeed = true;
				break;
			case 0x0F:
				if (opcode[1] >= 0x80 && opcode[1] <= 0x8F) // jcc near
					isJmpIndeed = true;
				break;
			case 0xEB: // short jmp
			case 0x74: // jz
			case 0x75: // jnz
			case 0x76: // jbe
			case 0x77: // ja
			case 0x78: // js
			case 0x79: // jns
			case 0x7A: // jp
			case 0x7B: // jnp
			case 0x7C: // jl
			case 0x7D: // jge
			case 0x7E: // jle
			case 0x7F: // jg
				isJmpIndeed = true;
				break;
			default:
				break;
#else
			case 0xE8: // jmp
			case 0xE9: // call
				isJmpIndeed = true;
				break;
			case 0xFF:
				if (opcode[1] == 0x25 || opcode[1] == 0x15)
					isJmpIndeed = true;
				break;
			case 0xEB: // short jmp
			case 0x74: // jz
			case 0x75: // jnz
			case 0x76: // jbe
			case 0x77: // ja
			case 0x78: // js
			case 0x79: // jns
			case 0x7A: // jp
			case 0x7B: // jnp
			case 0x7C: // jl
			case 0x7D: // jge
			case 0x7E: // jle
			case 0x7F: // jg
				isJmpIndeed = true;
				break;
			case 0x0F:
				if (opcode[1] >= 0x80 && opcode[1] <= 0x8F) // jcc near
					isJmpIndeed = true;
				break;
			default:
				break;
#endif
			}
			if (!isJmpIndeed)
				throw "Not a jmp instruction!";

			hde_s disasm = { 0 };
			HDE_DISASM((void*)address, &disasm);
			CHECK_ERROR(disasm);
#if defined(_M_X64) || defined(__x86_64__)
			if (disasm.flags & F_RELATIVE)
			{
				if (disasm.flags & F_IMM8)
					return address + disasm.len + (char)disasm.imm.imm8;
				else if (disasm.flags & F_IMM16)
					return address + disasm.len + (short)disasm.imm.imm16;
				else if (disasm.flags & F_IMM32)
					return address + disasm.len + disasm.imm.imm32;
				else if (disasm.flags & F_IMM64)
					return address + disasm.len + disasm.imm.imm64;
				else
					throw "Relative instruction without immediate value!";
			}
			else
			{
				if (disasm.flags & F_IMM8)
					return disasm.imm.imm8;
				else if (disasm.flags & F_IMM16)
					return disasm.imm.imm16;
				else if (disasm.flags & F_IMM32)
					return disasm.imm.imm32;
				else if (disasm.flags & F_IMM64)
					return disasm.imm.imm64;
				else
					throw "Non-relative instruction without immediate value!";
			}
#else
			if (disasm.flags & F_RELATIVE)
			{
				if (disasm.flags & F_IMM8)
					return address + disasm.len + (char)disasm.imm.imm8;
				else if (disasm.flags & F_IMM16)
					return address + disasm.len + (short)disasm.imm.imm16;
				else if (disasm.flags & F_IMM32)
					return address + disasm.len + disasm.imm.imm32;
				else
					throw "Relative instruction without immediate value!";
			}
			else
			{
				if (disasm.flags & F_IMM8)
					return disasm.imm.imm8;
				else if (disasm.flags & F_IMM16)
					return disasm.imm.imm16;
				else if (disasm.flags & F_IMM32)
					return disasm.imm.imm32;
				else
					throw "Non-relative instruction without immediate value!";
			}
#endif

			return 0;
		}

		// Try to find a place to inject the trampoline
		// You cannot just put a trampoline in the middle of instruction and expect it to work
		void handleTrampoline(size_t _address, size_t& orig_size)
		{
			size_t orignal_size = 0;
#if defined(_M_X64) || defined(__x86_64__)
			size_t needed_size = 14; // for an absolute jmp

			hde_s disasm = { 0 };
			while (orignal_size < needed_size)
			{
				size_t instr_size = HDE_DISASM((void*)(_address + orignal_size), &disasm);
				CHECK_ERROR(disasm);
				orignal_size += instr_size;
			}

			unsigned char* trampoline = (unsigned char*)g_pageController.allocate(orignal_size + 28, 0x100); // call + jmp
			unsigned char* trampCopy = trampoline;
			if (trampoline)
			{
				scoped_unprotect unprotect(_address, orignal_size);
				for (int i = 0; i < orignal_size; i++)
				{
					unsigned char* opcode = (unsigned char*)(_address + i);
					unsigned char* pTrampBuffer = trampoline + i + 14; // +14 just to give space for the call
					if (*opcode == 0xE8 || *opcode == 0xE9) // if it's a relative jmp or call, we need to fix the offset in the trampoline
					{
						size_t dest = 0;
						dest = getBranchDestinationForJmp((size_t)opcode);
						if (dest != 0)
						{
							size_t offset_in_original = opcode - (unsigned char*)_address;
							size_t offset_in_trampoline = pTrampBuffer - (unsigned char*)_address + offset_in_original;
							if (dest >= _address && dest < _address + orignal_size) // if the destination is inside the original instructions, we need to fix it to point to the trampoline
								dest = (size_t)pTrampBuffer + (dest - _address);
							else
								dest = dest;
							if (*opcode == 0xE8) // call
							{
								MAKE_CALL(pTrampBuffer, dest);
							}
							else // jmp
							{
								MAKE_JMP(pTrampBuffer, dest);
							}
							i += 4; // skip the rest of the instruction since we already wrote it in the trampoline
						}
					}
				}
				MAKE_JMP(trampoline, _address + orignal_size); // jump back to the original function after the overwritten bytes
			}
#else
			size_t needed_size = 5; // for a relative jmp

			hde_s disasm = { 0 };
			while (orignal_size < needed_size)
			{
				size_t instr_size = HDE_DISASM((void*)(_address + orignal_size), &disasm);
				CHECK_ERROR(disasm);
				orignal_size += instr_size;
			}

			unsigned char* trampoline = (unsigned char*)g_pageController.allocate(orignal_size + 10, 0x100); // we need some space for the original instructions and a jmp back to the original function, so we allocate a bit more than the original instructions size
			this->trampoline = trampoline;
			if (trampoline)
			{
				trampoline += 5;
				scoped_unprotect unprotect(_address, orignal_size);

				disasm = { 0 };
				size_t offset = 0;
				while (offset < orignal_size)
				{
					size_t instr_size = HDE_DISASM((void*)(_address + offset), &disasm);
					CHECK_ERROR(disasm);
					memcpy(trampoline + offset, (void*)(_address + offset), instr_size);
					if (disasm.flags & F_RELATIVE) // if the instruction has a relative offset, we need to fix it in the trampoline
					{
						size_t dest = 0;
						if (disasm.flags & F_IMM8)
							dest = _address + offset + instr_size + (char)disasm.imm.imm8;
						else if (disasm.flags & F_IMM16)
							dest = _address + offset + instr_size + (short)disasm.imm.imm16;
						else if (disasm.flags & F_IMM32)
							dest = _address + offset + instr_size + disasm.imm.imm32;
						else
							throw "Relative instruction without immediate value!";

						size_t offset_in_trampoline = ((size_t)trampoline - _address) + offset;
						size_t new_offset = dest - (size_t)(trampoline + offset);
						
						*(DWORD*)(trampoline + offset + 1) = (DWORD)new_offset;
					}
					offset += instr_size;
				}
			}
			orig_size = orignal_size;
#endif
		}
	public:
		MidAsmHook(size_t _address, void(__cdecl* hook_func)(CTX&))
		{
			size_t orig_size = 0;
			try
			{
				handleTrampoline(_address, orig_size);
			}
			catch (const char* err)
			{
				MessageBoxA(nullptr, err, "SafeHook Error", MB_ICONERROR | MB_OK);
			}
			if (!trampoline)
				return;

			scoped_unprotect unprotect(_address, orig_size);
			{
				unsigned char* ptr = (unsigned char*)_address;
				*ptr = 0xE9; // jmp
				*(DWORD*)(ptr + 1) = MAKE_RELATIVE_OFFSET(ptr, trampoline); // relative offset to the trampoline
			}

			new (&unsafe_hook) MidAsmHookUnsafe((size_t)trampoline, hook_func);

			{
				unsigned char* ptr = (unsigned char*)trampoline + orig_size + 5;

				*ptr = 0xE9;
				*(DWORD*)(ptr + 1) = MAKE_RELATIVE_OFFSET((size_t)ptr, _address + orig_size);
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