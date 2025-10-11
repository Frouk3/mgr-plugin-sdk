#pragma once

#include <eObjID.h>
#include <FileRead.h>
#include <HkDataManagerImplement.h>

struct cObjReadManager
{
    eObjID m_Object;
    int field_4; // From what I've seen in the code, this member might or might not be a set type
    int m_Tries; // How many tries we have to load the object?

    BOOL getObjectData(DataArchiveHolder* holder, eObjID object)
    {
        return ((BOOL(__thiscall*)(cObjReadManager*, DataArchiveHolder*, eObjID))(shared::base + 0x5FE6B0))(this, holder, object);
    }

    BOOL getDataAtSet(DataArchiveHolder* data, eObjID object, int setType)
    {
        return ((BOOL(__thiscall*)(cObjReadManager*, DataArchiveHolder*, eObjID, int))(shared::base + 0x601170))(this, data, object, setType);
    }

    BOOL requestObject(eObjID object, int setType)
    {
        return ((BOOL(__thiscall*)(cObjReadManager*, eObjID, int))(shared::base + 0x600A60))(this, object, setType);
    }

    BOOL isObjectLoaded(eObjID object, int setType)
    {
        return ((BOOL(__thiscall*)(cObjReadManager*, eObjID, int))(shared::base + 0x600CA0))(this, object, setType);
    }

    void removeRequest(eObjID object, int setType)
    {
        ((void(__thiscall*)(cObjReadManager*, eObjID, int))(shared::base + 0x600BD0))(this, object, setType);
    }

    void removeReference(eObjID object, int setType)
    {
        ((void(__thiscall*)(cObjReadManager*, eObjID, int))(shared::base + 0x5FE7D0))(this, object, setType);
    }

    void removeUseRef(eObjID object, int setType)
    {
        ((void(__thiscall*)(cObjReadManager*, eObjID, int))(shared::base + 0x5FE7D0))(this, object, setType);
    }

    void addUseRef(eObjID object, int setType)
    {
        ((void(__thiscall*)(cObjReadManager*, eObjID, int))(shared::base + 0x5FE710))(this, object, setType);
    }
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