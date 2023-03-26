#pragma once
#include "TargetManager.h"
#include "Entity.h"

class TargetManagerImplement : public TargetManager
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

    virtual int Function0() {};
    virtual void Function1() {};
    virtual ~TargetManagerImplement() override {};
    virtual void Function2() {};
    virtual void Function3() {};
    virtual int* Function4() {};
    virtual int Function5() {};
    virtual void Function6(int a2) {};
    virtual int Function7() {};
    virtual void Function8(void *a2) {};
    virtual int Function9() {};
    virtual void Function10(void *a2) {};
    virtual void Function11() {};
    virtual int __stdcall Function12(int a2, float a3, float a4, float a5, int a6, int a7, int a8, int a9, int a10) {};
    virtual void Function13() {};
    virtual void Function14() {};
    virtual void Function15(char *a2) {};
    virtual void Function16() {};
    virtual int Function17() {};
    virtual Entity* Function18() {};
    virtual void Function19() {};
    virtual void Function20() {};
    virtual int __stdcall Function21(int a2, float a3, float a4, float a5) {};
};

extern TargetManagerImplement*& g_pTargetManagerImplement;