#include "BehaviorUniqueAllocator.h"

class BehaviorUniqueAllocatorImplement : public BehaviorUniqueAllocator
{
public:
    int field_4;
    int field_8;
    int field_C;

    int Function0();
    int Function1();
    int Function2();
    int Function3();
    float Function4();
    virtual ~BehaviorUniqueAllocatorImplement() override {};
};

extern BehaviorUniqueAllocatorImplement *&g_pBehaviorUniqueAllocatorImplement;
BehaviorUniqueAllocatorImplement *GetBehaviorUniqueAllocatorImplement();