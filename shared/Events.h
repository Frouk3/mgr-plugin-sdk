#pragma once

#include "injector/injector.hpp"
#include "shared.h"
#include "stdint.h"
#include <vector>
#include <functional>

class Events
{
public:
   // Base class for events
	/*template <typename ...Args>
	class IEventBase
	{
	protected:
		typedef std::function<void(Args...)> FuncCallback;
		class Key
		{
		private:
			std::vector<FuncCallback> hooks;
		public:

			std::vector<FuncCallback> &getHooks()
			{
				return hooks;
			}

			Key() {};

			~Key() 
			{
				hooks.clear();
			};

			void add(FuncCallback func)
			{
				hooks.emplace_back(func);
			}

			void remove(FuncCallback func)
			{
				auto it = std::find(hooks.begin(), hooks.end(), func);
				if (it != hooks.end())
				{
					hooks.erase(it);
				}
			}

			void run()
			{
				for (FuncCallback& func : hooks)
					func();
			}

			Key& operator+=(FuncCallback func)
			{
				add(func);
				return *this;
			}

			Key& operator-=(FuncCallback func)
			{
				remove(func);
				return *this;
			}
		};

		uintptr_t callback;
		void(__cdecl *mainhook)();

	public:
		IEventBase()
		{
			callback = NULL;
			mainhook = nullptr;
		}

		IEventBase(uintptr_t where)
		{
			Patch(where);
		}

		~IEventBase()
		{
			
		}

	private:
		void Patch(uintptr_t where)
		{

		}
	public:
	};*/
public:
	template <int mPriority, unsigned int address, void(*mainhook)()>
	class IEvent
	{
	private:
		uintptr_t returnAddress;

		class Key
		{
		private:
			std::vector<std::function<void()>> vector;
		public:

			Key()
			{
				
			}

			~Key()
			{
				vector.clear();
			}

			Key& operator +=(std::function<void()> function)
			{
				vector.emplace_back(function);
				return *this;
			}

			std::vector<std::function<void()>>& getVector()
			{
				return vector;
			}

			void operator()()
			{
				for (std::function<void()> func : vector)
					func();
			}
		};
	public:
		Key before; // Use to add events before event occurs
		Key after; // Use to add events after event occurs

		IEvent()
		{
			returnAddress = (uintptr_t)injector::MakeCALL(shared::base + address, mainhook, true);
		}

		void CallBefore()
		{
			before();
		}

		void CallAfter()
		{
			after();
		}

		IEvent& operator+=(std::function<void()> func)
		{
			(mPriority == 0 ? before : after) += func;
			return *this;
		}

		~IEvent()
		{
			injector::MakeCALL(shared::base + address, returnAddress, true);
		}
	};

	static void __cdecl CallHooks(std::vector<std::function<void()>> *pKey)
	{
		for (std::function<void()> func : *pKey)
			func();
	}
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
	static inline IEvent<0, 0x6526A2, Caves::OnUpdateMainHook> OnUpdateEvent; // Every non-game tick
	static inline IEvent<0, 0x65104D, Caves::OnGameStartupMainHook> OnGameStartupEvent; // Executed after logo sequence
	static inline IEvent<0, 0x64D227, Caves::OnSceneStartupMainHook> OnSceneStartupEvent; // Executes functions if scene should be prepared
	static inline IEvent<0, 0x654237, Caves::OnSceneCleanupMainHook> OnSceneCleanupEvent; // Executes functions if scene wants to be cleaned
	static inline IEvent<0, 0x64D411, Caves::OnTickEventMainHook> OnTickEvent; // Every in-game tick
	static inline IEvent<0, 0x64D40A, Caves::OnPauseEventMainHook> OnPauseEvent; // Every tick that is in pause
	static inline IEvent<0, 0x652651, Caves::OnEndSceneMainHook> OnEndScene; // On render, though render is executed after the end scene call
	static inline IEvent<1, 0x651253, Caves::OnDeviceResetHook> OnDeviceReset; // On Device reset
	static inline IEvent<0, 0x653360, Caves::OnApplicationStartup> OnApplicationStartEvent; // On first application startup function
	static inline IEvent<0, 0xB9807A, Caves::OnPresentHook> OnPresent; // Used for rendering purposes
	static inline IEvent<1, 0x65304D, Caves::OnHeapStartupHook> OnHeapStartup; // On heap starting up
	static inline IEvent<0, 0x6530B1, Caves::OnHavokStartupHook> OnHavokStartupEvent; // Havok startup
	static inline IEvent<0, 0x64F3CF, Caves::OnGameCleanupHook> OnGameCleanupEvent; // when game checks that it should be cleanup
	static inline IEvent<0, 0x652AE3, Caves::OnMainCleanupEventHook> OnMainCleanupEvent; // If game cleanup was successful without any errors while closing the game, Main Cleanup is executed
};



#define DEFINE_CAVE(Cave, Event)                                        \
void __declspec(naked) Cave()                                           \
{                                                                       \
	__asm																\
	{																	\
		__asm pushad													\
		__asm lea eax, Event.before										\
		__asm push eax													\
		__asm call Events::CallHooks									\
		__asm add esp, 04 /* push with __cdecl -> add esp, sizeargs*/	\
		__asm popad														\
		__asm call dword ptr [Event]									\
		__asm push eax													\
		__asm pushad													\
		__asm lea eax, Event.after										\
		__asm push eax													\
		__asm call Events::CallHooks									\
		__asm add esp, 04												\
		__asm popad														\
		__asm pop eax													\
		__asm ret														\
	}																	\
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