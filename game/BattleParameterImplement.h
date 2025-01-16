#pragma once

#include <BattleParameter.h>

class BattleParameterImplement : public BattleParameter
{
public:
    Hw::cHeapVariable *m_Allocator;
    int field_8;
};