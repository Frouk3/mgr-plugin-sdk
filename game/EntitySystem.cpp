#include "EntitySystem.h"
#include "shared.h"

Entity *EntitySystem::ConstructEntity(const char* name, unsigned int index, void *pInfo)
{
    return ((Entity *(__thiscall *)(EntitySystem *, const char*, unsigned int, void *))(shared::base + 0x682090))(this, name, index, pInfo);
}

// Same as previous, but only takes array of info
Entity *EntitySystem::ConstructEntity(void *pInfo)
{
    return ((Entity *(__thiscall *)(EntitySystem*, void *))(shared::base + 0x681B80))(this, pInfo);
}

EntitySystem &g_EntitySystem = *(EntitySystem*)(shared::base + 0x17E9A98);