#pragma once

#include <lib.h>
#include <EntityHandle.h>

struct ReactionObjectManager
{
    lib::AllocatedArray<EntityHandle> *m_ReactionObjects;
    int field_4;
    int field_8;
};