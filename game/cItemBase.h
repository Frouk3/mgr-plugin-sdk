#pragma once
#include <shared.h>
#include <Entity.h>

class cItemBase
{
public:
    unsigned int m_nUsageFlags;
    int field_8;
    int field_C;
    unsigned int m_nItemAlias;
    unsigned int m_nCreationFlags;
    int field_18;
    int field_1C;
    char m_ItemName[32];
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    Entity *m_pTargetEntity;

    virtual const char* getClassName() {};
    virtual ~cItemBase() {};

    void startup(void *a2)
    {
        CallVMTFunc<2, cItemBase *, void *>(this, a2);
    }
};