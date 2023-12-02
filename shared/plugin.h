#include "injector/injector.hpp"
#include "shared.h"
#include "stdint.h"
#include <list>

#ifndef plugin
namespace plugin
{
    uint32_t DoHook(uintptr_t address, void (*hook)())
    {
        uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

        injector::MakeCALL(address, hook, true);

        return origCall;
    }

    namespace UpdateEvent // updates always
    {
        uintptr_t returnAddress;
        std::list<void(*)()> funcPtrs;

        void Run()
        {
            for (auto& f : funcPtrs)
                f();
        }

        void Add(void(*funcPtr)())
        {
            funcPtrs.emplace_back(funcPtr);
        }

        void __declspec(naked) MainHook()
        {
            __asm
            {
                pushad
                call Run
                popad
                jmp returnAddress
            }
        }
    }

    namespace OnGameStartup // starts on game launch(or scene startup)
    {
        uintptr_t returnAddress;
        std::list<void(*)()> funcPtrs;

        void Run()
        {
            for (auto &f : funcPtrs)
                f();
        }

        void Add(void(*funcPtr)())
        {
            funcPtrs.emplace_back(funcPtr);
        }

        void __declspec(naked) MainHook()
        {
            __asm
            {
                pushad
                call Run
                popad
                jmp returnAddress
            }
        }
    }

    namespace OnSceneStartup // starts on every phase
    {
        uintptr_t returnAddress;
        std::list<void(*)()> funcPtrs;

        void Run()
        {
            for (auto& f : funcPtrs)
                f();
        }

        void Add(void(*funcPtr)())
        {
            funcPtrs.emplace_back(funcPtr);
        }

        void __declspec(naked) MainHook()
        {
            __asm
            {
                pushad
                call Run
                popad
                jmp returnAddress
            }
        }
    }
    // on every cutscene
    namespace OnSceneCleanup
    {
        uintptr_t returnAddress;
        std::list<void(*)()> funcPtrs;

        void Run()
        {
            for (auto& f: funcPtrs)
                f();
        }

        void Add(void(*funcPtr)())
        {
            funcPtrs.emplace_back(funcPtr);
        }

        void __declspec(naked) MainHook()
        {
            __asm
            {
                pushad
                call Run
                popad
                jmp returnAddress
            }
        }
    }

    namespace OnTickEvent // event only during in game(when game doesn't have Trigger::StaFlags.STA_PAUSE)
    {
        uintptr_t returnAddress;
        std::list<void(*)()> funcPtrs;

        void Run()
        {
            for (auto& f : funcPtrs)
                f();
        }

        void Add(void(*funcPtr)())
        {
            funcPtrs.emplace_back(funcPtr);
        }

        void __declspec(naked) MainHook()
        {
            __asm
            {
                pushad
                call Run
                popad
                jmp returnAddress
            }
        }
    }

    namespace OnPauseEvent // update during pause
    {
        uintptr_t returnAddress;
        std::list<void(*)()> funcPtrs;

        void Run()
        {
            for (auto& f : funcPtrs)
                f();
        }

        void Add(void(*funcPtr)())
        {
            funcPtrs.emplace_back(funcPtr);
        }

        void __declspec(naked) MainHook()
        {
            __asm
            {
                pushad
                call Run
                popad
                jmp returnAddress
            }
        }
    }

    namespace OnEndScene
    {
        uintptr_t returnAddress;
        std::list<void(*)()> funcPtrs;

        void Run()
        {
            for (auto &f : funcPtrs)
                f();
        }

        void Add(void(*funcPtr)())
        {
            funcPtrs.emplace_back(funcPtr);
        }

        void __declspec(naked) MainHook()
        {
            __asm
            {
                pushad
                call Run
                popad
                jmp returnAddress
            }
        }
    }

    namespace OnDeviceReset
    {
        namespace After
        {
            uintptr_t returnAddress;
            std::list<void(*)()> funcPtrs;

            void Run()
            {
                for (auto &f : funcPtrs)
                    f();
            }

            void Add(void(*funcPtr)())
            {
                funcPtrs.emplace_back(funcPtr);
            }

            void __declspec(naked) MainHook()
            {
                __asm
                {
                    pushad
                    call Run
                    popad
                    jmp returnAddress
                }
            }
        }

        namespace Before
        {
            uintptr_t returnAddress;
            std::list<void(*)()> funcPtrs;

            void Run()
            {
                for (auto &f : funcPtrs)
                    f();
            }

            void Add(void(*funcPtr)())
            {
                funcPtrs.emplace_back(funcPtr);
            }

            void __declspec(naked) MainHook()
            {
                __asm
                {
                    pushad
                    call Run
                    popad
                    jmp returnAddress
                }
            }
        }
    }

    namespace OnExit
    {
        void Add(void(__cdecl *atexitFunc)())
        {
            atexit(atexitFunc);
        }
    }

    void InitEvents()
    {
        UpdateEvent::returnAddress = DoHook(shared::base + 0x6526A2, UpdateEvent::MainHook);
        OnGameStartup::returnAddress = DoHook(shared::base + 0x65104D, OnGameStartup::MainHook);
        OnSceneStartup::returnAddress = DoHook(shared::base + 0x64D227, OnSceneStartup::MainHook);
        OnSceneCleanup::returnAddress = DoHook(shared::base + 0x650770, OnSceneCleanup::MainHook);
        OnTickEvent::returnAddress = DoHook(shared::base + 0x64D411, OnTickEvent::MainHook);
        OnPauseEvent::returnAddress = DoHook(shared::base + 0x64D40A, OnPauseEvent::MainHook);
        OnEndScene::returnAddress = DoHook(shared::base + 0x65264C, OnEndScene::MainHook);
        OnDeviceReset::After::returnAddress = DoHook(shared::base + 0xB9D499, OnDeviceReset::After::MainHook);
        OnDeviceReset::Before::returnAddress = DoHook(shared::base + 0xB9D0FA, OnDeviceReset::Before::MainHook);
        // we do not want to do this 
        // OnExit::returnAddress = DoHook(shared::base + 0x9F975C, OnExit::MainHook);
    }

    void OnStartup();

    void Init()
    {
        InitEvents();
        OnStartup();
    }
}
#endif

#ifndef DllMain
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