#pragma once

class cObject
{
public:

    virtual const char** getClassName() {static const char *objName = "cObject"; return &objName; };
    virtual ~cObject() {};
};