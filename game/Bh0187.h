#pragma once

#include <Behavior.h>

class Bh0187 : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    float field_880;
    int field_884;
    int field_888;
    int field_88C;
    float field_890;
    float field_894;
    int field_898;
    int field_89C;

    Bh0187()
    {
        MAKE_CALL(shared::base + 0xE9C0, void(__thiscall *)(Bh0187 *), this);
    }

    static inline ContextInstance &m_Context = *(ContextInstance*)(shared::base + 0x1734B70);
};

VALIDATE_SIZE(Bh0187, 0x8A0);