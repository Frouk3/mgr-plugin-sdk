#pragma once

#include <SignalManager.h>
#include <Slot.h>
#include <Hw.h>
#include <lib.h>

struct Signal
{
    int m_nID;
    int field_4;
    Hw::CriticalSection field_8;
    int field_24;
    lib::AllocatedArray<Slot *> *m_Slots;
    int field_2C;
};

class SignalManagerImplement : public SignalManager
{
public:
    lib::StaticArray<Signal *, 256> m_Signals;

    static inline SignalManagerImplement* &ms_Instance = *(SignalManagerImplement**)(shared::base + 0x19C53D4);
};