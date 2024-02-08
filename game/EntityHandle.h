#pragma once
#include "shared.h"

struct Entity;

struct EntityHandle
{
    unsigned int m_nHandle;

    Entity* getEntity()
    {
        return ((Entity *(__thiscall*)(EntityHandle*))(shared::base + 0x681330))(this);
    }

    EntityHandle &operator=(Entity* entity)
    {
        return *((EntityHandle * (__thiscall*)(EntityHandle*, Entity*))(shared::base + 0x67C970))(this, entity);
    }
};