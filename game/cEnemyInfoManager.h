#pragma once

#include <cHeadMark.h>
#include <cCutPointDisp.h>
#include <cEnemyTarget.h>
#include <cEnemyEnergyGauge.h>
#include <cEnemyEnergyGaugePrologue.h>
#include <cItemBoxTargetCursor.h>
#include <cEnemyName.h>
#include <cEnemyItemDisp.h>
#include <cEnemyTargetDisp.h>
#include <cEnemyLeftHandInfo.h>
#include <cGrenadeMark.h>
#include <cNpcInfo.h>
#include <cWeakPointDisp.h>
#include <cWeakPointLineDisp.h>
#include <cItemTargetCursor.h>
#include <cSlashFinishLine.h>
#include <cLockOnMarkerDisp.h>

class cEnemyInfoManager
{
public:
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    cHeadMark *m_pcHeadMark;
    cCutPointDisp *m_pCutPointDisp;
    cEnemyTarget *m_pEnemyTarget;
    cEnemyEnergyGauge *m_pEnemyEnergyGauge;
    cEnemyEnergyGaugePrologue *m_pEnemyEnergyGaugePrologue;
    cItemBoxTargetCursor *m_pcItemBoxTargetCursor;
    cEnemyName *m_pcEnemyName;
    cEnemyItemDisp *m_pcEnemyItemDisp;
    cEnemyTargetDisp *m_pEnemyTargetDisp;
    cEnemyLeftHandInfo *m_pEnemyLeftHandInfo;
    cGrenadeMark *m_pGrenadeMark;
    cNpcInfo *m_pNPCInfo;
    cWeakPointDisp *m_pWeakPointDisp;
    cWeakPointLineDisp *m_pWeakPointLineDisp;
    cItemTargetCursor *m_pItemTargetCursor;
    cSlashFinishLine *m_pSlashFinishLine;
    int field_88;
    cLockOnMarkerDisp *m_pLockOnMarkerDisp;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;

    virtual ~cEnemyInfoManager() {};

    static inline cEnemyInfoManager& ms_Instance = *(cEnemyInfoManager*)(shared::base + 0x1737940);
};