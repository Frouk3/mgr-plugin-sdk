#pragma once

#include "cXmlBinary.h"
#include "cModel.h"
#include "Entity.h"
#include "shared.h"
#include "eObjID.h"
#include "common.h"
#include <cEspControler.h>

#define OBJ_CONTEXT(c) c::Context

class cObj : public cModel
{
public:
    int field_490;
    void* m_DataFile;
    int field_498;
    int m_pModel;
    int m_nSetType;
    int m_nType;
    int m_nSetFlag;
    int m_nSetRtn;
    eObjID m_nObjId;
    eObjID m_nModelIndex;
    int field_4B8;
    int field_4BC;
    int m_nObjectFlags;
    int field_4C4;
    char field_4C8;
    char field_4C9;
    int* m_pGroupId;
    int field_4D0;
    int field_4D4;
    int field_4D8;
    cEspControler* field_4DC;
    int field_4E0;
    int field_4E4;
    int field_4E8;
    int m_nHashNo;
    Entity* m_pEntity;
    cXmlBinary field_4F4;
    int field_514;
    cObj* m_pOwner;
    int field_51C;
    int field_520;
    float field_524;
    int field_528;
    int field_52C;

    // vft

    ContextInstance* getContext()
    {
        return ReturnCallVMTFunc<ContextInstance*, 1, cObj*>(this);
    }

    BOOL createDummy()
    {
        return ReturnCallVMTFunc<BOOL, 2, cObj*>(this);
    }

    void fadeOut()
    {
        CallVMTFunc<3, cObj*>(this);
    }

    void enableRender()
    {
        CallVMTFunc<7, cObj*>(this);
    }

    void disableRender()
    {
        CallVMTFunc<8, cObj*>(this);
    }

    void setGroupId(int* idPtr)
    {
        CallVMTFunc<15, cObj*, int*>(this, idPtr);
    }

    // vft end 

    cObj()
    {
        ((void(__thiscall*)(cObj*))(shared::base + 0x5FD150))(this);
    }

    static inline ContextInstance& Context = *(ContextInstance*)(shared::base + 0x177B380);
};

VALIDATE_SIZE(cObj, 0x530);