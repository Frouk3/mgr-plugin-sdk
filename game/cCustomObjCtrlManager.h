#pragma once

#include <cUISystem.h>

class cCustomObjCtrlManager
{
public:
    int field_4;
    int field_8;
    char *m_Name;
    int field_10;
    cUIWorkBase *m_UIWork;
    cCustomObjCtrl *m_ObjCtrl;

    virtual ~cCustomObjCtrlManager() {};
};