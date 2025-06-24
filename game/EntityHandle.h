#pragma once
#include <shared.h>
#include <common.h>

struct Entity;
struct EntitySystem;

class EntityHandle : public sHandle<Entity>
{
public:

    operator Entity*();

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