#pragma once

#include <Behavior.h>

class Pl0110 : public Behavior
{
public:
    Entity *m_pVisor;
    Entity *m_pSheath;
    Entity *m_pHead;
    float field_87C;
};

VALIDATE_SIZE(Pl0110, 0x880);