#pragma once

#include "DatsuSetTable.h"

class DatsuSetTableImplement : public DatsuSetTable
{
public:
	Hw::cHeapVariable* m_pHeap;
	int field_8;
};