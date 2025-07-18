#pragma once

#include <TargetManager.h>
#include <Entity.h>

class TargetManagerImplement : public TargetManager
{
public:
    int field_4;
    int field_8;
    Entity* m_TargetEntity;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;

    static inline TargetManagerImplement*& pInstance = *(TargetManagerImplement**)(shared::base + 0x17EA108);
};

VALIDATE_SIZE(TargetManagerImplement, 0x24);