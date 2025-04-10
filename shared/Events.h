#pragma once

#include "injector/injector.hpp"
#include "shared.h"
#include "stdint.h"
#include <vector>
#include <functional>

class Events
{
public:
    template <int mPriority>
    class IEvent
    {
    private:
        uintptr_t returnAddress;
        void(__cdecl *mainhookptr)() = nullptr;


        class Key
        {
        private:
            std::vector<std::function<void()>>* vector;
        public:

            Key()
            {
                vector = nullptr;
            }

            Key(std::vector<std::function<void()>>* vector) : vector(vector) {};

            Key& operator +=(std::function<void()> function)
            {
                vector->emplace_back(function);
                return *this;
            }

            std::vector<std::function<void()>>* getVector()
            {
                return vector;
            }
        };
    public:
        Key before;
        Key after;

        IEvent()
        {
            this->returnAddress = 0;
            this->mainhookptr = nullptr;

            before = Key(new std::vector<std::function<void()>>);
            after = Key(new std::vector<std::function<void()>>);
        }

        IEvent(std::vector<std::function<void()>>* before, std::vector<std::function<void()>>* after, void(__cdecl* func)())
        {
            this->returnAddress = 0;
            this->mainhookptr = func;

            this->before = Key(before);
            this->after = Key(after);
        }

        IEvent(std::vector<std::function<void()>>* before, std::vector<std::function<void()>>* after, void(__cdecl* mainhook)(), unsigned int address)
        {
            this->IEvent::IEvent(before, after, mainhook);
            this->Patch(address);
        }

        IEvent(void(__cdecl* mainhook)(), unsigned int address)
        {
            this->mainhookptr = mainhook;
            this->Patch(address);

            before = Key(new std::vector<std::function<void()>>());
            after = Key(new std::vector<std::function<void()>>());
        }

        IEvent& operator+=(std::function<void()> funcptr)
        {
            (mPriority == 0 ? before : after) += funcptr;
            return *this;
        }

        void SetMainHook(void(__cdecl *funcptr)())
        {
            mainhookptr = funcptr;
        }

        void Patch(uint32_t address)
        {
            this->returnAddress = (uintptr_t)injector::MakeCALL(address, mainhookptr, true);
        }

        void RunBefore()
        {
            for (auto& f : *before.getVector())
                f();
        }
        
        void RunAfter()
        {
            for (auto& f : *after.getVector())
                f();
        }
    };
private:

    struct Caves
    {
        static inline void OnUpdateMainHook();
        static inline void OnGameStartupMainHook();
        static inline void OnSceneStartupMainHook();
        static inline void OnSceneCleanupMainHook();
        static inline void OnTickEventMainHook();
        static inline void OnPauseEventMainHook();
        static inline void OnEndSceneMainHook();
        static inline void OnApplicationStartup();
        static inline void OnPresentHook();
        static inline void OnHeapStartupHook();
        static inline void OnHavokStartupHook();
        static inline void OnGameCleanupHook();
        static inline void OnMainCleanupEventHook();
        static inline void OnDeviceResetHook();
    };
public:
    static inline IEvent OnUpdateEvent = IEvent<0>(Caves::OnUpdateMainHook, shared::base + 0x6526A2); // Every non-game tick
    static inline IEvent OnGameStartupEvent = IEvent<0>(Caves::OnGameStartupMainHook, shared::base + 0x65104D); // Executed after logo sequence
    static inline IEvent OnSceneStartupEvent = IEvent<0>(Caves::OnSceneStartupMainHook, shared::base + 0x64D227); // Executes functions if scene should be prepared
    static inline IEvent OnSceneCleanupEvent = IEvent<0>(Caves::OnSceneCleanupMainHook, shared::base + 0x654237); // Executes functions if scene wants to be cleaned
    static inline IEvent OnTickEvent = IEvent<0>(Caves::OnTickEventMainHook, shared::base + 0x64D411); // Every in-game tick
    static inline IEvent OnPauseEvent = IEvent<0>(Caves::OnPauseEventMainHook, shared::base + 0x64D40A); // Every tick that is in pause
    static inline IEvent OnEndScene = IEvent<0>(Caves::OnEndSceneMainHook, shared::base + 0x65264C); // On render, though render is executed after the end scene call
    static inline IEvent OnDeviceReset = IEvent<1>(Caves::OnDeviceResetHook, shared::base + 0x651253); // On Device reset
    static inline IEvent OnApplicationStartEvent = IEvent<0>(Caves::OnApplicationStartup, shared::base + 0x653360); // On first application startup function
    static inline IEvent OnPresent = IEvent<0>(Caves::OnPresentHook, shared::base + 0xB9807A); // Used for rendering purposes
    static inline IEvent OnHeapStartup = IEvent<1>(Caves::OnHeapStartupHook, shared::base + 0x65304D); // On heap starting up
    static inline IEvent OnHavokStartupEvent = IEvent<0>(Caves::OnHavokStartupHook, shared::base + 0x6530B1); // Havok startup
    static inline IEvent OnGameCleanupEvent = IEvent<0>(Caves::OnGameCleanupHook, shared::base + 0x64F3CF); // when game checks that it should be cleanup
    static inline IEvent OnMainCleanupEvent = IEvent<0>(Caves::OnMainCleanupEventHook, shared::base + 0x652AE3); // If game cleanup was successful without any errors while closing the game, Main Cleanup is executed

    Events()
    {

    };
};

#define DEFINE_CAVE(Cave, Event)                          \
void __declspec(naked) Cave() \
{                                                   \
    __asm pushad                                    \
    __asm lea ecx, Event                            \
    __asm call Events::IEvent<0>::RunBefore                    \
    __asm popad                                     \
    __asm call Event.returnAddress                  \
    __asm pushad                                    \
    __asm lea ecx, Event                            \
    __asm call Events::IEvent<0>::RunAfter                     \
    __asm popad                                     \
    __asm ret          \
}

DEFINE_CAVE(Events::Caves::OnUpdateMainHook, Events::OnUpdateEvent)
DEFINE_CAVE(Events::Caves::OnGameStartupMainHook, Events::OnGameStartupEvent)
DEFINE_CAVE(Events::Caves::OnSceneStartupMainHook, Events::OnSceneStartupEvent)
DEFINE_CAVE(Events::Caves::OnSceneCleanupMainHook, Events::OnSceneCleanupEvent)
DEFINE_CAVE(Events::Caves::OnTickEventMainHook, Events::OnTickEvent)
DEFINE_CAVE(Events::Caves::OnPauseEventMainHook, Events::OnPauseEvent)
DEFINE_CAVE(Events::Caves::OnEndSceneMainHook, Events::OnEndScene)
DEFINE_CAVE(Events::Caves::OnDeviceResetHook, Events::OnDeviceReset)
DEFINE_CAVE(Events::Caves::OnApplicationStartup, Events::OnApplicationStartEvent)
DEFINE_CAVE(Events::Caves::OnPresentHook, Events::OnPresent)
DEFINE_CAVE(Events::Caves::OnHeapStartupHook, Events::OnHeapStartup)
DEFINE_CAVE(Events::Caves::OnHavokStartupHook, Events::OnHavokStartupEvent)
DEFINE_CAVE(Events::Caves::OnGameCleanupHook, Events::OnGameCleanupEvent)
DEFINE_CAVE(Events::Caves::OnMainCleanupEventHook, Events::OnMainCleanupEvent)

inline Events ____unusedEventClass;

//void __declspec(naked) Events::Caves::OnMainCleanupHook()
//{
//    __asm
//    {
//        pushad
//        lea ecx, OnMainCleanupEvent
//        call IEvent::Run
//        popad
//        jmp OnMainCleanupEvent.returnAddress
//    }
//}