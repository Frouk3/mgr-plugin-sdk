#pragma once

#include <BehaviorBa.h>

class GimmickBehaviorBase : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;
};

VALIDATE_SIZE(GimmickBehaviorBase, 0xB40);