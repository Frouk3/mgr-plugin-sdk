#pragma once

#include <Entity.h>

class ContentsBase
{
public:
    int field_4;
    int field_8;
    int field_C;

    virtual ~ContentsBase() {};
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