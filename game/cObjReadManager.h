#pragma once

#include <eObjID.h>
#include <FileRead.h>

struct cObjReadManager
{
    eObjID m_Object;
    int field_4; // From what I've seen in the code, this member might or might not be a set type
    int m_Tries; // How many tries we have to load the object?
};

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