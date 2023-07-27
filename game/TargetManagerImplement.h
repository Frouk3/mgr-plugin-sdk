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

    
};

extern TargetManagerImplement*& g_pTargetManagerImplement;