#pragma once

class stKogekkoCamParamBase
{
public:

    virtual ~stKogekkoCamParamBase() {};
};

class stKogekkoCamParamNormal : public stKogekkoCamParamBase
{
public:
    int field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
};

class stKogekkoCamParamNarrow : public stKogekkoCamParamBase
{
public:
    int field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
};