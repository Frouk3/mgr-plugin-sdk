#pragma once

#include <VoiceSubtitleManager.h>
#include <Hw.h>

class VoiceSubtitleManagerImplement : public VoiceSubtitleManager
{
public:
    Hw::cHeapPhysical *m_Allocator;
    int field_8;
    int field_C;
    int field_10;
    int field_14;

    static inline VoiceSubtitleManagerImplement*& ms_Instance = *(VoiceSubtitleManagerImplement**)(shared::base + 0x17EA1A8);
};