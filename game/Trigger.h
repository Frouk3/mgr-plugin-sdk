#pragma once

namespace Trigger
{
    class cCondition;
};

class Trigger::cCondition
{
public:
    int field_4;
    int field_8;
    int field_C;

    virtual ~cCondition();
    bool CanRun();
};