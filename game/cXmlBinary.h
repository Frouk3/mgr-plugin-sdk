#pragma once

#include "cXml.h"

class cXmlBinary : public cXml
{
public:
    int field_4;
    int field_8;
    void* m_pFile;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;

    virtual ~cXmlBinary() override {};
};