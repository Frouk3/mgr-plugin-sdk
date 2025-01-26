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
};