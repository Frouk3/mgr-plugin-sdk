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

class DashStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
};

class DeadStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
};

class DiveRollStatePl0010 : public StateMachineNode
{
public:
    int field_30;
};

class DownwardCliffOverJumpStatePl0010 : public StateMachineNode
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
};

class FreeFallStatePl0010 : public StateMachineNode
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
};

class GlobalStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
};

class HighOverJumpStatePl0010 : public StateMachineNode
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

class IdleStatePl0010 : public StateMachineNode
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

class JumpStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
};

class LandingStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
};

class LongCliffOverJumpStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
};

class LowOverJumpStatePl0010 : public StateMachineNode
{
public:
    int field_30;
};

class MiddleCatLeapStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
};

class MiddleOverJumpStatePl0010 : public StateMachineNode
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

class MiddleWallPopStatePl0010 : public StateMachineNode
{
public:
    int field_30;
};

class MostHighWallPopStatePl0010 : public StateMachineNode
{
};

class NarrowScaffoldIdleStatePl0010 : public StateMachineNode
{
};

class NarrowScaffoldRunStatePl0010 : public StateMachineNode
{
};

class NarrowScaffoldWalkStatePl0010 : public StateMachineNode
{
};

class OvercomeBridgeStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
};

class OvercomeContainerStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
};

class OvercomeEnemyStatePl0010 : public StateMachineNode
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
};

class OvercomeMissileStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
};

class OvercomeTrainToTrainStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
};

class QuickDashStatePl0010 : public StateMachineNode
{
};

class QuickTurnStatePl0010 : public StateMachineNode
{
public:
    int field_30;
};

class RunStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
};

class ShortCliffOverJumpStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
};

class SlidingStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
};

class SlipFallStatePl0010 : public StateMachineNode
{
};

class SlipLandingStatePl0010 : public StateMachineNode
{
};

class TurnStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
};

class TwoStageJumpStatePl0010 : public StateMachineNode
{
};

class UnevenCliffOverJumpStatePl0010 : public StateMachineNode
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
};

class WalkStatePl0010 : public StateMachineNode
{
};

class WallEdgeGrabFromBelowStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
};

class WallEdgeGrabFromOverStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
};

class WallPopStatePl0010 : public StateMachineNode
{
public:
    int field_30;
};

class ZangekiChanceStatePl0010 : public StateMachineNode
{
public:
    int field_30;
};

class ZangekiCutStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
};

class ZangekiDatsuJumpStatePl0010 : public StateMachineNode
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
    EntityHandle field_50;
    int field_54;
    EntityHandle field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
};

class ZangekiDatsuShortStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    EntityHandle field_48;
    int field_4C;
    EntityHandle field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
};

class ZangekiEventQteStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
    int field_150;
    int field_154;
    int field_158;
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    int field_16C;
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    int field_218;
    int field_21C;
};

class ZangekiForbidStatePl0010 : public StateMachineNode
{
};

class ZangekiHoldStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
};

class ZangekiHugeCutDownStatePl0010 : public StateMachineNode
{
};

class ZangekiHugeCutLeftKesaStatePl0010 : public StateMachineNode
{
};

class ZangekiHugeCutLeftToRightStatePl0010 : public StateMachineNode
{
};

class ZangekiHugeCutRightKesaStatePl0010 : public StateMachineNode
{
};

class ZangekiHugeCutRightToLeftStatePl0010 : public StateMachineNode
{
};

class ZangekiHugeHoldStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
};

class ZangekiIdleStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
};

class ZangekiInterceptStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
};

class ZangekiLandingStatePl0010 : public StateMachineNode
{
public:
    int field_30;
};

class ZangekiMoveStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
};

class ZangekiNormalStatePl0010 : public StateMachineNode
{
public:
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
};

class ZangekiOnPartsStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
    int field_150;
    int field_154;
    int field_158;
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    int field_16C;
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    int field_218;
    int field_21C;
};

class ZangekiReadyStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
};

class ZangekiStatePl0010 : public StateMachineNode
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

class ZangekiTateStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
};

class ZangekiYokoStatePl0010 : public StateMachineNode
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
};

