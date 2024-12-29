#pragma once

#include <hkpShapeRayCastOutput.h>

class hkpCollidable;

struct hkpWorldRayCastOutput: public hkpShapeRayCastOutput
{
public:
    const hkpCollidable *m_rootCollidable;
    int field_48;
    int field_4C;
    hkpCdBody *field_50;
    int field_54;
    int field_58;
    int field_5C;
};

typedef hkpWorldRayCastOutput hkpWorldRayCastOutputPpu;