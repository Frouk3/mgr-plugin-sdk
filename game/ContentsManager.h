#pragma once

#include <Entity.h>

class ContentsBase
{
public:
    int field_4;
    int field_8;
    int field_C;
    int field_10;

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735D64);

    virtual ContextInstance& getContext() { return ms_Context; };
};

class BrokenBridgeContents : public ContentsBase
{
public:
    int field_10;
    int field_14;
    EntityHandle field_18;
};

class ContentsManager
{
public:

    virtual ~ContentsManager() {};
};