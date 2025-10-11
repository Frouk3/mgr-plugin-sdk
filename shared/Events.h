#pragma once

#include <Windows.h>
#include <functional>
#include "injector/hooking.hpp"

struct GameManager;
struct cGameRuntime;

class Events
{
public:
	enum class CallingConvention {Cdecl, Stdcall, Fastcall, Thiscall};
	enum class FunctionAddPriority {AddBefore, AddAfter};

	template <FunctionAddPriority prior, uintptr_t injectionPoint, CallingConvention C, typename... Args>
	class IEventBase
	{
	public:
		class Key
		{
		private:
			std::vector<std::function<void(Args...)>> m_vector;
		public:

			std::vector<std::function<void(Args...)>>& getVector() { return m_vector; }

			void add(std::function<void(Args...)> cb) { m_vector.push_back(std::move(cb)); }

			Key& operator+=(std::function<void(Args...)> cb) { add(std::move(cb)); return *this; }
		};
	public:
		Key before;
		Key after;

		IEventBase& operator+=(std::function<void(Args...)> cb) { (prior == FunctionAddPriority::AddBefore ? before : after) += cb; return *this; }
	};

	template <FunctionAddPriority prior, uintptr_t injectionPoint, CallingConvention C, typename... Args>
	class IEvent;

	template <FunctionAddPriority prior, uintptr_t injectionPoint, typename... Args>
	class IEvent<prior, injectionPoint, CallingConvention::Cdecl, Args...> : public IEventBase<prior, injectionPoint, CallingConvention::Cdecl, Args...>
	{
	private:
		using hook = injector::function_hooker<injectionPoint, void*(Args...)>;
	public:
		IEvent()
		{
			injector::make_static_hook<hook>([this](std::function<void* (Args...)> orig, Args... args)
				{
					for (auto& hook : this->before.getVector())
						hook(args...);

					void* ret = orig(args...);

					for (auto& hook : this->after.getVector())
						hook(args...);

					return ret;
				});
		}
	};

	template <FunctionAddPriority prior, uintptr_t injectionPoint, typename... Args>
	class IEvent<prior, injectionPoint, CallingConvention::Thiscall, Args...> : public IEventBase<prior, injectionPoint, CallingConvention::Thiscall, Args...>
	{
	private:
		using hook = injector::function_hooker_thiscall<injectionPoint, void* (Args...)>;
	public:
		IEvent()
		{
			injector::make_static_hook<hook>([this](std::function<void* (Args...)> orig, Args... args)
				{
					for (auto& hook : this->before.getVector())
						hook(args...);

					void* ret = orig(args...);

					for (auto& hook : this->after.getVector())
						hook(args...);

					return ret;
				});
		}
	};

	template <FunctionAddPriority prior, uintptr_t injectionPoint, typename... Args>
	class IEvent<prior, injectionPoint, CallingConvention::Stdcall, Args...> : public IEventBase<prior, injectionPoint, CallingConvention::Stdcall, Args...>
	{
	private:
		using hook = injector::function_hooker_stdcall<injectionPoint, void* (Args...)>;
	public:
		IEvent()
		{
			injector::make_static_hook<hook>([this](std::function<void* (Args...)> orig, Args... args)
				{
					for (auto& hook : this->before.getVector())
						hook(args...);

					void* ret = orig(args...);

					for (auto& hook : this->after.getVector())
						hook(args...);

					return ret;
				});
		}
	};

	template <FunctionAddPriority prior, uintptr_t injectionPoint, typename... Args>
	class IEvent<prior, injectionPoint, CallingConvention::Fastcall, Args...> : public IEventBase<prior, injectionPoint, CallingConvention::Fastcall, Args...>
	{
	private:
		using hook = injector::function_hooker_fastcall<injectionPoint, void* (Args...)>;
	public:
		IEvent()
		{
			injector::make_static_hook<hook>([this](std::function<void* (Args...)> orig, Args... args)
				{
					for (auto& hook : this->before.getVector())
						hook(args...);

					void* ret = orig(args...);

					for (auto& hook : this->after.getVector())
						hook(args...);

					return ret;
				});
		}
	};
public:
	static inline IEvent<FunctionAddPriority::AddBefore, 0x6526A2, CallingConvention::Cdecl> OnUpdateEvent; // Every non-game tick
	static inline IEvent<FunctionAddPriority::AddAfter, 0x652CDF, CallingConvention::Thiscall, GameManager *> OnGameStartupEvent; // Executed after logo sequence
	static inline IEvent<FunctionAddPriority::AddBefore, 0x650719, CallingConvention::Thiscall, cGameRuntime *> OnSceneStartupEvent; // Executes functions if scene should be prepared
	static inline IEvent<FunctionAddPriority::AddBefore, 0x654237, CallingConvention::Thiscall, void *> OnSceneCleanupEvent; // Executes functions if scene wants to be cleaned
	static inline IEvent<FunctionAddPriority::AddBefore, 0x64D411, CallingConvention::Cdecl> OnTickEvent; // Every in-game tick
	static inline IEvent<FunctionAddPriority::AddBefore, 0x64D40A, CallingConvention::Cdecl> OnPauseEvent; // Every tick that is in pause
	static inline IEvent<FunctionAddPriority::AddBefore, 0x652651, CallingConvention::Cdecl> OnEndScene; // On render, though render is executed after the end scene call
	static inline IEvent<FunctionAddPriority::AddAfter, 0x651253, CallingConvention::Cdecl> OnDeviceReset; // On Device reset
	static inline IEvent<FunctionAddPriority::AddBefore, 0x653360, CallingConvention::Cdecl> OnApplicationStartEvent; // On first application startup function
	static inline IEvent<FunctionAddPriority::AddBefore, 0xB9807A, CallingConvention::Cdecl> OnPresent; // Used for rendering purposes
	static inline IEvent<FunctionAddPriority::AddAfter, 0x65304D, CallingConvention::Cdecl> OnHeapStartup; // On heap starting up
	static inline IEvent<FunctionAddPriority::AddBefore, 0x6530B1, CallingConvention::Thiscall, void*> OnHavokStartupEvent; // Havok startup
	static inline IEvent<FunctionAddPriority::AddBefore, 0x64F3CF, CallingConvention::Cdecl> OnGameCleanupEvent; // when game checks that it should be cleanup
	static inline IEvent<FunctionAddPriority::AddAfter, 0x652AE3, CallingConvention::Cdecl> OnMainCleanupEvent; // If game cleanup was successful without any errors while closing the game, Main Cleanup is executed
};