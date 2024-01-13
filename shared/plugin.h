#ifndef PLUGIN_INIT
#define PLUGIN_INIT
#include "injector/injector.hpp"
#include "shared.h"
#include "stdint.h"
#include <vector>

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

class Events
{
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

public:
    static inline IEvent OnUpdateEvent = IEvent(&OnUpdateList, nullptr);
    static inline IEvent OnGameStartupEvent = IEvent(&OnGameStartupList, nullptr);
    static inline IEvent OnSceneStartupEvent = IEvent(&OnSceneStartupList, nullptr);
    static inline IEvent OnSceneCleanupEvent = IEvent(&OnSceneCleanupList, nullptr);
    static inline IEvent OnTickEvent = IEvent(&OnTickEventList, nullptr);
    static inline IEvent OnPauseEvent = IEvent(&OnPauseEventList, nullptr);
    static inline IEvent OnEndScene = IEvent(&OnEndSceneList, nullptr);
    static inline IEventTwoState OnDeviceReset = IEventTwoState(IEvent(&OnResetBeforeList, nullptr), IEvent(&OnResetAfterList, nullptr));
};

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

static inline void __declspec(naked) OnUpdateMainHook()
{
    __asm
    {
        pushad
        call OnUpdateRun
        popad
        jmp Events::OnUpdateEvent.returnAddress
    }
}

static inline void __declspec(naked) OnGameStartupMainHook()
{
    __asm
    {
        pushad
        call OnGameStartupRun
        popad
        jmp Events::OnGameStartupEvent.returnAddress
    }
}

static inline void __declspec(naked) OnSceneStartupMainHook()
{
    __asm
    {
        pushad
        call OnSceneStartupRun
        popad
        jmp Events::OnSceneStartupEvent.returnAddress
    }
}

static inline void __declspec(naked) OnResetAfterMainHook()
{
    __asm
    {
        pushad
        call OnResetAfterRun
        popad
        jmp Events::OnDeviceReset.after.returnAddress
    }
}

static inline void __declspec(naked) OnSceneCleanupMainHook()
{
    __asm
    {
        pushad
        call OnSceneCleanupRun
        popad
        jmp Events::OnSceneCleanupEvent.returnAddress
    }
}

static inline void __declspec(naked) OnTickEventMainHook()
{
    __asm
    {
        pushad
        call OnTickEventRun
        popad
        jmp Events::OnTickEvent.returnAddress
    }
}

static inline void __declspec(naked) OnResetBeforeMainHook()
{
    __asm
    {
        pushad
        call OnResetBeforeRun
        popad
        jmp Events::OnDeviceReset.before.returnAddress
    }
}

static inline void __declspec(naked) OnPauseEventMainHook()
{
    __asm
    {
        pushad
        call OnPauseEventRun
        popad
        jmp Events::OnPauseEvent.returnAddress
    }
}

static inline void __declspec(naked) OnEndSceneMainHook()
{
    __asm
    {
        pushad
        call OnEndSceneRun
        popad
        jmp Events::OnEndScene.returnAddress
    }
}


namespace plugin
{
    inline void InitEvents()
    {
        Events::OnUpdateEvent.SetMainHook(OnUpdateMainHook);
        Events::OnGameStartupEvent.SetMainHook(OnGameStartupMainHook);
        Events::OnSceneStartupEvent.SetMainHook(OnSceneStartupMainHook);
        Events::OnSceneCleanupEvent.SetMainHook(OnSceneCleanupMainHook);
        Events::OnTickEvent.SetMainHook(OnTickEventMainHook);
        Events::OnPauseEvent.SetMainHook(OnPauseEventMainHook);
        Events::OnEndScene.SetMainHook(OnEndSceneMainHook);
        Events::OnDeviceReset.after.SetMainHook(OnResetAfterMainHook);
        Events::OnDeviceReset.before.SetMainHook(OnResetBeforeMainHook);

        Events::OnUpdateEvent.Patch(shared::base + 0x6526A2);
        Events::OnGameStartupEvent.Patch(shared::base + 0x65104D);
        Events::OnSceneStartupEvent.Patch(shared::base + 0x64D227);
        Events::OnSceneCleanupEvent.Patch(shared::base + 0x654237);
        Events::OnTickEvent.Patch(shared::base + 0x64D411);
        Events::OnPauseEvent.Patch(shared::base + 0x64D40A);
        Events::OnEndScene.Patch(shared::base + 0x65264C);
        Events::OnDeviceReset.after.Patch(shared::base + 0xB9D499);
        Events::OnDeviceReset.before.Patch(shared::base + 0xB9D0FA);
        // we do not want to do this 
        // OnExit::returnAddress = DoHook(shared::base + 0x9F975C, OnExit::MainHook);
    }

    inline void OnStartup();

    inline void Init()
    {
        InitEvents();
        OnStartup();
    }
}

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID)
{
    DisableThreadLibraryCalls(hInstance);

    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        plugin::Init();
        break;
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}
#endif