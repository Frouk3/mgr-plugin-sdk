#pragma once

#include <cXmlBinary.h>
#include <cModel.h>
#include <Entity.h>
#include <shared.h>
#include <eObjID.h>
#include <common.h>
#include <cEspControler.h>
#include <HkDataManagerImplement.h>

class cObj : public cModel
{
public:
    int field_490;
    DataArchiveHolder m_DataFile;
    void* m_pModel;
    int m_nSetType;
    int m_nType;
    int m_nSetFlag;
    int m_nSetRtn;
    eObjID m_ObjId;
    eObjID m_ModelIndex;
    int field_4B8;
    int field_4BC;
    int m_nObjectFlags;
    int field_4C4;
    char field_4C8;
    char field_4C9;
    int *m_pCollisionFilter;
    int field_4D0;
    int field_4D4;
    int field_4D8;
    cEspControler *field_4DC;
    int field_4E0;
    int field_4E4;
    int field_4E8;
    int m_nHashNo;
    Entity *m_pEntity;
    cXmlBinary m_BxmReader;
    int field_514;
    cObj *m_pOwner;
    int field_51C;
    int field_520;
    float field_524;
    int field_528;
    int field_52C;

    // vft

    ContextInstance& getContext()
    {
        return ReturnCallVMTFunc<ContextInstance&, 1, cObj*>(this);
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

    void setCollisionFilter(int* pCollisionFilter)
    {
        CallVMTFunc<15, cObj*, int*>(this, pCollisionFilter);
    }

    // vft end 

    cObj()
    {
        ((void(__thiscall*)(cObj*))(shared::base + 0x5FD150))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x177B380);
};

VALIDATE_SIZE(cObj, 0x530);