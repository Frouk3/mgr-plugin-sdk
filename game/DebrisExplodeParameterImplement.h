#pragma once

#include <DebrisExplodeParameter.h>

class DebrisExplodeParameterImplement : public DebrisExplodeParameter
{
public:
	Hw::cHeapVariable* m_Allocator;
	int field_8;
};