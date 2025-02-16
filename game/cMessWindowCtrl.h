#pragma once

#include <cMessWindow.h>

class cMessWindowCtrl
{
public:
    cMessWindow *m_pcMessWindow;
    int field_8;
    int field_C;

    virtual ~cMessWindowCtrl() {};

    int createWindow(int a2, int a3, int a4)
    {
        return ReturnCallVMTFunc<int, 1, cMessWindowCtrl *, int, int, int>(this, a2, a3, a4);
    }
};