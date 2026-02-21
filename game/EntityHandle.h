#pragma once
#include <shared.h>
#include <common.h>

class Entity;
struct EntitySystem;

class EntityHandle : public sHandle<Entity>
{
public:

	operator Entity* () const { return getEntity(); }
	Entity* getEntity() const { return ReturnCallMethod<Entity*, 0x681330, const EntityHandle*>(this); }

	EntityHandle& operator=(Entity* entity) { return ReturnCallMethod<EntityHandle&, 0x67C970, EntityHandle*, Entity*>(this, entity); }
};