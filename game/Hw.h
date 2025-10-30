#pragma once
#define DIRECTINPUT_VERSION 0x800u
#include <Windows.h>
#include <d3dx9.h>
#include <dinput.h>
#include <shared.h>
#include <Xinput.h>
#include <CriFs.h>
#include <DirectXMath.h>

extern void PrintfLog(const char* fmt, ...);

namespace Hw
{
	class KeyboardManagerBase;
	class KeyboardManager;

	class cKeyboardState;
	enum KEYBOARD_MAP;
	class cFmerge;
	struct FmergeHeader;

	class cMtx;

	class cUcol;
	class cFcol;

	class cCriticalSection;
	class cSemaphore;
	class cRand;

	struct cDvdFst;
	struct DvdReadManager;

	template <typename tC>
	class cSingleton;

	enum ANISOTROPY_LEVEL
	{
		ANISOTROPY_LEVEL1=1,
		ANISOTROPY_LEVEL2=2,
		ANISOTROPY_LEVEL4=4,
		ANISOTROPY_LEVEL8=8,
		ANISOTROPY_LEVEL16=16
	};

	enum BLENDOP_MODE
	{
		BLENDOP_ADD=0,
		BLENDOP_SUB=1,
		BLENDOP_REVSUB=4,
		BLENDOP_MIN=2,
		BLENDOP_MAX=3,
		BLENDOP_DEFAULT=0,
		BLENDALPHAOP_DEFAULT=0
	};

	enum BLEND_ELEM
	{
		BLEND_ZERO=0,
		BLEND_ONE=1,
		BLEND_SRCCOLOR=4,
		BLEND_INVSRCCOLOR=5,
		BLEND_SRCALPHA=6,
		BLEND_INVSRCALPHA=7,
		BLEND_DESTALPHA=10,
		BLEND_INVDESTALPHA=11,
		BLEND_DESTCOLOR=8,
		BLEND_INVDESTCOLOR=9,
		BLEND_SRCALPHASAT=16,
		BLEND_BOTHINVSRCALPHA=0,
		BLEND_BLENDFACTOR=12,
		BLEND_INVBLENDFACTOR=13,
		BLEND_SRC_DEFAULT=1,
		BLEND_DST_DEFAULT=0,
		BLEND_ALPHASRC_DEFAULT=1,
		BLEND_ALPHADST_DEFAULT=0
	};

	enum COMP_MODE
	{
		COMP_NEVER=0,
		COMP_LESS=1,
		COMP_EQUAL=2,
		COMP_LESSEQUAL=3,
		COMP_GREATER=4,
		COMP_NOTEQUAL=5,
		COMP_GREATEREQUAL=6,
		COMP_ALWAYS=7,
		COMP_Z_DEFAULT=3,
		COMP_ALPHATEST_DEFAULT=7
	};

	enum HW_ALLOC_MODE
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

	enum INPUT_PAD_ANALOG
	{
		INPUT_PAD_ANALOG_STICK_LEFT = 0x0,
		INPUT_PAD_ANALOG_STICK_RIGHT = 0x1,
		INPUT_PAD_ANALOG_TRIGGER_LEFT = 0x2,
		INPUT_PAD_ANALOG_TRIGGER_RIGHT = 0x3,
		INPUT_PAD_ANALOG_NUM = 0x4,
		INPUT_PAD_ANALOG_ALL = 0x5
	};

	enum eThreadId
	{
		THREAD_ID_INVALID=0
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

	class cTaskManager;
	class cJobManager;

	struct RenderBufferHeapManager;

	template <typename T>
	struct cFixedVector;

	template <typename T>
	struct cFixedList;

	template <typename tC, typename tHeapBinder>
	struct cExpandableVector;

	struct cVec2;
	struct cVec3;
	struct cVec4;
	struct cQuat;

	inline BOOL createSubWindow(const char *classname, const char *windowname, unsigned int x, unsigned int y)
	{
		return ((BOOL(__cdecl *)(const char*, const char *, unsigned int, unsigned int))(shared::base + 0xB98770))(classname, windowname, x, y);
	}

	class TextureManager
	{
	public:
		struct Texture
		{
			LPDIRECT3DTEXTURE9 m_pTexture;
			LPDIRECT3DTEXTURE9 *m_ppTexture;
			int field_8;
			int m_nWidth;
			int m_nHeight;
			int field_14;
			D3DFORMAT m_Format;
			D3DPOOL m_Pool;
			int field_20;
			int field_24;
		};

		inline void removeTexture(Texture& texture)
		{
			((void(__cdecl *)(Texture &))(shared::base + 0xBA16D0))(texture);
		}

		static inline cFixedList<Texture> &Textures = *(cFixedList<Texture>*)(shared::base + 0x1B20720);
		static inline cCriticalSection &TextureCriticalSection = *(cCriticalSection*)(shared::base + 0x1B20740);
	};

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

			class ListenerPositionWork : public Work{};

			class ListenerSpatializationWork : public Work{};

			class ObjectEnvironmentDryLevelWork : public Work{};

			class ObjectEnvironmentValuesWork : public Work{};

			class ObjectListenerMaskWork : public Work{};

			class ObjectOutputMaskWork : public Work{};

			class ObjectPositionWork : public Work{};

			class ObjectRTPCValueWork : public Work{};

			class ObjectRegisterWork : public Work{};

			class ObjectReleaseWork : public Work{};

			class ObjectSwitchWork : public Work{};

			class PostEventWork : public Work{};

			class ReleaseEventWork : public Work{};

			class ScalingFactorWork : public Work{};

			class StateWork : public Work{};

			class StopEventWork : public Work{};
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
			void (__cdecl *m_pfnThreadFunction)(void *);
			void *m_pThreadParameter;
		};

		static inline BOOL startupThread(cWork* pThread, unsigned int stackSize, int a3, const char *threadName, int priority)
		{
			return ((BOOL(__cdecl *)(cWork*, unsigned int, int, const char *, int))(shared::base + 0x9D7DB0))(pThread, stackSize, a3, threadName, priority);
		}

		static inline BOOL createThread(void (__cdecl *pfnThreadFunction)(void *), void *pParameter, unsigned int stackSize, int a4, const char *threadName, int priority)
		{
			return ((BOOL(__cdecl *)(void (__cdecl *)(void *), void *, unsigned int, int, const char *, int))(shared::base + 0x9D82C0))(pfnThreadFunction, pParameter, stackSize, a4, threadName, priority);
		}
		
		// Should be always called at the end of the thread function
		static inline void Exit()
		{
			((void(__cdecl *)())(shared::base + 0x9D7C70))();
		}
	};

	class GraphicDevice
	{
	public:

		static inline LPDIRECT3D9 &m_pD3D = *(LPDIRECT3D9*)(shared::base + 0x1B206D8);
		static inline LPDIRECT3DDEVICE9 &m_pDevice = *(LPDIRECT3DDEVICE9*)(shared::base + 0x1B206D4);
	};

	class OsWindow
	{
	public:

		static inline HWND &m_MainWindow = *(HWND*)(shared::base + 0x19D504C);
		static inline HWND &m_SecondWindow = *(HWND*)(shared::base + 0x1B205E0);
	};

	inline RenderBufferHeapManager& RenderBufferManager = *(RenderBufferHeapManager*)(shared::base + 0x1ADD490);

	inline cRand& g_Rand = *(cRand*)(shared::base + 0x19D0814);
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

	cHeap()
	{
		((void(__thiscall*)(cHeap*))(shared::base + 0x9D3650))(this);
	}

	virtual ~cHeap() {};

	void cleanup()
	{
		CallVMTFunc<1, cHeap*>(this);
	}

	void destroy()
	{
		CallVMTFunc<2, cHeap*>(this);
	}

	BOOL isValid()
	{
		return ReturnCallVMTFunc<BOOL, 3, cHeap*>(this);
	}

	size_t getSize()
	{
		return ReturnCallVMTFunc<size_t, 4, cHeap*>(this);
	}

	size_t getUsedSize()
	{
		return ReturnCallVMTFunc<size_t, 5, cHeap*>(this);
	}

	size_t getAllocatableSize()
	{
		return ReturnCallVMTFunc<size_t, 6, cHeap*>(this);
	}

	void* getNextAlloc(void *block)
	{
		return ReturnCallVMTFunc<void*, 7, cHeap*, void *>(this, block);
	}

	size_t getAllocSize(void* block)
	{
		return ReturnCallVMTFunc<size_t, 8, cHeap*, void*>(this, block);
	}

	size_t getRestSizeLimit()
	{
		return ReturnCallVMTFunc<size_t, 9, cHeap*>(this);
	}

	size_t getChildHeapSize()
	{
		return ReturnCallVMTFunc<size_t, 10, cHeap*>(this);
	}

	void setDefragmentableFlag(void *a1)
	{
		CallVMTFunc<11, cHeap*, void*>(this, a1);
	}

	void* createChildHeap(HANDLE* pHandle, size_t Size)
	{
		return ReturnCallVMTFunc<void*, 12, cHeap*, HANDLE*, size_t>(this, pHandle, Size);
	}

	void destroyChildHeap(HANDLE* pHandle, size_t Size)
	{
		CallVMTFunc<13, cHeap*, HANDLE*, size_t>(this, pHandle, Size);
	}

	void* allocImpl(size_t size, size_t align, HW_ALLOC_MODE allocMode, int a4)
	{
		return ReturnCallVMTFunc<void*, 14, cHeap*, size_t, size_t, HW_ALLOC_MODE, int>(this, size, align, allocMode, a4);
	}

	void dealloc(void* block, size_t size)
	{
		CallVMTFunc<15, cHeap*, void*, size_t>(this, block, size);
	}

	void *alloc(size_t size, size_t align, HW_ALLOC_MODE allocMode, int a3)
	{
		return ((void*(__thiscall*)(Hw::cHeap *, size_t, size_t, HW_ALLOC_MODE, int))(shared::base + 0x9D29B0))(this, size, align, allocMode, a3);
	}

	void setSubHeap(Hw::cHeap &rHeap)
	{
		((void(__thiscall *)(Hw::cHeap *, Hw::cHeap&))(shared::base + 0x9D2930))(this, rHeap);
	}

	void unsetSubHeap()
	{
		((void(__thiscall *)(Hw::cHeap *))(shared::base + 0x9D2940))(this);
	}
};

inline void *__cdecl operator new(size_t s, Hw::cHeap &rHeap) 
{
	return ((void*(__cdecl *)(size_t, Hw::cHeap &))(shared::base + 0x9D3500))(s, rHeap);
}

inline void __cdecl operator delete(void* block, Hw::cHeap *rHeap) // to separate the delete operator
{
	return ((void(__cdecl*)(void*, size_t))(shared::base + 0x9D48D0))(block, 0);
}

inline void *__cdecl operator new[](size_t s, Hw::cHeap& rHeap)
{
	return ((void*(__cdecl*)(size_t, Hw::cHeap&))(shared::base + 0x9D3580))(s, rHeap);
}

inline void __cdecl operator delete[](void *block, Hw::cHeap* rHeap) // to separate the delete[] operator
{
	return ((void(__cdecl*)(void*))(shared::base + 0x9D4940))(block);
}

// Usage after heap startup
inline void* __cdecl memAlloc(size_t s)
{
	return ((void* (__cdecl*)(size_t))(shared::base + 0x61E180))(s);
}

// Usage after heap startup
inline void __cdecl memDealloc(void* block)
{
	((void(__cdecl*)(void*))(shared::base + 0x61D3D0))(block);
}

class Hw::cHeapVariableBase : public Hw::cHeap
{
public:
	class cList
	{
	public:
		cList* m_pPrev;
		cList* m_pNext;
		void* m_pMemoryBlock;
		size_t m_MemorySize;
		cHeapVariableBase* m_pAllocator;
	};

	HANDLE m_hHeap;
	Hw::cHeapVariableBase::cList *m_pFirstList;
	Hw::cHeapVariableBase::cList *m_pLastList;
	size_t m_HeapSize;
	size_t m_RestSize;
	size_t m_ChildHeapSize;

	cHeapVariableBase()
	{
		((void(__thiscall*)(Hw::cHeapVariableBase*))(shared::base + 0x9D3AF0))(this);
	}
};

class Hw::cHeapVariable : public Hw::cHeapVariableBase
{
public:

	cHeapVariable()
	{
		((void(__thiscall*)(Hw::cHeapVariable*))(shared::base + 0x9D44F0))(this);
	}

	int create(size_t size, Hw::cHeap& rHeap, const char *pName)
	{
		return ReturnCallVMTFunc<int, 16, Hw::cHeapVariable*, size_t, Hw::cHeap&, const char*>(this, size, rHeap, pName);
	}

	int create(size_t size, size_t align, Hw::cHeap& rHeap, const char* pName)
	{
		return ReturnCallVMTFunc<int, 17, Hw::cHeapVariable*, size_t, size_t, Hw::cHeap&, const char*>(this, size, align, rHeap, pName);
	}
};

class Hw::cHeapPhysicalBase : public Hw::cHeap
{
public:
	class cList
	{
	public:
		cList* m_pPrevious;
		cList* m_pNext;
		size_t m_TotalSize;
		size_t m_Size;
		int field_10;
		int field_14;
		cHeapPhysicalBase* m_pAllocator;
	};
public:
	cList* m_pMainBlock;
	cList* m_pFirstBlock;
	cList *m_pLastBlock;
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

	cHeapPhysicalBase()
	{
		((void(__thiscall*)(Hw::cHeapPhysicalBase*))(shared::base + 0x9D3860))(this);
	}
};

class Hw::cHeapPhysical : public Hw::cHeapPhysicalBase
{
public:

	cHeapPhysical()
	{
		((void(__thiscall*)(Hw::cHeapPhysical*))(shared::base + 0x9D48F0))(this);
	}

	int create(size_t size, Hw::cHeap &rHeap, const char *name)
	{
		return ReturnCallVMTFunc<int, 17, Hw::cHeapPhysical*, size_t, Hw::cHeap&, const char*>(this, size, rHeap, name);
	}
};

class Hw::cHeapHook
{
public:

	cHeapHook()
	{
		((void(__thiscall *)(cHeapHook *))(shared::base + 0x9D32E0))(this);
	}

	virtual ~cHeapHook() {};
};

class Hw::cHeapFixed : public Hw::cHeap
{
public:
	struct cList 
	{
		cList *m_pPrevious;
		cList *m_pNext;
		cHeapFixed *m_pHeap;
	};
public:
	void* m_pAlloc;
	size_t m_HeapSize;
	size_t m_BlockSize;
	size_t m_BlockNum;
	size_t m_BlockAlign;
	size_t m_RestNum;
	Hw::cHeapFixed::cList *m_pFreeList;
	Hw::cHeapFixed::cList *m_pFirstList;

	cHeapFixed()
	{
		((void(__thiscall *)(Hw::cHeapFixed*))(shared::base + 0x9D36F0))(this);
	}

	BOOL create(size_t fixedSize, size_t allocAmount, size_t reservedSize, Hw::cHeap *creator, const char *name)
	{
		return ReturnCallVMTFunc<BOOL, 16, cHeapFixed*, size_t, size_t, size_t, Hw::cHeap *, const char*>(this, fixedSize, allocAmount, reservedSize, creator, name);
	}

	void* alloc()
	{
		return ((void* (__thiscall*)(Hw::cHeapFixed*))(shared::base + 0x9D2BC0))(this);
	}

	int canAlloc(size_t size, size_t num)
	{
		return ((int (__thiscall*)(Hw::cHeapFixed*, size_t, size_t))(shared::base + 0x9D2BA0))(this, size, num);
	}

	unsigned int getBlockMaxNum()
	{
		return ((unsigned int (__thiscall*)(Hw::cHeapFixed*))(shared::base + 0x9D2C80))(this);
	}

	unsigned int getBlockUsedNum()
	{
		return ((unsigned int (__thiscall*)(Hw::cHeapFixed*))(shared::base + 0x9D2C90))(this);
	}
};

class Hw::cHeapOneTime : public Hw::cHeap
{
public:
	struct cList
	{
		cList *m_pNext;
		cList *m_pPrev;
		void *m_pMemory;
		cHeapOneTime *m_pHeap;
	};

	void *m_pAlloc;
	int m_BlockSize;
	size_t m_HeapSize;
	int m_BlockRest;
	Hw::cHeapOneTime::cList *m_pFirstList;
	Hw::cHeapOneTime::cList *m_pLastList;
	int m_RestSize;

	cHeapOneTime()
	{
		((void(__thiscall *)(Hw::cHeapOneTime *))(shared::base + 0x9D3800))(this);
	}
};

class Hw::cHeapGlobal : public Hw::cHeapVariableBase
{
public:

	cHeapGlobal()
	{
		((void(__thiscall *)(cHeapGlobal *))(shared::base + 0x9D3F20))(this);
	}

	static inline cHeapGlobal* GetInstance() // -> return Hw::cHeapGlobal::ms_Instance.GetInstance();
	{
		return ((cHeapGlobal * (__cdecl*)())(shared::base + 0x61D830))();
	}

	BOOL create(size_t size, const char *target) // Got optimised away
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

	static inline cHeapGlobal &ms_Instance = *(cHeapGlobal*)(shared::base + 0x1783AF0); // Actually a singleton
};

class Hw::cShareHeapPhysical : public Hw::cHeapPhysical
{
public:
	cHeapPhysical *m_pShareHeap;

	cShareHeapPhysical()
	{
		((void(__thiscall *)(cShareHeapPhysical *))(shared::base + 0x9D4BD0))(this);
	}

	int create(Hw::cHeapPhysical &shareHeap, const char *name)
	{
		return ReturnCallVMTFunc<int, 18, cShareHeapPhysical*, Hw::cHeapPhysical&, const char*>(this, shareHeap, name);
	}

	int startupShareHeap()
	{
		return ReturnCallVMTFunc<int, 19, cShareHeapPhysical*>(this);
	}
};

template <typename tC, unsigned const align, typename tHeapBinder = Hw::cHeap>
class Hw::cFactory
{
public:
	class const_iterator
	{
	protected:
		tC *m_Ptr;

		cHeap *getHeapPtr()
		{
			return &m_Heap;
		}

		tC* getNextPtr()
		{
			return m_Heap.getNextAlloc(m_Ptr);
		}

	public:
		const_iterator(void *pPtr) : m_Ptr((tC*)pPtr) {}
		const_iterator(const const_iterator &other) : m_Ptr(other.m_Ptr) {}
		const_iterator() : m_Ptr(nullptr) {}

		const_iterator& operator++(int offset)
		{
			while (offset--)
				m_Ptr = getNextPtr();

			return *this;
		}

		const_iterator& operator++()
		{
			m_Ptr = getNextPtr();

			return *this;
		}

		bool operator==(const const_iterator &other) const
		{
			return m_Ptr == other.m_Ptr;
		}

		bool operator!=(const const_iterator &other) const
		{
			return m_Ptr != other.m_Ptr;
		}

		void operator=(const const_iterator &other)
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
		iterator(void *pPtr) : const_iterator(pPtr) {}
		iterator(const iterator &other) : const_iterator(other) {}
		iterator() : const_iterator() {}

		void operator=(const iterator &other)
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

	const const_iterator npos;
private:
	void *_pad01;
protected:
	tHeapBinder m_Heap;
public:

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

	void destroy()
	{
		if (!m_Heap.isValid())
			return;

		for (iterator it = begin(); it != end(); it++)
			operator delete(&(*it), &m_Heap);
	}

	iterator erase(iterator pos)
	{
		iterator next = pos;
		++next;
		operator delete(&(*pos), &m_Heap);
		return next;
	}

	unsigned int getSize()
	{
		return m_Heap.getSize();
	}

	unsigned int getUsedSize()
	{
		return m_Heap.getUsedSize();
	}

	unsigned int getAllocatableSize()
	{
		return m_Heap.getAllocatableSize();
	}

	tHeapBinder& getHeap()
	{
		return m_Heap;
	}
};

template <typename tC, unsigned const align>
class Hw::cFactoryVariable : public Hw::cFactory<tC, align, Hw::cHeapVariable>
{
public:
	cFactoryVariable() : Hw::cFactory<tC, align, Hw::cHeapVariable>() {}

	int create(size_t heapSize, Hw::cHeap &rHeap, const char *name = "FactoryVariable")
	{
		return this->m_Heap.create(heapSize, align, rHeap, name);
	}
};

template <typename tC, unsigned const align>
class Hw::cFactoryFixed : public Hw::cFactory<tC, align, Hw::cHeapFixed>
{
public:
	cFactoryFixed() : Hw::cFactory<tC, align, Hw::cHeapFixed>() {}

	int create(unsigned int count, Hw::cHeap &rHeap, const char *name = "FactoryFixed")
	{
		return this->m_Heap.create(sizeof(tC), count, align, rHeap, name);
	}

	int canAlloc(int num)
	{
		return this->m_Heap.canAlloc(sizeof(tC), num);
	}

	tC* newWork()
	{
		return (tC*)this->m_Heap.alloc();
	}

	cFactory::iterator newWorkIt()
	{
		return cFactory::iterator(this->m_Heap.alloc());
	}

	size_t getUsedNum()
	{
		return this->m_Heap.getBlockUsedNum();
	}

	size_t getMaxNum()
	{
		return this->m_Heap.getBlockMaxNum();
	}
};

struct Hw::FmergeHeader
{
    char magic[4];
    size_t m_nAmountOfFiles;
    size_t m_nPositionOffset;
    size_t m_nExtensionOffset;
    size_t m_nNamesOffset;
    size_t m_nSizesOffset;
    size_t m_nHashMapOffset;
};

class Hw::cFmerge
{
public:
	FmergeHeader* m_data;
	char *m_dds;

	cFmerge(char* data) : m_data((FmergeHeader*)data), m_dds(nullptr) {};

	cFmerge()
	{
		((void(__thiscall*)(Hw::cFmerge*))(shared::base + 0x9E3530))(this);
	}

	void *getDtt()
	{
		return ((void*(__thiscall *)(Hw::cFmerge*))(shared::base + 0x9E3550))(this);
	}

	void *getData()
	{
		return ((void*(__thiscall *)(Hw::cFmerge*))(shared::base + 0x9E3560))(this);
	}

	void setData(void *data, int index)
	{
		((void(__thiscall *)(Hw::cFmerge*, void*, int))(shared::base + 0x9E3570))(this, data, index);
	}

	void *getDataAt(int index)
	{
		return ((void*(__thiscall *)(Hw::cFmerge*, int))(shared::base + 0x9E3580))(this, index);
	}

	size_t getFileAmount()
	{
		return ((size_t(__thiscall *)(Hw::cFmerge*))(shared::base + 0x9E3590))(this);
	}

	size_t getFileIndexSize(size_t fileIndex)
	{
		return ((size_t(__thiscall *)(Hw::cFmerge*, size_t))(shared::base + 0x9E3670))(this, fileIndex);
	}

	const char *getFileIndexFileName(size_t fileIndex)
	{
		return ((const char*(__thiscall *)(Hw::cFmerge *, size_t))(shared::base + 0x9E38D0))(this, fileIndex);
	}

	BOOL getFileIndexExtension(char *pExt, size_t fileIndex)
	{
		return ((BOOL(__thiscall *)(Hw::cFmerge*, char *, size_t))(shared::base + 0x9E3C20))(this, pExt, fileIndex);
	}

	void *getIndexFileData(size_t fileIndex)
	{
		return ((void*(__thiscall *)(Hw::cFmerge*, size_t))(shared::base + 0x9E3CF0))(this, fileIndex);
	}

	size_t getFileIndexSize(size_t fileIndex)
	{
		return ((size_t(__thiscall *)(Hw::cFmerge*, size_t))(shared::base + 0x9E3EE0))(this, fileIndex);
	}

	size_t getExtensionFileIndex(const char* ext, unsigned int no)
	{
		return ((size_t(__thiscall *)(Hw::cFmerge *, const char *, unsigned int))(shared::base + 0x9E3F20))(this, ext, no);
	}

	size_t getFileNameIndexI(const char *name)
	{
		return ((size_t(__thiscall *)(Hw::cFmerge *, const char*))(shared::base + 0x9E3FD0))(this, name);
	}

	size_t getSubStrFileIndex(const char *name, unsigned int matchLimit)
	{
		return ((size_t(__thiscall *)(Hw::cFmerge *, const char *, unsigned int))(shared::base + 0x9E4130))(this, name, matchLimit);
	}

	void* getExtensionFileData(const char *name, unsigned int matchLimit)
	{
		return ((void*(__thiscall *)(Hw::cFmerge*, const char *, unsigned int))(shared::base + 0x9E44B0))(this, name, matchLimit);
	}
	
	void* getFileNameData(const char *name)
	{
		return ((void*(__thiscall *)(Hw::cFmerge *, const char *))(shared::base + 0x9E4500))(this, name);
	}

	void *getFileNameData(const char *name, unsigned int no)
	{
		return ((void*(__thiscall *)(Hw::cFmerge*, const char*, unsigned int))(shared::base + 0x9E4550))(this, name, no);
	}

	size_t getFileNameSize(const char *name, unsigned int no)
	{
		return ((size_t(__thiscall *)(Hw::cFmerge *, const char *, unsigned int))(shared::base + 0x9E46D0))(this, name, no);
	}

	operator bool()
	{
		return m_data != nullptr;
	}

	void setData(char *data, char *dds = nullptr)
	{
		((void(__thiscall *)(Hw::cFmerge*, char*, char*))(shared::base + 0x9E3540))(this, data, dds);
	}
};

enum Hw::KEYBOARD_MAP
{
    KB_SPACE=32,
    KB_A=65,
    KB_B=66,
    KB_C=67,
    KB_D=68,
    KB_E=69,
    KB_F=70,
    KB_G=71,
    KB_H=72,
    KB_I=73,
    KB_J=74,
    KB_K=75,
    KB_L=76,
    KB_M=77,
    KB_N=78,
    KB_O=79,
    KB_P=80,
    KB_Q=81,
    KB_R=82,
    KB_S=83,
    KB_T=84,
    KB_U=85,
    KB_V=86,
    KB_W=87,
    KB_X=88,
    KB_Y=89,
    KB_Z=90,
    KB_0=48,
    KB_1=49,
    KB_2=50,
    KB_3=51,
    KB_4=52,
    KB_5=53,
    KB_6=54,
    KB_7=55,
    KB_8=56,
    KB_9=57,
    KB_MINUS=45,
    KB_EQ=61,
    KB_BRAC_L=91,
    KB_BRAC_R=93,
    KB_PERIOD=46,
    KB_APOS=39,
    KB_SLASH=47,
    KB_COMMA=44,
    KB_SEMICOLON=59,
    KB_GRAVE=96,
    KB_COLON=58,
    KB_AT=64,
    KB_YEN=92,
    KB_CIRCUMFLEX=94,
    KB_RET=10,
    KB_TAB=9,
    KB_BS=8,
    KB_F1=128,
    KB_F2=129,
    KB_F3=130,
    KB_F4=131,
    KB_F5=132,
    KB_F6=133,
    KB_F7=134,
    KB_F8=135,
    KB_F9=136,
    KB_F10=137,
    KB_F11=138,
    KB_F12=139,
    KB_DN=140,
    KB_LT=141,
    KB_RT=142,
    KB_UP=143,
    KB_CAP=144,
    KB_ESC=145,
    KB_INS=146,
    KB_DEL=147,
    KB_HOME=148,
    KB_END=149,
    KB_PAGE_UP=150,
    KB_PAGE_DN=151,
    KB_SYSRQ=152,
    KB_SCRLOCK=153,
    KB_PAUSE=154,
    KB_CTRL_L=155,
    KB_CTRL_R=156,
    KB_ALT_L=157,
    KB_ALT_R=158,
    KB_SHIFT_L=159,
    KB_SHIFT_R=160,
    KB_WIN_L=161,
    KB_WIN_R=162,
    KB_APPS=163,
    KB_BACKSLASH=164,
    KB_NUMLOCK=165,
    KB_NUM0=166,
    KB_NUM1=167,
    KB_NUM2=168,
    KB_NUM3=169,
    KB_NUM4=170,
    KB_NUM5=171,
    KB_NUM6=172,
    KB_NUM7=173,
    KB_NUM8=174,
    KB_NUM9=175,
    KB_NUM_ADD=176,
    KB_NUM_SUB=177,
    KB_NUM_DEC=178,
    KB_NUM_DIV=179,
    KB_NUM_MUL=180,
    KB_NUM_ENT=181,
    KB_MAP_MAX=182,
    KB_MAP_INVALID=183
};

class Hw::cKeyboardState
{
public:
	enum { KB_MAP_FLAG_SIZE=6 };
public:
	unsigned int m_pOn[KB_MAP_FLAG_SIZE];
	unsigned int m_pTrig[KB_MAP_FLAG_SIZE];
	unsigned int m_pRel[KB_MAP_FLAG_SIZE];
	unsigned int m_pRep[KB_MAP_FLAG_SIZE];
	unsigned int m_pOld[KB_MAP_FLAG_SIZE];
	int m_RepCount;

	BOOL on(KEYBOARD_MAP vKey)
	{
		return ((BOOL(__thiscall*)(cKeyboardState*, KEYBOARD_MAP))(shared::base + 0x9D93A0))(this, vKey);
	}

	BOOL on(char vKey) // unused
	{
		return ((BOOL(__thiscall*)(cKeyboardState*, char))(shared::base + 0x9D93D0))(this, vKey);
	}

	BOOL trig(KEYBOARD_MAP vKey)
	{
		return ((BOOL(__thiscall*)(cKeyboardState*, KEYBOARD_MAP))(shared::base + 0x9D9400))(this, vKey);
	}

	BOOL trig(char vKey) // unused
	{
		return ((BOOL(__thiscall*)(cKeyboardState*, char))(shared::base + 0x9D9430))(this, vKey);
	}

	BOOL rel(KEYBOARD_MAP vKey)
	{
		return ((BOOL(__thiscall*)(cKeyboardState*, KEYBOARD_MAP))(shared::base + 0x9D9460))(this, vKey);
	}

	BOOL rel(char vKey) // unused
	{
		return ((BOOL(__thiscall*)(cKeyboardState*, char))(shared::base + 0x9D9490))(this, vKey);
	}

	BOOL rep(KEYBOARD_MAP vKey)
	{
		return ((BOOL(__thiscall*)(cKeyboardState*, KEYBOARD_MAP))(shared::base + 0x9D94C0))(this, vKey);
	}

	BOOL rep(char vKey) // unused
	{
		return ((BOOL(__thiscall*)(cKeyboardState*, char))(shared::base + 0x9D94F0))(this, vKey);
	}

	void setOn(KEYBOARD_MAP vKey, BOOL bDown)
	{
		((void(__thiscall*)(cKeyboardState*, KEYBOARD_MAP, BOOL))(shared::base + 0x9D9620))(this, vKey, bDown);
	}

	void setTrig(KEYBOARD_MAP vKey)
	{
		((void(__thiscall*)(cKeyboardState*, KEYBOARD_MAP))(shared::base + 0x9D9650))(this, vKey);
	}
};

class Hw::KeyboardManagerBase
{
public:
	static inline int m_RepeatWait = *(int*)(shared::base + 0x14CD830);
	static inline int m_RepeatCycle = *(int*)(shared::base + 0x14CD834);

	static inline void InitState(cKeyboardState& rState)
	{
		((void(__cdecl*)(cKeyboardState&))(shared::base + 0x9DA4A0))(rState);
	}

	static inline int UpdateStateOnToOld(cKeyboardState& rState)
	{
		return ((int(__cdecl*)(cKeyboardState&))(shared::base + 0x9DA4C0))(rState);
	}
};

class Hw::KeyboardManager : public Hw::KeyboardManagerBase
{
public:
	enum{ MAX_KEY_MAP_FLAG=256 };

	static inline int UpdateKeyState(cKeyboardState& rState)
	{
		return ((int(__cdecl*)(cKeyboardState&))(shared::base + 0x9DA500))(rState);
	}

	static inline int UpdateState(cKeyboardState& rState)
	{
		return ((int(__cdecl*)(cKeyboardState&))(shared::base + 0x9DA710))(rState);
	}
};

class Hw::cUcol
{
public:
	unsigned int r, g, b, a;

	cUcol(unsigned int color = 0) 
	{
		r = (color >> 16) & 0xFF;
		g = (color >> 8) & 0xFF;
		b = color & 0xFF;
		a = (color >> 24) & 0xFF;
	}

	cUcol(const cFcol& fcol);
	cUcol(unsigned int r, unsigned int g, unsigned int b, unsigned int a) : r(r), g(g), b(b), a(a) {}

	void setRGBAU(unsigned int r, unsigned int g, unsigned int b, unsigned int a) 
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	void setRGBAF(float r, float g, float b, float a)
	{
		this->r = r * 255;
	}

	operator unsigned int() const 
	{
		return (a << 24) | (r << 16) | (g << 8) | b;
	}

	cUcol& operator=(unsigned int color) 
	{
		r = (color >> 16) & 0xFF;
		g = (color >> 8) & 0xFF;
		b = color & 0xFF;
		a = (color >> 24) & 0xFF;

		return *this;
	}

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
	cFcol(unsigned int color) 
	{
		r = ((color >> 16) & 0xFF) / 255.0f;
		g = ((color >> 8) & 0xFF) / 255.0f;
		b = (color & 0xFF) / 255.0f;
		a = ((color >> 24) & 0xFF) / 255.0f;
	}

	void setRGBAF(float r, float g, float b, float a) 
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	void setRGBAU(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
	{
		this->r = (float)r / 255.f;
		this->g = (float)g / 255.f;
		this->b = (float)b / 255.f;
		this->a = (float)a / 255.f;
	}

	operator unsigned int() const 
	{
		return ((unsigned int)(a * 255) << 24) | ((unsigned int)(r * 255) << 16)
			| ((unsigned int)(g * 255) << 8) | (unsigned int)(b * 255);
	}

	cFcol& operator=(unsigned int color) 
	{
		r = ((color >> 16) & 0xFF) / 255.0f;
		g = ((color >> 8) & 0xFF) / 255.0f;
		b = (color & 0xFF) / 255.0f;
		a = ((color >> 24) & 0xFF) / 255.0f;

		return *this;
	}

	cFcol& operator=(const cUcol& ucol);

	cFcol operator+(const cUcol& ucol) const;
	cFcol operator-(const cUcol& ucol) const;
	cFcol operator*(const cUcol& ucol) const;
	cFcol operator/(const cUcol& ucol) const;

	bool operator==(const cUcol& ucol) const;
	bool operator!=(const cUcol& ucol) const;
};

Hw::cUcol::cUcol(const cFcol& fcol) 
{
	r = (unsigned int)(int)(fcol.r * 255.0f);
	g = (unsigned int)(int)(fcol.g * 255.0f);
	b = (unsigned int)(int)(fcol.b * 255.0f);
	a = (unsigned int)(int)(fcol.a * 255.0f);
}

Hw::cFcol::cFcol(const cUcol& ucol) 
{
	r = ucol.r / 255.0f;
	g = ucol.g / 255.0f;
	b = ucol.b / 255.0f;
	a = ucol.a / 255.0f;
}

Hw::cFcol &Hw::cFcol::operator=(const cUcol& ucol)
{
	setRGBAU(ucol.r, ucol.g, ucol.b, ucol.a);

	return *this;
}

Hw::cUcol &Hw::cUcol::operator=(const cFcol &fcol)
{
	setRGBAF(fcol.r, fcol.g, fcol.b, fcol.a);

	return *this;
}

Hw::cUcol Hw::cUcol::operator+(const cFcol& fcol) const 
{
	return cUcol(
		min(255, r + (unsigned int)(fcol.r * 255)),
		min(255, g + (unsigned int)(fcol.g * 255)),
		min(255, b + (unsigned int)(fcol.b * 255)),
		min(255, a + (unsigned int)(fcol.a * 255))
	);
}

Hw::cUcol Hw::cUcol::operator-(const cFcol& fcol) const 
{
	return cUcol(
		max(0, r - (unsigned int)(fcol.r * 255)),
		max(0, g - (unsigned int)(fcol.g * 255)),
		max(0, b - (unsigned int)(fcol.b * 255)),
		max(0, a - (unsigned int)(fcol.a * 255))
	);
}

Hw::cUcol Hw::cUcol::operator*(const cFcol& fcol) const 
{
	return cUcol(
		min(255, (int)(r * fcol.r)),
		min(255, (int)(g * fcol.g)),
		min(255, (int)(b * fcol.b)),
		min(255, (int)(a * fcol.a))
	);
}

Hw::cUcol Hw::cUcol::operator/(const cFcol& fcol) const 
{
	return cUcol(
		min(255, r / max(fcol.r, 1e-6f)),
		min(255, g / max(fcol.g, 1e-6f)),
		min(255, b / max(fcol.b, 1e-6f)),
		min(255, a / max(fcol.a, 1e-6f))
	);
}

bool Hw::cUcol::operator==(const cFcol& fcol) const 
{
	return r == (unsigned int)(fcol.r * 255) &&
		g == (unsigned int)(fcol.g * 255) &&
		b == (unsigned int)(fcol.b * 255) &&
		a == (unsigned int)(fcol.a * 255);
}

bool Hw::cUcol::operator!=(const cFcol& fcol) const 
{
	return !(*this == fcol);
}

Hw::cFcol Hw::cFcol::operator+(const cUcol& ucol) const 
{
	return cFcol(
		r + ucol.r / 255.0f,
		g + ucol.g / 255.0f,
		b + ucol.b / 255.0f,
		a + ucol.a / 255.0f
	);
}

Hw::cFcol Hw::cFcol::operator-(const cUcol& ucol) const 
{
	return cFcol(
		r - ucol.r / 255.0f,
		g - ucol.g / 255.0f,
		b - ucol.b / 255.0f,
		a - ucol.a / 255.0f
	);
}

Hw::cFcol Hw::cFcol::operator*(const cUcol& ucol) const 
{
	return cFcol(
		r * ucol.r / 255.0f,
		g * ucol.g / 255.0f,
		b * ucol.b / 255.0f,
		a * ucol.a / 255.0f
	);
}

Hw::cFcol Hw::cFcol::operator/(const cUcol& ucol) const 
{
	return cFcol(
		r / max(ucol.r, 1u) / 255.0f,
		g / max(ucol.g, 1u) / 255.0f,
		b / max(ucol.b, 1u) / 255.0f,
		a / max(ucol.a, 1u) / 255.0f
	);
}

bool Hw::cFcol::operator==(const cUcol& ucol) const
{
	return fabs(r - ucol.r / 255.0f) < 1e-6f &&
		fabs(g - ucol.g / 255.0f) < 1e-6f &&
		fabs(b - ucol.b / 255.0f) < 1e-6f &&
		fabs(a - ucol.a / 255.0f) < 1e-6f;
};

bool Hw::cFcol::operator!=(const cUcol& ucol) const 
{
	return !(*this == ucol);
}

class Hw::cRand
{
private:
	unsigned int m_nSeed;
public:
	cRand()
	{
		((void(__thiscall *)(cRand *))(shared::base + 0x9DBBB0))(this);
	}

	~cRand()
	{
		((void(__thiscall *)(cRand *))(shared::base + 0x9DBBC0))(this);
	}

	void setSeed(unsigned int seed)
	{
		((void(__thiscall*)(cRand*, unsigned int))(shared::base + 0x9DBBD0))(this, seed);
	}

	unsigned int getSeed()
	{
		return ((unsigned int(__thiscall *)(cRand *))(shared::base + 0x9DBBE0))(this);
	}

	unsigned short rollU16()
	{
		return ((unsigned short(__thiscall *)(cRand*))(shared::base + 0x9DBBF0))(this);
	}

	unsigned int rollU32()
	{
		return ((unsigned int(__thiscall *)(cRand*))(shared::base + 0x9DBC10))(this);
	}

	void initSeed()
	{
		((void(__thiscall *)(cRand*))(shared::base + 0x9DE290))(this);
	}

	unsigned short getU16(unsigned short min, unsigned short max)
	{
		return ((unsigned short(__thiscall*)(cRand*, unsigned short, unsigned short))(shared::base + 0x9DE2A0))(this, min, max);
	}

	short getS16(short min, short max)
	{
		return ((int(__thiscall*)(cRand*, int, int))(shared::base + 0x9DE2D0))(this, min, max);
	}

	float getF32(float min, float max)
	{
		return ((float(__thiscall*)(cRand*, float, float))(shared::base + 0x9DE300))(this, min, max);
	}
};

class Hw::cSemaphore
{
public:
	HANDLE m_hSemaphore;

	cSemaphore()
	{
		((void(__thiscall *)(cSemaphore*))(shared::base + 0x9D7360))(this);
	}
		
	BOOL startup(long init_count, long max_count)
	{
		return ((BOOL(__thiscall *)(cSemaphore *, long, long))(shared::base + 0x9D7370))(this, init_count, max_count);
	}

	void cleanup()
	{
		((void(__thiscall *)(cSemaphore*))(shared::base + 0x9D73B0))(this);
	}
	
	void hold()
	{
		((void(__thiscall *)(cSemaphore *))(shared::base + 0x9D73D0))(this);
	}

	void release()
	{
		((void(__thiscall *)(cSemaphore *))(shared::base + 0x9D73E0))(this);
	}
};

class Hw::cCriticalSection
{
public:
	RTL_CRITICAL_SECTION m_critsection;
	BOOL m_bInit;

	cCriticalSection()
	{
		this->m_bInit = FALSE;
	}

	BOOL startup()
	{
		return ((BOOL(__thiscall*)(cCriticalSection*))(shared::base + 0x9D7240))(this);
	}

	void enter()
	{
		((void(__thiscall *)(cCriticalSection*))(shared::base + 0xA6C0))(this);
	}

	void leave()
	{
		((void(__thiscall *)(cCriticalSection*))(shared::base + 0xA6D0))(this);
	}

	void cleanup()
	{
		((void(__thiscall*)(cCriticalSection*))(shared::base + 0x9D7270))(this);
	}
};

template <typename tC>
class Hw::cSingleton
{
private:
	// static inline tC m_instance; // it doesn't work like this, but we can't do it either way
	// static inline BOOL m_wasInitialized = FALSE; // C++11 versions create a guard near the static variable, so this member here is pointless

	cSingleton() {};
public:

	// remove copy, move and assign copy operators

	cSingleton(const cSingleton<tC> &) = delete;
	cSingleton(cSingleton<tC> &&) = delete;
	cSingleton<tC> &operator=(const cSingleton<tC> &) = delete;

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

	cVec2()
	{
		x = 0.f;
		y = 0.f;
	}

	cVec2(float x, float y) : x(x), y(y) {}

	void operator=(const cVec2& lhs)
	{
		x = lhs.x;
		y = lhs.y;
	}

	cVec2 operator+(const cVec2& lhs) const
	{
		return cVec2(x + lhs.x, y + lhs.y);
	}

	cVec2& operator+=(const cVec2& lhs)
	{
		x += lhs.x;
		y += lhs.y;
		return *this;
	}

	cVec2 operator-(const cVec2& lhs) const
	{
		return cVec2(x - lhs.x, y - lhs.y);
	}

	cVec2& operator-=(const cVec2& lhs)
	{
		x -= lhs.x;
		y -= lhs.y;
		return *this;
	}

	cVec2 operator*(float scale) const
	{
		return cVec2(x * scale, y * scale);
	}

	cVec2 operator*(const cVec2& lhs) const
	{
		return cVec2(x * lhs.x, y * lhs.y);
	}

	cVec2& operator*=(float scale)
	{
		x *= scale;
		y *= scale;
		return *this;
	}

	cVec2& operator*=(const cVec2& lhs)
	{
		x *= lhs.x;
		y *= lhs.y;
		return *this;
	}

	cVec2 operator/(float scale) const
	{
		return cVec2(x / scale, y / scale);
	}

	cVec2 operator/(const cVec2& lhs) const
	{
		return cVec2(x / lhs.x, y / lhs.y);
	}

	cVec2& operator/=(float scale)
	{
		x /= scale;
		y /= scale;
		return *this;
	}

	cVec2& operator/=(const cVec2& lhs)
	{
		x /= lhs.x;
		y /= lhs.y;
		return *this;
	}

	float length()
	{
		return sqrtf(powf(x, 2) + powf(y, 2));
	}

	cVec2 Normalize()
	{
		float length = this->length();
		return cVec2(x / length, y / length);
	}

	bool operator==(const cVec2& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	bool operator!=(const cVec2& rhs) const
	{
		return !(*this == rhs);
	}

	float dot(const cVec2& lhs) const 
	{
		return x * lhs.x + y * lhs.y;
	}
};

class Hw::cVec3
{
public:
	float x, y, z;

	cVec3()
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}

	cVec3(float x, float y, float z) : x(x), y(y), z(z) {}

	void operator=(const cVec3& lhs)
	{
		x = lhs.x;
		y = lhs.y;
		z = lhs.z;
	}

	cVec3 operator+(const cVec3& lhs) const
	{
		return cVec3(x + lhs.x, y + lhs.y, z + lhs.z);
	}

	cVec3& operator+=(const cVec3& lhs)
	{
		x += lhs.x;
		y += lhs.y;
		z += lhs.z;
		return *this;
	}

	cVec3 operator-(const cVec3& lhs) const
	{
		return cVec3(x - lhs.x, y - lhs.y, z - lhs.z);
	}

	cVec3& operator-=(const cVec3& lhs)
	{
		x -= lhs.x;
		y -= lhs.y;
		z -= lhs.z;
		return *this;
	}

	cVec3 operator*(float scale) const
	{
		return cVec3(x * scale, y * scale, z * scale);
	}

	cVec3 operator*(const cVec3& lhs) const
	{
		return cVec3(x * lhs.x, y * lhs.y, z * lhs.z);
	}

	cVec3& operator*=(float scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
		return *this;
	}

	cVec3& operator*=(const cVec3& lhs)
	{
		x *= lhs.x;
		y *= lhs.y;
		z *= lhs.z;
		return *this;
	}

	cVec3 operator/(float scale) const
	{
		return cVec3(x / scale, y / scale, z / scale);
	}

	cVec3 operator/(const cVec3& lhs) const
	{
		return cVec3(x / lhs.x, y / lhs.y, z / lhs.z);
	}

	cVec3& operator/=(float scale)
	{
		x /= scale;
		y /= scale;
		z /= scale;
		return *this;
	}

	cVec3& operator/=(const cVec3& lhs)
	{
		x /= lhs.x;
		y /= lhs.y;
		z /= lhs.z;
		return *this;
	}

	float length()
	{
		return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
	}

	float length2D()
	{
		return sqrtf(powf(x, 2) + powf(z, 2));
	}

	cVec3 Normalize()
	{
		float length = this->length();
		return cVec3(x / length, y / length, z / length);
	}

	bool operator==(const cVec3& rhs) const
	{
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}

	bool operator!=(const cVec3& rhs) const
	{
		return !(*this == rhs);
	}

	float dot(const cVec3& lhs) const 
	{
		return x * lhs.x + y * lhs.y + z * lhs.z;
	}

	cVec3 cross(const cVec3& lhs) const 
	{
		return cVec3(
			y * lhs.z - z * lhs.y,
			z * lhs.x - x * lhs.z,
			x * lhs.y - y * lhs.x
		);
	}
};

class Hw::cVec4
{
public:
	float x, y, z, w;

	void operator=(const cVec4& right)
	{
		this->x = right.x;
		this->y = right.y;
		this->z = right.z;
		this->w = right.w;
	}

	cVec4()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 1.f;
	}

	cVec4(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w)
	{
	};

	float length()
	{
		return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
	}

	float length2D()
	{
		return sqrtf(powf(x, 2) + powf(z, 2));
	}

	cVec4 operator+(const cVec4& rhs) const
	{
		return cVec4(x + rhs.x, y + rhs.y, z + rhs.z, 1.0f);
	}

	cVec4& operator+=(const cVec4& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	cVec4 operator-(const cVec4& rhs) const
	{
		return cVec4(x - rhs.x, y - rhs.y, z - rhs.z, w);
	}

	cVec4& operator-=(const cVec4& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	cVec4 operator*(float scale) const
	{
		return cVec4(x * scale, y * scale, z * scale, w);
	}

	cVec4 operator*(const cVec4& rhs) const
	{
		return cVec4(x * rhs.x, y * rhs.y, z * rhs.z, w);
	}

	cVec4& operator*=(float scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
		return *this;
	}

	cVec4& operator*=(const cVec4& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	cVec4 operator/(float scale) const
	{
		return cVec4(x / scale, y / scale, z / scale, w);
	}

	cVec4 operator/(const cVec4& rhs) const
	{
		return cVec4(x / rhs.x, y / rhs.y, z / rhs.z, w);
	}

	cVec4& operator/=(float scale)
	{
		x /= scale;
		y /= scale;
		z /= scale;
		return *this;
	}

	cVec4& operator/=(const cVec4& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}

	bool operator==(const cVec4& rhs) const
	{
		return x == rhs.x && y == rhs.y && z == rhs.z; // && w == rhs.w; <-- I'm not sure about using w here
	}

	bool operator!=(const cVec4& rhs) const
	{
		return !(*this == rhs);
	}
	
	cVec4 Normalize()
	{
		float length = this->length();
		return cVec4(x / length, y / length, z / length, w);
	}

	float dot(const cVec4& lhs) const 
	{
		return x * lhs.x + y * lhs.y + z * lhs.z + w * lhs.w;
	}

	cVec4 cross(const cVec4& lhs) const 
	{
		return cVec4(
			y * lhs.z - z * lhs.y,
			z * lhs.x - x * lhs.z,
			x * lhs.y - y * lhs.x,
			1.0f
		);
	}
};

struct Hw::cQuat
{
	float x;
	float y;
	float z;
	float w;

	cQuat(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w) {};
	cQuat() { x = 0.f; y = 0.f; z = 0.f; w = 1.f; };

	static inline void Multiply(cQuat &out, const cVec4& rotation)
	{
		((void(__cdecl*)(cQuat&, const cVec4&))(shared::base + 0x9DB590))(out, rotation);
	}
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

	D3DXMATRIX& toDxMtx()
	{
		return *(D3DXMATRIX*)this;
	}

	D3DXMATRIX& toDxMtx() const
	{
		return *(D3DXMATRIX*)this;
	}

	cMtx& operator=(const cMtx& other)
	{
		r[0] = other.r[0];
		r[1] = other.r[1];
		r[2] = other.r[2];
		r[3] = other.r[3];

		return *this;
	}
};

VALIDATE_SIZE(Hw::cMtx, 0x40);

class Hw::cJobManager
{
public:
	class cWork
	{
	public:
		cJobManager* m_Owner;
		int m_nThreadIndex;
		HANDLE m_hSemaphore;
		HANDLE m_hTask;
		void(__cdecl *m_func)(LPVOID reserved, void *arg);
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

	cJobManager()
	{
		((void(__thiscall*)(cJobManager*))(shared::base + 0x9D6F30))(this);
	}

	~cJobManager()
	{
		((void(__thiscall*)(cJobManager*))(shared::base + 0x9D8B60))(this);
	}

	int shutdown()
	{
		return ((int(__thiscall*)(cJobManager*))(shared::base + 0x9D8860))(this);
	}

	unsigned int getCurrentThreadId()
	{
		return ((unsigned int(__thiscall*)(cJobManager*))(shared::base + 0x9D7AD0))(this);
	}

	void setJobFunction(void(__cdecl* function)(LPVOID reserved, LPVOID parameter), LPVOID parameter, unsigned int jobIndex)
	{
		((void(__thiscall*)(cJobManager*, void(__cdecl*)(LPVOID, LPVOID), LPVOID, unsigned int))(shared::base + 0x9D75D0))(this, function, parameter, jobIndex);
	}

	BOOL startup(size_t jobAmount, int* threadIndices, Hw::cHeap* allocator, void* a5, void* a6, const char** threadNames, int a8)
	{
		return ((BOOL(__thiscall*)(cJobManager*, size_t, int*, Hw::cHeap*, void*, void*, const char**, int))(shared::base + 0x9D8B70))(this, jobAmount, threadIndices, allocator, a5, a6, threadNames, a8);
	}

	void activate(unsigned int jobs)
	{
		((void(__thiscall*)(cJobManager*, unsigned int))(shared::base + 0x9D79A0))(this, jobs);
	}
};

class Hw::cTaskManager
{
public:
	class cWork;

	int m_nWorkNum;
	cWork *m_pWorkBuff;
	cWork *m_pActiveWorkList;
	cWork *m_pUnusingWorkList;
	cWork *m_pCurrentWork;
	int m_nRotateTaskId;
	cTaskManager *m_pPrevTaskManager;

	cTaskManager()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D6DF0))(this);
	}

	cWork *newWork(int task_prio)
	{
		return ((cWork*(__thiscall *)(cTaskManager*, int))(shared::base + 0x9D7420))(this, task_prio);
	}

	void deleteWork(cWork *pWork)
	{
		((void(__thiscall *)(cTaskManager*, cWork *))(shared::base + 0x9D74A0))(this, pWork);
	}

	eTaskId getCurrentId()
	{
		return ((eTaskId(__thiscall *)(cTaskManager*))(shared::base + 0x9D7500))(this);
	}
	
	void execute(void(__cdecl *rFunc)(LPVOID parameter), LPVOID pParam, int task_prio, const char* task_name)
	{
		((void(__thiscall*)(cTaskManager*, void(__cdecl *)(LPVOID), LPVOID, int, const char*))(shared::base + 0x9D7870))(this, rFunc, pParam, task_prio, task_name);
	}

	void killWork(cWork *pWork)
	{
		((void(__thiscall *)(cTaskManager *, cWork*))(shared::base + 0x9D7F40))(this, pWork);
	}

	void cleanup()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D8450))(this);
	}

	void sleep(int count)
	{
		((void(__thiscall*)(cTaskManager*, int))(shared::base + 0x9D8570))(this, count);
	}

	~cTaskManager()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D8A00))(this);
	}

	BOOL startup(unsigned int taskCapacity, unsigned int taskStackSize, Hw::cHeapVariable* allocator)
	{
		return ((BOOL(__thiscall*)(cTaskManager*, unsigned int, unsigned int, Hw::cHeapVariable*))(shared::base + 0x9D8A10))(this, taskCapacity, taskStackSize, allocator);
	}

	void update()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D8DA0))(this);
	}

	static inline void chain(void(__cdecl *rFunc)(LPVOID), LPVOID pParam)
	{
		((void(__cdecl *)(void(__cdecl* )(LPVOID), LPVOID))(shared::base + 0x9D8950))(rFunc, pParam);
	}

	static inline cTaskManager *getCurrentManager()
	{
		return ((cTaskManager*(__cdecl *)())(shared::base + 0x9D6E10))();
	}

	static inline void setCurrentManager(cTaskManager *pManager)
	{
		((void(__cdecl *)(cTaskManager *))(shared::base + 0x9D6E20))(pManager);
	}

	static inline cTaskManager *&m_pCurrentTaskManager = *(cTaskManager**)(shared::base + 0x19D0564); // private: static class
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

	Hw::cTaskManager *m_pManager;
	void (__cdecl *m_pFunc)(void *);
	void *m_pParam;
	eTaskId m_TaskId;
	int m_nTaskPrio;
	const char *m_TaskName;
	eStatus m_Status;
	int m_nSleepCount;
	int m_nTaskStackSize;
	cSemaphore m_SyncTaskStart;
	cSemaphore m_SyncTaskStop;
	cWork *m_pPrev;
	cWork *m_pNext;
	void (__cdecl *m_pTaskReport)(eStatus);

	void execute(void(__cdecl *rFunc)(LPVOID), LPVOID pParam, const char* task_name, eTaskId task_id)
	{
		((void(__thiscall *)(cWork*, void(__cdecl *)(LPVOID), LPVOID, const char*, eTaskId))(shared::base + 0x9D6E30))(this, rFunc, pParam, task_name, task_id);
	}

	void setTaskReport(void(__cdecl *rFunc)(eStatus))
	{
		((void(__thiscall *)(cWork *, void(__cdecl*)(eStatus)))(shared::base + 0x9D6E70))(this, rFunc);
	}

	BOOL isExit()
	{
		return ((BOOL(__thiscall *)(cWork*))(shared::base + 0x9D6E80))(this);
	}

	eTaskId getTaskId()
	{
		return ((eTaskId(__thiscall *)(cWork*))(shared::base + 0x9D6E90))(this);
	}

	const char *getTaskName()
	{
		return ((const char*(__thiscall *)(cWork*))(shared::base + 0x9D6EA0))(this);
	}

	int getTaskPrio()
	{
		return ((int(__thiscall *)(cWork*))(shared::base + 0x9D6EB0))(this);
	}

	void setTaskPrio(int task_prio)
	{
		((void(__thiscall *)(cWork*, int))(shared::base + 0x9D6EC0))(this, task_prio);
	}

	void chainWork(cWork *pPrev, cWork *pNext)
	{
		((void(__thiscall *)(cWork*, cWork*, cWork*))(shared::base + 0x9D6ED0))(this, pPrev, pNext);
	}

	void unchainWork()
	{
		((void(__thiscall *)(cWork*))(shared::base + 0x9D6EF0))(this);
	}

	cWork *getNextWork()
	{
		return ((cWork*(__thiscall *)(cWork*))(shared::base + 0x9D6F20))(this);
	}

	BOOL startup(unsigned int stack_size, /* unused */ int __formal, cTaskManager* pManager)
	{
		return ((BOOL(__thiscall *)(cWork *, unsigned int, int, cTaskManager*))(shared::base + 0x9D7540))(this, stack_size, __formal, pManager);
	}

	void waitTaskStart()
	{
		((void(__thiscall *)(cWork *))(shared::base + 0x9D7590))(this);
	}

	void sendTaskStart()
	{
		((void(__thiscall *)(cWork *))(shared::base + 0x9D75A0))(this);
	}

	void waitTaskStop()
	{
		((void(__thiscall *)(cWork*))(shared::base + 0x9D75B0))(this);
	}

	void sendTaskStop()
	{
		((void(__thiscall *)(cWork*))(shared::base + 0x9D75C0))(this);
	}

	void updateSleep()
	{
		((void(__thiscall *)(cWork*))(shared::base + 0x9D7910))(this);
	}

	void kill()
	{
		((void(__thiscall *)(cWork *))(shared::base + 0x9D7950))(this);
	}

	void cleanup()
	{
		((void(__thiscall*)(cWork*))(shared::base + 0x9D8000))(this);
	}

	void chain(void(__cdecl *rFunc)(LPVOID), LPVOID pParam)
	{
		((void(__thiscall *)(cWork*, void(__cdecl*)(LPVOID), LPVOID))(shared::base + 0x9D8090))(this, rFunc, pParam);
	}

	void sleep(int count)
	{
		((void(__thiscall*)(cWork*, int))(shared::base + 0x9D80E0))(this, count);
	}
};

namespace cInput
{
	enum eInputButton
	{
		DPAD_LEFT = 1,
		DPAD_RIGHT = 2,
		DPAD_DOWN = 4,
		DPAD_UP = 8,
		BUTTON_A = 0x10,
		BUTTON_B = 0x20,
		BUTTON_X = 0x40,
		BUTTON_Y = 0x80,
		BUTTON_START = 0x100,
		BUTTON_BACK = 0x200,
		LEFT_SHOULDER = 0x400,
		LEFT_TRIGGER = 0x800,
		LEFT_STICK = 0x1000,
		RIGHT_SHOULDER = 0x2000,
		RIGHT_TRIGGER = 0x4000,
		RIGHT_STICK = 0x8000
	};

	enum eSaveKeybind
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

	struct ControllerState
	{
		XINPUT_STATE m_XInputState;
		int m_bAvailable;
		float m_fCurrentLeftVibration;
		float m_fTargetLeftVibration;
		float m_fCurrentRightVibration;
		float m_fTargetRightVibration;
		float m_fLeftMotorSpeed;
		float m_fRightMotorSpeed;
		int m_nCurrentVibrationTime;
		int m_nVibrationTotal;
		int m_bVibrationEnabled;
	};

	struct cKeyboardState
	{
		unsigned int m_aKeysDown[6];
		unsigned int m_aKeysPressed[6]; // bit is set when the key is pressed once
		unsigned int m_aKeysReleased[6];
		unsigned int m_aKeysAlternated[6];
		unsigned int m_aKeyHistory[6];
		int m_nPressDelay; // used for pressed last time timer

		
	};

	struct MouseInput
	{
		int m_nMouseButtons;
		int m_nButtonsPressed;
		int m_nButtonsReleased;
		int m_nButtonsAlternated;
		Hw::cVec2 m_MousePosition;
		int field_18;
		int m_nRepeatCount;
		Hw::cVec2 m_LastMousePosition;
	};

	struct InputUnit
	{
		unsigned int m_nButtonsDown;
		unsigned int m_nButtonsPressed;
		unsigned int m_nButtonsReleased;
		unsigned int m_nButtonsAlternated;
		Hw::cVec2 m_fLeftStick;
		Hw::cVec2 m_fRightStick;
		float m_fLeftTrigger;
		float m_fRightTrigger;
		int m_bValidInput;
		int m_nRepeatCount;
	};

	struct GlobalInput
	{
		char field_0;
		char field_1;
		char field_2;
		char field_3;
		__int16 field_4;
		__int16 field_6;
		int field_8;
		int field_C;
		int field_10;
		bool m_bIsPCInput;
		int field_18;
		int field_1C;
		int field_20;
		int field_24;
		int field_28;
	};

	inline void resetInputUnit(InputUnit* unit)
	{
		((void(__cdecl*)(InputUnit*))(shared::base + 0x9DAFC0))(unit);
	}

	inline int getControllerIndex(int dwUserIndex)
	{
		return ((int(__cdecl*)(int))(shared::base + 0x9FD140))(dwUserIndex);
	}

	inline int isControllerAvailable(int index)
	{
		return ((int(__cdecl*)(int))(shared::base + 0x9DA340))(index);
	}

	inline void updateInputUnit(InputUnit *unit, int dwUserIndex)
	{
		((void(__cdecl*)(InputUnit*, int))(shared::base + 0x9DAFE0))(unit, dwUserIndex);
	}

	inline void setVibrationEnabled(BOOL bEnabled)
	{
		((void(__cdecl*)(BOOL))(shared::base + 0x9DA2F0))(bEnabled);
	}

	inline void setInputUnitButtons(InputUnit *unit, unsigned int buttons)
	{
		((void(__cdecl*)(InputUnit*, unsigned int))(shared::base + 0x9DA210))(unit, buttons);
	}

	inline BOOL isKeybindDown(eSaveKeybind keybind)
	{
		return ((BOOL(__cdecl*)(eSaveKeybind))(shared::base + 0x61D280))(keybind);
	}

	inline void updateControllerStateInput(ControllerState* state, int index)
	{
		((void(__cdecl*)(ControllerState*, int))(shared::base + 0x9DA900))(state, index);
	}

	inline LPDIRECTINPUT8& ms_InputDevice = *(LPDIRECTINPUT8*)(shared::base + 0x19D06E4);
	inline LPDIRECTINPUTDEVICE8W* ms_aControllerDevices = (LPDIRECTINPUTDEVICE8W*)(shared::base + 0x19D05A8); // 4 elements
	inline LPDIRECTINPUTDEVICE8W& ms_MouseDevice = *(LPDIRECTINPUTDEVICE8W*)(shared::base + 0x19D06F4);
	inline LPDIRECTINPUTDEVICE8W& ms_PCInputDevice = *(LPDIRECTINPUTDEVICE8W*)(shared::base + 0x19D06E8);

	inline MouseInput& ms_MouseInput = *(MouseInput*)(shared::base + 0x177B798);
	inline cKeyboardState& ms_cKeyboardState = *(cKeyboardState*)(shared::base + 0x177B7C0);
	inline ControllerState *ms_aControllers = (ControllerState*)(shared::base + 0x19D05F0); // Maximum 4 controllers
	inline GlobalInput& ms_GlobalInput = *(GlobalInput*)(shared::base + 0x19C1404);

	inline char* ms_InputKeys = (char*)(shared::base + 0x19D06F8); // 256 elements
	inline char* ms_MouseStateInput = (char*)(shared::base + 0x19D06D0); // 20 elements

	inline bool& ms_bUpdateKeyboard = *(bool*)(shared::base + 0x14CDDE8);
	inline bool& ms_bUpdateMouse = *(bool*)(shared::base + 0x19D07F8);
	inline bool& ms_bMouseAvailable = *(bool*)(shared::base + 0x19D0800);
	inline bool& ms_bKeyboardAvailable = *(bool*)(shared::base + 0x19D06EC);

	inline int* ms_aKeyMap = (int*)(shared::base + 0x14CD838); // 364 elements...
	inline int* ms_aAvailableKeys = (int*)(shared::base + 0x14B5D80); // 107 elements, briefly, this array consists of keys that can be pressed
	inline int* ms_aMouseButtons = (int*)(shared::base + 0x14B5D74); // 3 elements, buttons that are checked via binary operations(and, xor, or, etc.)
	inline int& ms_nControllersAmount = *(int*)(shared::base + 0x19D0808); // how much were acquired

	inline float* ms_aStickButtonThreshold = (float*)(shared::base + 0x19D05C0); // 4 elements, threshold in any direction that will convert as a button press, also used for left or right triggers
	inline float* ms_aStickDeadzone = (float*)(shared::base + 0x19D05D0); // 4 elements
	inline float* ms_aMaxStickThreshold = (float*)(shared::base + 0x19D05E0); // 4 elements, threshold until the stick is fully moved
};
class Hw::cTexture
{
public:
	void *m_Texture;
	cTextureInstance *m_pTextureInstance;
	int m_nTextureAmount;
	int field_10;
	int field_14;
	void *m_TextureAttributes;

	cTexture()
	{
		((void(__thiscall *)(cTexture *))(shared::base + 0xB972C0))(this);
	}

	virtual ~cTexture() {};

	BOOL create(void *wtb)
	{
		return ((BOOL(__thiscall *)(cTexture *, void *))(shared::base + 0xBA25D0))(this, wtb);
	}

	BOOL create(void *wta, void *wtp)
	{
		return ((BOOL(__thiscall *)(cTexture *, void *, void*))(shared::base + 0xBA4D00))(this, wta, wtp);
	}

	void reset()
	{
		((void(__thiscall *)(cTexture *))(shared::base + 0xB972F0))(this);
	}
};

class Hw::cTextureInstance
{
public:
	IDirect3DTexture9 *m_Texture;
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
public:
	int field_4;
	int field_8;
	int field_C;
	D3DXMATRIX m_projectionMatrix;
	D3DXMATRIX m_invertedProjectionMatrix;
	float m_fAspectRatio;
	float m_fFOV;
	float m_fNearClip;
	float m_fFarClip;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;

	virtual ~CameraProj() {};
};

VALIDATE_SIZE(Hw::CameraProj, 0xB0);

class Hw::cCameraBase
{
public:
	class cCameraMatrix
	{
	public:
		Hw::cVec4 m_Trans;
		Hw::cVec4 m_Target;
		Hw::cVec4 m_Up;
		Hw::cVec4 m_Rot;
		float m_fRoll;
		float m_Dist;
		float m_fFOV;

		cCameraMatrix &operator=(const cCameraMatrix &lvalue)
		{
			((void(__thiscall *)(cCameraMatrix *, const cCameraMatrix &))(shared::base + 0x9A01F0))(this, lvalue);
			return *this;
		}

		cVec4 calculateViewOffset()
		{
			cVec4 result;
			result = *((cVec4*(__thiscall*)(cCameraMatrix*, cVec4*))(shared::base + 0x9B9090))(this, &result);
			return result;
		}
	};

	Hw::cMtx m_ViewMatrix;
	Hw::cMtx m_TransposeViewMatrix;
	Hw::cMtx m_InverseViewMatrix;
	Hw::cMtx m_ViewMatrixOld;
	cCameraMatrix m_CameraMatrix;
	float field_14C;

	void setViewMatrix(const D3DXMATRIX& matrix)
	{
		((void(__thiscall *)(cCameraBase *, const D3DXMATRIX&))(shared::base + 0x9E5170))(this, matrix);
	}

	void move(const cVec4& offset)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E4F20))(this, offset);
	}

	// Move camera according to the offset of camera
	void moveWithOffset(const cVec4& offset)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E4FA0))(this, offset);
	}

	// Move camera according to the Y offset
	void moveWithY(const cVec4& offset)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E5090))(this, offset);
	}

	void setPosition(const cVec4& position)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E5F20))(this, position);
	}

	void setOffset(const cVec4& offset)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E6060))(this, offset);
	}

	void setLookAt(const cVec4& lookAt)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E5FC0))(this, lookAt);
	}

	void setCameraOffset(const cVec4& cameraOffset)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E6090))(this, cameraOffset);
	}

	void setDistance(float distance)
	{
		((void(__thiscall *)(cCameraBase *, float))(shared::base + 0x9E62D0))(this, distance);
	}

	// m_fDistance += clamp(distance, minDistance, maxDistance)
	void adjustDistanceToLookAt(float distance, float maxDistance, float minDistance)
	{
		((void(__thiscall *)(cCameraBase *, float, float, float))(shared::base + 0x9E62F0))(this, distance, maxDistance, minDistance);
	}

	void adjustDistanceToPosition(float distance, float maxDistance, float minDistance)
	{
		((void(__thiscall *)(cCameraBase *, float, float, float))(shared::base + 0x9E6390))(this, distance, maxDistance, minDistance);
	}

	// m_vecLookAtPosition += with
	void setLookAtAlong(const cVec4& with)
	{
		((void(__thiscall *)(cCameraBase *, const cVec4&))(shared::base + 0x9E6000))(this, with);
	}

	void place(const cVec4& position, const cVec4& lookAt, const cVec4& offset)
	{
		((void(__thiscall *)(cCameraBase*, const cVec4&, const cVec4&, const cVec4&))(shared::base + 0x9E5D10))(this, position, lookAt, offset);
	}

	void place(const cVec4& position, const cVec4& cameraOffset, float distance)
	{
		((void(__thiscall *)(cCameraBase*, const cVec4&, const cVec4&, float))(shared::base + 0x9E5DA0))(this, position, cameraOffset, distance);
	}

	void lookAt(const cVec4& lookAt, const cVec4& cameraOffset, float distance)
	{
		((void(__thiscall *)(cCameraBase*, const cVec4&, const cVec4&, float))(shared::base + 0x9E5E60))(this, lookAt, cameraOffset, distance);
	}

	// m_vecPosition += with
	void moveAlong(const cVec4& with)
	{
		((void(__thiscall *)(cCameraBase*, const cVec4&))(shared::base + 0x9E5F60))(this, with);
	}

	void updatePosition()
	{
		((void(__thiscall *)(cCameraBase*))(shared::base + 0x9E51B0))(this);
	}

	void updateLookAtPos() // z = -distance
	{
		((void(__thiscall *)(cCameraBase *))(shared::base + 0x9E5260))(this);
	}

	void resetOffset()
	{
		((void(__thiscall *)(cCameraBase *))(shared::base + 0x9E5310))(this);
	}

	void calculateCameraOffset()
	{
		((void(__thiscall *)(cCameraBase*))(shared::base + 0x9E5380))(this);
	}

	void calculateCameraDistance()
	{
		((void(__thiscall *)(cCameraBase *))(shared::base + 0x9E54E0))(this);
	}

	void updateCameraViewMatrix()
	{
		((void(__thiscall *)(cCameraBase *))(shared::base + 0x9E6410))(this);
	}

	void calculateInverseViewMatrix()
	{
		((void(__thiscall *)(cCameraBase *))(shared::base + 0x9E5170))(this);
	}
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
		((void(__thiscall*)(Hw::cPrimHeap*))(shared::base + 0xB97EC0))(this);
	}

	virtual ~cPrimHeap() {};

	void* allocBuffer(size_t size, size_t reserved = 0x20)
	{
		return ((void* (__thiscall*)(cPrimHeap*, size_t, size_t))(shared::base + 0xB9B1F0))(this, size, reserved);
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
		((void(__thiscall*)(cIndexBufferHeap*))(shared::base + 0xB9C7F0))(this);
	}

	virtual ~cIndexBufferHeap() {};
};

struct Hw::RenderBufferHeapManager
{
	cPrimHeap *field_0;
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

	void draw()
	{
		CallVMTFunc<1, Hw::cOtWork*>(this);
	}
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
	IDirect3DVertexDeclaration9 *m_VertexDeclaration;
	int m_UsageFlags;

	virtual void dummyVM() {};
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

class Hw::cPrimFT : public Hw::cOtWork{};

class Hw::cPrimFTyuv : public Hw::cOtWork{};

class Hw::cPrimFV : public Hw::cOtWork{};

class Hw::cPrimG : public Hw::cOtWork{};

class Hw::cPrimIF : public Hw::cOtWork{};

class Hw::cPrimIFT : public Hw::cOtWork{};

class Hw::cRenderPredicate
{
public:

	virtual ~cRenderPredicate() {};
};

class Hw::cShaderPreset : public Hw::cShader{};

class Hw::cShaderCharacter : public Hw::cShaderPreset{};

class Hw::cShaderPF : public Hw::cShaderPreset{};

class Hw::cShaderPFT : public Hw::cShaderPreset{};

class Hw::cShaderPFTyuv : public Hw::cShaderPreset{};

class Hw::cShaderPFTyuva : public Hw::cShaderPreset{};

class Hw::cShaderPFV : public Hw::cShaderPreset{};

class Hw::cShaderPG : public Hw::cShaderPreset{};

class Hw::cVertexFormatP : public Hw::cVertexFormat{};

class Hw::cVertexFormatPG : public Hw::cVertexFormat{};

class Hw::cVertexFormatPT : public Hw::cVertexFormat{};

class Hw::cVertexFormatPV : public Hw::cVertexFormat{};

class Hw::cZTexture : public Hw::cTargetTexture{};

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

class cFilterShaderCopyTexAlp : public cFilterShaderCopyTex{};

template <typename T>
struct Hw::cFixedVector
{
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

	BOOL create(size_t capacity, Hw::cHeap* allocator)
	{
		if (m_vector)
			return 0;

		m_vector = allocator->AllocateMemory(sizeof(T) * capacity);
		if (m_vector)
		{
			m_capacity = capacity;
			m_size = 0;
			m_bInitialized = 1; // is initialized?
			return 1;
		}
		else
		{
			ePrintf("cFixedVector::create Failed to allocate memory[%s need:%d Allocatable:%d]", allocator->m_TargetAlloc, sizeof(T) * capacity, allocator->getFreeMemory());
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
		cTag *m_pTag;
	public:

		const_iterator(cTag *pTag)
		{
			m_pTag = pTag;
		}

		const_iterator(const const_iterator &it)
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

		bool operator==(const const_iterator &other)
		{
			return m_pTag == other.m_pTag;
		}

		bool operator!=(const const_iterator& other)
		{
			return !(*this == other);
		}

		tC &operator*() const
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
			m_pTag = it.m_pTag;
		}

		iterator(cTag *pTag)
		{
			m_pTag = pTag;
		}

		iterator(const const_iterator &it)
		{
			m_pTag = it.m_pTag;
		}

		iterator()
		{
			m_pTag = nullptr;
		}

		iterator &operator=(const iterator& it)
		{
			m_pTag = it.m_pTag;

			return *this;
		}

		tC& operator*()
		{
			return m_pTag->m_value;
		}

		tC *operator->()
		{
			return &m_pTag->m_value;
		}

		iterator getPrev()
		{
			return m_pTag->m_prev;
		}

		iterator getNext()
		{
			return m_pTag->m_next;
		}
	};

	const iterator m_npos;
	cTag* m_pAllocated;
	size_t m_capacity;
	size_t m_size;
	iterator m_freeBegin;
	iterator m_first;
	iterator m_last;

	cFixedList() : m_npos(nullptr)
	{
		m_pAllocated = nullptr;
		m_freeBegin = m_npos;
		m_first = m_npos;
		m_last = m_npos;
	};

	~cFixedList()
	{
		destroy();
	}

	BOOL create(size_t capacity, Hw::cHeap &allocator)
	{
		if (m_pAllocated)
			return FALSE;

		m_pAllocated = (cTag*)allocator.AllocateMemory(sizeof(cTag) * capacity + sizeof(cTag), 32, 0, 0);
		if (m_pAllocated)
		{
			m_capacity = capacity;
			m_size = 0;
			m_last = m_pAllocated + capacity;

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

			m_capacity = 0;
			m_size = 0;
			m_first = m_npos;
			m_last = m_npos;
			m_freeBegin = m_npos;
		}
	}

	iterator insert(const_iterator &where, const tC& element)
	{
		cTag* free = m_freeBegin;
		if (m_freeBegin == m_npos)
		{
			PrintfLog("cFixedList<tC>::insert  list max over!");
			return m_npos;
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

		if (m_first == where)
			m_first = free;

		return free;
	}

	iterator pushBack(const tC& element)
	{
		return insert(m_last, element);
	}

	iterator pushFront(const tC& element)
	{
		return insert(m_first, element);
	}

	iterator erase(iterator &it)
	{
		cTag* prev = it.m_pTag->m_prev;
		cTag* next = it.m_pTag->m_next;

		if (prev)
			prev->m_next = next;
		if (next)
			next->m_prev = prev;

		if (m_first == it)
			m_first = next;

		--m_size;

		it->m_pTag->m_prev = m_freeBegin.getPrev();
		it->m_pTag->m_next = m_freeBegin.m_pTag;

		if (m_freeBegin.getPrev())
			m_freeBegin.getPrev()->m_next = it->m_pTag;
		if (m_freeBegin.m_pTag)
			m_freeBegin.m_pTag->m_prev = it->m_pTag;

		m_freeBegin = it->m_pTag;

		return next;
	}

	void clear()
	{
		resetChain();
	}

	iterator begin()
	{
		return m_first;
	}

	const_iterator begin() const
	{
		return m_first;
	}

	const_iterator end() const
	{
		return m_last;
	}

	iterator end()
	{
		return m_last;
	}

	size_t getSize() const
	{
		return m_size;
	}

	size_t getCapacity() const
	{
		return m_capacity;
	}

	BOOL canAdd() const
	{
		return m_size < m_capacity && m_freeBegin != m_npos;
	}

	void chain(iterator &it)
	{
		cTag* prev = it->m_prev;
		cTag* next = it->m_next;

		if (prev)
			prev->m_next = next;
		if (next)
			next->m_prev = prev;
	}

	iterator unchain(iterator &it)
	{
		cTag* prev = it.m_pTag->m_prev;
		cTag* next = it.m_pTag->m_next;

		if (prev)
			prev->m_next = next;
		if (next)
			next->m_prev = prev;

		if (m_first == it)
			m_first = next;

		if (m_last == it)
			m_last = prev;
	}

	void resetChain()
	{
		if (m_capacity > 0)
		{
			cTag* current = m_pAllocated;
			for (int i = 0; i < m_capacity; i++)
			{
				current->m_prev = (current - 1);
				current->m_next = (current + 1);
				++current;
			}
		}

		m_pAllocated->m_prev = nullptr;

		m_pAllocated[m_capacity - 1].m_next = 0;

		m_last->m_prev = nullptr;
		m_last->m_next = nullptr;

		m_first = m_last;
		m_freeBegin = m_pAllocated;

		m_size = 0;
	}

	iterator createIterator()
	{
		iterator &free = m_freeBegin;
		if (free == m_npos)
			return m_npos;

		chain(free);

		m_freeBegin = free->getNext();
		++m_size;

		return free;
	}

	void releaseIterator(iterator &it)
	{
		if (it == m_npos)
			return;

		cTag* tag = it.m_pTag;

		unchain(it);

		tag->m_next = m_freeBegin.m_pTag; 
		tag->m_prev = nullptr;         
		if (m_freeBegin != m_npos)
			m_freeBegin.m_pTag->m_prev = tag;

		m_freeBegin = it;

		--m_size;
	}
};

template <typename tC, typename tHeapBinder = Hw::cHeap>
struct Hw::cExpandableVector
{
	int field_0;
	tC *m_vector;
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

		ePrintf("Hw::cExpandableVector<tC, tHeapBinder>::create lack of memory[%s %d/%d]", m_Allocator->m_TargetAlloc, sizeof(tC) * size, m_Allocator->getFreeMemory());
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
			PrintfLog("Hw::cExpandableVector<tC,tHeapBinder>::reallocate Out of memory");
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
			PrintfLog("Hw::cExpandableVector<tC,tHeapBinder>::resize insufficient capacity");
			return FALSE;
		}
		return FALSE;
	}
};

struct Hw::cDvdFst
{
	int field_0;
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
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;
	int field_B4;
	int field_B8;

	struct Work
	{
		int m_State;
		CriFsBinderWork *m_CriBinderWork;
		CriFsLoaderHn *m_CriLoader;
		char m_Filepath[64];
		int m_MaxTime;
		int m_AttemptTime;
		void *m_Filedata;
		int m_Buffersize;
		int m_Priority;
		int field_60;
		int field_64;
		int field_68;
		Work *m_pNext;
		Work *m_pPrevious;
	};

	struct ReadWork : Work // Probably FileReadWork
	{
		char m_Filepath[64];
		void *m_Filedata;
		int m_Buffersize;
		int field_BC;
		int m_WaitAmount;
		int m_ReaderFlags;
		int m_Priority;
	}; 
};

struct Hw::DvdReadManager
{
	int field_0;
	int field_4;
	Hw::cHeapFixed m_DvdReadFactory;
};

VALIDATE_SIZE(Hw::cHeap, 0x40);

inline Hw::cTaskManager& g_MainTaskManager = *(Hw::cTaskManager*)(shared::base + 0x17E9164);
inline Hw::cKeyboardState& g_Keyboard = *(Hw::cKeyboardState*)(shared::base + 0x177B7C0);