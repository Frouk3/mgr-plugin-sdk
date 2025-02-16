#pragma once

#include <SituationManager.h>
#include <Entity.h>
#include <Hw.h>
#include <lib.h>

class SituationManagerImplement : public SituationManager
{
public:
    struct Unit
    {
        int field_0;
        EntityHandle m_Entity;
        eObjID m_Object;
        int field_C;
        cVec4 m_vecEventPosition;
    };

    Hw::cHeapVariable *m_Allocator;
    Hw::CriticalSection field_8;
    int field_24;
    lib::AllocatedArray<Unit *> *m_UnitArray;
    int field_2C;

    static inline SituationManagerImplement*& ms_Instance = *(SituationManagerImplement**)(shared::base + 0x17EA1A4);

    static inline SituationManagerImplement *get()
    {
        return ((SituationManagerImplement *(__cdecl *)())(shared::base + 0x8206D0))();
    }
};

VALIDATE_SIZE(SituationManagerImplement, 0x30);