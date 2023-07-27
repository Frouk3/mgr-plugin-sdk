#include "injector/injector.hpp"
#include "shared.h"
#include "stdint.h"
#include <list>

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
    // !!! DOESN'T WORK CURRENTLY !!!
    namespace DrawingEvent
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
        DrawingEvent::returnAddress = DrawingEvent::DoHook(shared::base + 0x65264C);
    }

    void OnStartup();

    void Init()
    {
        InitEvents();
        OnStartup();
    }
}