#pragma once

#include "injector/injector.hpp"
#include "shared.h"
#include "stdint.h"
#include <vector>

class Events
{
private:
    // OnUpdate

    static inline std::vector<void(*)()> OnUpdateList;
///////////////////////////////////////////////////////////////////////
    // OnGameStartup

    static inline std::vector<void(*)()> OnGameStartupList;
///////////////////////////////////////////////////////////////////////
    // OnSceneStartup

    static inline std::vector<void(*)()> OnSceneStartupList;
///////////////////////////////////////////////////////////////////////
    // OnSceneCleanup

    static inline std::vector<void(*)()> OnSceneCleanupList;
///////////////////////////////////////////////////////////////////////
    // OnTickEvent

    static inline std::vector<void(*)()> OnTickEventList;
///////////////////////////////////////////////////////////////////////
    // OnPauseEvent

    static inline std::vector<void(*)()> OnPauseEventList;
///////////////////////////////////////////////////////////////////////
    // OnEndScene

    static inline std::vector<void(*)()> OnEndSceneList;
///////////////////////////////////////////////////////////////////////
    // OnReset
    // Before

    static inline std::vector<void(*)()> OnResetBeforeList;
    // After

    static inline std::vector<void(*)()> OnResetAfterList;

///////////////////////////////////////////////////////////////////////
    // OnAppStart

    static inline std::vector<void(*)()> OnApplicationStartList;
///////////////////////////////////////////////////////////////////////
    // OnPresent

    static inline std::vector<void(*)()> OnPresentList;
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
            uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

            injector::MakeCALL(address, this->mainhookptr, true);

            this->returnAddress = origCall;
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
    static inline void OnUpdateRun()
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
    }

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
    };
public:
    static inline IEvent OnUpdateEvent = IEvent(&OnUpdateList, Caves::OnUpdateMainHook, shared::base + 0x6526A2);
    static inline IEvent OnGameStartupEvent = IEvent(&OnGameStartupList, Caves::OnGameStartupMainHook, shared::base + 0x65104D);
    static inline IEvent OnSceneStartupEvent = IEvent(&OnSceneStartupList, Caves::OnSceneStartupMainHook, shared::base + 0x64D227);
    static inline IEvent OnSceneCleanupEvent = IEvent(&OnSceneCleanupList, Caves::OnSceneCleanupMainHook, shared::base + 0x654237);
    static inline IEvent OnTickEvent = IEvent(&OnTickEventList, Caves::OnTickEventMainHook, shared::base + 0x64D411);
    static inline IEvent OnPauseEvent = IEvent(&OnPauseEventList, Caves::OnPauseEventMainHook, shared::base + 0x64D40A);
    static inline IEvent OnEndScene = IEvent(&OnEndSceneList, Caves::OnEndSceneMainHook, shared::base + 0x65264C);
    static inline IEventTwoState OnDeviceReset = IEventTwoState(IEvent(&OnResetBeforeList, Caves::OnResetBeforeMainHook, shared::base + 0xB9D0FA), IEvent(&OnResetAfterList, Caves::OnResetAfterMainHook, shared::base + 0xB9D499));
    static inline IEvent OnApplicationStartEvent = IEvent(&OnApplicationStartList, Caves::OnApplicationStartup, shared::base + 0x653360);
    static inline IEvent OnPresent = IEvent(&OnPresentList, Caves::OnPresentHook, shared::base + 0xB9807A);

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
        call OnApplicationStartRun
        popad
        jmp Events::OnApplicationStartEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnEndSceneMainHook()
{
    {
        __asm
        {
            pushad
            call OnEndSceneRun
            popad
            jmp Events::OnEndScene.returnAddress
        }
    }
}

void __declspec(naked) Events::Caves::OnPauseEventMainHook()
{
    __asm
    {
        pushad
        call OnPauseEventRun
        popad
        jmp Events::OnPauseEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnResetBeforeMainHook()
{
    __asm
    {
        pushad
        call OnResetBeforeRun
        popad
        jmp Events::OnDeviceReset.before.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnTickEventMainHook()
{
    __asm
    {
        pushad
        call OnTickEventRun
        popad
        jmp Events::OnTickEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnSceneCleanupMainHook()
{
    __asm
    {
        pushad
        call OnSceneCleanupRun
        popad
        jmp Events::OnSceneCleanupEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnResetAfterMainHook()
{
    __asm
    {
        pushad
        call OnResetAfterRun
        popad
        jmp Events::OnDeviceReset.after.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnSceneStartupMainHook()
{
    __asm
    {
        pushad
        call OnSceneStartupRun
        popad
        jmp Events::OnSceneStartupEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnGameStartupMainHook()
{
    __asm
    {
        pushad
        call OnGameStartupRun
        popad
        jmp Events::OnGameStartupEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnUpdateMainHook()
{
    __asm
    {
        pushad
        call OnUpdateRun
        popad
        jmp Events::OnUpdateEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnPresentHook()
{
    __asm
    {
        pushad
        call OnPresentRun
        popad
        jmp Events::OnPresent.returnAddress
    }
}