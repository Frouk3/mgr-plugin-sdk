#include "EntitySystem.h"
#include "shared.h"

Entity *EntitySystem::ConstructEntity(const char* name, unsigned int index, ObjectInfo *pObjInfo)
{
    return ((Entity *(__thiscall *)(EntitySystem *, const char*, unsigned int, ObjectInfo *))(shared::base + 0x682090))(this, name, index, pObjInfo);
}

// Same as previous, but only takes array of info
Entity *EntitySystem::ConstructEntity(EntityInfo *pInfo)
{
    return ((Entity *(__thiscall *)(EntitySystem*, EntityInfo *))(shared::base + 0x681B80))(this, pInfo);
}

EntitySystem &g_EntitySystem = *(EntitySystem*)(shared::base + 0x17E9A98);