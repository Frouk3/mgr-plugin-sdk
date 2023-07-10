#include "injector/injector.hpp"
#include "shared.h"
#include "stdint.h"
#include <list>

namespace plugin
{
    namespace UpdateEvent
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

    namespace OnGameStartup
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

    namespace OnSceneStartup
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

    void InitEvents()
    {
        UpdateEvent::returnAddress = UpdateEvent::DoHook(shared::base + 0x6526A2);
        OnGameStartup::returnAddress = OnGameStartup::DoHook(shared::base + 0x65104D);
        OnSceneStartup::returnAddress = OnSceneStartup::DoHook(shared::base + 0x64D227);
        OnSceneCleanup::returnAddress = OnSceneCleanup::DoHook(shared::base + 0x650770);
    }

    void OnStartup();

    void Init()
    {
        InitEvents();
        OnStartup();
    }
}