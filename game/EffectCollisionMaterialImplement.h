#pragma once

#include <EffectCollisionMaterial.h>
#include <shared.h>

class EffectCollisionMaterialImplement : public EffectCollisionMaterial
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

    static inline EffectCollisionMaterialImplement *&ms_Instance = *(EffectCollisionMaterialImplement**)(shared::base + 0x1735DBC);
};