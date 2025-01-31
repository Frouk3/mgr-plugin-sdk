#pragma once

#include <lib.h>
#include <CharacterControl.h>
#include <CharacterControlManager.h>
#include <shared.h>

class CharacterControlManagerImplement : public CharacterControlManager
{
public:
    lib::AllocatedArray<CharacterControl *> *m_CharacterControls;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;

    static inline CharacterControlManagerImplement *&ms_Instance = *(CharacterControlManagerImplement**)(shared::base + 0x1735D9C);
};

VALIDATE_SIZE(CharacterControlManagerImplement, 0x30);