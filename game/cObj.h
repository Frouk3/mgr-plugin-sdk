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
    Hw::cFmerge m_DataFile;
    void* m_pModel;
    int m_SetType;
    int m_Type;
    int m_SetFlag;
    int m_SetRtn;
    eObjID m_ObjId;
    eObjID m_ModelIndex;
    int field_4B8;
    int field_4BC;
    unsigned int m_ObjectFlags;
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

    cObj() { CallMethod<0x5FD150, cObj*>(this); }

    // vft

    ContextInstance& getContext() { return ReturnCallVMTFunc<ContextInstance&, 1, cObj*>(this); }
    BOOL createDummy() { return ReturnCallVMTFunc<BOOL, 2, cObj*>(this); }
    void fadeOut() { CallVMTFunc<3, cObj*>(this); }
    void updateBoneTransform() { CallVMTFunc<6, cObj*>(this); }
    void onDisp() { CallVMTFunc<7, cObj*>(this); }
    void offDisp() { CallVMTFunc<8, cObj*>(this); }
    void setCollisionFilter(int* pCollisionFilter) { CallVMTFunc<15, cObj*, int*>(this, pCollisionFilter); }

    // vft end 

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x177B380);
};

VALIDATE_SIZE(cObj, 0x530);