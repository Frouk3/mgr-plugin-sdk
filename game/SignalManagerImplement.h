#pragma once

#include <SignalManager.h>
#include <Slot.h>
#include <Hw.h>
#include <lib.h>

struct Signal
{
    int m_nID;
    int field_4;
    Hw::cCriticalSection field_8;
    int field_24;
    lib::AllocatedArray<Slot *> *m_Slots;
    int field_2C;
};

class SignalManagerImplement : public SignalManager
{
public:
    lib::StaticArray<Signal *, 256> m_Signals;
};

inline SignalManagerImplement* &g_SignalManager = *(SignalManagerImplement**)(shared::base + 0x19C53D4);