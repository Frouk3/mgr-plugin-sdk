#pragma once
#include <Windows.h>
#include <d3dx9.h>
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

    inline LPDIRECT3D9 &pDirect3D9 = *(LPDIRECT3D9*)(shared::base + 0x1B206D8);
    inline LPDIRECT3DDEVICE9 &GraphicDevice = *(LPDIRECT3DDEVICE9*)(shared::base + 0x1B206D4);
    inline HWND &OSWindow = *(HWND*)(shared::base + 0x19D504C); 
}

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

    void* getBlock(void *unk1)
    {
        return ReturnCallVMTFunc<void*, 7, cHeap*, void *>(this, unk1);
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
    HANDLE* m_pHandle;
    int field_44;
    int field_48;
    int m_nMemoryLimit;
    int m_nFreeMemory;
    int m_nUsedMemory;

};

class Hw::cHeapVariable : public Hw::cHeapVariableBase
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
    D3DXMATRIX field_50;
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
    D3DXMATRIX m_viewMatrix;
    D3DXMATRIX field_40;
    D3DXMATRIX field_80;
    D3DXMATRIX field_C0;
    D3DXMATRIX field_100;
    int field_140;
    float field_144;
    float field_148;
    float field_14C;
};

VALIDATE_SIZE(Hw::cCameraBase, 0x150);

class Hw::cHeapPhysicalBase : public Hw::cHeap
{
public:
    HANDLE* m_pHandle;
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
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
    int field_150;
    int field_154;
    int field_158;
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    int field_16C;
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    int field_218;
    int field_21C;
    int field_220;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    int field_284;
    int field_288;
    int field_28C;
    int field_290;
    int field_294;
    int field_298;
    int field_29C;
    int field_2A0;
    int field_2A4;
    int field_2A8;
    int field_2AC;
    int field_2B0;
    int field_2B4;
    int field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;
    int field_2C8;
    int field_2CC;
    int field_2D0;
    int field_2D4;
    int field_2D8;
    int field_2DC;
    int field_2E0;
    int field_2E4;
    int field_2E8;
    int field_2EC;
    int field_2F0;
    int field_2F4;
    int field_2F8;
    int field_2FC;
    int field_300;
    int field_304;
    int field_308;
    int field_30C;
    int field_310;
    int field_314;
    int field_318;
    int field_31C;
    int field_320;
    int field_324;
    int field_328;
    int field_32C;
    int field_330;
    int field_334;
    int field_338;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
    int field_34C;
    int field_350;
    int field_354;
    int field_358;
    int field_35C;
    int field_360;
    int field_364;
    int field_368;
    int field_36C;
    int field_370;
    int field_374;
    int field_378;
    int field_37C;
    int field_380;
    int field_384;
    int field_388;
    int field_38C;
    int field_390;
    int field_394;
    int field_398;
    int field_39C;
    int field_3A0;
    int field_3A4;
    int field_3A8;
    int field_3AC;
    int field_3B0;
    int field_3B4;
    int field_3B8;
    int field_3BC;
    int field_3C0;
    int field_3C4;
    int field_3C8;
    int field_3CC;
    int field_3D0;
    int field_3D4;
    int field_3D8;
    int field_3DC;
    int field_3E0;
    int field_3E4;
    int field_3E8;
    int field_3EC;
    int field_3F0;
    int field_3F4;
    int field_3F8;
    int field_3FC;
    int field_400;
    int field_404;
    int field_408;
    int field_40C;
    int field_410;
    int field_414;
    int field_418;
    int field_41C;
    int field_420;
    int field_424;
    int field_428;
    int field_42C;
    int field_430;
    int field_434;
    int field_438;
    int field_43C;
    int field_440;
    int field_444;
    int field_448;
    int field_44C;
    int field_450;
    int field_454;
    int field_458;
    int field_45C;
    int field_460;
    int field_464;
    int field_468;
    int field_46C;

};

class Hw::cHeapPhysical : public Hw::cHeapPhysicalBase
{
public:

    
};

class Hw::cHeapHook
{
public:

    virtual ~cHeapHook() {};
};

class Hw::cHeapFixed : public Hw::cHeap
{
public:
    HANDLE* m_pHandle;
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

class Hw::cPrimHeap
{
public:
    int field_4;
    int field_8;
    int field_C;
    int field_10;

    virtual ~cPrimHeap() {};
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
};

inline void *__cdecl operator new(size_t s, Hw::cHeap *allocator)
{
    return ((void*(__cdecl *)(size_t, Hw::cHeap *))(shared::base + 0x9D3500))(s, allocator);
}

template <typename T>
struct Hw::cFixedVector
{
    int field_0;
    T* m_pBegin;
    size_t m_nCapacity;
    size_t m_nSize;
    int field_10;

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
        if (!this->m_pBegin)
            return false;

        if (this->m_nSize >= this->m_nCapacity)
            return false;

        for (int i = this->m_nSize; i > 0; --i)
            this->m_pBegin[i] = this->m_pBegin[i - 1];

        this->m_pBegin[0] = element;
        ++this->m_nSize;
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
    Node* m_pLast;
    Node* m_pFirst;
    Node* m_pEnd;

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
        return iterator(this->m_pEnd);
    }

    auto end()
    {
        return iterator(this->m_pEnd); // if we check the node with last, it'll crash for some unknown reason
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

        this->m_pEnd->m_prev = nullptr;
        this->m_pEnd->m_next = nullptr;

        this->m_pFirst = this->m_pEnd;
        this->m_pLast = this->m_pBegin;

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
            this->m_pEnd = &this->m_pBegin[capacity];
            this->setupNodes();

            return 1;
        }
        return 0;
    }

    void insert(Node* &retNode, Node* const& where, const T & element)
    {
        Node *m_pLast = this->m_pLast;
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
            this->m_pLast = m_next;
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
        this->insert(node, this->m_pEnd, element);
    }

    void push_front(const T& element)
    {
        Node* node;
        this->insert(node, this->m_pBegin, element);
    }
};

VALIDATE_SIZE(Hw::cHeap, 0x40);