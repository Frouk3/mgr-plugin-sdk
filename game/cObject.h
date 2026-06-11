#pragma once

#include <cRtti.h>
class cObject
{
public:

    virtual cRtti* getRtti() { return nullptr; } // dummy is always a dummy
    virtual ~cObject() {};
};