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
        void(__stdcall* run)(IEvent *) = nullptr;

        IEvent()
        {
            this->returnAddress = 0;
            this->mainhookptr = nullptr;
            this->run = nullptr;
            this->listPtr = nullptr;
        }

        IEvent(std::vector<void(*)()>* listVec, void(__cdecl* func)())
        {
            this->returnAddress = 0;
            this->listPtr = listVec;
            this->mainhookptr = func;
            this->run = nullptr;
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
            this->run = [](IEvent* self)
                {
                    for (auto& f : *self->listPtr)
                        f();
                };
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
    /*static inline void OnUpdateRun()
    {
        for (auto& f : OnUpdateList)
            f();
    }

    static inline void OnGameStartupRun()
    {
        for (auto& f : OnGameStartupList)
            f();
    }

    static inline void OnSceneStartupRun()
    {
        for (auto& f : OnSceneStartupList)
            f();
    }

    static inline void OnSceneCleanupRun()
    {
        for (auto& f : OnSceneCleanupList)
            f();
    }

    static inline void OnTickEventRun()
    {
        for (auto& f : OnTickEventList)
            f();
    }

    static inline void OnPauseEventRun()
    {
        for (auto& f : OnPauseEventList)
            f();
    }

    static inline void OnEndSceneRun()
    {
        for (auto& f : OnEndSceneList)
            f();
    }

    static inline void OnResetBeforeRun()
    {
        for (auto& f : OnResetBeforeList)
            f();
    }

    static inline void OnResetAfterRun()
    {
        for (auto& f : OnResetAfterList)
            f();
    }

    static inline void OnApplicationStartRun()
    {
        for (auto& f : OnApplicationStartList)
            f();
    }

    static inline void OnPresentRun()
    {
        for (auto &f : OnPresentList)
            f();
    }*/

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
        push ecx
        call OnApplicationStartEvent.run
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
        push ecx
        call OnEndScene.run
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
        push ecx
        call OnPauseEvent.run
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
        push ecx
        call OnDeviceReset.before.run
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
        push ecx
        call OnTickEvent.run
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
        push ecx
        call OnSceneCleanupEvent.run
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
        push ecx
        call OnDeviceReset.after.run
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
        push ecx
        call OnSceneStartupEvent.run
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
        push ecx
        call OnGameStartupEvent.run
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
        push ecx
        call OnUpdateEvent.run
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
        push ecx
        call OnPresent.run
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
        push ecx
        call OnApplicationStartEventMid.run
        popad
        jmp Events::OnApplicationStartEventMid.returnAddress
    }
}