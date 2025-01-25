#pragma once

// seems to be unused
namespace Constraint
{
    class WorkBase
    {
        int field_4;

        virtual ~WorkBase() {};
    };

    class ConstructionKit : public WorkBase
    {
    public:
        int field_8;
        int field_C;
        int field_10;
        int field_14;
        int field_18;
    };

    class Fixed : public WorkBase{};

    class Hinge : public WorkBase
    {
    public:
        int field_8;
    };

    class PoweredChain : public WorkBase 
    {
    public:
        int field_8;
    };

    
}