#pragma once

#include <eObjID.h>
#include <FileRead.h>
#include <HkDataManagerImplement.h>

class cObjReadManager
{
public:
    eObjID m_Object;
    int field_4; // From what I've seen in the code, this member might or might not be a set type
    int m_Attempts; // How many attempts we need to spend for checking if the object is loaded

    BOOL getObjectData(Hw::cFmerge& holder, eObjID object) { return ReturnCallMethod<BOOL, 0x5FE6B0, cObjReadManager*, Hw::cFmerge&, eObjID>(this, holder, object); }
    BOOL getDataAtSet(Hw::cFmerge& data, eObjID object, int setType) { return ReturnCallMethod<BOOL, 0x601170, cObjReadManager*, Hw::cFmerge&, eObjID, int>(this, data, object, setType); }
    BOOL requestObject(eObjID object, int setType) { return ReturnCallMethod<BOOL, 0x600A60, cObjReadManager*, eObjID, int>(this, object, setType); }
    BOOL isObjectLoaded(eObjID object, int setType) { return ReturnCallMethod<BOOL, 0x600CA0, cObjReadManager*, eObjID, int>(this, object, setType); }
    void removeRequest(eObjID object, int setType) { CallMethod<0x600BD0, cObjReadManager*, eObjID, int>(this, object, setType); }
    void removeReference(eObjID object, int setType) { CallMethod<0x5FE7D0, cObjReadManager*, eObjID, int>(this, object, setType); }
    void addUseRef(eObjID object, int setType) { CallMethod<0x5FE710, cObjReadManager*, eObjID, int>(this, object, setType); }
    void updateHookLoading() { CallMethod<0x604670, cObjReadManager *>(this); }
};

inline cObjReadManager& g_ObjReadManager = *(cObjReadManager*)(shared::base + 0x177B364);

namespace ObjReadSystem
{
    class Work : public FileRead::Listener
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
    };
}