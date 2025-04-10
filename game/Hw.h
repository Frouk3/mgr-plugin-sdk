#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <dinput.h>
#include "shared.h"

extern void(__cdecl* ePrintf)(const char* fmt, ...);

namespace Hw
{
    class cHeap;
    class cHeapVariableBase;
    class cHeapVariable;
    class cTexture;
    class CameraProj;
    class cCameraBase;
    class cHeapPhysical;
    class cHeapHook;
    class cHeapFixed;
    class cHeapOneTime;
    class cHeapPhysicalBase;
    class cHeapGlobal;
    class cShareHeapPhysical;
    class cPrimHeap;
    class cIndexBufferHeap;
    class cRenderTargetInfo;
    class cOtWork;
    class CriticalSection;

    template <typename T>
    struct cFixedVector;

    template <typename T>
    struct cFixedList;

    template <typename tC, typename tHeapBinder>
    struct cExpandableVector;

    struct cVec2;
    struct cVec3;
    struct cVec4;
    struct cQuaternion;

    inline BOOL createSubWindow(const char *classname, const char *windowname, unsigned int x, unsigned int y)
    {
        return ((BOOL(__cdecl *)(const char*, const char *, unsigned int, unsigned int))(shared::base + 0xB98770))(classname, windowname, x, y);
    } 

    inline LPDIRECT3D9 &pDirect3D9 = *(LPDIRECT3D9*)(shared::base + 0x1B206D8);
    inline LPDIRECT3DDEVICE9 &GraphicDevice = *(LPDIRECT3DDEVICE9*)(shared::base + 0x1B206D4);
    inline LPDIRECTINPUT8& InputDevice = *(LPDIRECTINPUT8*)(shared::base + 0x19D06E4);
    inline LPDIRECTINPUTDEVICE8W& InputDeviceW = *(LPDIRECTINPUTDEVICE8W*)(shared::base + 0x19D06F4);
    inline HWND &OSWindow = *(HWND*)(shared::base + 0x19D504C);
    inline HWND &SecondWindow = *(HWND*)(shared::base + 0x1B205E0);

    inline LPDIRECT3DSWAPCHAIN9& MainSwapChain = *(LPDIRECT3DSWAPCHAIN9*)(shared::base + 0x1B206FC); // Seems to be unused
    inline LPDIRECT3DSWAPCHAIN9& SecondWindowSwapChain = *(LPDIRECT3DSWAPCHAIN9*)(shared::base + 0x1B20700); // This one unused too
}

struct Hw::cVec2
{
    float x;
    float y;

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

struct Hw::cVec3
{
    float x;
    float y;
    float z;

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

struct Hw::cVec4
{
    float x;
    float y;
    float z;
    float w;

    static inline void Normalize(cVec4* v1, cVec4* v2)
    {
        ((void(__cdecl*)(cVec4*, cVec4*))(shared::base + 0x9DF460))(v1, v2);
    }

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
        Normalize(this, this);
        return *this;
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

struct Hw::cQuaternion
{
    float x;
    float y;
    float z;
    float w;

    cQuaternion(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w) {};
    cQuaternion() { x = 0.f; y = 0.f; z = 0.f; w = 1.f; };
};

VALIDATE_SIZE(Hw::cVec4, 0x10);

typedef Hw::cVec2 cVec2;
typedef Hw::cVec3 cVec3;
typedef Hw::cVec4 cVec4;
typedef Hw::cQuaternion cQuaternion;

class Hw::CriticalSection
{
public:
    RTL_CRITICAL_SECTION m_critsection;
    BOOL m_bInit;

    CriticalSection()
    {
        this->m_bInit = FALSE;
    }

    BOOL init()
    {
        return ((BOOL(__thiscall*)(CriticalSection*))(shared::base + 0x9D7240))(this);
    }

    void enter()
    {
        if (this->m_bInit)
            EnterCriticalSection(&this->m_critsection);
    }

    void leave()
    {
        if (this->m_bInit)
            LeaveCriticalSection(&this->m_critsection);
    }

    void shutdown()
    {
        ((void(__thiscall*)(CriticalSection*))(shared::base + 0x9D7270))(this);
    }
};

class Hw::cHeap
{
public:
    int field_4;
    Hw::CriticalSection m_CriticalSection;
    int field_24;
    Hw::cHeap* m_pReservedHeap;
    Hw::cHeap* m_pHeapOwner;
    Hw::cHeap* m_pNext;
    Hw::cHeap* m_pPrev;
    const char* m_TargetAlloc;
    int field_3C;

    cHeap()
    {
        ((void(__thiscall*)(cHeap*))(shared::base + 0x9D3650))(this);
    }

    virtual ~cHeap() {};

    void startup()
    {
        CallVMTFunc<1, cHeap*>(this);
    }

    void shutdown()
    {
        CallVMTFunc<2, cHeap*>(this);
    }

    BOOL hasHandle()
    {
        return ReturnCallVMTFunc<BOOL, 3, cHeap*>(this);
    }

    size_t getMemoryLimit()
    {
        return ReturnCallVMTFunc<size_t, 4, cHeap*>(this);
    }

    size_t getAvailableMemory()
    {
        return ReturnCallVMTFunc<size_t, 5, cHeap*>(this);
    }

    size_t getFreeMemory()
    {
        return ReturnCallVMTFunc<size_t, 6, cHeap*>(this);
    }

    void* getBlock(void *block)
    {
        return ReturnCallVMTFunc<void*, 7, cHeap*, void *>(this, block);
    }

    size_t getMemorySizeByBlock(void* block)
    {
        return ReturnCallVMTFunc<size_t, 8, cHeap*, void*>(this, block);
    }

    size_t getCriticalLimit()
    {
        return ReturnCallVMTFunc<size_t, 9, cHeap*>(this);
    }
    // memory that is used by child heaps
    size_t getChildHeapMemory()
    {
        return ReturnCallVMTFunc<size_t, 10, cHeap*>(this);
    }

    void unused(void *unk1)
    {
        CallVMTFunc<11, cHeap*, void*>(this, unk1);
    }

    void* createChildHeap(HANDLE* pHandle, size_t Size)
    {
        return ReturnCallVMTFunc<void*, 12, cHeap*, HANDLE*, size_t>(this, pHandle, Size);
    }

    void removeChildHeap(HANDLE* pHandle, size_t Size)
    {
        CallVMTFunc<13, cHeap*, HANDLE*, size_t>(this, pHandle, Size);
    }

    void* allocate(size_t size, size_t preserved, int a3, int a4)
    {
        return ReturnCallVMTFunc<void*, 14, cHeap*, size_t, size_t, int, int>(this, size, preserved, a3, a4);
    }

    void free(void* block, size_t size)
    {
        CallVMTFunc<15, cHeap*, void*, size_t>(this, block, size);
    }

    void *AllocateMemory(size_t size, size_t preserved, int alignment, int a3)
    {
        return ((void*(__thiscall*)(Hw::cHeap *, size_t, size_t, int, int))(shared::base + 0x9D29B0))(this, size, preserved, alignment, a3);
    }
};

class Hw::cHeapVariableBase : public Hw::cHeap
{
public:
    HANDLE m_HeapHandle;
    int field_44;
    int field_48;
    int m_nMemoryLimit;
    int m_nFreeMemory;
    int m_nUsedMemory;

    cHeapVariableBase()
    {
        ((void(__thiscall*)(Hw::cHeapVariableBase*))(shared::base + 0x9D3AF0))(this);
    }

    struct HeapBlock
    {
        HeapBlock* m_pPrevious;
        HeapBlock* m_pNext;
        void* m_pMemoryBlock;
        size_t m_nMemorySize;
        cHeapVariableBase* m_pAllocator;
    };
};

class Hw::cHeapVariable : public Hw::cHeapVariableBase
{
public:

    cHeapVariable()
    {
        ((void(__thiscall*)(Hw::cHeapVariable*))(shared::base + 0x9D44F0))(this);
    }
};

class Hw::cHeapPhysicalBase : public Hw::cHeap
{
public:
    HANDLE m_HeapHandle;
    int filed_44;
    int field_48;
    int m_nMemoryLimit;
    int m_nFreeMemory;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    void* m_pBlocks[256];

    cHeapPhysicalBase()
    {
        ((void(__thiscall*)(Hw::cHeapPhysicalBase*))(shared::base + 0x9D3860))(this);
    }

    struct HeapBlock
    {
        HeapBlock* m_pPrevious;
        HeapBlock* m_pNext;
        size_t m_nTotalSize;
        size_t m_nSize;
        int field_10;
        int field_14;
        Hw::cHeapPhysicalBase* m_pAllocator;
    };
};

class Hw::cHeapPhysical : public Hw::cHeapPhysicalBase
{
public:

    cHeapPhysical()
    {
        ((void(__thiscall*)(Hw::cHeapPhysical*))(shared::base + 0x9D48F0))(this);
    }
};

class Hw::cHeapHook
{
public:

    virtual ~cHeapHook() {};
};

class Hw::cHeapFixed : public Hw::cHeap
{
public:
    HANDLE m_HeapHandle;
    int field_44;
    int m_nFixedSize;
    int field_4C;
    int m_nFixedReservedSize;
    int m_nFixedAmount;
    int field_58;
    int field_5C;

    void* AllocateMemory()
    {
        return ((void* (__thiscall*)(Hw::cHeapFixed*))(shared::base + 0x9D2BC0))(this);
    }
};

class Hw::cHeapOneTime : public Hw::cHeap
{
public:


};

class Hw::cHeapGlobal : public Hw::cHeapVariableBase
{
public:

    static inline cHeapGlobal* get()
    {
        return ((cHeapGlobal * (__cdecl*)())(shared::base + 0x61D830))();
    }

    static inline Hw::cHeapGlobal& Instance = *(Hw::cHeapGlobal*)(shared::base + 0x1783AF0);
};

class Hw::cShareHeapPhysical : Hw::cHeapPhysical
{
public:


};

class Hw::cTexture
{
public:
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;

    virtual ~cTexture() {};
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
    struct CameraMatrix
    {
        cVec4 m_vecPosition;
        cVec4 m_vecLookAtPosition;
        cVec4 m_vecOffset;
        cVec4 m_vecCameraOffset;
        float m_fRoll;
        float m_fDistance;
        float m_fFOV;

        CameraMatrix &operator=(const CameraMatrix &lvalue)
        {
            ((void(__thiscall *)(CameraMatrix *, const CameraMatrix &))(shared::base + 0x9A01F0))(this, lvalue);
            return *this;
        }

        cVec4 calculateViewOffset()
        {
            ((cVec4(__thiscall*)(CameraMatrix*))(shared::base + 0x9B9090))(this);
        }
    };

    D3DXMATRIX m_viewMatrix;
    D3DXMATRIX field_40;
    D3DXMATRIX m_invertedViewMatrix;
    D3DXMATRIX field_C0;
    CameraMatrix m_CameraMatrix;
    float field_14C;

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

    void place(const cVec4& position, const cVec4& lookAt, const cVec4& offset)
    {
        ((void(__thiscall *)(cCameraBase*, const cVec4&, const cVec4&, const cVec4&))(shared::base + 0x9E5D10))(this, position, lookAt, offset);
    }

    void updatePosition()
    {
        ((void(__thiscall *)(cCameraBase*))(shared::base + 0x9E51B0))(this);
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

inline void *__cdecl operator new(size_t s, Hw::cHeap *allocator)
{
    return ((void*(__cdecl *)(size_t, Hw::cHeap *))(shared::base + 0x9D3500))(s, allocator);
}

inline void __cdecl operator delete(void* block, Hw::cHeap* allocator) // to separate the delete operator
{
    return ((void(__cdecl*)(void*, size_t))(shared::base + 0x9D48D0))(block, 0);
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

template <typename T>
struct Hw::cFixedVector
{
    int field_0;
    T* m_pBegin;
    size_t m_nCapacity;
    size_t m_nSize;
    int field_10;

    cFixedVector()
    {
        field_0 = 0;
        m_pBegin = nullptr;
        m_nCapacity = 0;
        m_nSize = 0;
        field_10 = 0;
    }

    BOOL create(size_t capacity, Hw::cHeap* allocator)
    {
        if (this->m_pBegin)
            return 0;

        this->m_pBegin = allocator->AllocateMemory(sizeof(T) * capacity);
        if (this->m_pBegin)
        {
            this->m_nCapacity = capacity;
            this->m_nSize = 0;
            this->field_10 = 1; // is initialized?
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
        if (!this->m_pBegin)
            return false;

        if (this->m_nSize >= this->m_nCapacity)
            return false;

        this->m_pBegin[this->m_nSize++] = element;
        return true;
    }

    bool push_front(const T& element)
    {
        this->insert(this->m_pBegin[0], element);
        return true;
    }

    void insert(T& insIndex, const T& element)
    {
        if (!this->m_pBegin)
            return;

        if (this->m_nSize >= this->m_nCapacity)
            return;

        size_t insertIndex = &insIndex - this->m_pBegin;
        if (insertIndex > this->m_nSize)
            return;

        for (int i = this->m_nSize; i > insertIndex; --i)
            this->m_pBegin[i] = this->m_pBegin[i - 1];

        this->m_pBegin[insertIndex] = element;
        ++this->m_nSize;
    }

    void remove(T& element)
    {
        if (!this->m_pBegin)
            return;

        if (&element - this->m_pBegin >= this->m_nSize)
            return;

        for (auto i = &element; i != this->m_pBegin[this->m_nSize - 1]; ++i)
            *i = i[1];

        --this->m_nSize;
    }

    auto& get(size_t index)
    {
        return this->m_pBegin[index];
    }

    auto& get(size_t index) const
    {
        return this->m_pBegin[index];
    }

    auto& operator[](size_t index)
    {
        return this->get(index);
    }

    auto& operator[](size_t index) const
    {
        return this->get(index);
    }

    auto begin()
    {
        return &this->m_pBegin[0];
    }

    auto begin() const
    {
        return &this->m_pBegin[0];
    }

    auto end()
    {
        return &this->m_pBegin[this->m_nSize];
    }

    auto end() const
    {
        return &this->m_pBegin[this->m_nSize];
    }
};

template <typename T>
struct Hw::cFixedList
{
    struct Node
    {
        T m_value;
        Node* m_prev;
        Node* m_next;
    };

    Node* m_pHead;
    Node* m_pBegin;
    size_t m_nCapacity;
    size_t m_nSize;
    Node* m_pEnd;
    Node* m_pFirst;
    Node* m_pLast;

    class iterator
    {
    private:
        Node* m_current;
    public:
        explicit iterator(Node* node) : m_current(node) {};

        iterator& operator++()
        {
            if (this->m_current)
                this->m_current = this->m_current->m_next;

            return *this;
        }

        iterator& operator--()
        {
            if (this->m_current)
                this->m_current = this->m_current->m_prev;

            return *this;
        }

        T& operator*() const
        {
            return this->m_current->m_value;
        }

        bool operator==(const iterator& other) const
        {
            return this->m_current == other.m_current;
        }

        bool operator!=(const iterator& other) const
        {
            return !(*this == other);
        }
    };

    auto begin()
    {
        return iterator(this->m_pFirst);
    }

    auto begin() const
    {
        return iterator(this->m_pFirst);
    }

    auto end() const
    {
        return iterator(this->m_pLast);
    }

    auto end()
    {
        return iterator(this->m_pLast);
    }

    auto rbegin()
    {
        return iterator(this->m_pLast);
    }

    auto rbegin() const
    {
        return iterator(this->m_pLast);
    }

    auto rend()
    {
        return iterator(this->m_pFirst);
    }

    auto rend() const
    {
        return iterator(this->m_pFirst);
    }

    void setupNodes()
    {
        if (this->m_nCapacity > 0)
        {
            Node* current = this->m_pBegin;
            for (int i = 0; i < this->m_nCapacity; i++)
            {
                current->m_prev = (current - 1);
                current->m_next = (current + 1);
                ++current;
            }
        }

        this->m_pBegin->m_prev = nullptr;

        this->m_pBegin[this->m_nCapacity - 1].m_next = 0;

        this->m_pLast->m_prev = nullptr;
        this->m_pLast->m_next = nullptr;

        this->m_pFirst = this->m_pLast;
        this->m_pEnd = this->m_pBegin;

        this->m_nSize = 0;
    }

    BOOL create(size_t capacity, Hw::cHeap * allocator)
    {
        if (this->m_pBegin)
            return 0;

        this->m_pBegin = (Node*)allocator->AllocateMemory(sizeof(Node) * capacity + sizeof(Node), 32, 0, 0);
        if (this->m_pBegin)
        {
            this->m_nCapacity = capacity;
            this->m_nSize = 0;
            this->m_pLast = &this->m_pBegin[capacity];

            this->setupNodes();

            return 1;
        }
        return 0;
    }

    void insert(Node* &retNode, Node* const& where, const T & element)
    {
        Node *m_pLast = this->m_pEnd;
        if (m_pLast == this->m_pHead)
        {
            m_pLast = this->m_pHead;
        }
        else
        {
            Node *m_prev = m_pLast->m_prev;
            Node *m_next = m_pLast->m_next;
            if (m_prev)
                m_prev->m_next = m_next;
            if (m_next)
                m_next->m_prev = m_prev;
            this->m_pEnd = m_next;
            ++this->m_nSize;
        }
        if (m_pLast == this->m_pHead)
        {
            ePrintf("cFixedList<tC>::insert  list max over!");
            retNode = this->m_pHead;
        }
        else
        {
            if (m_pLast)
                m_pLast->m_value = element;
            Node *v8 = where;
            Node* v9;
            if (where)
                v9 = v8->m_prev;
            else
                v9 = 0;
            m_pLast->m_prev = v9;
            m_pLast->m_next = v8;
            if (v9)
                v9->m_next = m_pLast;
            if (v8)
                v8->m_prev = m_pLast;
            if (this->m_pFirst == where)
                this->m_pFirst = m_pLast;
            retNode = m_pLast;
        }
    }

    void push_back(const T& element)
    {
        Node* node;
        this->insert(node, this->m_pLast, element);
    }

    void push_front(const T& element)
    {
        Node* node;
        this->insert(node, this->m_pFirst, element);
    }

    void remove(const Node*& node)
    {
        Node* m_prev = node->m_prev;
        Node* m_next = node->m_next;
        if (m_prev)
            m_prev->m_next = m_next;
        if (m_next)
            m_next->m_prev = m_prev;
        if (this->m_pFirst == node)
            this->m_pFirst = m_next;
        --this->m_nSize;
        Node* m_pLast = this->m_pLast;
        Node* v10;
        if (m_pLast)
            v10 = m_pLast->m_prev;
        else
            v10 = nullptr;
        node->m_prev = v10;
        node->m_next = m_pLast;
        if (v10)
            v10->m_next = node;
        if (m_pLast)
            m_pLast->m_prev = node;
        this->m_pLast = node;
    }

    void remove(const T& value)
    {
        Node *current = this->m_pFirst;
        while (current)
        {
            if (current->m_value == value)
            {
                this->remove(current);
                return;
            }

            current = current->m_next;
        }
    }
};

template <typename tC, typename tHeapBinder>
struct Hw::cExpandableVector
{
    int field_0;
    tC *m_pBegin;
    size_t m_nCapacity;
    size_t m_nSize;
    BOOL m_bArrayInitialized;
    tHeapBinder* m_Allocator; // Why use the allocator member?? It cannot bind directly to the declared heap, so it's the solver

    cExpandableVector()
    {
        field_0 = 0;
        m_pBegin = nullptr;
        m_nCapacity = 0;
        m_nSize = 0;
        m_bArrayInitialized = FALSE;
    };

    cExpandableVector(tHeapBinder* allocator) : m_Allocator(allocator) 
    {
        field_0 = 0;
        m_pBegin = nullptr;
        m_nCapacity = 0;
        m_nSize = 0;
        m_bArrayInitialized = FALSE;
    }

    ~cExpandableVector()
    {
        operator delete(m_pBegin, m_Allocator);
        m_pBegin = nullptr;

        m_nCapacity = 0;
        m_nSize = 0;
        m_bArrayInitialized = FALSE;
    }

    BOOL create(size_t size)
    {
        if (m_pBegin)
            return FALSE;

        m_pBegin = (tC*)m_Allocator->AllocateMemory(sizeof(tC) * size, 32, 0, 0);
        if (m_pBegin)
        {
            m_nSize = 0;
            m_nCapacity = size;
            m_bArrayInitialized = TRUE;

            return TRUE;
        }

        ePrintf("Hw::cExpandableVector<tC, tHeapBinder>::create lack of memory[%s %d/%d]", m_Allocator->m_TargetAlloc, sizeof(tC) * size, m_Allocator->getFreeMemory());
        return FALSE;
    }

    void insert(tC& where, const tC& element)
    {
        if (!m_pBegin)
            return;

        size_t index = m_pBegin - &where;

        if (index > m_nSize)
            return;

        if (m_nSize >= m_nCapacity)
        {
            if (!m_nCapacity)
                create(32u);
            else
                reallocate(m_nCapacity * 2);
        }

        for (size_t i = index; i < m_nSize; i++)
            m_pBegin[i] = m_pBegin[i - 1];

        m_pBegin[index] = element;
        ++m_nSize;
    }

    void push_back(const tC& element)
    {
        if (!m_pBegin)
            return;

        if (m_nSize >= m_nCapacity)
        {
            if (!m_nCapacity)
                create(32u);
            else
                reallocate(m_nCapacity * 2);
        }

        m_pBegin[m_nSize++] = element;
    }

    void push_front(const tC& element)
    {
        insert(m_pBegin[0], element);
    }

    void remove(tC& element)
    {
        if (!m_pBegin)
            return;

        if (&element - m_pBegin >= m_nSize)
            return;

        size_t index = &element - m_pBegin;

        for (auto elem = &m_pBegin[index]; elem != &m_pBegin[m_nSize - 1]; elem++)
            *elem = elem[1];

        --m_nSize;
    }

    void clear()
    {
        if (m_pBegin)
        {
            for (size_t i = m_nSize - 1; i > 0; i--)
                m_pBegin[i].~tC();

            m_nSize = 0;
        }
    }

    auto &get(size_t index)
    {
        return m_pBegin[index];
    }

    auto &get(size_t index) const
    {
        return m_pBegin[index];
    }

    auto &operator[](size_t index)
    {
        return get(index);
    }

    auto &operator[](size_t index) const
    {
        return get(index);
    }

    auto begin()
    {
        return m_pBegin;
    }

    auto begin() const
    {
        return m_pBegin;
    }

    auto end()
    {
        return &m_pBegin[m_nSize];
    }

    auto end() const
    {
        return &m_pBegin[m_nSize];
    }

    auto rbegin()
    {
        return &m_pBegin[m_nSize];
    }

    auto rbegin() const
    {
        return &m_pBegin[m_nSize];
    }

    auto rend()
    {
        return m_pBegin;
    }

    auto rend() const
    {
        return m_pBegin;
    }

    BOOL reallocate(size_t newSize)
    {
        if (m_nCapacity == newSize)
            return TRUE;

        tC* newArray = (tC*)m_Allocator->AllocateMemory(sizeof(tC) * newSize, 32, 0, 0);

        if (newArray)
        {
            if (m_nSize >= newSize)
            {
                if (m_nSize > 0)
                {
                    for (size_t elementIndex = 0; elementIndex < m_nSize; elementIndex++)
                        newArray[elementIndex] = m_pBegin[elementIndex];
                }
                m_nSize = newSize;
            }
            else
            {
                for (size_t elementIndex = 0; elementIndex < m_nSize; elementIndex++)
                    newArray[elementIndex] = m_pBegin[elementIndex];
            }
            if (m_bArrayInitialized)
            {
                operator delete(m_pBegin, m_Allocator);
                m_bArrayInitialized = FALSE;
            }

            m_pBegin = newArray;
            m_nCapacity = newSize;
            m_bArrayInitialized = TRUE;

            return TRUE;
        }
        else
        {
            ePrintf("Hw::cExpandableVector<tC,tHeapBinder>::reallocate Out of memory");
            return FALSE;
        }

        return FALSE;
    }

    BOOL resize(size_t size)
    {
        if (size <= m_nCapacity || reallocate(size))
        {
            if (size != m_nSize)
                m_nSize = size;
            return TRUE;
        }
        else
        {
            ePrintf("Hw::cExpandableVector<tC,tHeapBinder>::resize insufficient capacity");
            return FALSE;
        }
        return FALSE;
    }
};

VALIDATE_SIZE(Hw::cHeap, 0x40);