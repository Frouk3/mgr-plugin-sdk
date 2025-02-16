#pragma once

#include <Hw.h>
#include <Entity.h>

namespace SoundArea
{
    class Shape
    {
    public:
        int field_4;
        int field_8;
        int field_C;
        D3DXMATRIX field_10;
        float field_50;
        float field_54;
        float field_58;
        float field_5C;
        float field_60;
        float field_64;
        float field_68;
        float field_6C;
        float field_70;
        float field_74;
        float field_78;
        float field_7C;
        float field_80;
        float field_84;
        float field_88;
        float field_8C;
        D3DXMATRIX field_90;
        D3DXMATRIX field_D0;
        Entity *field_110;
        int field_114;
        int field_118;
        int field_11C;

        virtual ~Shape() {};
    };

    class ShapeSphere : public Shape
    {
    public:
        int field_120;
        int field_124;
        int field_128;
        float field_12C;
        float field_130;
        D3DXVECTOR3 field_134;
        float field_140;
        float field_144;
        float field_148;
        int field_14C;
    };

    class ShapeBox : public Shape
    {
    public:
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
        float field_154;
        float field_158;
        int field_15C;
        int field_160;
        int field_164;
        int field_168;
        float field_16C;
        float field_170;
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
        float field_1A0;
        float field_1A4;
        float field_1A8;
        float field_1AC;
        int field_1B0;
        int field_1B4;
        int field_1B8;
        int field_1BC;
    };

    class ShapeLine : public Shape
    {
    public:
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
    };

    class ShapePrism : public Shape
    {
    public:
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
    };

    class ShapeRail : public Shape
    {
    public:
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
    };

    
}