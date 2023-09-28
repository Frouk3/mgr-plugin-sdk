#pragma once

struct cVec3
{
    float x;
    float y;
    float z;

    cVec3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
    {
        this->x, this->y, this->z = x, y, z;
    }
};