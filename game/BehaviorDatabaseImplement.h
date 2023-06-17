#pragma once
#include "BehaviorDatabase.h"
#include "Behavior.h"
#include "lib.h"

class BehaviorDatabaseImplement : public BehaviorDatabase
{
public:
    struct UsedContainer
    {
        int field_0;
        int field_4;
        int field_8;
    };
    lib::AllocatedArray<BehaviorDatabaseImplement::UsedContainer> *m_pUsedContainer;
    lib::StaticArray<BehaviorData *, 2048> *m_pBehaviorData;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;

    int Function0(int a2);
    int Function1(int a2);
    void Function2(float a2);
    int Function3();
    void Function4(int a2, int a3);
    virtual ~BehaviorDatabaseImplement() override {};
};

extern BehaviorDatabaseImplement*& g_pBehaviorDatabaseImplement;
BehaviorDatabaseImplement *GetBehaviorDatabaseImplement();