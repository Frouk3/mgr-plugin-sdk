#pragma once

#include <Behavior.h>

class Pl001c : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    float field_880;
    float field_884;
    float field_888;
    float field_88C;
    float field_890;
    float field_894;
    float field_898;
    float field_89C;
    float field_8A0;
    float field_8A4;
    float field_8A8;
    float field_8AC;
    float field_8B0;
    float field_8B4;
    float field_8B8;
    float field_8BC;
    float field_8C0;
    int field_8C4;
    float field_8C8;
    float field_8CC;
    int field_8D0;
    int field_8D4;
    int field_8D8;
    float field_8DC;
    int field_8E0;
    int field_8E4;
    int field_8E8;
    int field_8EC;
    float field_8F0;
    float field_8F4;
    float field_8F8;
    float field_8FC;
    float field_900;
    float field_904;
    float field_908;
    float field_90C;
    float field_910;
    float field_914;
    float field_918;
    float field_91C;
    float field_920;
    float field_924;
    float field_928;
    float field_92C;
    float field_930;
    float field_934;
    float field_938;
    float field_93C;
    float field_940;
    float field_944;
    float field_948;
    float field_94C;
    float field_950;
    float field_954;
    float field_958;
    float field_95C;
    float field_960;
    float field_964;
    int field_968;
    int field_96C;
    float field_970;
    float field_974;
    float field_978;
    float field_97C;
    float field_980;
    int field_984;
    int field_988;
    int field_98C;

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17353E0);
};

VALIDATE_SIZE(Pl001c, 0x990);