#pragma once

#include <common.h>

class BoundingVolumeBase
{
public:
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int m_VolumeType;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
    float field_54;
    float field_58;
    float field_5C;
    float field_60;
    float field_64;
    float field_68;
    int field_6C;
    float field_70;
    float field_74;
    float field_78;
    float field_7C;
    float field_80;
    float field_84;
    float field_88;
    float field_8C;
    float field_90;
    float field_94;
    float field_98;
    float field_9C;
    float field_A0;
    float field_A4;
    float field_A8;
    float field_AC;
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
    float field_F8;
    float field_FC;

    BoundingVolumeBase()
    {
        ((void(__thiscall *)(BoundingVolumeBase *))(shared::base + 0x666D50))(this);
    }

    BoundingVolumeBase(int type)
    {
        ((void(__thiscall *)(BoundingVolumeBase *, int))(shared::base + 0x666C40))(this, type);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E99D0);

    virtual ContextInstance& getContext() { return ms_Context; };
};

class BoundingSphere : public BoundingVolumeBase
{
public:
    float field_100;
    int field_104;
    int field_108;
    int field_10C;

    BoundingSphere()
    {
        ((void(__thiscall *)(BoundingSphere *))(shared::base + 0x666F90))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E99D4);
};

class BoundingBox : public BoundingVolumeBase
{
public:
    float field_100;
    float field_104;
    float field_108;
    float field_10C;
    float field_110;
    float field_114;
    float field_118;
    float field_11C;
    float field_120;
    float field_124;
    float field_128;
    float field_12C;
    float field_130;
    float field_134;
    float field_138;
    float field_13C;
    float field_140;
    int field_144;
    int field_148;
    int field_14C;

    BoundingBox()
    {
        ((void(__thiscall *)(BoundingBox *))(shared::base + 0x667B60))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E99D8);
};

class BoundingCylinder : public BoundingVolumeBase
{
public:
    float field_100;
    float field_104;
    int field_108;
    int field_10C;

    BoundingCylinder()
    {
        ((void(__thiscall *)(BoundingCylinder *))(shared::base + 0x6681F0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E99DC);
};

class BoundingCapsule : public BoundingVolumeBase
{
public:
    float field_100;
    int field_104;
    int field_108;
    int field_10C;
    float field_110;
    float field_114;
    float field_118;
    float field_11C;
    float field_120;
    float field_124;
    float field_128;
    float field_12C;
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

    BoundingCapsule()
    {
        ((void(__thiscall *)(BoundingCapsule *))(shared::base + 0x6685C0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E99E0);
};

VALIDATE_SIZE(BoundingVolumeBase, 0x100);
VALIDATE_SIZE(BoundingSphere, 0x110);
VALIDATE_SIZE(BoundingCylinder, 0x110);
VALIDATE_SIZE(BoundingBox, 0x150);
VALIDATE_SIZE(BoundingCapsule, 0x310);