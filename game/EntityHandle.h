#pragma once
#include <shared.h>
#include <common.h>

class Entity;
struct EntitySystem;

class EntityHandle : public sHandle<Entity>
{
public:

	operator Entity* () const { return getEntity(); }
	Entity* getEntity() const { return MAKE_CALL(shared::base + 0x681330, Entity*(__thiscall *)(const EntityHandle*), this); }

	EntityHandle& operator=(Entity* entity) { return MAKE_CALL(shared::base + 0x67C970, EntityHandle&(__thiscall *)(EntityHandle*, Entity*), this, entity); }
};