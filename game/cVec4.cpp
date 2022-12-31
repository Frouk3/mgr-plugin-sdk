#include "cVec4.h"
#include "shared.h"

void cVec4::Normalize(cVec4& v1, cVec4& v2) noexcept
{
    DWORD address = shared::base + 0x9DF460;
    ((void (__cdecl *)(cVec4&, cVec4&))address)(v1, v2);
}