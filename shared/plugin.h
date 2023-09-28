#include "injector/injector.hpp"
#include "shared.h"
#include "stdint.h"
#include <list>

#ifndef plugin
namespace plugin
{
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

        uint32_t DoHook(uint32_t address)
        {
            uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

            injector::MakeCALL(address, MainHook, true);

            return origCall;
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

        uint32_t DoHook(uint32_t address)
        {
            uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

            injector::MakeCALL(address, MainHook, true);

            return origCall;
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

        uint32_t DoHook(uint32_t address)
        {
            uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

            injector::MakeCALL(address, MainHook, true);

            return origCall;
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

        uint32_t DoHook(uint32_t address)
        {
            uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

            injector::MakeCALL(address, MainHook, true);

            return origCall;
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

        uint32_t DoHook(uint32_t address)
        {
            uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

            injector::MakeCALL(address, MainHook, true);

            return origCall;
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
        
        uint32_t DoHook(uint32_t address)
        {
            uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);
            
            injector::MakeCALL(address, MainHook, true);

            return origCall;
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

        uint32_t DoHook(uint32_t address)
        {
            uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

            injector::MakeCALL(address, MainHook, true);

            return origCall; 
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

            uint32_t DoHook(uint32_t address)
            {
                uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

                injector::MakeCALL(address, MainHook, true);

                return origCall;
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

            uint32_t DoHook(uint32_t address)
            {
                uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

                injector::MakeCALL(address, MainHook, true);

                return origCall;
            }
        }
    }

    namespace OnExit
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

        uint32_t DoHook(uint32_t address)
        {
            uint32_t origCall = (uint32_t)injector::ReadRelativeOffset(address + 1);

            injector::MakeCALL(address, MainHook, true);

            return origCall;
        }
    }

    void InitEvents()
    {
        UpdateEvent::returnAddress = UpdateEvent::DoHook(shared::base + 0x6526A2);
        OnGameStartup::returnAddress = OnGameStartup::DoHook(shared::base + 0x65104D);
        OnSceneStartup::returnAddress = OnSceneStartup::DoHook(shared::base + 0x64D227);
        OnSceneCleanup::returnAddress = OnSceneCleanup::DoHook(shared::base + 0x650770);
        OnTickEvent::returnAddress = OnTickEvent::DoHook(shared::base + 0x64D411);
        OnPauseEvent::returnAddress = OnPauseEvent::DoHook(shared::base + 0x64D40A);
        OnEndScene::returnAddress = OnEndScene::DoHook(shared::base + 0x65264C);
        OnDeviceReset::After::returnAddress = OnDeviceReset::After::DoHook(shared::base + 0xB9D499);
        OnDeviceReset::Before::returnAddress = OnDeviceReset::Before::DoHook(shared::base + 0xB9D0FA);
        OnExit::returnAddress = OnExit::DoHook(shared::base + 0x9F975C);
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