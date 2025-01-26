#pragma once

#include <Hw.h>

class RayCastManager
{
public:
    int field_4;
    int field_8;
    int field_C;
    Hw::cHeapVariable m_RayCastFactory;
    Hw::cFixedVector<int> field_68;
    Hw::cFixedVector<int> field_7C[5];
    int field_E0;
    int field_E4;
    Hw::CriticalSection field_E8;
    int field_104;
    Hw::CriticalSection field_108;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138[5];
    void *field_14C[5]; // huh?
};