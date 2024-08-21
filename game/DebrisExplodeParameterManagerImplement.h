#pragma once
#include "DebrisExplodeParameterManager.h"
#include "lib.h"

class DebrisExplodeParameterManagerImplement : public DebrisExplodeParameterManager
{
public:
	Hw::cHeapVariable* m_pHeap;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	lib::AllocatedArray<struct DebrisExplodeParameterResource*>* m_pExplodeParameterResource;
	int field_2C;
};