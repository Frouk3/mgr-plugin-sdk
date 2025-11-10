#pragma once
#include <shared.h>
#include <Hw.h>

// cCameraShake, cCameraShakeOld, cCameraShakeAxis -> Completed

class __declspec(align(4)) /*alignment just for mark*/ cCameraShake
{
public:
    unsigned int m_BeFlag;
    char m_priority;
    char m_Type;

    enum eBeFlag : unsigned int
    {
        BE_ALIVE = 0x1,
        BE_MODE = 0x2,
        BE_MODE_DEC = 0x4,
        BE_MODE_TIME = 0x8,
        BE_MOVE = 0x10,
    };

    cCameraShake() { ((void(__thiscall *)(cCameraShake *))(shared::base + 0x9A3EC0))(this); }
    virtual ~cCameraShake() {}
    // non virtual destructor at 0x99FBF0

    void init() { CallVMTFunc<1, cCameraShake*>(this); }
    void move() { CallVMTFunc<2, cCameraShake*>(this); }
    void getAddShake(Hw::cVec4& addPos, Hw::cVec4& addRot, Hw::cVec4& nowPos, const Hw::cVec4& nowView, const Hw::cVec4& up) { CallVMTFunc<3, cCameraShake*, Hw::cVec4&, Hw::cVec4&, Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&>(this, addPos, addRot, nowPos, nowView, up); }

    void onBeFlag(eBeFlag flag) { ((void(__thiscall *)(cCameraShake*, eBeFlag))(shared::base + 0x9A3AE0))(this, flag); }
    void offBeFlag(eBeFlag flag) { ((void(__thiscall *)(cCameraShake*, eBeFlag))(shared::base + 0x9A3AF0))(this, flag); }
    int isBeFlag(eBeFlag flag) { return ((int(__thiscall *)(cCameraShake*, eBeFlag))(shared::base + 0x9A3B00))(this, flag); }
};

class cCameraShakeOld : public cCameraShake
{
public:
    float m_shake;
    float m_dir;
    float m_dir_y;
    float m_speed;
    float m_timer;
    float m_spd_dec;
    float m_power;
    float m_power_y;

    cCameraShakeOld() { ((void(__thiscall *)(cCameraShakeOld *))(shared::base + 0x9B2260))(this); }
    // non virtual destructor at 0x9B1DA0
};

class cCameraShakeAxis : public cCameraShakeOld
{
public:
    float m_AxisPowX;
    float m_AxisPowY;
    float m_AxisPowZ;
    float m_AxisRotX;
    float m_AxisRotY;
    float m_AxisRotZ;

    cCameraShakeAxis() { ((void(__thiscall *)(cCameraShakeAxis *))(shared::base + 0x9BB7C0))(this); }
    // non virtual destructor at 0x9A39B0
};

class cCameraShakeManager
{
public:
    int m_bShakeMoveStop;
    int m_bShakeMove;
    Hw::cCriticalSection m_CriticalSection;

    void startup() { ((void(__thiscall *)(cCameraShakeManager *))(shared::base + 0x9B1DB0))(this); }
    void cleanup() { ((void(__thiscall *)(cCameraShakeManager *))(shared::base + 0x9B1DD0))(this); }
    void move() { ((void(__thiscall *)(cCameraShakeManager *))(shared::base + 0x9B1DE0))(this); }
    void allKill() { ((void(__thiscall *)(cCameraShakeManager *))(shared::base + 0x9B21E0))(this); }
    cCameraShakeAxis *set(float power, float speed, float time, float speedDec, int priority) { return ((cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, float, float, float, float, int))(shared::base + 0x9B1FC0))(this, power, speed, time, speedDec, priority); }
    cCameraShakeAxis *setShakeFrame(float power, float speed, float time, float speedDec, int priority) { return ((cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, float, float, float, float, int))(shared::base + 0x9BB640))(this, power, speed, time, speedDec, priority); }
    cCameraShakeAxis *setShakeAxis(const Hw::cVec4& pow, const Hw::cVec4& rot, int priority) { return ((cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, const Hw::cVec4&, const Hw::cVec4&, int))(shared::base + 0x9A39C0))(this, pow, rot, priority); }
    cCameraShakeAxis *setShakeAxis(float powX, float powY, float powZ, int priority) { return ((cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, float, float, float, int))(shared::base + 0x9B2140))(this, powX, powY, powZ, priority); }
    cCameraShakeAxis *setShakeAxis(float powX, float powY, float powZ, float rotX, float rotY, float rotZ, int priority) { return ((cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, float, float, float, float, float, float, int))(shared::base + 0x9B2190))(this, powX, powY, powZ, rotX, rotY, rotZ, priority); }
    cCameraShakeAxis *getMaxPow(Hw::cVec4& addPos, Hw::cVec4& addRot, Hw::cVec4& nowPos, const Hw::cVec4& nowView, const Hw::cVec4& up) { return ((cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, Hw::cVec4&, Hw::cVec4&, Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&))(shared::base + 0x9B1E20))(this, addPos, addRot, nowPos, nowView, up); }
    unsigned int numAliveWork() { return ((unsigned int(__thiscall *)(cCameraShakeManager *))(shared::base + 0x9B1F20))(this); }
};

class cCameraShakeAllocator
{
public:
    cCameraShakeAxis m_UnitList[16];
    cCameraShakeAxis m_DummyUnit;

    cCameraShakeAllocator() { ((void(__thiscall *)(cCameraShakeAllocator *))(shared::base + 0x9C2F10))(this); }
    ~cCameraShakeAllocator() { ((void(__thiscall *)(cCameraShakeAllocator *))(shared::base + 0x9BB620))(this); } // More like of destructor than a cleanup
};

inline cCameraShakeManager& g_CamShakeMan = *(cCameraShakeManager *)(shared::base + 0x17EB8E0);
inline cCameraShakeAllocator& g_CamShakeAlloc = *(cCameraShakeAllocator *)(shared::base + 0x19C5F60);

VALIDATE_SIZE(cCameraShake, 0xC);
VALIDATE_SIZE(cCameraShakeOld, 0x2C);
VALIDATE_SIZE(cCameraShakeAxis, 0x44);
VALIDATE_SIZE(cCameraShakeManager, 0x24);
VALIDATE_SIZE(cCameraShakeAllocator, 0x484);