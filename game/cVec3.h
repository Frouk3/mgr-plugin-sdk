#pragma once

struct cVec3
{
    float x;
    float y;
    float z;

    cVec3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    cVec3& operator+=(const cVec3& lhs)
    {
        this->x += lhs.x;
        this->y += lhs.y;
        this->z += lhs.z;
        return *this;
    }
};