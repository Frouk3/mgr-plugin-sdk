#pragma once

#include "injector/injector.hpp"
#include "shared.h"
#include "stdint.h"
#include <vector>

class Events
{
private:

private:
    class IEvent
    {
    public:
        uintptr_t returnAddress;
        std::vector<void(*)()>* listPtr;
        void(__cdecl* mainhookptr)() = nullptr;

        IEvent()
        {
            this->returnAddress = 0;
            this->mainhookptr = nullptr;
            this->listPtr = nullptr;
        }

        IEvent(std::vector<void(*)()>* listVec, void(__cdecl* func)())
        {
            this->returnAddress = 0;
            this->listPtr = listVec;
            this->mainhookptr = func;
        }

        IEvent(std::vector<void(*)()>* listVec, void(__cdecl* mainhook)(), unsigned int address)
        {
            this->IEvent::IEvent(listVec, mainhook);
            this->Patch(address);
        }

        IEvent(void(__cdecl* mainhook)(), unsigned int address)
        {
            this->listPtr = new std::vector<void(__cdecl*)()>();
            this->mainhookptr = mainhook;
            this->Patch(address);
        }

        IEvent& operator+=(void(*funcptr)())
        {
            listPtr->emplace_back(funcptr);
            return *this;
        }

        void SetMainHook(void(*funcptr)())
        {
            mainhookptr = funcptr;
        }

        void Patch(uint32_t address)
        {
            this->returnAddress = (uintptr_t)injector::MakeCALL(address, this->mainhookptr, true);
        }

        void Run()
        {
            for (auto& f : *this->listPtr)
                f();
        }
    };

    class IEventTwoState
    {
    public:
        IEvent before;
        IEvent after;

        IEventTwoState(const IEvent& evBef, const IEvent& evAfter)
        {
            this->before = IEvent(evBef);
            this->after = IEvent(evAfter);
        }
    };
private:

    struct Caves
    {
        static inline void OnUpdateMainHook();
        static inline void OnGameStartupMainHook();
        static inline void OnSceneStartupMainHook();
        static inline void OnResetAfterMainHook();
        static inline void OnSceneCleanupMainHook();
        static inline void OnTickEventMainHook();
        static inline void OnResetBeforeMainHook();
        static inline void OnPauseEventMainHook();
        static inline void OnEndSceneMainHook();
        static inline void OnApplicationStartup();
        static inline void OnPresentHook();
        static inline void OnApplicationStartMid();
    };
public:
    static inline IEvent OnUpdateEvent = IEvent(Caves::OnUpdateMainHook, shared::base + 0x6526A2);
    static inline IEvent OnGameStartupEvent = IEvent(Caves::OnGameStartupMainHook, shared::base + 0x65104D);
    static inline IEvent OnSceneStartupEvent = IEvent(Caves::OnSceneStartupMainHook, shared::base + 0x64D227);
    static inline IEvent OnSceneCleanupEvent = IEvent(Caves::OnSceneCleanupMainHook, shared::base + 0x654237);
    static inline IEvent OnTickEvent = IEvent(Caves::OnTickEventMainHook, shared::base + 0x64D411);
    static inline IEvent OnPauseEvent = IEvent(Caves::OnPauseEventMainHook, shared::base + 0x64D40A);
    static inline IEvent OnEndScene = IEvent(Caves::OnEndSceneMainHook, shared::base + 0x65264C);
    static inline IEventTwoState OnDeviceReset = IEventTwoState(IEvent(Caves::OnResetBeforeMainHook, shared::base + 0xB9D0FA), IEvent(Caves::OnResetAfterMainHook, shared::base + 0xB9D499));
    static inline IEvent OnApplicationStartEvent = IEvent(Caves::OnApplicationStartup, shared::base + 0x653360);
    static inline IEvent OnPresent = IEvent(Caves::OnPresentHook, shared::base + 0xB9807A);
    static inline IEvent OnApplicationStartEventMid = IEvent(Caves::OnApplicationStartMid, shared::base + 0x653056);

    Events()
    {

    };
};

inline Events ____unusedEventClass;

void __declspec(naked) Events::Caves::OnApplicationStartup()
{
    __asm
    {
        pushad
        lea ecx, OnApplicationStartEvent
        call IEvent::Run
        popad
        jmp Events::OnApplicationStartEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnEndSceneMainHook()
{
    __asm
    {
        pushad
        lea ecx, OnEndScene
        call IEvent::Run
        popad
        jmp Events::OnEndScene.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnPauseEventMainHook()
{
    __asm
    {
        pushad
        lea ecx, OnPauseEvent
        call IEvent::Run
        popad
        jmp Events::OnPauseEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnResetBeforeMainHook()
{
    __asm
    {
        pushad
        lea ecx, OnDeviceReset.before
        call IEvent::Run
        popad
        jmp Events::OnDeviceReset.before.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnTickEventMainHook()
{
    __asm
    {
        pushad
        lea ecx, OnTickEvent
        call IEvent::Run
        popad
        jmp Events::OnTickEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnSceneCleanupMainHook()
{
    __asm
    {
        pushad
        lea ecx, OnSceneCleanupEvent
        call IEvent::Run
        popad
        jmp Events::OnSceneCleanupEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnResetAfterMainHook()
{
    __asm
    {
        pushad
        lea ecx, OnDeviceReset.after
        call IEvent::Run
        popad
        jmp Events::OnDeviceReset.after.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnSceneStartupMainHook()
{
    __asm
    {
        pushad
        lea ecx, OnSceneStartupEvent
        call IEvent::Run
        popad
        jmp Events::OnSceneStartupEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnGameStartupMainHook()
{
    __asm
    {
        pushad
        lea ecx, OnGameStartupEvent
        call IEvent::Run
        popad
        jmp Events::OnGameStartupEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnUpdateMainHook()
{
    __asm
    {
        pushad
        lea ecx, OnUpdateEvent
        call IEvent::Run
        popad
        jmp Events::OnUpdateEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnPresentHook()
{
    __asm
    {
        pushad
        lea ecx, OnPresent
        call IEvent::Run
        popad
        jmp Events::OnPresent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnApplicationStartMid()
{
    __asm
    {
        pushad
        lea ecx, OnApplicationStartEventMid
        call IEvent::Run
        popad
        jmp Events::OnApplicationStartEventMid.returnAddress
    }
}