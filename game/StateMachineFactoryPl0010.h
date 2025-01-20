#pragma once

#include <StateMachineFactory.h>
#include <StateMachineNode.h>

class StateMachineFactoryPl0010 : public StateMachineFactory
{
public:

};

class AnyDiveRollStatePl0010 : public StateMachineNode
{
public:

};

class AnyHighOverJumpStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    float field_38;
    float field_3C;
    int field_40;
    int field_44;
    float field_48;
    float field_4C;
    int field_50;
    int field_54;
    float field_58;
    int field_5C;
    int field_60;
};

class AnySlidingStatePl0010 : public StateMachineNode
{
public:

};

class AnywayHighJumpStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
};

class AvoidEnemyStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
};

class AvoidMiddleOverJumpStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
};

class AvoidSlidingStatePl0010 : public StateMachineNode
{
public:

};

class BodyStatePl0010 : public StateMachineNode
{
public:

};

class CatLeapStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};

