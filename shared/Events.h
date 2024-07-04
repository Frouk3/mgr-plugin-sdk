#pragma once

#include "injector/injector.hpp"
#include "shared.h"
#include "stdint.h"
#include <vector>
#include <functional>

class Events
{
private:

private:
    class IEvent
    {
    public:
        uintptr_t returnAddress;
        std::vector<std::function<void()>>* listPtr;
        void(__cdecl* mainhookptr)() = nullptr;

        IEvent()
        {
            this->returnAddress = 0;
            this->mainhookptr = nullptr;
            this->listPtr = nullptr;
        }

        IEvent(std::vector<std::function<void()>>* listVec, void(__cdecl* func)())
        {
            this->returnAddress = 0;
            this->listPtr = listVec;
            this->mainhookptr = func;
        }

        IEvent(std::vector<std::function<void()>>* listVec, void(__cdecl* mainhook)(), unsigned int address)
        {
            this->IEvent::IEvent(listVec, mainhook);
            this->Patch(address);
        }

        IEvent(void(__cdecl* mainhook)(), unsigned int address)
        {
            this->listPtr = new std::vector<std::function<void()>>();
            this->mainhookptr = mainhook;
            this->Patch(address);
        }

        IEvent& operator+=(std::function<void()> funcptr)
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
        static inline void OnHavokStartupHook();
        static inline void OnGameCleanupHook();
        static inline void OnMainCleanupHook();
    };
public:
    static inline IEvent OnUpdateEvent = IEvent(Caves::OnUpdateMainHook, shared::base + 0x6526A2); // Every non-game tick
    static inline IEvent OnGameStartupEvent = IEvent(Caves::OnGameStartupMainHook, shared::base + 0x65104D); // Executed after logo sequence
    static inline IEvent OnSceneStartupEvent = IEvent(Caves::OnSceneStartupMainHook, shared::base + 0x64D227); // Executes functions if scene should be prepared
    static inline IEvent OnSceneCleanupEvent = IEvent(Caves::OnSceneCleanupMainHook, shared::base + 0x654237); // Executes functions if scene wants to be cleaned
    static inline IEvent OnTickEvent = IEvent(Caves::OnTickEventMainHook, shared::base + 0x64D411); // Every in-game tick
    static inline IEvent OnPauseEvent = IEvent(Caves::OnPauseEventMainHook, shared::base + 0x64D40A); // Every tick that is in pause
    static inline IEvent OnEndScene = IEvent(Caves::OnEndSceneMainHook, shared::base + 0x65264C); // On render, though render is executed after the end scene call
    static inline IEventTwoState OnDeviceReset = IEventTwoState(IEvent(Caves::OnResetBeforeMainHook, shared::base + 0xB9D0FA), IEvent(Caves::OnResetAfterMainHook, shared::base + 0xB9D499)); // Device lost/reset
    static inline IEvent OnApplicationStartEvent = IEvent(Caves::OnApplicationStartup, shared::base + 0x653360); // On first application startup function
    static inline IEvent OnPresent = IEvent(Caves::OnPresentHook, shared::base + 0xB9807A); // Used for rendering purposes
    static inline IEvent OnApplicationStartEventMid = IEvent(Caves::OnApplicationStartMid, shared::base + 0x653056); // After heap startup, recommended to use if you want new allocatable heap to be managed
    static inline IEvent OnHavokStartupEvent = IEvent(Caves::OnHavokStartupHook, shared::base + 0x6530B1); // Havok startup
    static inline IEvent OnGameCleanupEvent = IEvent(Caves::OnGameCleanupHook, shared::base + 0x64F3CF); // when game checks that it should be cleanup
    static inline IEvent OnMainCleanupEvent = IEvent(Caves::OnMainCleanupHook, shared::base + 0x652AE3); // If game cleanup was successful without any errors while closing the game, Main Cleanup is executed

    Events()
    {

    };
};

inline Events ____unusedEventClass;


void __declspec(naked) Events::Caves::OnMainCleanupHook()
{
    __asm
    {
        pushad
        lea ecx, OnMainCleanupEvent
        call IEvent::Run
        popad
        jmp OnMainCleanupEvent.returnAddress
    }
}

void __declspec(naked) Events::Caves::OnGameCleanupHook()
{
    __asm
    {
        pushad
        lea ecx, OnGameCleanupEvent
        call IEvent::Run
        popad
        jmp OnGameCleanupEvent.returnAddress
    }
}

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

void __declspec(naked) Events::Caves::OnHavokStartupHook()
{
    __asm
    {
        pushad 
        lea ecx, OnHavokStartupEvent
        call IEvent::Run
        popad
        jmp Events::OnHavokStartupEvent.returnAddress
    }
}