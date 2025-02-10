#pragma once

#include <Behavior.h>

class E3_EnemyBoardDebrisSokushi : public Behavior
{
public:

    E3_EnemyBoardDebrisSokushi()
    {
        ((void(__thiscall *)(E3_EnemyBoardDebrisSokushi *))(shared::base + 0x6A6C40))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1734B54);
};

VALIDATE_SIZE(E3_EnemyBoardDebrisSokushi, 0x870);