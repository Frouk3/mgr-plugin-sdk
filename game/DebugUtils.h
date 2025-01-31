#pragma once

#include <Hw.h>

struct DebugEventInfo
{
    int m_nSeTotal;
    int m_nSeInUse;
    int m_nSeFree;
    int m_nBgmTotal;
    int m_nBgmInUse;
    int m_nBgmFree;
    int m_nObjTotal;
    int m_nObjInUse;
    int m_nObjFree;
    int field_24;
    int field_28;
    int field_2C;
    cVec4 m_vecListenerPosition;
    cVec4 m_vecListenerDirection;
    int m_nSysEventTotal;
    int m_nSysEventInUse;
    int m_nSysEventFree;
    int m_nSysObjTotal;
    int m_nSysObjInUse;
    int m_nSysObjFree;
    int m_nCommandTotal;
    int m_nCommandInUse;
    int m_nCommandFree;
    int m_nTransferTotal;
    int m_nTransferInUse;
    int m_nTransferFree;
    float m_fSync;
    float m_fAsync;
    Hw::cHeap *m_pSysHeap;
};