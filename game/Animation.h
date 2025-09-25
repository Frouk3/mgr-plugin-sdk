#pragma once
#include <EntityHandle.h>
#include <shared.h>

class Behavior;

class cParts;
struct Entity;

class EspCtrlCustomImpl;

struct Animation
{
public:
    class Control
    {
    public:
        class NodeListener
        {
        public:
            int field_4;
            int field_8;
            int field_C;

            NodeListener()
            {
                ((void(__thiscall *)(NodeListener *))(shared::base + 0xA27050))(this);
            }

            virtual ~NodeListener() {};
        };

        class Node
        {
        public:
            int field_4;
            int field_8;
            int field_C;
            int field_10;
            int field_14;
            int field_18;
            int field_1C;

            Node()
            {
                ((void(__thiscall *)(Node *))(shared::base + 0xA30770))(this);
            }

            virtual ~Node() {};
        };

        struct NodeSlot
        {
            class NodeHandler : public NodeListener {};

            Animation::Control::NodeSlot::NodeHandler m_aControlNodes[8];

            NodeSlot()
            {
                ((void(__thiscall *)(Animation::Control::NodeSlot *))(shared::base + 0xA308C0))(this);
            }
        };

        struct Unit
        {
            int field_0;
            Animation::Control::Node *field_4;
            Animation::Control::NodeSlot field_8;

            Unit()
            {
                ((void(__thiscall *)(Animation::Control::Unit *))(shared::base + 0xA30930))(this);
            }
        };

        struct NodeFactory
        {
            Hw::CriticalSection m_CriticalSection;
            int field_1C;
            Hw::cHeapVariable *m_pAllocator;
            size_t m_nCapacity;
            size_t m_nSize;
            int field_2C;
            int field_30;
            int field_34;
        };
    };

    class PostControl
    {
    public:
        class Work;
    };

    class EaseControl
    {
    public:
        int m_nSmoothState;
        float m_fCurrentSmooth;
        float m_fTargetEase;
        float m_fCurrentEase;

        void increaseSmooth(float delta)
        {
            ((void(__thiscall *)(EaseControl *, float))(shared::base + 0xA22F60))(this, delta);
        }

        void decreaseSmooth(float delta)
        {
            ((void(__thiscall *)(EaseControl *, float))(shared::base + 0xA22FD0))(this, delta);
        }

        void update(float delta)
        {
            ((void(__thiscall *)(EaseControl *, float))(shared::base + 0xA26F40))(this, delta);
        }
    };

    class Motion
    {
    public:
        class NodeListener;
    public:
        class Node
        {
        public:
            int field_4;
            int field_8;
            int field_C;
            int field_10;
            int field_14;
            int field_18;
            int field_1C;
            char m_AnimationName[64];
            int field_60;
            int field_64;
            float field_68;
            float field_6C;
            float m_fLocalPlaybackSpeed;
            float m_fLocalPlaybackRate;
            float field_78;
            int field_7C;
            int field_80;
            EspCtrlCustomImpl *field_84;
            NodeListener* field_88;
            NodeListener* field_8C;

            virtual ~Node() {};

            BOOL setup(int a2, const char *name, int a4, int a5)
            {
                return ((BOOL(__thiscall *)(Node *, int, const char *, int, int))(shared::base + 0xA339B0))(this, a2, name, a4, a5);
            }

            void setCurrentTime(float time, float *data)
            {
                CallVMTFunc<11, Node *, float, float *>(this, time, data);
            }

            void setCurrentTimeSlide(float timeSlide, float *data)
            {
                CallVMTFunc<12, Node *, float, float *>(this, timeSlide, data);
            }

            float getCurrentTime()
            {
                return ReturnCallVMTFunc<float, 13, Node*>(this);
            }

            float getElapsedTime()
            {
                return ReturnCallVMTFunc<float, 14, Node*>(this);
            }

            float getMaxTime()
            {
                return ReturnCallVMTFunc<float, 15, Node*>(this);
            }

            void setLocalWeight(float *a2, float* a3)
            {
                CallVMTFunc<16, Node*, float *, float*>(this, a2, a3);
            }
        };

        class NodeHandle : public sHandle<Node>
        {
        public:

            operator Node*();

            Node *getNode()
            {
                return *this;
            }
        };

        class NodeBlend : public Node
        {
        public:
            int field_90;
            int field_94;
            int field_98;
            float field_9C;
            int field_A0;
            float fiedl_A4;
            float field_A8;
            int field_AC;
        };

        class NodeGrindBlend : public NodeBlend
        {

        };

        class NodeListener
        {
        public:
            NodeListener *field_4;
            NodeListener *field_8;
            Node* m_pNode;

            NodeListener()
            {
                ((void(__thiscall *)(NodeListener *))(shared::base + 0xA41B40))(this);
            }

            /*
            ~NodeListener()
            {
                ((void(__thiscall *)(NodeListener *))(shared::base + 0xA41B60))(this);
            }
            */

            void remove()
            {
                ((void(__thiscall *)(NodeListener *))(shared::base + 0xA44210))(this);
            }

            virtual ~NodeListener() {};
        };

        class NodeParallel : public Node
        {
        public:
            float field_90;
            float field_94;
        };

        class NodeSequence : public Node
        {
        public:
            int field_90;
            int field_94;
        };

        class NodeSlot
        {
        public:
            class NodeHandler : public NodeListener
            {
            public:

                NodeHandler()
                {
                    ((void(__thiscall *)(NodeHandler *))(shared::base + 0xA41B70))(this);
                }
            };
        };

        class NodePlay : public NodeSequence
        {
        public:
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
        };

        class Unit
        {
        public:
            class NodeHandler : public NodeListener {};
        public:
            int field_0;
            Animation::Motion::Unit::NodeHandler m_MotionUnit;
            Animation::Motion::Unit::NodeHandler m_aMotionNodes[16];
            int field_114;
            int field_118;
            int field_11C;
            int field_120;
            int field_124;
            int field_128;
        };
    };

    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    char m_AnimationName[16];
    int field_24;
    int field_28;
    int field_2C;
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
    EntityHandle m_AnimationTarget;
    int field_90;
    unsigned int m_nAnimationFlags;
    int field_98;
    Entity *m_pEntityOwner;
    Behavior *m_pOwner;
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
    float m_fAnimationSize;
    float field_E4;
    float field_E8;
    float field_EC;
    int field_F0;
    Animation::Motion::Unit m_MotionUnit;
    int field_220;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    int field_284;
    void *field_288;
    int field_28C;
    int field_290;
    int field_294;
    int field_298;
    int field_29C;
    int field_2A0;
    Animation::Control::Unit field_2A4;
    int field_32C;
    int field_330;
    int field_334;
    int field_338;
    int field_33C;
    int field_340;

    class EspCtrlCustom
    {
    public:

        EspCtrlCustom()
        {
            ((void(__thiscall *)(EspCtrlCustom *))(shared::base + 0x5312E0))(this);
        }

        virtual ~EspCtrlCustom() {};
    };
    class FootIk2;
    class HandIk;

    Animation()
    {
        ((void (__thiscall *)(Animation *))(shared::base + 0xA35080))(this);
    }
};

class Animation::PostControl::Work
{
public:
    int field_4;
    int field_8;

    virtual ~Work() {};
    
    BOOL startup(void *a2, void* a3)
    {
        return ReturnCallVMTFunc<BOOL, 1, Work *, void *, void *>(this, a2, a3);
    }

    void updateSmoothing(float delta)
    {
        CallVMTFunc<2, Work*, float>(this, delta);
    }
};

class Animation::FootIk2 : public Animation::PostControl::Work
{
public:
    int field_C;
    Behavior *m_pOwner;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
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
    float field_80;
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
    float field_130;
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
    int m_TargetBoneIndex;
    cParts *m_pTargetBone;
    int field_188;
    int field_18C;
    float field_190;
    float field_194;
    float field_198;
    Animation::EaseControl m_EaseController;

    FootIk2()
    {
        ((void(__thiscall *)(FootIk2*))(shared::base + 0xA30E60))(this);
    }
};

VALIDATE_SIZE(Animation::FootIk2, 0x1AC);

class Animation::HandIk : public Animation::PostControl::Work
{
public:
    int field_C;
    int field_10;
    cParts *field_14;
    cParts *field_18;
    cParts *field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    float field_50;
    float field_54;
    float field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    cParts *field_80;
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
    Animation::EaseControl field_D0;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;

    HandIk()
    {
        ((void(__thiscall *)(HandIk *))(shared::base + 0xA2CD70))(this);
    }
};

inline HandleManager<Animation::Motion::Node> &g_MotionNodeHandleManager = *(HandleManager<Animation::Motion::Node>*)(shared::base + 0x19D9488);

inline Animation::Motion::NodeHandle::operator Animation::Motion::Node*()
{
    if (!this->m_Handle)
        return nullptr;

    size_t at = (this->m_Handle >> 8);

    if (at >= g_MotionNodeHandleManager.m_capacity)
    {
        PrintfLog("[HandleManage] Invalid handle value.");
        return nullptr;
    }
    if (((this->m_Handle ^ g_MotionNodeHandleManager.m_HandleArrayValue[at].m_Handle.m_Handle) & 0xFFFFFF00) != 0)
        return nullptr;

    return g_MotionNodeHandleManager.m_HandleArrayValue[at].m_value;
}

VALIDATE_SIZE(Animation::HandIk, 0xF0);
VALIDATE_SIZE(Animation, 0x344);