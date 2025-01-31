#pragma once

#include <DatsuSetTable.h>

class DatsuSetTableImplement : public DatsuSetTable
{
public:
	Hw::cHeapVariable* m_Allocator;
	int field_8;
};