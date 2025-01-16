#pragma once

#include <ModelSystem.h>
#include <cModelList.h>
#include <cModel.h>

class SceneModelSystem : public ModelSystem
{
public:
    Hw::cHeapVariable *field_4;
    cModelList m_ModelList;
    int field_50;
    Hw::cHeapVariable *field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    Hw::CriticalSection field_68;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    Hw::cFixedVector<cModel*> m_Models;
    int field_BC;

    SceneModelSystem()
    {
        ((void (__thiscall *)(SceneModelSystem *))(shared::base + 0x6197D0))(this);
    }

    void removeModel(cModel *model)
    {
        ((void(__thiscall *)(SceneModelSystem *, cModel *))(shared::base + 0x618C30))(this, model);
    }

    void addModel(cModel *model)
    {
        ((void(__thiscall *)(SceneModelSystem *, cModel *))(shared::base + 0x618BE0))(this, model);
    }

    static inline SceneModelSystem &Instance = *(SceneModelSystem*)(shared::base + 0x177B628);
};