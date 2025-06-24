#pragma once

#include <hkpPhantomOverlapListener.h>

class WindAction
{
public:
    virtual ~WindAction() {};
};

class WindActionImplement : public WindAction
{
public:
    class PhantomListener : public hkpPhantomOverlapListener{};
public:
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};