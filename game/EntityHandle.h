#pragma once
#include <shared.h>
#include <common.h>

class Entity;
struct EntitySystem;

class EntityHandle : public sHandle<Entity>
{
public:

    operator Entity* ()
    {
        return ((Entity * (__thiscall*)(EntityHandle*))(shared::base + 0x681330))(this);
    }

    Entity *getEntity()
    {
        return *this;
    }

    EntityHandle& operator=(Entity *entity)
    {
        ((void(__thiscall *)(EntityHandle *, Entity *))(shared::base + 0x67C970))(this, entity);
        return *this;
    }
};