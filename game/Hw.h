#pragma once
#define DIRECTINPUT_VERSION 0x800u
#include <Windows.h>
#include <d3dx9.h>
#include <dinput.h>
#include <shared.h>
#include <Xinput.h>
#include <DirectXMath.h>

namespace Hw
{
	// Input

	class KeyboardManagerBase;
	class KeyboardManager;
	class cKeyboardState;

	class MouseManagerBase;
	class MouseManager;
	class cMouseState;

	class PadManager;
	class cPadState;

	enum KEYBOARD_MAP;
	enum MAUSE_MAP { MOUSE_BTN_L = 1, MOUSE_BTN_R = 2, MOUSE_BTN_M = 4 }; // don't ask about it's name, it's like that in the original code
	enum INPUT_PAD_ANALOG { INPUT_PAD_ANALOG_STICK_LEFT = 0, INPUT_PAD_ANALOG_STICK_RIGHT, INPUT_PAD_ANALOG_TRIGGER_LEFT, INPUT_PAD_ANALOG_TRIGGER_RIGHT, INPUT_PAD_ANALOG_NUM, INPUT_PAD_ANALOG_ALL };
	enum PAD_MAP
	{
		PAD_BTN_L = 0x1, // Left DPad
		PAD_BTN_R = 0x2, // Right DPad
		PAD_BTN_D = 0x4, // Down DPad
		PAD_BTN_U = 0x8, // Up DPad
		PAD_BTN_A = 0x10, // A/Cross
		PAD_BTN_B = 0x20, // B/Circle
		PAD_BTN_X = 0x40, // X/Square
		PAD_BTN_Y = 0x80, // Y/Triangle
		PAD_BTN_ST = 0x100, // Start
		PAD_BTN_SL = 0x200, // Select
		PAD_BTN_L1 = 0x400, // L1/LB/Left Shoulder
		PAD_BTN_L2 = 0x800, // L2/LT/Left Trigger
		PAD_BTN_L3 = 0x1000, // L3/Left Stick Button
		PAD_BTN_R1 = 0x2000, // R1/RB/Right Shoulder
		PAD_BTN_R2 = 0x4000, // R2/RT/Right Trigger
		PAD_BTN_R3 = 0x8000, // R3/Right Stick Button
		PAD_BTN_LAL = 0x10000, // LAnalogLeft
		PAD_BTN_LAR = 0x20000, // LAnalogRight
		PAD_BTN_LAU = 0x40000, // LAnalogUp
		PAD_BTN_LAD = 0x80000, // LAnalogDown
		PAD_BTN_RAL = 0x100000, // RAnalogLeft
		PAD_BTN_RAR = 0x200000, // RAnalogRight
		PAD_BTN_RAU = 0x400000, // RAnalogUp
		PAD_BTN_RAD = 0x800000, // RAnalogDown
		PAD_BTN_PVL = 0x1000000,
		PAD_BTN_PVR = 0x2000000,
		PAD_BTN_PVD = 0x4000000,
		PAD_BTN_PVU = 0x8000000,
		PAD_BTN_1 = 0x40,
		PAD_BTN_2 = 0x80,
		PAD_BTN_C = 0x400,
		PAD_BTN_Z = 0x800,
		PAD_BTN_PLUS = 0x100,
		PAD_BTN_MINUS = 0x200,
		PAD_BTN_HOME = 0x80000000,
		PAD_BTN_BL = 0x40,
		PAD_BTN_BR = 0x20,
		PAD_BTN_BU = 0x80,
		PAD_BTN_BD = 0x10,
	};

	/*
	enum eSaveKeybind <- probably needs to be in pl0000 class
	{
		KEYBIND_FORWARD,
		KEYBIND_BACK,
		KEYBIND_LEFT,
		KEYBIND_RIGHT,
		KEYBIND_WALK,
		KEYBIND_JUMP,
		KEYBIND_LIGHT_ATTACK,
		KEYBIND_HEAVY_ATTACK,
		KEYBIND_BLADEMODE,
		KEYBIND_NINJARUN,
		KEYBIND_ACTION,
		KEYBIND_RIPPERMODE,
		KEYBIND_SWITCH_LOCK_ON,
		KEYBIND_USE_SUBWEAPON,
		KEYBIND_USE_ITEM,
		KEYBIND_AR_MODE,
		KEYBIND_WEAPON_SELECT_SCREEN,
		KEYBIND_CODEC_SCREEN,
		KEYBIND_PAUSE,
		KEYBIND_CAMERA_RESET,
		KEYBIND_EXECUTION,
		KEYBIND_DEFFENSIVE_OFFENSIVE,
		KEYBIND_FIRE_SUBWEAPON,

		KEYBIND_TOTAL
	};
	*/

	class InputSystem;
	// user

	class UserReplace;
	enum REAL_USER_NO { REAL_USER_NO_INVALID = -1, REAL_USER_NO_0 = 0, REAL_USER_NO_1 = 1, REAL_USER_NO_2 = 2, REAL_USER_NO_3 = 3 };

	class cFmerge;
	struct FmergeHeader;

	class cMtx;

	class cUcol;
	class cFcol;

	class cCriticalSection;
	class cSemaphore;
	class cRand;

	template <typename tC>
	class cSingleton;

	enum ANISOTROPY_LEVEL
	{
		ANISOTROPY_LEVEL1 = 1,
		ANISOTROPY_LEVEL2 = 2,
		ANISOTROPY_LEVEL4 = 4,
		ANISOTROPY_LEVEL8 = 8,
		ANISOTROPY_LEVEL16 = 16
	};

	enum BLENDOP_MODE
	{
		BLENDOP_ADD = 0,
		BLENDOP_SUB = 1,
		BLENDOP_REVSUB = 4,
		BLENDOP_MIN = 2,
		BLENDOP_MAX = 3,
		BLENDOP_DEFAULT = 0,
		BLENDALPHAOP_DEFAULT = 0
	};

	enum BLEND_ELEM
	{
		BLEND_ZERO = 0,
		BLEND_ONE = 1,
		BLEND_SRCCOLOR = 4,
		BLEND_INVSRCCOLOR = 5,
		BLEND_SRCALPHA = 6,
		BLEND_INVSRCALPHA = 7,
		BLEND_DESTALPHA = 10,
		BLEND_INVDESTALPHA = 11,
		BLEND_DESTCOLOR = 8,
		BLEND_INVDESTCOLOR = 9,
		BLEND_SRCALPHASAT = 16,
		BLEND_BOTHINVSRCALPHA = 0,
		BLEND_BLENDFACTOR = 12,
		BLEND_INVBLENDFACTOR = 13,
		BLEND_SRC_DEFAULT = 1,
		BLEND_DST_DEFAULT = 0,
		BLEND_ALPHASRC_DEFAULT = 1,
		BLEND_ALPHADST_DEFAULT = 0
	};

	enum COMP_MODE
	{
		COMP_NEVER = 0,
		COMP_LESS = 1,
		COMP_EQUAL = 2,
		COMP_LESSEQUAL = 3,
		COMP_GREATER = 4,
		COMP_NOTEQUAL = 5,
		COMP_GREATEREQUAL = 6,
		COMP_ALWAYS = 7,
		COMP_Z_DEFAULT = 3,
		COMP_ALPHATEST_DEFAULT = 7
	};

	enum HW_ALLOC_MODE : int
	{
		HW_ALLOC_VIRTUAL = 0x0,
		HW_ALLOC_PHYSICAL = 0x1,
		HW_ALLOC_PHYSICAL_BACK = 0x2,
		HW_ALLOC_COMBINE = 0x3
	};

	enum eTaskId : int
	{
		TASK_ID_INVALID = 0
	};

	enum CULL_MODE : int
	{
		CULL_NONE = 0x0,
		CULL_CW = 0x2,
		CULL_CCW = 0x6,
		CULL_DEFAULT = 0x6,
		CULL_DEFAULT_REV = 0x2
	};

	enum eThreadId
	{
		THREAD_ID_INVALID = 0
	};

	enum ROT_ORDER
	{
		ROT_XYZ = 0,
		ROT_XZY,
		ROT_YXZ,
		ROT_YZX,
		ROT_ZXY,
		ROT_ZYX,
		ROT_DEFAULT = ROT_ZYX
	};

	class cHeap;
	class cHeapVariableBase;
	class cHeapVariable;
	class cHeapPhysical;
	class cHeapHook;
	class cHeapFixed;
	class cHeapOneTime;
	class cHeapPhysicalBase;
	class cHeapGlobal;
	class cShareHeapPhysical;

	template <typename tC, unsigned const align, typename tHeapBinder>
	class cFactory;

	template <typename tC, unsigned const align>
	class cFactoryVariable;

	template <typename tC, unsigned const align>
	class cFactoryFixed;

	// Graphics
	class cViewPort;

	class CameraProj;
	class cCameraBase;

	class cIndexBufferHeap;
	class cRenderTargetInfo;

	class cTexture;
	class cTextureInstance;
	class cLockableTexture;
	class cTargetTexture;
	class cShareTargetTexture;
	class cZTexture;

	class cOtWork;
	class cShader;
	class cPixelShader;
	class cVertexShader;
	struct cVertexInfo;
	struct cPixelInfo;
	class cDepthSurface;

	class cOtManagerBase;

	class cPrimHeap;
	class cPrimF;
	class cPrimFT;
	class cPrimFTyuv;
	class cPrimFV;
	class cPrimG;
	class cPrimIF;
	class cPrimIFT;

	class cRenderPredicate;

	class cShaderPreset;
	class cShaderCharacter;
	class cShaderPF;
	class cShaderPFT;
	class cShaderPFTyuv;
	class cShaderPFTyuva;
	class cShaderPFV;
	class cShaderPG;
	class cVertexFormat;
	class cVertexFormatP;
	class cVertexFormatPG;
	class cVertexFormatPT;
	class cVertexFormatPV;

	class cUv;

	// etc.

	class cTimeUnit;

	class cTaskManager;
	class cJobManager;

	struct RenderBufferHeapManager;

	template <typename T>
	class cFixedVector;

	template <typename T>
	class cFixedList;

	template <typename tC, typename tHeapBinder>
	class cExpandableVector;

	template <typename tC>
	class cHwLFFreeListTemp;

	class cVec2;
	class cVec3;
	class cVec4;
	class cQuat;

	inline BOOL createSubWindow(const char* classname, const char* windowname, unsigned int x, unsigned int y) { return MAKE_CALL(shared::base + 0xB98770, BOOL(__cdecl*)(const char*, const char*, unsigned int, unsigned int), classname, windowname, x, y); }

	class TextureManager
	{
	public:
		struct Texture
		{
			LPDIRECT3DTEXTURE9 m_pTexture;
			LPDIRECT3DTEXTURE9* m_ppTexture;
			int field_8;
			int m_nWidth;
			int m_nHeight;
			int field_14;
			D3DFORMAT m_Format;
			D3DPOOL m_Pool;
			int field_20;
			int field_24;
		};

		inline void removeTexture(Texture& texture) { MAKE_CALL(shared::base + 0xBA16D0, void(__cdecl*)(Texture&), texture); }

		static inline cFixedList<Texture>& m_Textures = *(cFixedList<Texture>*)(shared::base + 0x1B20720);
		static inline cCriticalSection& m_TextureCriticalSection = *(cCriticalSection*)(shared::base + 0x1B20740);
	};

	class ResourceManager;

	class Wwise
	{
	public:
		class Command
		{
			class Work
			{
			public:

				virtual ~Work() {};
			};

			class ListenerPositionWork : public Work {};

			class ListenerSpatializationWork : public Work {};

			class ObjectEnvironmentDryLevelWork : public Work {};

			class ObjectEnvironmentValuesWork : public Work {};

			class ObjectListenerMaskWork : public Work {};

			class ObjectOutputMaskWork : public Work {};

			class ObjectPositionWork : public Work {};

			class ObjectRTPCValueWork : public Work {};

			class ObjectRegisterWork : public Work {};

			class ObjectReleaseWork : public Work {};

			class ObjectSwitchWork : public Work {};

			class PostEventWork : public Work {};

			class ReleaseEventWork : public Work {};

			class ScalingFactorWork : public Work {};

			class StateWork : public Work {};

			class StopEventWork : public Work {};
		};
	};

	class ThreadSystem
	{
	public:
		class cWork
		{
		public:
			eThreadId m_ThreadId;
			int field_4;
			int m_nThreadIndex;
			void(__cdecl* m_pfnThreadFunction)(void*);
			void* m_pThreadParameter;
		};

		static inline BOOL startupThread(cWork* pThread, unsigned int stackSize, int a3, const char* threadName, int priority) { return MAKE_CALL(shared::base + 0x9D7DB0, BOOL(__cdecl*)(cWork*, unsigned int, int, const char*, int), pThread, stackSize, a3, threadName, priority); }
		static inline BOOL createThread(void(__cdecl* pfnThreadFunction)(void*), void* pParameter, unsigned int stackSize, int a4, const char* threadName, int priority) { return MAKE_CALL(shared::base + 0x9D82C0, BOOL(__cdecl*)(void(__cdecl*)(void*), void*, unsigned int, int, const char*, int), pfnThreadFunction, pParameter, stackSize, a4, threadName, priority); }
		// Should be always called at the end of the thread function
		static inline void Exit() { MAKE_CALL(shared::base + 0x9D7C70, void(__cdecl *)(), ); }
	};

	class GraphicDevice
	{
	public:

		static inline D3DPRESENT_PARAMETERS*& m_pD3DParams = *(D3DPRESENT_PARAMETERS**)(shared::base + 0x1B205E4);
		static inline D3DPRESENT_PARAMETERS& m_D3DFullscreenParams = *(D3DPRESENT_PARAMETERS*)(shared::base + 0x1B205E8);
		static inline D3DPRESENT_PARAMETERS& m_D3DWindowParams = *(D3DPRESENT_PARAMETERS*)(shared::base + 0x1B20620);
		static inline LPDIRECT3D9& m_pD3D = *(LPDIRECT3D9*)(shared::base + 0x1B206D8);
		static inline LPDIRECT3DDEVICE9& m_pDevice = *(LPDIRECT3DDEVICE9*)(shared::base + 0x1B206D4);
	};

	class OsWindow
	{
	public:

		static inline HWND& m_MainWindow = *(HWND*)(shared::base + 0x19D504C);
		static inline HWND& m_SecondWindow = *(HWND*)(shared::base + 0x1B205E0);
	};

	class OsTime
	{
	public:
		static inline int Startup() { return MAKE_CALL(shared::base + 0x9F8110, int(__cdecl *)(), ); }
		static inline float GetHiSystemTime() { return MAKE_CALL(shared::base + 0x9F81D0, float(__cdecl *)(), ); }
		static inline LONGLONG GetHiSystemTickCount() { return MAKE_CALL(shared::base + 0x9F8230, LONGLONG(__cdecl *)(), ); }
		static inline float GetSystemSecPerTick() { return MAKE_CALL(shared::base + 0x9F8260, float(__cdecl *)(), ); }
		static inline int GetSystemTime() { return MAKE_CALL(shared::base + 0xB98000, int(__cdecl *)(), ); }

		static inline float& m_SecondsPerTick = *(float*)(shared::base + 0x19D4F14);
		static inline LARGE_INTEGER& m_SystemHiTime = *(LARGE_INTEGER*)(shared::base + 0x19D4F18);
		static inline LARGE_INTEGER& m_SystemFreq = *(LARGE_INTEGER*)(shared::base + 0x19D4F20);
		static inline int& m_bSystemTimeInit = *(int*)(shared::base + 0x19D4F40);
	};

	class OsSystem
	{
	public:
		static inline float GetHiSystemTime() { return MAKE_CALL(shared::base + 0x9F8C10, float(__cdecl*)()); }
	};

	inline RenderBufferHeapManager& g_RenderBufferManager = *(RenderBufferHeapManager*)(shared::base + 0x1ADD490);

	inline cRand& g_Rand = *(cRand*)(shared::base + 0x19D0814);
};

class Hw::cSemaphore
{
private:
	void* m_hSemaphore;
public:
	cSemaphore() { MAKE_CALL(shared::base + 0x9D7360, void(__thiscall*)(cSemaphore*), this); }

	int startup(unsigned int init_count, unsigned int max_count) { return MAKE_CALL(shared::base + 0x9D7370, int(__thiscall*)(cSemaphore*, unsigned int, unsigned int), this, init_count, max_count); }
	void cleanup() { MAKE_CALL(shared::base + 0x9D73B0, void(__thiscall*)(cSemaphore*), this); }
	void hold() { MAKE_CALL(shared::base + 0x9D73D0, void(__thiscall*)(cSemaphore*), this); }
	void release() { MAKE_CALL(shared::base + 0x9D73E0, void(__thiscall*)(cSemaphore*), this); }
};

class Hw::cCriticalSection
{
private:
	CRITICAL_SECTION m_CriticalSection;
	BOOL m_IsStartuped;
	// private: int pad1C; public: // +4 for alignment
public:

	cCriticalSection() { m_IsStartuped = FALSE; }
	BOOL startup() { return MAKE_CALL(shared::base + 0x9D7240, BOOL(__thiscall*)(cCriticalSection*), this); }
	void cleanup() { MAKE_CALL(shared::base + 0x9D7270, void(__thiscall*)(cCriticalSection*), this); }
	void enter() { MAKE_CALL(shared::base + 0xA6C0, void(__thiscall*)(cCriticalSection*), this); }
	void leave() { MAKE_CALL(shared::base + 0xA6D0, void(__thiscall*)(cCriticalSection*), this); }
	int isValid() const { return m_IsStartuped; }
};

class Hw::cHeap
{
public:
	int field_4;
	Hw::cCriticalSection m_CriticalSection;
	int field_24;
	Hw::cHeap* m_pSubHeap;
	Hw::cHeap* m_pParentHeap;
	Hw::cHeap* m_pNext;
	Hw::cHeap* m_pPrev;
	const char* m_pHeapName;
	unsigned int m_OutOfMemoryFlag;

	cHeap() { MAKE_CALL(shared::base + 0x9D3650, void(__thiscall*)(cHeap*), this); }
	virtual ~cHeap() {};

	void cleanup() { MAKE_VCALL(1, void(__thiscall*)(cHeap *), this); }
	void destroy() { MAKE_VCALL(2, void(__thiscall*)(cHeap *), this); }
	BOOL isValid() const { return MAKE_VCALL(3, BOOL(__thiscall*)(const cHeap *), this); }
	size_t getSize() const { return MAKE_VCALL(4, size_t(__thiscall*)(const cHeap *), this); }
	size_t getUsedSize() const { return MAKE_VCALL(5, size_t(__thiscall*)(const cHeap *), this); }
	size_t getAllocatableSize() const { return MAKE_VCALL(6, size_t(__thiscall*)(const cHeap *), this); }
	// Pass nullptr to get the first allocation
	void* getNextAlloc(void* block) const { return MAKE_VCALL(7, void*(__thiscall*)(const cHeap *, void*), this, block); }
	size_t getAllocSize(void* block) const { return MAKE_VCALL(8, size_t(__thiscall*)(const cHeap *, void*), this, block); }
	// returns critical size at which it cannot allocate more memory
	size_t getRestSizeLimit() const { return MAKE_VCALL(9, size_t(__thiscall*)(const cHeap *), this); }
	size_t getChildHeapSize() const { return MAKE_VCALL(10, size_t(__thiscall*)(const cHeap *), this); }
	void setDefragmentableFlag(void* a1) { MAKE_VCALL(11, void(__thiscall*)(cHeap *, void*), this, a1); }
	void* createChildHeap(HANDLE* pHandle, size_t Size) { return MAKE_VCALL(12, void*(__thiscall*)(cHeap *, HANDLE*, size_t), this, pHandle, Size); }
	void destroyChildHeap(HANDLE* pHandle, size_t Size) { MAKE_VCALL(13, void(__thiscall*)(cHeap *, HANDLE*, size_t), this, pHandle, Size); }
	void* allocImpl(size_t size, size_t align, HW_ALLOC_MODE allocMode, int a4) { return MAKE_VCALL(14, void*(__thiscall*)(cHeap *, size_t, size_t, HW_ALLOC_MODE, int), this, size, align, allocMode, a4); }
	void dealloc(void* block, size_t size) { MAKE_VCALL(15, void(__thiscall*)(cHeap *, void*, size_t), this, block, size); }
	void* alloc(unsigned int size, int align = 32, HW_ALLOC_MODE allocMode = HW_ALLOC_MODE::HW_ALLOC_VIRTUAL, int a3 = 0) { return MAKE_CALL(shared::base + 0x9D29B0, void*(__thiscall*)(cHeap *, unsigned int, int, HW_ALLOC_MODE, int), this, size, align, allocMode, a3); }
	void setSubHeap(Hw::cHeap& rHeap) { MAKE_CALL(shared::base + 0x9D2930, void(__thiscall*)(cHeap *, Hw::cHeap&), this, rHeap); }
	void unsetSubHeap() { MAKE_CALL(shared::base + 0x9D2940, void(__thiscall*)(cHeap *), this); }

	static inline void free(void* block) { MAKE_CALL(shared::base + 0x9D4920, void(__cdecl*)(void*), block); }
};

inline void* __cdecl operator new(size_t s, Hw::cHeap* rHeap) { return MAKE_CALL(shared::base + 0x9D3500, void*(__cdecl*)(size_t, Hw::cHeap*), s, rHeap); }
inline void __cdecl operator delete(void* block, Hw::cHeap* rHeap) { MAKE_CALL(shared::base + 0x9D48D0, void(__cdecl*)(void*, Hw::cHeap*), block, rHeap); } // Separated to avoid ambiguity
inline void* __cdecl operator new[](size_t s, Hw::cHeap* rHeap) { return MAKE_CALL(shared::base + 0x9D3580, void*(__cdecl*)(size_t, Hw::cHeap*), s, rHeap); }
inline void __cdecl operator delete[](void* block, Hw::cHeap* rHeap) { MAKE_CALL(shared::base + 0x9D4940, void(__cdecl*)(void*, Hw::cHeap*), block, rHeap); } // Separated to avoid ambiguity
// Usage after heap startup
inline void* __cdecl memAlloc(size_t s) { return MAKE_CALL(shared::base + 0x61E180, void*(__cdecl*)(size_t), s); }
// Usage after heap startup
inline void __cdecl memDealloc(void* block) { MAKE_CALL(shared::base + 0x61D3D0, void(__cdecl*)(void*), block); }

class Hw::cHeapVariableBase : public Hw::cHeap
{
public:
	class cList
	{
	public:
		cList* m_pPrev, * m_pNext;
		void* m_pMemoryBlock;
		size_t m_MemorySize;
		cHeapVariableBase* m_pAllocator;
	};

	HANDLE m_hHeap;
	Hw::cHeapVariableBase::cList* m_pFirstList, * m_pLastList;
	size_t m_HeapSize;
	size_t m_RestSize;
	size_t m_ChildHeapSize;

	cHeapVariableBase() { MAKE_CALL(shared::base + 0x9D3AF0, void(__thiscall*)(cHeapVariableBase *), this); }
};

class Hw::cHeapVariable : public Hw::cHeapVariableBase
{
public:

	cHeapVariable() { MAKE_CALL(shared::base + 0x9D44F0, void(__thiscall*)(cHeapVariable *), this); }

	int create(size_t size, Hw::cHeap& rHeap, const char* pName) { return MAKE_VCALL(16, int(__thiscall*)(cHeapVariable *, size_t, Hw::cHeap&, const char*), this, size, rHeap, pName); }
	int create(size_t size, size_t align, Hw::cHeap& rHeap, const char* pName) { return MAKE_VCALL(17, int(__thiscall*)(cHeapVariable *, size_t, size_t, Hw::cHeap&, const char*), this, size, align, rHeap, pName); }
};

class Hw::cHeapPhysicalBase : public Hw::cHeap
{
public:
	class cList
	{
	public:
		cList* m_pPrevious, * m_pNext;
		size_t m_TotalSize;
		size_t m_Size;
		int field_10;
		int field_14;
		cHeapPhysicalBase* m_pAllocator;
	};
public:
	cList* m_pMainBlock, * m_pFirstBlock, * m_pLastBlock;
	size_t m_MemoryLimit;
	size_t m_FreeMemory;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	cList* m_pBlocks[256];

	cHeapPhysicalBase() { MAKE_CALL(shared::base + 0x9D3860, void(__thiscall*)(cHeapPhysicalBase *), this); }
};

class Hw::cHeapPhysical : public Hw::cHeapPhysicalBase
{
public:

	cHeapPhysical() { MAKE_CALL(shared::base + 0x9D48F0, void(__thiscall*)(cHeapPhysical *), this); }

	int create(size_t size, Hw::cHeap& rHeap, const char* name) { return MAKE_VCALL(17, int(__thiscall*)(cHeapPhysical *, size_t, Hw::cHeap&, const char*), this, size, rHeap, name); }
};

class Hw::cHeapHook
{
public:

	cHeapHook() { MAKE_CALL(shared::base + 0x9D32E0, void(__thiscall*)(cHeapHook *), this); }
	virtual ~cHeapHook() {};
};

class Hw::cHeapFixed : public Hw::cHeap
{
public:
	struct cList
	{
		cList* m_pPrevious, * m_pNext;
		cHeapFixed* m_pHeap;
	};
public:
	void* m_pAlloc;
	size_t m_HeapSize;
	size_t m_BlockSize;
	size_t m_BlockNum;
	size_t m_BlockAlign;
	size_t m_RestNum;
	Hw::cHeapFixed::cList* m_pFreeList, * m_pFirstList;

	cHeapFixed() { MAKE_CALL(shared::base + 0x9D36F0, void(__thiscall*)(cHeapFixed *), this); }

	BOOL create(size_t fixedSize, size_t allocAmount, size_t reservedSize, Hw::cHeap& creator, const char* name) { return MAKE_VCALL(16, BOOL(__thiscall*)(cHeapFixed *, size_t, size_t, size_t, Hw::cHeap&, const char*), this, fixedSize, allocAmount, reservedSize, creator, name); }
	void* alloc() { return MAKE_CALL(shared::base + 0x9D2BC0, void*(__thiscall*)(cHeapFixed *), this); }
	int canAlloc(size_t size, size_t num) { return MAKE_CALL(shared::base + 0x9D2BA0, int(__thiscall*)(cHeapFixed *, size_t, size_t), this, size, num); }
	unsigned int getBlockMaxNum() { return MAKE_CALL(shared::base + 0x9D2C80, unsigned int(__thiscall*)(cHeapFixed *), this); }
	unsigned int getBlockUsedNum() { return MAKE_CALL(shared::base + 0x9D2C90, unsigned int(__thiscall*)(cHeapFixed *), this); }
};

class Hw::cHeapOneTime : public Hw::cHeap
{
public:
	struct cList
	{
		cList* m_pNext, * m_pPrev;
		void* m_pMemory;
		cHeapOneTime* m_pHeap;
	};

	void* m_pAlloc;
	int m_BlockSize;
	size_t m_HeapSize;
	int m_BlockRest;
	Hw::cHeapOneTime::cList* m_pFirstList, * m_pLastList;
	int m_RestSize;

	cHeapOneTime() { MAKE_CALL(shared::base + 0x9D3800, void(__thiscall*)(cHeapOneTime *), this); }
};

class Hw::cHeapGlobal : public Hw::cHeapVariableBase
{
public:

	cHeapGlobal() { MAKE_CALL(shared::base + 0x9D3F20, void(__thiscall*)(cHeapGlobal *), this); }

	static inline cHeapGlobal* GetInstance() { return MAKE_CALL(shared::base + 0x61D830, cHeapGlobal*(__cdecl*)()); } // -> return Hw::cHeapGlobal::ms_Instance.GetInstance(); 

	BOOL create(size_t size, const char* target) // Got optimised away
	{
		if (isValid()) // already created
			return FALSE;

		if (!this->m_CriticalSection.startup())
			return FALSE;

		this->m_hHeap = HeapCreate(1u, 0u, 0u);

		if (!this->m_hHeap)
			return FALSE;

		this->m_HeapSize = size;
		this->m_RestSize = size;
		this->m_pHeapName = target;
		this->m_pFirstList = nullptr;
		this->m_pLastList = nullptr;
		return TRUE;
	}

	// non virtual ~cHeapGlobal() -> at 0x9D3F60
	static inline cHeapGlobal& m_Instance = *(cHeapGlobal*)(shared::base + 0x1783AF0); // Actually a singleton
};

class Hw::cShareHeapPhysical : public Hw::cHeapPhysical
{
public:
	cHeapPhysical* m_pShareHeap;

	cShareHeapPhysical() { MAKE_CALL(shared::base + 0x9D4BD0, void(__thiscall*)(cShareHeapPhysical *), this); }
	int create(Hw::cHeapPhysical& shareHeap, const char* name) { return MAKE_VCALL(18, int(__thiscall*)(cShareHeapPhysical *, Hw::cHeapPhysical&, const char*), this, shareHeap, name); }
	int startupShareHeap() { return MAKE_VCALL(19, int(__thiscall*)(cShareHeapPhysical *), this); }
};

template <typename tC, unsigned const align, typename tHeapBinder = Hw::cHeap>
class Hw::cFactory
{
public:
	class const_iterator;
	class iterator;

	const iterator npos;
private:
	void* _pad04;
public:
	tHeapBinder m_Heap;
public:
	class const_iterator
	{
	protected:
		tC* m_Ptr;

		cHeap* getHeapPtr()
		{
			return ((cHeap**)m_Ptr)[-1]; // Tricky way to get heap pointer from allocation
		}

		tC* getNextPtr()
		{
			return (tC*)getHeapPtr()->getNextAlloc(m_Ptr);
		}

	public:
		const_iterator(void* pPtr) : m_Ptr((tC*)pPtr) {}
		const_iterator(const const_iterator& other) : m_Ptr(other.m_Ptr) {}
		const_iterator() : m_Ptr(nullptr) {}

		const_iterator& operator++(int)
		{
			const_iterator temp = m_Ptr;

			m_Ptr = getNextPtr();

			return temp;
		}

		const_iterator& operator++()
		{
			m_Ptr = getNextPtr();

			return *this;
		}

		bool operator==(const const_iterator& other) const
		{
			return m_Ptr == other.m_Ptr;
		}

		bool operator!=(const const_iterator& other) const
		{
			return m_Ptr != other.m_Ptr;
		}

		void operator=(const const_iterator& other)
		{
			m_Ptr = other.m_Ptr;
		}

		tC& operator*() const
		{
			return *m_Ptr;
		}

		tC* operator->() const
		{
			return m_Ptr;
		}
	};

	class iterator : public const_iterator
	{
	public:
		iterator(void* pPtr) : const_iterator(pPtr) {}
		iterator(const iterator& other) : const_iterator(other) {}
		iterator() : const_iterator() {}

		void operator=(const iterator& other)
		{
			this->m_Ptr = other.m_Ptr;
		}

		tC& operator*()
		{
			return *(this->m_Ptr);
		}

		tC* operator->()
		{
			return this->m_Ptr;
		}
	};

	cFactory() : npos(nullptr) {}
	~cFactory() { destroy(); }

	iterator begin()
	{
		return iterator(m_Heap.getNextAlloc(nullptr));
	}

	const_iterator begin() const
	{
		return const_iterator(m_Heap.getNextAlloc(nullptr));
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	const_iterator end() const
	{
		return const_iterator(nullptr);
	}
private:
	// optimize makes it confusing to reverse

	void destroyLocal()
	{
		iterator it = begin();
		iterator itEnd = end();

		while (it != itEnd)
		{
			iterator current = it;
			++it;

			operator delete(&(*current), &m_Heap);
		}
	}
public:

	void destroy()
	{
		if (!m_Heap.isValid())
			return;

		destroyLocal();
		m_Heap.destroy();
	}

	iterator erase(iterator& pos)
	{
		iterator next = pos;
		++next;
		operator delete(&(*pos), &m_Heap);
		return next;
	}

	unsigned int getSize() const
	{
		return m_Heap.getSize();
	}

	unsigned int getUsedSize() const
	{
		return m_Heap.getUsedSize();
	}

	unsigned int getAllocatableSize() const
	{
		return m_Heap.getAllocatableSize();
	}

	tHeapBinder& getHeap() const
	{
		return m_Heap;
	}
};

template <typename tC, unsigned const align>
class Hw::cFactoryVariable : public Hw::cFactory<tC, align, Hw::cHeapVariable>
{
public:
	cFactoryVariable() : Hw::cFactory<tC, align, Hw::cHeapVariable>() {}

	int create(size_t heapSize, Hw::cHeap& rHeap, const char* name = "FactoryVariable")
	{
		return this->m_Heap.create(heapSize, align, rHeap, name);
	}
};

template <typename tC, unsigned const align>
class Hw::cFactoryFixed : public Hw::cFactory<tC, align, Hw::cHeapFixed>
{
public:
	cFactoryFixed() : Hw::cFactory<tC, align, Hw::cHeapFixed>() {}

	int create(unsigned int count, Hw::cHeap& rHeap, const char* name = "FactoryFixed")
	{
		return this->m_Heap.create(sizeof(tC), count, align, rHeap, name);
	}

	int canAlloc(int num) const
	{
		return this->m_Heap.canAlloc(sizeof(tC), num);
	}

	tC* newWork()
	{
		void* pAlloc = this->m_Heap.alloc();
		memset(pAlloc, 0, sizeof(tC));

		return new (pAlloc) tC();
	}

	cFactory<tC, align, Hw::cHeapFixed>::iterator newWorkIt()
	{
		return cFactory<tC, align, Hw::cHeapFixed>::iterator(this->m_Heap.alloc());
	}

	unsigned int getUsedNum() const
	{
		return this->m_Heap.getBlockUsedNum();
	}

	unsigned int getMaxNum() const
	{
		return this->m_Heap.getBlockMaxNum();
	}
};

struct Hw::FmergeHeader
{
	char magic[4];
	size_t m_FileNum;
	size_t m_OffsetTblOffs;
	size_t m_ExtOffs;
	size_t m_NamesOffs;
	size_t m_SizeOffs;
	size_t m_HashMapOffs;
};

class Hw::cFmerge
{
public:
	FmergeHeader* m_data;
	char* m_dtt;

	cFmerge(char* data) : m_data((FmergeHeader*)data), m_dtt(nullptr) {};
	cFmerge() { MAKE_CALL(shared::base + 0x9E3530, void(__thiscall*)(Hw::cFmerge*), this); }

	void* getDtt() { return MAKE_CALL(shared::base + 0x9E3550, void* (__thiscall*)(Hw::cFmerge*), this); }
	void* getData() { return MAKE_CALL(shared::base + 0x9E3560, void* (__thiscall*)(Hw::cFmerge*), this); }
	void setData(void* data, int index) { MAKE_CALL(shared::base + 0x9E3570, void(__thiscall*)(Hw::cFmerge*, void*, int), this, data, index); }
	void* getDataAt(int index) { return MAKE_CALL(shared::base + 0x9E3580, void* (__thiscall*)(Hw::cFmerge*, int), this, index); }
	size_t getFileAmount() { return MAKE_CALL(shared::base + 0x9E3590, size_t(__thiscall*)(Hw::cFmerge*), this); }
	size_t getFileIndexSize(size_t fileIndex) { return MAKE_CALL(shared::base + 0x9E3670, size_t(__thiscall*)(Hw::cFmerge*, size_t), this, fileIndex); }
	const char* getFileIndexFileName(size_t fileIndex) { return MAKE_CALL(shared::base + 0x9E38D0, const char* (__thiscall*)(Hw::cFmerge*, size_t), this, fileIndex); }
	BOOL getFileIndexExtension(char* pExt, size_t fileIndex) { return MAKE_CALL(shared::base + 0x9E3C20, BOOL(__thiscall*)(Hw::cFmerge*, char*, size_t), this, pExt, fileIndex); }
	void* getFileIndexData(size_t fileIndex) { return MAKE_CALL(shared::base + 0x9E3CF0, void* (__thiscall*)(Hw::cFmerge*, size_t), this, fileIndex); }
	size_t _getFileIndexSize(size_t fileIndex) { return MAKE_CALL(shared::base + 0x9E3EE0, size_t(__thiscall*)(Hw::cFmerge*, size_t), this, fileIndex); }
	size_t getExtensionFileIndex(const char* ext, unsigned int no) { return MAKE_CALL(shared::base + 0x9E3F20, size_t(__thiscall*)(Hw::cFmerge*, const char*, unsigned int), this, ext, no); }
	size_t getFileNameIndexI(const char* name) { return MAKE_CALL(shared::base + 0x9E3FD0, size_t(__thiscall*)(Hw::cFmerge*, const char*), this, name); }
	size_t getSubStrFileIndex(const char* name, unsigned int matchLimit) { return MAKE_CALL(shared::base + 0x9E4130, size_t(__thiscall*)(Hw::cFmerge*, const char*, unsigned int), this, name, matchLimit); }
	void* getExtensionFileData(const char* name, unsigned int matchLimit) { return MAKE_CALL(shared::base + 0x9E44B0, void* (__thiscall*)(Hw::cFmerge*, const char*, unsigned int), this, name, matchLimit); }
	void* getFileNameData(const char* name) { return MAKE_CALL(shared::base + 0x9E4500, void* (__thiscall*)(Hw::cFmerge*, const char*), this, name); }
	void* getFileNameData(const char* name, unsigned int no) { return MAKE_CALL(shared::base + 0x9E4550, void* (__thiscall*)(Hw::cFmerge*, const char*, unsigned int), this, name, no); }
	size_t getFileNameSize(const char* name, unsigned int no) { return MAKE_CALL(shared::base + 0x9E46D0, size_t(__thiscall*)(Hw::cFmerge*, const char*, unsigned int), this, name, no); }
	void setData(char* data, char* dds = nullptr) { MAKE_CALL(shared::base + 0x9E3540, void(__thiscall*)(Hw::cFmerge*, char*, char*), this, data, dds); }

	operator bool() { return m_data != nullptr; }
};

enum Hw::KEYBOARD_MAP
{
	KB_SPACE = 32,
	KB_A = 65,
	KB_B = 66,
	KB_C = 67,
	KB_D = 68,
	KB_E = 69,
	KB_F = 70,
	KB_G = 71,
	KB_H = 72,
	KB_I = 73,
	KB_J = 74,
	KB_K = 75,
	KB_L = 76,
	KB_M = 77,
	KB_N = 78,
	KB_O = 79,
	KB_P = 80,
	KB_Q = 81,
	KB_R = 82,
	KB_S = 83,
	KB_T = 84,
	KB_U = 85,
	KB_V = 86,
	KB_W = 87,
	KB_X = 88,
	KB_Y = 89,
	KB_Z = 90,
	KB_0 = 48,
	KB_1 = 49,
	KB_2 = 50,
	KB_3 = 51,
	KB_4 = 52,
	KB_5 = 53,
	KB_6 = 54,
	KB_7 = 55,
	KB_8 = 56,
	KB_9 = 57,
	KB_MINUS = 45,
	KB_EQ = 61,
	KB_BRAC_L = 91,
	KB_BRAC_R = 93,
	KB_PERIOD = 46,
	KB_APOS = 39,
	KB_SLASH = 47,
	KB_COMMA = 44,
	KB_SEMICOLON = 59,
	KB_GRAVE = 96,
	KB_COLON = 58,
	KB_AT = 64,
	KB_YEN = 92,
	KB_CIRCUMFLEX = 94,
	KB_RET = 10,
	KB_TAB = 9,
	KB_BS = 8,
	KB_F1 = 128,
	KB_F2 = 129,
	KB_F3 = 130,
	KB_F4 = 131,
	KB_F5 = 132,
	KB_F6 = 133,
	KB_F7 = 134,
	KB_F8 = 135,
	KB_F9 = 136,
	KB_F10 = 137,
	KB_F11 = 138,
	KB_F12 = 139,
	KB_DN = 140,
	KB_LT = 141,
	KB_RT = 142,
	KB_UP = 143,
	KB_CAP = 144,
	KB_ESC = 145,
	KB_INS = 146,
	KB_DEL = 147,
	KB_HOME = 148,
	KB_END = 149,
	KB_PAGE_UP = 150,
	KB_PAGE_DN = 151,
	KB_SYSRQ = 152,
	KB_SCRLOCK = 153,
	KB_PAUSE = 154,
	KB_CTRL_L = 155,
	KB_CTRL_R = 156,
	KB_ALT_L = 157,
	KB_ALT_R = 158,
	KB_SHIFT_L = 159,
	KB_SHIFT_R = 160,
	KB_WIN_L = 161,
	KB_WIN_R = 162,
	KB_APPS = 163,
	KB_BACKSLASH = 164,
	KB_NUMLOCK = 165,
	KB_NUM0 = 166,
	KB_NUM1 = 167,
	KB_NUM2 = 168,
	KB_NUM3 = 169,
	KB_NUM4 = 170,
	KB_NUM5 = 171,
	KB_NUM6 = 172,
	KB_NUM7 = 173,
	KB_NUM8 = 174,
	KB_NUM9 = 175,
	KB_NUM_ADD = 176,
	KB_NUM_SUB = 177,
	KB_NUM_DEC = 178,
	KB_NUM_DIV = 179,
	KB_NUM_MUL = 180,
	KB_NUM_ENT = 181,
	KB_MAP_MAX = 182,
	KB_MAP_INVALID = 183
};

class Hw::UserReplace
{
public:
	static inline REAL_USER_NO& m_MainUserNo = *(REAL_USER_NO*)(shared::base + 0x14CEA10);

	static inline REAL_USER_NO GetRealUserNo(int userNo) { return MAKE_CALL(shared::base + 0x9FD140, REAL_USER_NO(__cdecl*)(int), userNo); }
};

class Hw::cKeyboardState
{
public:
	enum { KB_MAP_FLAG_SIZE = 6 };
public:
	unsigned int m_pOn[KB_MAP_FLAG_SIZE];
	unsigned int m_pTrig[KB_MAP_FLAG_SIZE];
	unsigned int m_pRel[KB_MAP_FLAG_SIZE];
	unsigned int m_pRep[KB_MAP_FLAG_SIZE];
	unsigned int m_pOld[KB_MAP_FLAG_SIZE];
	int m_RepCount;

	BOOL on(KEYBOARD_MAP vKey) { return MAKE_CALL(shared::base + 0x9D93A0, BOOL(__thiscall*)(Hw::cKeyboardState*, KEYBOARD_MAP), this, vKey); }
	BOOL on(char vKey) { return MAKE_CALL(shared::base + 0x9D93D0, BOOL(__thiscall*)(Hw::cKeyboardState*, char), this, vKey); }
	BOOL trig(KEYBOARD_MAP vKey) { return MAKE_CALL(shared::base + 0x9D9400, BOOL(__thiscall*)(Hw::cKeyboardState*, KEYBOARD_MAP), this, vKey); }
	BOOL trig(char vKey) { return MAKE_CALL(shared::base + 0x9D9430, BOOL(__thiscall*)(Hw::cKeyboardState*, char), this, vKey); }
	BOOL rel(KEYBOARD_MAP vKey) { return MAKE_CALL(shared::base + 0x9D9460, BOOL(__thiscall*)(Hw::cKeyboardState*, KEYBOARD_MAP), this, vKey); }
	BOOL rel(char vKey) { return MAKE_CALL(shared::base + 0x9D9490, BOOL(__thiscall*)(Hw::cKeyboardState*, char), this, vKey); }
	BOOL rep(KEYBOARD_MAP vKey) { return MAKE_CALL(shared::base + 0x9D94C0, BOOL(__thiscall*)(Hw::cKeyboardState*, KEYBOARD_MAP), this, vKey); }
	BOOL rep(char vKey) { return MAKE_CALL(shared::base + 0x9D94F0, BOOL(__thiscall*)(Hw::cKeyboardState*, char), this, vKey); }
	void setOn(KEYBOARD_MAP vKey, BOOL bDown) { MAKE_CALL(shared::base + 0x9D9620, void(__thiscall*)(Hw::cKeyboardState*, KEYBOARD_MAP, BOOL), this, vKey, bDown); }
	void setTrig(KEYBOARD_MAP vKey) { MAKE_CALL(shared::base + 0x9D9650, void(__thiscall*)(Hw::cKeyboardState*, KEYBOARD_MAP), this, vKey); }
}; // class is complete

class Hw::cViewPort
{
public:
	float m_X, m_Y, m_W, m_H;
	float m_Near, m_Far;
};

class Hw::cMouseState
{
public:
	unsigned int m_On;
	unsigned int m_Trig;
	unsigned int m_Rel;
	unsigned int m_Rep;
	float x;
	float y;
	int m_Wheel;
	int m_RepCount;
	float prevX;
	float prevY;
};

class Hw::KeyboardManagerBase
{
public:
	static inline int& m_RepeatWait = *(int*)(shared::base + 0x14CD830);
	static inline int& m_RepeatCycle = *(int*)(shared::base + 0x14CD834);

	static inline void InitState(cKeyboardState& rState) { MAKE_CALL(shared::base + 0x9DA4A0, void(__cdecl*)(cKeyboardState&), rState); }
	static inline int UpdateStateOnToOld(cKeyboardState& rState) { return MAKE_CALL(shared::base + 0x9DA4C0, int(__cdecl*)(cKeyboardState&), rState); }
};

class Hw::MouseManagerBase
{
public:
	static inline void UpdateState(cMouseState& rState) { MAKE_CALL(shared::base + 0x9D9800, void(__cdecl*)(cMouseState&), rState); }

	static inline int& m_RepeatWait = *(int*)(shared::base + 0x14CDDEC);
	static inline int& m_RepeatCycle = *(int*)(shared::base + 0x14CDDF0);

	static inline char* m_pStateHidFlag = (char*)(shared::base + 0x19D06D0); //char m_pStateHidFlag[20];
	static inline int& m_IsStrokeValid = *(int*)(shared::base + 0x19D07F8);
};

class Hw::MouseManager : public Hw::MouseManagerBase
{
public:

	static inline LPDIRECTINPUTDEVICE8W& m_pMouseDevice = *(LPDIRECTINPUTDEVICE8W*)(shared::base + 0x19D06F4);
};

class Hw::KeyboardManager : public Hw::KeyboardManagerBase
{
public:
	enum { MAX_KEY_MAP_FLAG = 256 };

	static inline int UpdateKeyState(cKeyboardState& rState) { return MAKE_CALL(shared::base + 0x9DA500, int(__cdecl*)(cKeyboardState&), rState); }
	static inline int UpdateState(cKeyboardState& rState) { return MAKE_CALL(shared::base + 0x9DA710, int(__cdecl*)(cKeyboardState&), rState); }

	static inline int* m_pStrokeHidFlag = (int*)(shared::base + 0x14CD838); // int m_pStrokeHidFlag[KB_MAP_MAX][2];
	static inline char* m_pStateHidFlag = (char*)(shared::base + 0x19D06F8); //char m_pStateHidFlag[MAX_KEY_MAP_FLAG];
	static inline int& m_IsStateValid = *(int*)(shared::base + 0x14CDDE8);

	static inline LPDIRECTINPUTDEVICE8W& m_pKeyboardDevice = *(LPDIRECTINPUTDEVICE8W*)(shared::base + 0x19D06E8);
};

class Hw::PadManager
{
public:
	class cVibState
	{
	public:
		float m_fCurrent;
		float m_fTarget;
	};

	class cPadInfo
	{
	public:
		XINPUT_STATE m_XInputState;
		int m_IsValid;
		cVibState m_VibState[2];
		float m_LeftMotorSpeed;
		float m_RightMotorSpeed;
		int m_CurrentVibrationTime;
		int m_VibrationTotal;
		int m_bVibrationEnabled;
	};
	static inline void SetAnalogRange(float range, float thres, float ambit, Hw::INPUT_PAD_ANALOG analog) { MAKE_CALL(shared::base + 0x9D99F0, void(__cdecl*)(float, float, float, Hw::INPUT_PAD_ANALOG), range, thres, ambit, analog); }
	static inline void UpdatePad(cPadInfo& rInfo, int controllerId) { MAKE_CALL(shared::base + 0x9DA900, void(__cdecl*)(cPadInfo&, int), rInfo, controllerId); }
	static inline void SetVib(int controllerId, float leftMotorSpeed, float rightMotorSpeed, int time) { MAKE_CALL(shared::base + 0x9DA360, void(__cdecl*)(int, float, float, int), controllerId, leftMotorSpeed, rightMotorSpeed, time); }
	static inline void SetTriggerState(Hw::cPadState& pad, unsigned int buttons) { MAKE_CALL(shared::base + 0x9DA210, void(__cdecl*)(Hw::cPadState&, unsigned int), pad, buttons); }

	static inline int& m_RepeatWait = *(int*)(shared::base + 0x19D05B8);
	static inline int& m_RepeatCycle = *(int*)(shared::base + 0x19D05BC);

	static inline float* m_pAnalogAmbit = (float*)(shared::base + 0x19D05C0); // float m_pAnalogAmbit[4];
	static inline float* m_pAnalogThres = (float*)(shared::base + 0x19D05D0); // float m_pAnalogThres[4];
	static inline float* m_pAnalogRange = (float*)(shared::base + 0x19D05E0); // float m_pAnalogRange[4];

	static inline cPadInfo* m_pPadInfo = (cPadInfo*)(shared::base + 0x19D05F0); // Hw::PadManager::cPadInfo m_pPadInfo[4];
	static inline LPDIRECTINPUTDEVICE8W* m_pControllerDevices = (LPDIRECTINPUTDEVICE8W*)(shared::base + 0x19D05A8); // LPDIRECTINPUTDEVICE8W m_pControllerDevices[4];
};

class Hw::InputSystem
{
public:
	static inline void InitKeyboard(Hw::cKeyboardState& rState) { MAKE_CALL(shared::base + 0x9DAFF0, void(__cdecl*)(Hw::cKeyboardState&), rState); }
	static inline void UpdateKeyboard(Hw::cKeyboardState& rState) { MAKE_CALL(shared::base + 0x9DB010, void(__cdecl*)(Hw::cKeyboardState&), rState); }

	static inline void UpdateMouse(Hw::cMouseState& rState) { MAKE_CALL(shared::base + 0x9DA450, void(__cdecl*)(Hw::cMouseState&), rState); }

	static inline void InitPad(Hw::cPadState& rState) { MAKE_CALL(shared::base + 0x9DAFC0, void(__cdecl*)(Hw::cPadState&), rState); }
	static inline void UpdatePad(Hw::cPadState& rState, int controllerId) { MAKE_CALL(shared::base + 0x9DAFE0, void(__cdecl*)(Hw::cPadState&, int), rState, controllerId); }
	static inline void SetAnalogRange(float range, float thres, float ambit, Hw::INPUT_PAD_ANALOG analog) { MAKE_CALL(shared::base + 0x9DA270, void(__cdecl*)(float, float, float, Hw::INPUT_PAD_ANALOG), range, thres, ambit, analog); }

	static inline LPDIRECTINPUT8W& m_pInputDevice = *(LPDIRECTINPUT8W*)(shared::base + 0x19D06E4);
};

class Hw::cUcol
{
public:
	unsigned int r, g, b, a;

	cUcol(unsigned int color = 0) { r = (color >> 16) & 0xFF; g = (color >> 8) & 0xFF; b = color & 0xFF; a = (color >> 24) & 0xFF; }
	cUcol(const cFcol& fcol);
	cUcol(unsigned int r, unsigned int g, unsigned int b, unsigned int a) : r(r), g(g), b(b), a(a) {}

	void setRGBAU(unsigned int r, unsigned int g, unsigned int b, unsigned int a) { this->r = r; this->g = g; this->b = b; this->a = a; }
	void setRGBAF(float r, float g, float b, float a) { this->r = (int)(r * 255); this->g = (int)(g * 255); this->b = (int)(b * 255); this->a = (int)(a * 255); }

	operator unsigned int() const { return (a << 24) | (r << 16) | (g << 8) | b; }
	cUcol& operator=(unsigned int color) { r = (color >> 16) & 0xFF; g = (color >> 8) & 0xFF; b = color & 0xFF; a = (color >> 24) & 0xFF; return *this; }
	cUcol& operator=(const cFcol& fcol);
	cUcol operator+(const cFcol& fcol) const;
	cUcol operator-(const cFcol& fcol) const;
	cUcol operator*(const cFcol& fcol) const;
	cUcol operator/(const cFcol& fcol) const;
	bool operator==(const cFcol& fcol) const;
	bool operator!=(const cFcol& fcol) const;
};

class Hw::cFcol
{
public:
	float r, g, b, a;

	cFcol(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f) : r(r), g(g), b(b), a(a) {}
	cFcol(const cUcol& ucol);
	cFcol(unsigned int color) { r = ((color >> 16) & 0xFF) / 255.0f; g = ((color >> 8) & 0xFF) / 255.0f; b = (color & 0xFF) / 255.0f; a = ((color >> 24) & 0xFF) / 255.0f; }

	void setRGBAF(float r, float g, float b, float a) { this->r = r; this->g = g; this->b = b; this->a = a; }
	void setRGBAU(unsigned int r, unsigned int g, unsigned int b, unsigned int a) { this->r = (float)r / 255.f; this->g = (float)g / 255.f; this->b = (float)b / 255.f; this->a = (float)a / 255.f; }

	operator unsigned int() const { return ((unsigned int)(a * 255) << 24) | ((unsigned int)(r * 255) << 16) | ((unsigned int)(g * 255) << 8) | (unsigned int)(b * 255); }

	cFcol& operator=(unsigned int color) { r = ((color >> 16) & 0xFF) / 255.0f; g = ((color >> 8) & 0xFF) / 255.0f; b = (color & 0xFF) / 255.0f; a = ((color >> 24) & 0xFF) / 255.0f; return *this; }
	cFcol& operator=(const cUcol& ucol);
	cFcol operator+(const cUcol& ucol) const;
	cFcol operator-(const cUcol& ucol) const;
	cFcol operator*(const cUcol& ucol) const;
	cFcol operator/(const cUcol& ucol) const;
	bool operator==(const cUcol& ucol) const;
	bool operator!=(const cUcol& ucol) const;
};

inline Hw::cUcol::cUcol(const cFcol& fcol) { r = (unsigned int)(int)(fcol.r * 255.0f); g = (unsigned int)(int)(fcol.g * 255.0f); b = (unsigned int)(int)(fcol.b * 255.0f); a = (unsigned int)(int)(fcol.a * 255.0f); }
inline Hw::cFcol::cFcol(const cUcol& ucol) { r = ucol.r / 255.0f; g = ucol.g / 255.0f; b = ucol.b / 255.0f; a = ucol.a / 255.0f; }
inline Hw::cFcol& Hw::cFcol::operator=(const cUcol& ucol) { setRGBAU(ucol.r, ucol.g, ucol.b, ucol.a); return *this; }
inline Hw::cUcol& Hw::cUcol::operator=(const cFcol& fcol) { setRGBAF(fcol.r, fcol.g, fcol.b, fcol.a); return *this; }
inline Hw::cUcol Hw::cUcol::operator+(const cFcol& fcol) const
{
	return cUcol(
		min(255, r + (unsigned int)(fcol.r * 255)),
		min(255, g + (unsigned int)(fcol.g * 255)),
		min(255, b + (unsigned int)(fcol.b * 255)),
		min(255, a + (unsigned int)(fcol.a * 255))
	);
}

inline Hw::cUcol Hw::cUcol::operator-(const cFcol& fcol) const
{
	return cUcol(
		max(0, r - (unsigned int)(fcol.r * 255)),
		max(0, g - (unsigned int)(fcol.g * 255)),
		max(0, b - (unsigned int)(fcol.b * 255)),
		max(0, a - (unsigned int)(fcol.a * 255))
	);
}

inline Hw::cUcol Hw::cUcol::operator*(const cFcol& fcol) const
{
	return cUcol(
		min(255, (int)(r * fcol.r)),
		min(255, (int)(g * fcol.g)),
		min(255, (int)(b * fcol.b)),
		min(255, (int)(a * fcol.a))
	);
}

inline Hw::cUcol Hw::cUcol::operator/(const cFcol& fcol) const
{
	return cUcol(
		min(255, (int)((float)r / max(fcol.r, 1e-6f))),
		min(255, (int)((float)g / max(fcol.g, 1e-6f))),
		min(255, (int)((float)b / max(fcol.b, 1e-6f))),
		min(255, (int)((float)a / max(fcol.a, 1e-6f)))
	);
}

inline bool Hw::cUcol::operator==(const cFcol& fcol) const
{
	return r == (unsigned int)(fcol.r * 255) &&
		g == (unsigned int)(fcol.g * 255) &&
		b == (unsigned int)(fcol.b * 255) &&
		a == (unsigned int)(fcol.a * 255);
}

inline bool Hw::cUcol::operator!=(const cFcol& fcol) const
{
	return !(*this == fcol);
}

inline Hw::cFcol Hw::cFcol::operator+(const cUcol& ucol) const
{
	return cFcol(
		r + ucol.r / 255.0f,
		g + ucol.g / 255.0f,
		b + ucol.b / 255.0f,
		a + ucol.a / 255.0f
	);
}

inline Hw::cFcol Hw::cFcol::operator-(const cUcol& ucol) const
{
	return cFcol(
		r - ucol.r / 255.0f,
		g - ucol.g / 255.0f,
		b - ucol.b / 255.0f,
		a - ucol.a / 255.0f
	);
}

inline Hw::cFcol Hw::cFcol::operator*(const cUcol& ucol) const
{
	return cFcol(
		r * ucol.r / 255.0f,
		g * ucol.g / 255.0f,
		b * ucol.b / 255.0f,
		a * ucol.a / 255.0f
	);
}

inline Hw::cFcol Hw::cFcol::operator/(const cUcol& ucol) const
{
	return cFcol(
		r / max(ucol.r, 1u) / 255.0f,
		g / max(ucol.g, 1u) / 255.0f,
		b / max(ucol.b, 1u) / 255.0f,
		a / max(ucol.a, 1u) / 255.0f
	);
}

inline bool Hw::cFcol::operator==(const cUcol& ucol) const
{
	return fabs(r - ucol.r / 255.0f) < 1e-6f &&
		fabs(g - ucol.g / 255.0f) < 1e-6f &&
		fabs(b - ucol.b / 255.0f) < 1e-6f &&
		fabs(a - ucol.a / 255.0f) < 1e-6f;
};

inline bool Hw::cFcol::operator!=(const cUcol& ucol) const
{
	return !(*this == ucol);
}

class Hw::cRand
{
private:
	unsigned int m_Seed;
public:
	cRand() { MAKE_CALL(shared::base + 0x9DBBB0, void(__thiscall*)(cRand*), this); }
	~cRand() { MAKE_CALL(shared::base + 0x9DBBC0, void(__thiscall*)(cRand*), this); }

	void setSeed(unsigned int seed) { MAKE_CALL(shared::base + 0x9DBBD0, void(__thiscall*)(cRand*, unsigned int), this, seed); }
	unsigned int getSeed() { return MAKE_CALL(shared::base + 0x9DBBE0, unsigned int(__thiscall*)(cRand*), this); }
	unsigned short rollU16() { return MAKE_CALL(shared::base + 0x9DBBF0, unsigned short(__thiscall*)(cRand*), this); }
	unsigned int rollU32() { return MAKE_CALL(shared::base + 0x9DBC10, unsigned int(__thiscall*)(cRand*), this); }
	void initSeed() { MAKE_CALL(shared::base + 0x9DE290, void(__thiscall*)(cRand*), this); }
	unsigned short getU16(unsigned short min, unsigned short max) { return MAKE_CALL(shared::base + 0x9DE2A0, unsigned short(__thiscall*)(cRand*, unsigned short, unsigned short), this, min, max); }
	short getS16(short min, short max) { return MAKE_CALL(shared::base + 0x9DE2D0, short(__thiscall*)(cRand*, short, short), this, min, max); }
	float getF32(float min, float max) { return MAKE_CALL(shared::base + 0x9DE300, float(__thiscall*)(cRand*, float, float), this, min, max); }
	float getF0_1() { return MAKE_CALL(shared::base + 0x16220, float(__thiscall *)(cRand *), this); } // 11.06.2026, just found this
	float getF1_1() { return getF32(-1.0f, 1.0f); }
}; // class is complete(?, actually not sure)

template <typename tC>
class Hw::cSingleton
{
private:
	// static inline tC m_instance; // it doesn't work like this, but we can't do it either way
	// static inline BOOL m_wasInitialized = FALSE; // C++11 versions create a guard near the static variable, so this member here is pointless

	cSingleton() {};
public:

	// remove copy, move and assign copy operators

	cSingleton(const cSingleton<tC>&) = delete;
	cSingleton(cSingleton<tC>&&) = delete;
	cSingleton<tC>& operator=(const cSingleton<tC>&) = delete;

	static tC& GetInstance()
	{
		static tC instance;
		return instance;
	}
};

class Hw::cDepthSurface
{
public:

	virtual ~cDepthSurface() {};
};

class Hw::cOtManagerBase
{
public:

	virtual ~cOtManagerBase() {};
};

class Hw::cVec2
{
public:
	float x, y;

	cVec2() { x = 0.f; y = 0.f; }
	cVec2(float x, float y) : x(x), y(y) {}

	void setXY(float x, float y) { this->x = x; this->y = y; }

	void operator=(const cVec2& lhs) { x = lhs.x; y = lhs.y; }
	cVec2 operator+(const cVec2& lhs) { return cVec2(x + lhs.x, y + lhs.y); }
	cVec2 operator+(const cVec2& lhs) const { return cVec2(x + lhs.x, y + lhs.y); }
	cVec2& operator+=(const cVec2& lhs) { x += lhs.x; y += lhs.y; return *this; }
	cVec2 operator-(const cVec2& lhs) { return cVec2(x - lhs.x, y - lhs.y); }
	cVec2 operator-(const cVec2& lhs) const { return cVec2(x - lhs.x, y - lhs.y); }
	cVec2& operator-=(const cVec2& lhs) { x -= lhs.x; y -= lhs.y; return *this; }
	cVec2 operator*(float scale) { return cVec2(x * scale, y * scale); }
	cVec2 operator*(const cVec2& lhs) { return cVec2(x * lhs.x, y * lhs.y); }
	cVec2 operator*(const cVec2& lhs) const { return cVec2(x * lhs.x, y * lhs.y); }
	cVec2& operator*=(float scale) { x *= scale; y *= scale; return *this; }
	cVec2& operator*=(const cVec2& lhs) { x *= lhs.x; y *= lhs.y; return *this; }
	cVec2 operator/(float scale) { return cVec2(x / scale, y / scale); }
	cVec2 operator/(const cVec2& lhs) { return cVec2(x / lhs.x, y / lhs.y); }
	cVec2 operator/(const cVec2& lhs) const { return cVec2(x / lhs.x, y / lhs.y); }
	cVec2& operator/=(float scale) { x /= scale; y /= scale; return *this; }
	cVec2& operator/=(const cVec2& lhs) { x /= lhs.x; y /= lhs.y; return *this; }
	bool operator==(const cVec2& rhs) const { return x == rhs.x && y == rhs.y; }
	bool operator!=(const cVec2& rhs) const { return !(*this == rhs); }

	float length() { return sqrtf(powf(x, 2) + powf(y, 2)); }
	cVec2 normalize() { float length = this->length(); return cVec2(x / length, y / length); }
	float dot(const cVec2& lhs) { return x * lhs.x + y * lhs.y; }
};

class Hw::cVec3
{
public:
	float x, y, z;

	cVec3() { x = 0.f; y = 0.f; z = 0.f; }
	cVec3(const Hw::cVec4& lhs);
	cVec3(const Hw::cVec3& lhs) { x = lhs.x; y = lhs.y; z = lhs.z; }
	cVec3(float x, float y, float z) : x(x), y(y), z(z) {}
	void setXYZ(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }

	void setVec4(const Hw::cVec4& lhs);
	cVec3& operator=(const Hw::cVec4& lhs);
	cVec3 operator+(const Hw::cVec4& lhs);
	cVec3& operator+=(const Hw::cVec4& lhs);
	cVec3 operator-(const Hw::cVec4& lhs);
	cVec3& operator-=(const Hw::cVec4& lhs);
	cVec3 operator*(const Hw::cVec4& lhs);
	cVec3& operator*=(const Hw::cVec4& lhs);
	cVec3 operator/(const Hw::cVec4& lhs);
	cVec3& operator/=(const Hw::cVec4& lhs);
	bool operator==(const Hw::cVec4& lhs) const;
	bool operator!=(const Hw::cVec4& lhs) const;

	cVec3 operator*(Hw::cMtx& mat);
	cVec3& operator*=(Hw::cMtx& mat);

	cVec3& operator=(const cVec3& lhs) { x = lhs.x; y = lhs.y; z = lhs.z; return *this; }
	cVec3 operator+(const cVec3& lhs) { return cVec3(x + lhs.x, y + lhs.y, z + lhs.z); }
	cVec3 operator+(const cVec3& lhs) const { return cVec3(x + lhs.x, y + lhs.y, z + lhs.z); }
	cVec3& operator+=(const cVec3& lhs) { x += lhs.x; y += lhs.y; z += lhs.z; return *this; }
	cVec3 operator-(const cVec3& lhs) { return cVec3(x - lhs.x, y - lhs.y, z - lhs.z); }
	cVec3 operator-(const cVec3& lhs) const { return cVec3(x - lhs.x, y - lhs.y, z - lhs.z); }
	cVec3 operator-() const { return cVec3(-x, -y, -z); }
	cVec3& operator-=(const cVec3& lhs) { x -= lhs.x; y -= lhs.y; z -= lhs.z; return *this; }
	cVec3 operator*(float scale) { return cVec3(x * scale, y * scale, z * scale); }
	cVec3 operator*(const cVec3& lhs) { return cVec3(x * lhs.x, y * lhs.y, z * lhs.z); }
	cVec3 operator*(const cVec3& lhs) const { return cVec3(x * lhs.x, y * lhs.y, z * lhs.z); }
	cVec3& operator*=(float scale) { x *= scale; y *= scale; z *= scale; return *this; }
	cVec3& operator*=(const cVec3& lhs) { x *= lhs.x; y *= lhs.y; z *= lhs.z; return *this; }
	cVec3 operator/(float scale) { return cVec3(x / scale, y / scale, z / scale); }
	cVec3 operator/(const cVec3& lhs) { return cVec3(x / lhs.x, y / lhs.y, z / lhs.z); }
	cVec3 operator/(const cVec3& lhs) const { return cVec3(x / lhs.x, y / lhs.y, z / lhs.z); }
	cVec3& operator/=(float scale) { x /= scale; y /= scale; z /= scale; return *this; }
	cVec3& operator/=(const cVec3& lhs) { x /= lhs.x; y /= lhs.y; z /= lhs.z; return *this; }
	bool operator==(const cVec3& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }
	bool operator!=(const cVec3& rhs) const { return !(*this == rhs); }

	float length() { return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2)); }
	float length2D() { return sqrtf(powf(x, 2) + powf(z, 2)); }
	cVec3 normalize() { float length = this->length(); return cVec3(x / length, y / length, z / length); }
	float dot(const cVec3& lhs) { return x * lhs.x + y * lhs.y + z * lhs.z; }
	cVec3 cross(const cVec3& lhs) { return cVec3(y * lhs.z - z * lhs.y, z * lhs.x - x * lhs.z, x * lhs.y - y * lhs.x); }
};

class Hw::cVec4
{
public:
	float x, y, z, w;

	cVec4() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.f; }
	cVec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {} // No default for w to avoid confusion
	cVec4(const Hw::cVec4& lhs) { x = lhs.x; y = lhs.y; z = lhs.z; w = lhs.w; }
	cVec4(const Hw::cVec3& lhs);

	void setVec3(const Hw::cVec3& lhs);
	cVec4& operator=(const Hw::cVec3& lhs);
	cVec4 operator+(const Hw::cVec3& lhs);
	cVec4& operator+=(const Hw::cVec3& lhs);
	cVec4 operator-(const Hw::cVec3& lhs);
	cVec4& operator-=(const Hw::cVec3& lhs);
	cVec4 operator*(const Hw::cVec3& lhs);
	cVec4& operator*=(const Hw::cVec3& lhs);
	cVec4 operator/(const Hw::cVec3& lhs);
	cVec4& operator/=(const Hw::cVec3& lhs);
	bool operator==(const Hw::cVec3& lhs) const;
	bool operator!=(const Hw::cVec3& lhs) const;

	cVec4 operator*(Hw::cMtx& mat);
	cVec4& operator*=(Hw::cMtx& mat);

	void setXYZ(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
	void setXYZW(float x, float y, float z, float w) { this->x = x; this->y = y; this->z = z; this->w = w; }

	cVec4& operator=(const cVec4& right) { this->x = right.x; this->y = right.y; this->z = right.z; this->w = right.w; return *this; }
	cVec4 operator+(const cVec4& rhs) { return cVec4(x + rhs.x, y + rhs.y, z + rhs.z, 1.0f); }
	cVec4 operator+(const cVec4& rhs) const { return cVec4(x + rhs.x, y + rhs.y, z + rhs.z, 1.0f); }
	cVec4& operator+=(const cVec4& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; return *this; }
	cVec4 operator-(const cVec4& rhs) { return cVec4(x - rhs.x, y - rhs.y, z - rhs.z, w); }
	cVec4 operator-(const cVec4& rhs) const { return cVec4(x - rhs.x, y - rhs.y, z - rhs.z, w); }
	cVec4& operator-=(const cVec4& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w; return *this; }
	cVec4 operator*(float scale) { return cVec4(x * scale, y * scale, z * scale, w); }
	cVec4 operator*(const cVec4& rhs) { return cVec4(x * rhs.x, y * rhs.y, z * rhs.z, w); }
	cVec4 operator*(const cVec4& rhs) const { return cVec4(x * rhs.x, y * rhs.y, z * rhs.z, w); }
	cVec4& operator*=(float scale) { x *= scale; y *= scale; z *= scale; w *= scale; return *this; }
	cVec4& operator*=(const cVec4& rhs) { x *= rhs.x; y *= rhs.y; z *= rhs.z; w *= rhs.w; return *this; }
	cVec4 operator/(float scale) { return cVec4(x / scale, y / scale, z / scale, w); }
	cVec4 operator/(const cVec4& rhs) { return cVec4(x / rhs.x, y / rhs.y, z / rhs.z, w); }
	cVec4 operator/(const cVec4& rhs) const { return cVec4(x / rhs.x, y / rhs.y, z / rhs.z, w); }
	cVec4& operator/=(float scale) { x /= scale; y /= scale; z /= scale; w /= scale; return *this; }
	cVec4& operator/=(const cVec4& rhs) { x /= rhs.x; y /= rhs.y; z /= rhs.z; w /= rhs.w; return *this; }
	bool operator==(const cVec4& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }
	bool operator!=(const cVec4& rhs) const { return !(*this == rhs); }

	float length() const { return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2) + powf(w, 2)); }
	float length2D() const { return sqrtf(powf(x, 2) + powf(z, 2)); }
	cVec4 normalize() { float length = this->length(); return cVec4(x / length, y / length, z / length, w / length); }
	float dot(const cVec4& lhs) const { return x * lhs.x + y * lhs.y + z * lhs.z + w * lhs.w; }
	cVec4 cross(const cVec4& lhs) { return cVec4(y * lhs.z - z * lhs.y, z * lhs.x - x * lhs.z, x * lhs.y - y * lhs.x, 1.0f); }
};

inline Hw::cVec3::cVec3(const Hw::cVec4& lhs) { x = lhs.x; y = lhs.y; z = lhs.z; }
inline void Hw::cVec3::setVec4(const Hw::cVec4& lhs) { x = lhs.x; y = lhs.y; z = lhs.z; }
inline Hw::cVec3& Hw::cVec3::operator=(const Hw::cVec4& lhs) { x = lhs.x; y = lhs.y; z = lhs.z; return *this; }
inline Hw::cVec3 Hw::cVec3::operator+(const Hw::cVec4& lhs) { return cVec4(x + lhs.x, y + lhs.y, z + lhs.z, 1.0f); }
inline Hw::cVec3& Hw::cVec3::operator+=(const Hw::cVec4& lhs) { x += lhs.x; y += lhs.y; z += lhs.z; return *this; }
inline Hw::cVec3 Hw::cVec3::operator-(const Hw::cVec4& lhs) { return cVec4(x - lhs.x, y - lhs.y, z - lhs.z, 1.0f); }
inline Hw::cVec3& Hw::cVec3::operator-=(const Hw::cVec4& lhs) { x -= lhs.x; y -= lhs.y; z -= lhs.z; return *this; }
inline Hw::cVec3 Hw::cVec3::operator*(const Hw::cVec4& lhs) { return cVec4(x * lhs.x, y * lhs.y, z * lhs.z, 1.0f); }
inline Hw::cVec3& Hw::cVec3::operator*=(const Hw::cVec4& lhs) { x *= lhs.x; y *= lhs.y; z *= lhs.z; return *this; }
inline Hw::cVec3 Hw::cVec3::operator/(const Hw::cVec4& lhs) { return cVec4(x / lhs.x, y / lhs.y, z / lhs.z, 1.0f); }
inline Hw::cVec3& Hw::cVec3::operator/=(const Hw::cVec4& lhs) { x /= lhs.x; y /= lhs.y; z /= lhs.z; return *this; }
inline bool Hw::cVec3::operator==(const Hw::cVec4& lhs) const { return x == lhs.x && y == lhs.y && z == lhs.z; }
inline bool Hw::cVec3::operator!=(const Hw::cVec4& lhs) const { return !(*this == lhs); }

inline Hw::cVec4::cVec4(const Hw::cVec3& lhs) { x = lhs.x; y = lhs.y; z = lhs.z; w = 1.0f; }
inline void Hw::cVec4::setVec3(const Hw::cVec3& lhs) { x = lhs.x; y = lhs.y; z = lhs.z; }
inline Hw::cVec4& Hw::cVec4::operator=(const Hw::cVec3& lhs) { x = lhs.x; y = lhs.y; z = lhs.z; w = 1.0f; return *this; }
inline Hw::cVec4 Hw::cVec4::operator+(const Hw::cVec3& lhs) { return cVec4(x + lhs.x, y + lhs.y, z + lhs.z, 1.0f); }
inline Hw::cVec4& Hw::cVec4::operator+=(const Hw::cVec3& lhs) { x += lhs.x; y += lhs.y; z += lhs.z; return *this; }
inline Hw::cVec4 Hw::cVec4::operator-(const Hw::cVec3& lhs) { return cVec4(x - lhs.x, y - lhs.y, z - lhs.z, 1.0f); }
inline Hw::cVec4& Hw::cVec4::operator-=(const Hw::cVec3& lhs) { x -= lhs.x; y -= lhs.y; z -= lhs.z; return *this; }
inline Hw::cVec4 Hw::cVec4::operator*(const Hw::cVec3& lhs) { return cVec4(x * lhs.x, y * lhs.y, z * lhs.z, 1.0f); }
inline Hw::cVec4& Hw::cVec4::operator*=(const Hw::cVec3& lhs) { x *= lhs.x; y *= lhs.y; z *= lhs.z; return *this; }
inline Hw::cVec4 Hw::cVec4::operator/(const Hw::cVec3& lhs) { return cVec4(x / lhs.x, y / lhs.y, z / lhs.z, 1.0f); }
inline Hw::cVec4& Hw::cVec4::operator/=(const Hw::cVec3& lhs) { x /= lhs.x; y /= lhs.y; z /= lhs.z; return *this; }
inline bool Hw::cVec4::operator==(const Hw::cVec3& lhs) const { return x == lhs.x && y == lhs.y && z == lhs.z; }
inline bool Hw::cVec4::operator!=(const Hw::cVec3& lhs) const { return !(*this == lhs); }

class Hw::cQuat
{
public:
	float x, y, z, w;

	cQuat(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w) {};
	cQuat() { x = 0.f; y = 0.f; z = 0.f; w = 1.f; };
};

class Hw::cMtx
{
public:
	union
	{
		float _11, _12, _13, _14,
			_21, _22, _23, _24,
			_31, _32, _33, _34,
			_41, _42, _43, _44;

		float m[4][4];
		Hw::cVec4 r[4];
	};

	cMtx()
	{
		r[0] = Hw::cVec4(1.0f, 0.0f, 0.0f, 0.0f);
		r[1] = Hw::cVec4(0.0f, 1.0f, 0.0f, 0.0f);
		r[2] = Hw::cVec4(0.0f, 0.0f, 1.0f, 0.0f);
		r[3] = Hw::cVec4(0.0f, 0.0f, 0.0f, 1.0f);
	}

	cMtx(const cMtx& other) { r[0] = other.r[0]; r[1] = other.r[1]; r[2] = other.r[2]; r[3] = other.r[3]; }

	D3DXMATRIX& toDxMtx() { return *(D3DXMATRIX*)this; }
	D3DXMATRIX& toDxMtx() const { return *(D3DXMATRIX*)this; }

	cMtx& operator=(const cMtx& other)
	{
		r[0] = other.r[0];
		r[1] = other.r[1];
		r[2] = other.r[2];
		r[3] = other.r[3];

		return *this;
	}

	cMtx operator*(const cMtx& other) const
	{
		cMtx result;

		D3DXMatrixMultiply(&result.toDxMtx(), &toDxMtx(), &other.toDxMtx());

		return result;
	}
};

inline Hw::cVec3 Hw::cVec3::operator*(Hw::cMtx& mat)
{
	return Hw::cVec3(
		x * mat._11 + y * mat._21 + z * mat._31 + mat._41,
		x * mat._12 + y * mat._22 + z * mat._32 + mat._42,
		x * mat._13 + y * mat._23 + z * mat._33 + mat._43
	);
}
inline Hw::cVec3& Hw::cVec3::operator*=(Hw::cMtx& mat) { *this = *this * mat; return *this; }
inline Hw::cVec4 Hw::cVec4::operator*(Hw::cMtx& mat)
{
	return Hw::cVec4(
		x * mat._11 + y * mat._21 + z * mat._31 + w * mat._41,
		x * mat._12 + y * mat._22 + z * mat._32 + w * mat._42,
		x * mat._13 + y * mat._23 + z * mat._33 + w * mat._43,
		x * mat._14 + y * mat._24 + z * mat._34 + w * mat._44);
}
inline Hw::cVec4& Hw::cVec4::operator*=(Hw::cMtx& mat) { *this = *this * mat; return *this; }

VALIDATE_SIZE(Hw::cMtx, 0x40);

class Hw::cPadState
{
public:
	unsigned int m_On;
	unsigned int m_Trig;
	unsigned int m_Rel;
	unsigned int m_Rep;
	Hw::cVec2 m_LeftStick;
	Hw::cVec2 m_RightStick;
	float m_LeftTrigger;
	float m_RightTrigger;
	int m_bValidInput;
	int m_RepCount;
};

class Hw::cJobManager
{
public:
	class cWork
	{
	public:
		cJobManager* m_pManager;
		eThreadId m_ThreadId;
		cSemaphore m_hTaskWaitSemaphore;
		cSemaphore m_hTaskDoneSemaphore;
		void(__cdecl* m_func)(LPVOID reserved, void* arg);
		void* m_parameter;
	};

	cWork* m_pJobs;
	int m_nJobCapacity;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;

	cJobManager() { MAKE_CALL(shared::base + 0x9D6F30, void(__thiscall*)(cJobManager*), this); }
	~cJobManager() { MAKE_CALL(shared::base + 0x9D8B60, void(__thiscall*)(cJobManager*), this); }

	void shutdown()
	{
		MAKE_CALL(shared::base + 0x9D8860, void(__thiscall*)(cJobManager*), this);
	}

	unsigned int getCurrentThreadId()
	{
		return MAKE_CALL(shared::base + 0x9D7AD0, unsigned int(__thiscall*)(cJobManager*), this);
	}

	void setJobFunction(void(__cdecl* function)(LPVOID reserved, LPVOID parameter), LPVOID parameter, unsigned int jobIndex)
	{
		MAKE_CALL(shared::base + 0x9D75D0, void(__thiscall*)(cJobManager*, void(__cdecl*)(LPVOID, LPVOID), LPVOID, unsigned int), this, function, parameter, jobIndex);
	}

	BOOL startup(size_t jobAmount, int* threadIndices, Hw::cHeap* allocator, void* a5, void* a6, const char** threadNames, int a8)
	{
		return MAKE_CALL(shared::base + 0x9D8B70, BOOL(__thiscall*)(cJobManager*, size_t, int*, Hw::cHeap*, void*, void*, const char**, int), this, jobAmount, threadIndices, allocator, a5, a6, threadNames, a8);
	}

	void activate(unsigned int jobs)
	{
		MAKE_CALL(shared::base + 0x9D79A0, void(__thiscall*)(cJobManager*, unsigned int), this, jobs);
	}
};

class Hw::cTaskManager
{
public:
	class cWork;

	int m_nWorkNum;
	cWork* m_pWorkBuff;
	cWork* m_pActiveWorkList;
	cWork* m_pUnusingWorkList;
	cWork* m_pCurrentWork;
	int m_nRotateTaskId;
	cTaskManager* m_pPrevTaskManager;

	cTaskManager()
	{
		MAKE_CALL(shared::base + 0x9D6DF0, void(__thiscall*)(cTaskManager*), this);
	}

	cWork* newWork(int task_prio)
	{
		return MAKE_CALL(shared::base + 0x9D7420, cWork *(__thiscall*)(cTaskManager*, int), this, task_prio);
	}

	void deleteWork(cWork* pWork)
	{
		MAKE_CALL(shared::base + 0x9D74A0, void(__thiscall*)(cTaskManager*, cWork*), this, pWork);
	}

	eTaskId getCurrentId()
	{
		return MAKE_CALL(shared::base + 0x9D7500, eTaskId(__thiscall*)(cTaskManager*), this);
	}

	void execute(void(__cdecl* rFunc)(LPVOID parameter), LPVOID pParam, int task_prio, const char* task_name)
	{
		MAKE_CALL(shared::base + 0x9D7870, void(__thiscall*)(cTaskManager*, void(__cdecl*)(LPVOID), LPVOID, int, const char*), this, rFunc, pParam, task_prio, task_name);
	}

	void killWork(cWork* pWork)
	{
		MAKE_CALL(shared::base + 0x9D7F40, void(__thiscall*)(cTaskManager*, cWork*), this, pWork);
	}

	void cleanup()
	{
		MAKE_CALL(shared::base + 0x9D8450, void(__thiscall*)(cTaskManager*), this);
	}

	void sleep(int count)
	{
		MAKE_CALL(shared::base + 0x9D8570, void(__thiscall*)(cTaskManager*, int), this, count);
	}

	~cTaskManager()
	{
		MAKE_CALL(shared::base + 0x9D8A00, void(__thiscall*)(cTaskManager*), this);
	}

	BOOL startup(unsigned int taskCapacity, unsigned int taskStackSize, Hw::cHeapVariable* allocator)
	{
		return MAKE_CALL(shared::base + 0x9D8A10, BOOL(__thiscall*)(cTaskManager*, unsigned int, unsigned int, Hw::cHeapVariable*), this, taskCapacity, taskStackSize, allocator);
	}

	void update()
	{
		MAKE_CALL(shared::base + 0x9D8DA0, void(__thiscall*)(cTaskManager*), this);
	}

	static inline void chain(void(__cdecl* rFunc)(LPVOID), LPVOID pParam)
	{
		MAKE_CALL(shared::base + 0x9D8950, void(__cdecl*)(void(__cdecl*)(LPVOID), LPVOID), rFunc, pParam);
	}

	static inline cTaskManager* getCurrentManager()
	{
		return MAKE_CALL(shared::base + 0x9D6E10, cTaskManager *(__cdecl*)(), );
	}

	static inline void setCurrentManager(cTaskManager* pManager)
	{
		MAKE_CALL(shared::base + 0x9D6E20, void(__cdecl*)(cTaskManager*), pManager);
	}

	static inline cTaskManager*& m_pCurrentTaskManager = *(cTaskManager**)(shared::base + 0x19D0564); // private: static class
};

class Hw::cTaskManager::cWork
{
public:
	enum eStatus
	{
		STATUS_EXIT = 0x0,
		STATUS_EXEC = 0x1,
		STATUS_CHAIN = 0x2,
		STATUS_SLEEP = 0x3,
		STATUS_RUN = 0x4,
		STATUS_KILL = 0x5
	};

	Hw::cTaskManager* m_pManager;
	void(__cdecl* m_pFunc)(void*);
	void* m_pParam;
	eTaskId m_TaskId;
	int m_nTaskPrio;
	const char* m_TaskName;
	eStatus m_Status;
	int m_nSleepCount;
	int m_nTaskStackSize;
	cSemaphore m_SyncTaskStart;
	cSemaphore m_SyncTaskStop;
	cWork* m_pPrev;
	cWork* m_pNext;
	void(__cdecl* m_pTaskReport)(eStatus);

	void execute(void(__cdecl* rFunc)(LPVOID), LPVOID pParam, const char* task_name, eTaskId task_id)
	{
		MAKE_CALL(shared::base + 0x9D6E30, void(__thiscall*)(cWork*, void(__cdecl*)(LPVOID), LPVOID, const char*, eTaskId), this, rFunc, pParam, task_name, task_id);
	}

	void setTaskReport(void(__cdecl* rFunc)(eStatus))
	{
		MAKE_CALL(shared::base + 0x9D6E70, void(__thiscall*)(cWork*, void(__cdecl*)(eStatus)), this, rFunc);
	}

	BOOL isExit()
	{
		return MAKE_CALL(shared::base + 0x9D6E80, BOOL(__thiscall*)(cWork*), this);
	}

	eTaskId getTaskId()
	{
		return MAKE_CALL(shared::base + 0x9D6E90, eTaskId(__thiscall*)(cWork*), this);
	}

	const char* getTaskName()
	{
		return MAKE_CALL(shared::base + 0x9D6EA0, const char*(__thiscall*)(cWork*), this);
	}

	int getTaskPrio()
	{
		return MAKE_CALL(shared::base + 0x9D6EB0, int(__thiscall*)(cWork*), this);
	}

	void setTaskPrio(int task_prio)
	{
		MAKE_CALL(shared::base + 0x9D6EC0, void(__thiscall*)(cWork*, int), this, task_prio);
	}

	void chainWork(cWork* pPrev, cWork* pNext)
	{
		MAKE_CALL(shared::base + 0x9D6ED0, void(__thiscall*)(cWork*, cWork*, cWork*), this, pPrev, pNext);
	}

	void unchainWork()
	{
		MAKE_CALL(shared::base + 0x9D6EF0, void(__thiscall*)(cWork*), this);
	}

	cWork* getNextWork()
	{
		return MAKE_CALL(shared::base + 0x9D6F20, cWork *(__thiscall*)(cWork*), this);
	}

	BOOL startup(unsigned int stack_size, /* unused */ int __formal, cTaskManager* pManager)
	{
		return MAKE_CALL(shared::base + 0x9D7540, BOOL(__thiscall*)(cWork*, unsigned int, int, cTaskManager*), this, stack_size, __formal, pManager);
	}

	void waitTaskStart()
	{
		MAKE_CALL(shared::base + 0x9D7590, void(__thiscall*)(cWork*), this);
	}

	void sendTaskStart()
	{
		MAKE_CALL(shared::base + 0x9D75A0, void(__thiscall*)(cWork*), this);
	}

	void waitTaskStop()
	{
		MAKE_CALL(shared::base + 0x9D75B0, void(__thiscall*)(cWork*), this);
	}

	void sendTaskStop()
	{
		MAKE_CALL(shared::base + 0x9D75C0, void(__thiscall*)(cWork*), this);
	}

	void updateSleep()
	{
		MAKE_CALL(shared::base + 0x9D7910, void(__thiscall*)(cWork*), this);
	}

	void kill()
	{
		MAKE_CALL(shared::base + 0x9D7950, void(__thiscall*)(cWork*), this);
	}

	void cleanup()
	{
		MAKE_CALL(shared::base + 0x9D8000, void(__thiscall*)(cWork*), this);
	}

	void chain(void(__cdecl* rFunc)(LPVOID), LPVOID pParam)
	{
		MAKE_CALL(shared::base + 0x9D8090, void(__thiscall*)(cWork*, void(__cdecl*)(LPVOID), LPVOID), this, rFunc, pParam);
	}

	void sleep(int count)
	{
		MAKE_CALL(shared::base + 0x9D80E0, void(__thiscall*)(cWork*, int), this, count);
	}
};

class Hw::cTimeUnit
{
public:
	int m_Year, m_Month, m_Day, m_Hour, m_Minute, m_Second, m_MilliSecond;
};

class Hw::cTexture
{
public:
	void* m_Texture;
	cTextureInstance* m_pTextureInstance;
	int m_nTextureAmount;
	int field_10;
	int field_14;
	void* m_TextureAttributes;

	cTexture()
	{
		MAKE_CALL(shared::base + 0xB972C0, void(__thiscall*)(cTexture*), this);
	}

	virtual ~cTexture() {};

	BOOL create(void* wtb)
	{
		return MAKE_CALL(shared::base + 0xBA25D0, BOOL(__thiscall*)(cTexture*, void*), this, wtb);
	}

	BOOL create(void* wta, void* wtp)
	{
		return MAKE_CALL(shared::base + 0xBA4D00, BOOL(__thiscall*)(cTexture*, void*, void*), this, wta, wtp);
	}

	void reset()
	{
		MAKE_CALL(shared::base + 0xB972F0, void(__thiscall*)(cTexture*), this);
	}
};

class Hw::cTextureInstance
{
public:
	IDirect3DTexture9* m_Texture;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;

	virtual ~cTextureInstance() {};
};

class Hw::cLockableTexture : public Hw::cTexture
{
public:
	Hw::cTextureInstance m_Texture;
};

class Hw::cTargetTexture : public Hw::cTexture
{
public:
	Hw::cTextureInstance m_Texture;
};

class Hw::cShareTargetTexture : public Hw::cTargetTexture
{
public:
	int field_4C;
};

class Hw::CameraProj
{
private:
	int _pad04[3];
public:
	Hw::cMtx m_ProjMatrix;
	Hw::cMtx m_InverseProjMatrix;
	float m_Aspect;
	float m_Fovy;
	float m_NearZ;
	float m_FarZ;
	int m_bAspect; // do we want to update projection matrix after changing aspect ratio?
private:
	int _padA4[3];
public:

	CameraProj() { MAKE_CALL(shared::base + 0x812610, void(__thiscall*)(CameraProj*), this); }
	// non virtual destructor at 0x812450

	virtual ~CameraProj() {};

	void set(float nearZ, float farZ, float fovy) { MAKE_CALL(shared::base + 0x9E4D60, void(__thiscall*)(CameraProj*, float, float, float), this, nearZ, farZ, fovy); }
	void updateProjMatrixPers() { MAKE_CALL(shared::base + 0x9E5AA0, void(__thiscall*)(CameraProj*), this); }
	void setProjMatrix(const Hw::cMtx& mat, int __formal = 0 /* unused arg */) { MAKE_CALL(shared::base + 0x9E5B30, void(__thiscall*)(CameraProj*, const Hw::cMtx&, int), this, mat, __formal); }
};

VALIDATE_SIZE(Hw::CameraProj, 0xB0);

class Hw::cCameraBase
{
public:
	Hw::cMtx m_ViewMatrix;
	Hw::cMtx m_TransposeViewMatrix;
	Hw::cMtx m_InverseViewMatrix;
	Hw::cMtx m_ViewMatrixOld;
	Hw::cVec4 m_Trans;
	Hw::cVec4 m_Target;
	Hw::cVec4 m_Up;
	Hw::cVec4 m_Rot;
	Hw::ROT_ORDER m_RotOrder;
	float m_Dist;
	float m_Fovy;
private:
	int _pad14C;
public:

	void initialize() { MAKE_CALL(shared::base + 0x9E4EC0, void(__thiscall*)(cCameraBase*), this); }
	void movePos(const Hw::cVec4& pos) { MAKE_CALL(shared::base + 0x9E4F20, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, pos); }
	// Move according to the rotation vector, Z would be forward
	void movePosFront(const Hw::cVec4& pos) { MAKE_CALL(shared::base + 0x9E4FA0, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, pos); }
	// Move camera according to the Y rotation axis, Z is forward, it doesn't affect pitch at all
	void movePosFrontY(const Hw::cVec4& pos) { MAKE_CALL(shared::base + 0x9E5090, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, pos); }
	void updateViewInverseMatrix() { MAKE_CALL(shared::base + 0x9E5170, void(__thiscall*)(cCameraBase*), this); }
	void setViewMatrix(const Hw::cMtx& mat) { MAKE_CALL(shared::base + 0x9E5180, void(__thiscall*)(cCameraBase*, const Hw::cMtx&), this, mat); }
	void updateTrans() { MAKE_CALL(shared::base + 0x9E51B0, void(__thiscall*)(cCameraBase*), this); }
	void updateTarget() { MAKE_CALL(shared::base + 0x9E5260, void(__thiscall*)(cCameraBase*), this); }
	void updateUp() { MAKE_CALL(shared::base + 0x9E5310, void(__thiscall*)(cCameraBase*), this); }
	void updateRot() { MAKE_CALL(shared::base + 0x9E5380, void(__thiscall*)(cCameraBase*), this); }
	void updateDist() { MAKE_CALL(shared::base + 0x9E54E0, void(__thiscall*)(cCameraBase*), this); }
	void setLookAt(const Hw::cVec4& trans, const Hw::cVec4& target, const Hw::cVec4& up) { MAKE_CALL(shared::base + 0x9E5D10, void(__thiscall*)(cCameraBase*, const Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&), this, trans, target, up); }
	void setLookFor(const Hw::cVec4& trans, const Hw::cVec4& rot, float dist) { MAKE_CALL(shared::base + 0x9E5DA0, void(__thiscall*)(cCameraBase*, const Hw::cVec4&, const Hw::cVec4&, float), this, trans, rot, dist); }
	void setWatchAt(const Hw::cVec4& target, const Hw::cVec4& rot, float dist) { MAKE_CALL(shared::base + 0x9E5E60, void(__thiscall*)(cCameraBase*, const Hw::cVec4&, const Hw::cVec4&, float), this, target, rot, dist); }
	void setTrans(const Hw::cVec4& trans) { MAKE_CALL(shared::base + 0x9E5F20, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, trans); }
	void addTrans(const Hw::cVec4& trans) { MAKE_CALL(shared::base + 0x9E5F60, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, trans); }
	void setTarget(const Hw::cVec4& target) { MAKE_CALL(shared::base + 0x9E5FC0, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, target); }
	void addTarget(const Hw::cVec4& target) { MAKE_CALL(shared::base + 0x9E6000, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, target); }
	void setUp(const Hw::cVec4& up) { MAKE_CALL(shared::base + 0x9E6060, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, up); }
	void setTargetRot(const Hw::cVec4& rot) { MAKE_CALL(shared::base + 0x9E6090, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, rot); }
	void addTargetRot(const Hw::cVec4& rot) { MAKE_CALL(shared::base + 0x9E6120, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, rot); }
	void setTransRot(const Hw::cVec4& rot) { MAKE_CALL(shared::base + 0x9E61B0, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, rot); }
	void addTransRot(const Hw::cVec4& rot) { MAKE_CALL(shared::base + 0x9E6240, void(__thiscall*)(cCameraBase*, const Hw::cVec4&), this, rot); }
	void setTargetDist(float dist) { MAKE_CALL(shared::base + 0x9E62D0, void(__thiscall*)(cCameraBase*, float), this, dist); }
	void addTargetDist(float dist, float min, float max) { MAKE_CALL(shared::base + 0x9E62F0, void(__thiscall*)(cCameraBase*, float, float, float), this, dist, min, max); }
	void setTransDist(float dist) { MAKE_CALL(shared::base + 0x9E6370, void(__thiscall*)(cCameraBase*, float), this, dist); }
	void addTransDist(float dist, float min, float max) { MAKE_CALL(shared::base + 0x9E6390, void(__thiscall*)(cCameraBase*, float, float, float), this, dist, min, max); }
	void updateViewMatrix() { MAKE_CALL(shared::base + 0x9E6410, void(__thiscall*)(cCameraBase*), this); }
};

VALIDATE_SIZE(Hw::cCameraBase, 0x150);

class Hw::cPrimHeap
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;

	cPrimHeap()
	{
		MAKE_CALL(shared::base + 0xB97EC0, void(__thiscall*)(Hw::cPrimHeap*), this);
	}

	virtual ~cPrimHeap() {};

	void* allocBuffer(size_t size, size_t reserved = 0x20)
	{
		return MAKE_CALL(shared::base + 0xB9B1F0, void*(__thiscall*)(cPrimHeap*, size_t, size_t), this, size, reserved);
	}
};

class Hw::cIndexBufferHeap
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;

	cIndexBufferHeap()
	{
		MAKE_CALL(shared::base + 0xB9C7F0, void(__thiscall*)(cIndexBufferHeap*), this);
	}

	virtual ~cIndexBufferHeap() {};
};

struct Hw::RenderBufferHeapManager
{
	cPrimHeap* field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	cPrimHeap field_20[2];
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	cIndexBufferHeap field_80[2];
	int field_B8;
};

class Hw::cRenderTargetInfo
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;

	virtual ~cRenderTargetInfo() {};
};

class Hw::cOtWork
{
public:

	virtual ~cOtWork() {};

	void draw() { MAKE_VCALL(1, void(__thiscall *)(cOtWork *), this); }
};

struct Hw::cVertexInfo
{
	LPDIRECT3DVERTEXSHADER9 m_VertexShader;
	LPD3DXCONSTANTTABLE m_ConstantTable;
	unsigned short field_C;
};

struct Hw::cPixelInfo
{
	LPDIRECT3DPIXELSHADER9 m_PixelShader;
	LPD3DXCONSTANTTABLE m_ConstantTable;
	unsigned short field_C;
};

class Hw::cVertexShader
{
public:
	cVertexInfo m_VertexData;

	virtual ~cVertexShader() {};
};

class Hw::cPixelShader
{
public:
	cPixelInfo m_PixelData;

	virtual ~cPixelShader() {};
};

class Hw::cShader
{
public:
	Hw::cVertexShader m_VertexShader;
	Hw::cPixelShader m_PixelShader;
	int field_24;

	virtual ~cShader() {};
};

VALIDATE_SIZE(Hw::cShader, 0x28);

class Hw::cVertexFormat
{
public:
	IDirect3DVertexDeclaration9* m_VertexDeclaration;
	int m_UsageFlags;

	virtual void dummyVM() {};
};

class Hw::cUv
{
public:
	float u, v;

	cUv() : u(0.f), v(0.f) {}
	cUv(float u, float v) : u(u), v(v) {}
	~cUv() { u = v = 0.f; }

	void setUV(float u, float v)
	{
		this->u = u;
		this->v = v;
	}
};

class Hw::cPrimF : public Hw::cOtWork
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
};

class Hw::cPrimFT : public Hw::cOtWork {};

class Hw::cPrimFTyuv : public Hw::cOtWork {};

class Hw::cPrimFV : public Hw::cOtWork {};

class Hw::cPrimG : public Hw::cOtWork {};

class Hw::cPrimIF : public Hw::cOtWork {};

class Hw::cPrimIFT : public Hw::cOtWork {};

class Hw::cRenderPredicate
{
public:

	virtual ~cRenderPredicate() {};
};

class Hw::cShaderPreset : public Hw::cShader {};

class Hw::cShaderCharacter : public Hw::cShaderPreset {};

class Hw::cShaderPF : public Hw::cShaderPreset {};

class Hw::cShaderPFT : public Hw::cShaderPreset {};

class Hw::cShaderPFTyuv : public Hw::cShaderPreset {};

class Hw::cShaderPFTyuva : public Hw::cShaderPreset {};

class Hw::cShaderPFV : public Hw::cShaderPreset {};

class Hw::cShaderPG : public Hw::cShaderPreset {};

class Hw::cVertexFormatP : public Hw::cVertexFormat {};

class Hw::cVertexFormatPG : public Hw::cVertexFormat {};

class Hw::cVertexFormatPT : public Hw::cVertexFormat {};

class Hw::cVertexFormatPV : public Hw::cVertexFormat {};

class Hw::cZTexture : public Hw::cTargetTexture {};

class cFilterShaderCopyTex : public Hw::cShader
{
public:
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
};

class cFilterShaderCopyTexAlp : public cFilterShaderCopyTex {};

template <typename T>
class Hw::cFixedVector
{
public:
	int field_0;
	T* m_vector;
	size_t m_capacity;
	size_t m_size;
	BOOL m_bInitialized;

	cFixedVector()
	{
		field_0 = 0;
		m_vector = nullptr;
		m_capacity = 0;
		m_size = 0;
		m_bInitialized = 0;
	}

	~cFixedVector()
	{
		if (m_vector)
		{
			m_size = 0;
			if (m_bInitialized)
				operator delete(m_vector, (Hw::cHeap*)nullptr);
		}
	}

	BOOL create(size_t capacity, Hw::cHeap& rHeap)
	{
		if (m_vector)
			return 0;

		m_vector = rHeap.alloc(sizeof(T) * capacity);
		if (m_vector)
		{
			m_capacity = capacity;
			m_size = 0;
			m_bInitialized = 1; // is initialized?
			return 1;
		}
		else
		{
			MAKE_CALL(shared::base + 0x9D5650, void(__cdecl*)(const char*, ...), "cFixedVector::create Failed to allocate memory[%s need:%d Allocatable:%d]", rHeap.m_pHeapName, sizeof(T) * capacity, rHeap.getAllocatableSize());
			return 0;
		}
		return 0;
	}

	bool push_back(const T& element)
	{
		if (!m_vector)
			return false;

		if (m_size >= m_capacity)
			return false;

		m_vector[m_size++] = element;
		return true;
	}

	bool push_front(const T& element)
	{
		insert(m_vector[0], element);
		return true;
	}

	void insert(T& insIndex, const T& element)
	{
		if (!m_vector)
			return;

		if (m_size >= m_capacity)
			return;

		size_t insertIndex = &insIndex - m_vector;
		if (insertIndex > m_size)
			return;

		for (int i = m_size; i > insertIndex; --i)
			m_vector[i] = m_vector[i - 1];

		m_vector[insertIndex] = element;
		++m_size;
	}

	void remove(T& element)
	{
		if (!m_vector)
			return;

		if (&element - m_vector >= m_size)
			return;

		for (T* i = &element; i != m_vector[m_size - 1]; ++i)
			*i = i[1];

		--m_size;
	}

	T& get(size_t index)
	{
		return m_vector[index];
	}

	T& get(size_t index) const
	{
		return m_vector[index];
	}

	T& operator[](size_t index)
	{
		return get(index);
	}

	T& operator[](size_t index) const
	{
		return get(index);
	}

	T* begin()
	{
		return m_vector;
	}

	T* begin() const
	{
		return m_vector;
	}

	T* end()
	{
		return m_vector + m_size;
	}

	T* end() const
	{
		return m_vector + m_size;
	}
};

template <typename tC>
class Hw::cFixedList
{
public:
	class cTag
	{
	public:
		tC m_value;
		cTag* m_prev;
		cTag* m_next;

		cTag()
		{
			m_prev = m_next = nullptr;
		}

		~cTag()
		{
			m_prev = m_next = nullptr;
		}
	};

	class const_iterator
	{
	protected:
		cTag* m_pTag;
	public:

		const_iterator(cTag* pTag)
		{
			m_pTag = pTag;
		}

		const_iterator(const const_iterator& it)
		{
			m_pTag = it.m_pTag;
		}

		const_iterator()
		{
			m_pTag = nullptr;
		}

		const_iterator& operator++()
		{
			if (m_pTag)
				m_pTag = m_pTag->m_next;

			return *this;
		}

		const_iterator& operator--()
		{
			if (m_pTag)
				m_pTag = m_pTag->m_prev;

			return *this;
		}

		const_iterator& operator=(const const_iterator& it) const
		{
			m_pTag = it.m_pTag;

			return *this;
		}

		bool operator==(const const_iterator& other)
		{
			return m_pTag == other.m_pTag;
		}

		bool operator!=(const const_iterator& other)
		{
			return !(*this == other);
		}

		tC& operator*() const
		{
			return m_pTag->m_value;
		}

		tC* operator->() const
		{
			return &m_pTag->m_value;
		}

		const_iterator getPrev() const
		{
			return m_pTag->m_prev;
		}

		const_iterator getNext() const
		{
			return m_pTag->m_next;
		}
	};

	class iterator : public const_iterator
	{
	public:
		iterator(const iterator& it)
		{
			this->m_pTag = it.m_pTag;
		}

		iterator(cTag* pTag)
		{
			this->m_pTag = pTag;
		}

		iterator(const const_iterator& it)
		{
			this->m_pTag = it.m_pTag;
		}

		iterator()
		{
			this->m_pTag = nullptr;
		}

		iterator& operator=(const iterator& it)
		{
			this->m_pTag = it.m_pTag;

			return *this;
		}

		tC& operator*()
		{
			return this->m_pTag->m_value;
		}

		tC* operator->()
		{
			return &this->m_pTag->m_value;
		}

		iterator getPrev()
		{
			return this->m_pTag->m_prev;
		}

		iterator getNext()
		{
			return this->m_pTag->m_next;
		}
	};

	const iterator npos;
private:
	cTag* m_pAllocated;
	int m_Capacity;
	int m_UsedNum;
	iterator m_FreeBegin;
	iterator m_UsedBegin;
	iterator m_UsedEnd;
public:

	cFixedList() : npos(nullptr)
	{
		m_pAllocated = nullptr;
		m_FreeBegin = npos;
		m_UsedBegin = npos;
		m_UsedEnd = npos;
	};

	~cFixedList()
	{
		destroy();
	}

	BOOL create(int capacity, Hw::cHeap& allocator)
	{
		if (m_pAllocated)
			return FALSE;

		m_pAllocated = (cTag*)allocator.alloc(sizeof(cTag) * capacity + sizeof(cTag));
		if (m_pAllocated)
		{
			m_Capacity = capacity;
			m_UsedNum = 0;
			m_UsedEnd = m_pAllocated + capacity;

			resetChain();

			return TRUE;
		}
		return FALSE;
	}

	void destroy()
	{
		if (m_pAllocated)
		{
			if (m_pAllocated) // if this was generated by a macro, it makes sense
			{
				operator delete(m_pAllocated, (Hw::cHeap*)nullptr);
				m_pAllocated = nullptr;
			}

			m_Capacity = 0;
			m_UsedNum = 0;
			m_UsedBegin = npos;
			m_UsedEnd = npos;
			m_FreeBegin = npos;
		}
	}

	iterator insert(const_iterator& where, const tC& element)
	{
		cTag* free = m_FreeBegin;
		if (m_FreeBegin == npos)
		{
			MAKE_CALL(shared::base + 0x9D5650, void(__cdecl*)(const char*, ...), "cFixedList<tC>::insert  list max over!");
			return npos;
		}

		free = createIterator();

		if (free)
			free->m_value = element;

		free->m_prev = where.getPrev();
		free->m_next = where->m_pTag;

		if (where.getPrev())
			where.getPrev()->m_next = free;

		if (where->m_pTag)
			where->m_pTag->m_prev = free;

		if (m_UsedBegin == where)
			m_UsedBegin = free;

		return free;
	}

	iterator insert(const_iterator& it)
	{
		return insert(it, tC());
	}

	iterator pushFront()
	{
		return insert(m_UsedBegin);
	}

	iterator pushFront(const tC& element)
	{
		return insert(m_UsedBegin, element);
	}

	iterator pushBack()
	{
		return insert(m_UsedEnd);
	}

	iterator pushBack(const tC& element)
	{
		return insert(m_UsedEnd, element);
	}

	iterator erase(iterator& it)
	{
		cTag* prev = it.m_pTag->m_prev;
		cTag* next = it.m_pTag->m_next;

		if (prev)
			prev->m_next = next;
		if (next)
			next->m_prev = prev;

		if (m_UsedBegin == it)
			m_UsedBegin = next;

		--m_UsedNum;

		it->m_pTag->m_prev = m_FreeBegin.getPrev();
		it->m_pTag->m_next = m_FreeBegin.m_pTag;

		if (m_FreeBegin.getPrev())
			m_FreeBegin.getPrev()->m_next = it->m_pTag;
		if (m_FreeBegin.m_pTag)
			m_FreeBegin.m_pTag->m_prev = it->m_pTag;

		m_FreeBegin = it->m_pTag;

		return next;
	}

	void clear()
	{
		resetChain();
	}

	iterator begin()
	{
		return m_UsedBegin;
	}

	const_iterator begin() const
	{
		return m_UsedBegin;
	}

	const_iterator end() const
	{
		return m_UsedEnd;
	}

	iterator end()
	{
		return m_UsedEnd;
	}

	int getSize() const
	{
		return m_UsedNum;
	}

	int getCapacity() const
	{
		return m_Capacity;
	}

	BOOL canAdd() const
	{
		return m_UsedNum < m_Capacity /* && m_freeBegin != npos // not confirmed, but it's a good practise */;
	}

private:
	void chain(const_iterator& what, iterator& it)
	{
		cTag* prev = what->m_pTag;
		cTag* next = prev->m_next;

		it->m_pTag->m_prev = prev;
		it->m_pTag->m_next = next;

		if (prev) prev->m_next = it->m_pTag;
		if (next) next->m_prev = it->m_pTag;
	}

	iterator unchain(iterator& it)
	{
		cTag* prev = it.m_pTag->m_prev;
		cTag* next = it.m_pTag->m_next;

		if (prev) prev->m_next = next;
		if (next) next->m_prev = prev;

		if (m_UsedBegin == it)
			m_UsedBegin = next;

		if (m_UsedEnd == it)
			m_UsedEnd = prev;
	}

	void resetChain()
	{
		if (m_Capacity > 0)
		{
			cTag* current = m_pAllocated;
			for (int i = 0; i < m_Capacity; i++)
			{
				current->m_prev = (current - 1);
				current->m_next = (current + 1);
				++current;
			}
		}

		m_pAllocated->m_prev = nullptr;

		m_pAllocated[m_Capacity - 1].m_next = 0;

		m_UsedEnd->m_prev = nullptr;
		m_UsedEnd->m_next = nullptr;

		m_UsedBegin = m_UsedEnd;
		m_FreeBegin = m_pAllocated;

		m_UsedNum = 0;
	}

	iterator createIterator()
	{
		iterator& free = m_FreeBegin;
		if (free == npos)
			return npos;

		chain(m_UsedEnd, free);

		m_FreeBegin = free->getNext();
		++m_UsedNum;

		return free;
	}

	void releaseIterator(iterator& it)
	{
		if (it == npos)
			return;

		cTag* tag = it.m_pTag;

		unchain(it);

		tag->m_next = m_FreeBegin.m_pTag;
		tag->m_prev = nullptr;
		if (m_FreeBegin != npos)
			m_FreeBegin.m_pTag->m_prev = tag;

		m_FreeBegin = it;

		--m_UsedNum;
	}

	// void callCopyConstruction(iterator& it, const tC& elem);
	// void callDefaultConstruction(iterator &it);
	// void callDestruction(iterator& it);
	// void destructAll();
};

template <typename tC, typename tHeapBinder = Hw::cHeap>
class Hw::cExpandableVector
{
public:
	int field_0;
	tC* m_vector;
	size_t m_capacity;
	size_t m_size;
	BOOL m_ArrayInitialized;
	tHeapBinder* m_Allocator;

	cExpandableVector()
	{
		field_0 = 0;
		m_vector = nullptr;
		m_capacity = 0;
		m_size = 0;
		m_ArrayInitialized = FALSE;
	};

	cExpandableVector(tHeapBinder* allocator) : m_Allocator(allocator)
	{
		field_0 = 0;
		m_vector = nullptr;
		m_capacity = 0;
		m_size = 0;
		m_ArrayInitialized = FALSE;
	}

	~cExpandableVector()
	{
		operator delete(m_vector, m_Allocator);
		m_vector = nullptr;

		m_capacity = 0;
		m_size = 0;
		m_ArrayInitialized = FALSE;
	}

	BOOL create(size_t size)
	{
		if (m_vector)
			return FALSE;

		m_vector = (tC*)m_Allocator->AllocateMemory(sizeof(tC) * size, 32, 0, 0);
		if (m_vector)
		{
			m_size = 0;
			m_capacity = size;
			m_ArrayInitialized = TRUE;

			return TRUE;
		}

		MAKE_CALL(shared::base + 0x9D5650, void(__cdecl*)(const char*, ...), "Hw::cExpandableVector<tC, tHeapBinder>::create lack of memory[%s %d/%d]", m_Allocator->m_pHeapName, sizeof(tC) * size, m_Allocator->getAllocatableSize());
		return FALSE;
	}

	void insert(tC& where, const tC& element)
	{
		if (!m_vector)
			return;

		size_t index = &where - m_vector;

		if (index > m_size)
			return;

		if (m_size >= m_capacity)
		{
			if (!m_capacity)
				create(32u);
			else
				reallocate(m_capacity * 2);
		}

		for (size_t i = index; i < m_size; i++)
			m_vector[i] = m_vector[i - 1];

		m_vector[index] = element;
		++m_size;
	}

	void push_back(const tC& element)
	{
		if (!m_vector)
			return;

		if (m_size >= m_capacity)
		{
			if (!m_capacity)
				create(32u);
			else
				reallocate(m_capacity * 2);
		}

		m_vector[m_size++] = element;
	}

	void push_front(const tC& element)
	{
		insert(m_vector[0], element);
	}

	void remove(tC& element)
	{
		if (!m_vector)
			return;

		if (&element - m_vector >= m_size)
			return;

		size_t index = &element - m_vector;

		if (index >= m_capacity) //< Invalid element for vector
			return;

		for (tC* elem = m_vector + index; elem != m_vector + m_size - 1; elem++)
			*elem = elem[1];

		--m_size;
	}

	void clear()
	{
		if (m_vector)
			m_size = 0;
	}

	tC& get(size_t index)
	{
		return m_vector[index];
	}

	tC& get(size_t index) const
	{
		return m_vector[index];
	}

	tC& operator[](size_t index)
	{
		return get(index);
	}

	tC& operator[](size_t index) const
	{
		return get(index);
	}

	tC* begin()
	{
		return m_vector;
	}

	tC* begin() const
	{
		return m_vector;
	}

	tC* end()
	{
		return m_vector + m_size;
	}

	tC* end() const
	{
		return m_vector + m_size;
	}

	tC* rbegin()
	{
		return m_vector + m_size;
	}

	tC* rbegin() const
	{
		return m_vector + m_size;
	}

	tC* rend()
	{
		return m_vector;
	}

	tC* rend() const
	{
		return m_vector;
	}

	BOOL reallocate(size_t newSize)
	{
		if (m_capacity == newSize)
			return TRUE;

		tC* newArray = (tC*)m_Allocator->AllocateMemory(sizeof(tC) * newSize, 32, 0, 0);

		if (newArray)
		{
			if (m_size >= newSize)
			{
				if (m_size > 0)
				{
					for (size_t elementIndex = 0; elementIndex < m_size; elementIndex++)
						newArray[elementIndex] = m_vector[elementIndex];
				}
				m_size = newSize;
			}
			else
			{
				for (size_t elementIndex = 0; elementIndex < m_size; elementIndex++)
					newArray[elementIndex] = m_vector[elementIndex];
			}
			if (m_ArrayInitialized)
			{
				operator delete(m_vector, m_Allocator);
				m_ArrayInitialized = FALSE;
			}

			m_vector = newArray;
			m_capacity = newSize;
			m_ArrayInitialized = TRUE;

			return TRUE;
		}
		else
		{
			MAKE_CALL(shared::base + 0x9D5650, void(__cdecl*)(const char*, ...), "Hw::cExpandableVector<tC,tHeapBinder>::reallocate Out of memory");
			return FALSE;
		}

		return FALSE;
	}

	BOOL resize(size_t size)
	{
		if (size <= m_capacity || reallocate(size))
		{
			if (size != m_size)
				m_size = size;
			return TRUE;
		}
		else
		{
			MAKE_CALL(shared::base + 0x9D5650, void(__cdecl*)(const char*, ...), "Hw::cExpandableVector<tC,tHeapBinder>::resize insufficient capacity");
			return FALSE;
		}
		return FALSE;
	}
};

template <typename tC>
class Hw::cHwLFFreeListTemp
{
public:
	class cTag
	{
	public:
		tC m_value;
		cTag* m_pPrev, * m_pNext;

		cTag()
		{
			m_pPrev = m_pNext = nullptr;
		}

		~cTag()
		{
			m_pPrev = m_pNext = nullptr;
		}
	};

	class const_iterator
	{
	protected:
		cTag* m_pTag;
	public:
		const_iterator(cTag* pTag)
		{
			m_pTag = pTag;
		}

		const_iterator(const const_iterator& it)
		{
			m_pTag = it.m_pTag;
		}

		const_iterator()
		{
			m_pTag = nullptr;
		}

		const_iterator& operator++()
		{
			if (m_pTag)
				m_pTag = m_pTag->m_pNext;

			return *this;
		}

		const_iterator& operator--()
		{
			if (m_pTag)
				m_pTag = m_pTag->m_pPrev;

			return *this;
		}

		const_iterator& operator=(const const_iterator& it) const
		{
			m_pTag = it.m_pTag;

			return *this;
		}

		bool operator==(const const_iterator& other)
		{
			return m_pTag == other.m_pTag;
		}

		bool operator!=(const const_iterator& other)
		{
			return !(*this == other);
		}

		tC& operator*() const
		{
			return m_pTag->m_value;
		}

		tC* operator->() const
		{
			return &m_pTag->m_value;
		}

		const_iterator getPrev() const
		{
			return m_pTag->m_pPrev;
		}

		const_iterator getNext() const
		{
			return m_pTag->m_pNext;
		}
	};

	class iterator : public const_iterator
	{
	public:
		iterator(const iterator& it)
		{
			this->m_pTag = it.m_pTag;
		}

		iterator(cTag* pTag)
		{
			this->m_pTag = pTag;
		}

		iterator(const const_iterator& it)
		{
			this->m_pTag = it.m_pTag;
		}

		iterator()
		{
			this->m_pTag = nullptr;
		}

		iterator& operator=(const iterator& it)
		{
			this->m_pTag = it.m_pTag;

			return *this;
		}

		tC& operator*()
		{
			return this->m_pTag->m_value;
		}

		tC* operator->()
		{
			return &this->m_pTag->m_value;
		}

		iterator getPrev()
		{
			return this->m_pTag->m_pPrev;
		}

		iterator getNext()
		{
			return this->m_pTag->m_pNext;
		}
	};

	class cList
	{
	public:
		iterator m_pBegin;
		int m_UsedNum;
		int m_FreeNum;
	};

	int field_4;
	cList m_UsedList;
	int field_14;
	cTag* m_pAllocated;
	int m_Capacity;
	Hw::cHeap* m_pHeap;
	int field_24;
	cList m_QueueUseList;
	int field_34;
	iterator m_pUsedBegin;

	void resetChain()
	{
		m_UsedList.m_pBegin = iterator();
		m_UsedList.m_UsedNum = 0;
		m_UsedList.m_FreeNum = 0;

		if (m_Capacity > 0)
		{
			char* base = (char*)m_pAllocated;
			const size_t stride = sizeof(cTag);

			for (int i = 0; i < m_Capacity; ++i)
			{
				cTag* node = (cTag*)(base + i * stride);
				void* expected;
				do
				{
					expected = (void*)&m_UsedList.m_pBegin;
					node->m_pNext = (cTag*)expected;
				} while (InterlockedCompareExchangePointer(
					(void**)&m_UsedList.m_pBegin.m_pTag,
					node,
					expected) != expected); // this is such brainfuckery

				InterlockedIncrement(&m_UsedList.m_FreeNum);
			}
		}
	}

	virtual ~cHwLFFreeListTemp()
	{

	}
};

inline Hw::cTaskManager& g_MainTaskManager = *(Hw::cTaskManager*)(shared::base + 0x17E9164);
inline Hw::cKeyboardState& g_Keyboard = *(Hw::cKeyboardState*)(shared::base + 0x177B7C0);
inline Hw::cMouseState& g_Mouse = *(Hw::cMouseState*)(shared::base + 0x177B798);
inline Hw::cPadState& g_dbPad = *(Hw::cPadState*)(shared::base + 0x177BA90);

VALIDATE_SIZE(Hw::cHeap, 0x40);