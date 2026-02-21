#pragma once

#include <ContentsManager.h>
#include <Hw.h>
#include <lib.h>
#include <common.h>

class ContentsManagerImplement : public ContentsManager
{
public:
    Hw::cHeapVariable *m_pHeap;
    Hw::cCriticalSection m_CriticalSection;
    int field_24;
    int m_RotateContentsId;
    lib::AllocatedArray<ContentsBase *> *m_pContent;
};