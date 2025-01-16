#pragma once

#include <shared.h>

struct cZandatsuTarget
{

    cZandatsuTarget& operator=(const cZandatsuTarget& lhs)
    {
        ((void(__thiscall*)(cZandatsuTarget *, const cZandatsuTarget&))(shared::base + 0x4A50C0))(this, lhs);
        return *this;
    }
};