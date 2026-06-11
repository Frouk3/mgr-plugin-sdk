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
        Hw::cVec4 m_vecEventPosition;
    };

    Hw::cHeapVariable *m_Allocator;
    Hw::cCriticalSection field_8;
    int field_24;
    lib::AllocatedArray<Unit *> *m_UnitArray;
    int field_2C;

    static inline SituationManagerImplement *get()
    {
        return MAKE_CALL(shared::base + 0x8206D0, SituationManagerImplement *(__cdecl *)());
    }
};

inline SituationManagerImplement*& g_SituationManager = *(SituationManagerImplement**)(shared::base + 0x17EA1A4);

VALIDATE_SIZE(SituationManagerImplement, 0x30);