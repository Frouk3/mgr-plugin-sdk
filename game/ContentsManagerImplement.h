#pragma once

#include <ContentsManager.h>
#include <Hw.h>
#include <lib.h>
#include <common.h>

class ContentsManagerImplement : public ContentsManager
{
public:
    Hw::cHeapVariable *m_Allocator;
    Hw::CriticalSection field_8;
    int field_24;
    int field_28;
    lib::AllocatedArray<ContentsBase *> *m_Content;
};