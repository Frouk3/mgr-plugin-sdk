#pragma once

#include <BehaviorEmBase.h>

class EmBaseDLC : public BehaviorEmBase
{ 
public:
	int field_DC0;
	int field_DC4;
	int field_DC8;
	int field_DCC;
	cEspControler m_RageEsp;
	int m_bWasRaged;
	float m_fRageDuration;
	int field_E88;
	int field_E8C;

	EmBaseDLC() { MAKE_CALL(shared::base + 0x6A73F0, void(__thiscall *)(EmBaseDLC*), this); }

	void SetRaged(void *a2 = nullptr)
	{
		MAKE_VCALL(220, void(__thiscall *)(EmBaseDLC *, void *), this, a2);
	}

	static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9C3C);
};

VALIDATE_SIZE(EmBaseDLC, 0xE90);