#pragma once

#include <hkpShape.h>

class hkpShape;
class hkMotionState;
class hkpCollidable;

class hkpCdBody
{
public:
    friend class hkpCollidable;
public:
    const hkpShape*       m_shape;
    hkpShapeKey           m_shapeKey;
public:
	const void* m_motion;

public:
	const hkpCdBody* m_parent;
};