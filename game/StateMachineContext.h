#pragma once

#include <StateMachineFactory.h>

class StateMachineContext
{
public:
	StateMachineFactory* m_pFactory;
	float field_8;

	static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x19C53C0);

	virtual ContextInstance& getContext() { return *(ContextInstance*)(shared::base + 0x19C53C0); }
	virtual ~StateMachineContext() {};
};