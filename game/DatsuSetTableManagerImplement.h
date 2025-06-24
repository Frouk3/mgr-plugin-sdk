#pragma once

#include <DatsuSetTableManager.h>
#include <lib.h>

class DatsuSetTableManagerImplement : public DatsuSetTableManager
{
public:
	Hw::cHeapVariable* m_Allocator;
	Hw::CriticalSection m_ResourceSection;
	int field_24;
	lib::AllocatedArray<struct DatsuSetTableResource*> *m_datsuResources;
	int field_2C;

	static inline DatsuSetTableManagerImplement*& ms_Instance = *(DatsuSetTableManagerImplement**)(shared::base + 0x1736A20);
};