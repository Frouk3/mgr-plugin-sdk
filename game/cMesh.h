#pragma once
#include "cMeshBase.h"

class cMesh : public cMeshBase
{
public:

    cMesh()
    {
        MAKE_CALL(shared::base + 0x611B50, void(__thiscall *)(cMesh *), this);
    }
};