#pragma once
#include <DebrisExplodeParameterManager.h>
#include <lib.h>

class DebrisExplodeParameterManagerImplement : public DebrisExplodeParameterManager
{
public:
	Hw::cHeapVariable* m_Allocator;
	Hw::CriticalSection m_ResourceSection;
	int field_24;
	lib::AllocatedArray<struct DebrisExplodeParameterResource*>* m_explodeParameterResources;
	int field_2C;

	static inline DebrisExplodeParameterManagerImplement* &ms_Instance = *(DebrisExplodeParameterManagerImplement**)(shared::base + 0x1736A50);
};