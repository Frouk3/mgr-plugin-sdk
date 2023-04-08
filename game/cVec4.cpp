#include "cVec4.h"
#include "shared.h"

void cVec4::Normalize(cVec4* v1, cVec4* v2)
{
    ((void (__cdecl *)(cVec4*, cVec4*))(shared::base + 0x9DF460))(v1, v2);
}

void cVec4::operator=(cVec4& right)
{
    this->x = right.x;
    this->y = right.y;
    this->z = right.z;
    this->w = right.w;
}