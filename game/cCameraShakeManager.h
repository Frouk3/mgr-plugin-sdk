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

    cCameraShake() { MAKE_CALL(shared::base + 0x9A3EC0, void(__thiscall *)(cCameraShake*), this); }
    virtual ~cCameraShake() {}
    // non virtual destructor at 0x99FBF0

    void init() { MAKE_VCALL(1, void(__thiscall *)(cCameraShake*), this); }
    void move() { MAKE_VCALL(2, void(__thiscall *)(cCameraShake*), this); }
    void getAddShake(Hw::cVec4& addPos, Hw::cVec4& addRot, Hw::cVec4& nowPos, const Hw::cVec4& nowView, const Hw::cVec4& up) { MAKE_VCALL(3, void(__thiscall *)(cCameraShake*, Hw::cVec4&, Hw::cVec4&, Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&), this, addPos, addRot, nowPos, nowView, up); }

    void onBeFlag(eBeFlag flag) { MAKE_CALL(shared::base + 0x9A3AE0, void(__thiscall *)(cCameraShake*, eBeFlag), this, flag); }
    void offBeFlag(eBeFlag flag) { MAKE_CALL(shared::base + 0x9A3AF0, void(__thiscall *)(cCameraShake*, eBeFlag), this, flag); }
    int isBeFlag(eBeFlag flag) { return MAKE_CALL(shared::base + 0x9A3B00, int(__thiscall *)(cCameraShake*, eBeFlag), this, flag); }
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

    cCameraShakeOld() { MAKE_CALL(shared::base + 0x9B2260, void(__thiscall *)(cCameraShakeOld*), this); }
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

    cCameraShakeAxis() { MAKE_CALL(shared::base + 0x9BB7C0, void(__thiscall *)(cCameraShakeAxis*), this); }
    // non virtual destructor at 0x9A39B0
};

class cCameraShakeManager
{
public:
    int m_bShakeMoveStop;
    int m_bShakeMove;
    Hw::cCriticalSection m_CriticalSection;

    void startup() { MAKE_CALL(shared::base + 0x9B1DB0, void(__thiscall *)(cCameraShakeManager*), this); }
    void cleanup() { MAKE_CALL(shared::base + 0x9B1DD0, void(__thiscall *)(cCameraShakeManager*), this); }
    void move() { MAKE_CALL(shared::base + 0x9B1DE0, void(__thiscall *)(cCameraShakeManager*), this); }
    void allKill() { MAKE_CALL(shared::base + 0x9B21E0, void(__thiscall *)(cCameraShakeManager*), this); }
    cCameraShakeAxis *set(float power, float speed, float time, float speedDec, int priority) { return MAKE_CALL(shared::base + 0x9B1FC0, cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, float, float, float, float, int), this, power, speed, time, speedDec, priority); }
    cCameraShakeAxis *setShakeFrame(float power, float speed, float time, float speedDec, int priority) { return MAKE_CALL(shared::base + 0x9BB640, cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, float, float, float, float, int), this, power, speed, time, speedDec, priority); }
    cCameraShakeAxis *setShakeAxis(const Hw::cVec4& pow, const Hw::cVec4& rot, int priority) { return MAKE_CALL(shared::base + 0x9A39C0, cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, const Hw::cVec4&, const Hw::cVec4&, int), this, pow, rot, priority); }
    cCameraShakeAxis *setShakeAxis(float powX, float powY, float powZ, int priority) { return MAKE_CALL(shared::base + 0x9B2140, cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, float, float, float, int), this, powX, powY, powZ, priority); }
    cCameraShakeAxis *setShakeAxis(float powX, float powY, float powZ, float rotX, float rotY, float rotZ, int priority) { return MAKE_CALL(shared::base + 0x9B2190, cCameraShakeAxis *(__thiscall *)(cCameraShakeManager *, float, float, float, float, float, float, int), this, powX, powY, powZ, rotX, rotY, rotZ, priority); }
};

class cCameraShakeAllocator
{
public:
    cCameraShakeAxis m_UnitList[16];
    cCameraShakeAxis m_DummyUnit;

    cCameraShakeAllocator() { MAKE_CALL(shared::base + 0x9C2F10, void(__thiscall *)(cCameraShakeAllocator *), this); }
    ~cCameraShakeAllocator() { MAKE_CALL(shared::base + 0x9BB620, void(__thiscall *)(cCameraShakeAllocator *), this); } // More like of destructor than a cleanup
};

inline cCameraShakeManager& g_CamShakeMan = *(cCameraShakeManager *)(shared::base + 0x17EB8E0);
inline cCameraShakeAllocator& g_CamShakeAlloc = *(cCameraShakeAllocator *)(shared::base + 0x19C5F60);

VALIDATE_SIZE(cCameraShake, 0xC);
VALIDATE_SIZE(cCameraShakeOld, 0x2C);
VALIDATE_SIZE(cCameraShakeAxis, 0x44);
VALIDATE_SIZE(cCameraShakeManager, 0x24);
VALIDATE_SIZE(cCameraShakeAllocator, 0x484);