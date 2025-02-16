#pragma once

#include <cTaskManager.h>
#include <FileRead.h>

struct GameManager
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int m_nCoreDatReader;
    int m_nCoreDttReader;
    int m_TempDataBuffer;
    int field_30;
    int m_nCoreEffDataId;
    int m_nCoreEffDttId;
    int field_3C;
    int field_40;
    int m_nCoreUIDataId;
    int m_nCoreUIDttId;
    int field_4C;
    int field_50;
    int m_nCoreDlcDataId;
    int field_58;
    int field_5C;
    int field_60;
    cTaskManager m_TaskManager;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int m_bShowInterface;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
};