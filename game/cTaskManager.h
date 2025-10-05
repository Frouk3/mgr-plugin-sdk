#pragma once

#include <Hw.h>

struct cTaskManager
{
	struct cTask;

	int m_nTaskCapacity;
	cTask* m_pTaskBegin;
	cTask* m_pFirst;
	cTask* m_pLastTask;
	cTask* m_pCurrentTask;
	int m_nTasks;
	cTaskManager* field_18;

	cTaskManager()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D6DF0))(this);
	}

	cTask* setNewTaskByPriority(unsigned int priority)
	{
		return ((cTask * (__thiscall*)(cTaskManager*, int))(shared::base + 0x9D7420))(this, priority);
	}
	
	void startTask(void(__cdecl *callback)(LPVOID parameter), LPVOID parameter, unsigned int priority, const char* taskName)
	{
		((void(__thiscall*)(cTaskManager*, void(__cdecl *)(LPVOID), LPVOID, unsigned int, const char*))(shared::base + 0x9D7870))(this, callback, parameter, priority, taskName);
	}

	void cleanup()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D8450))(this);
	}

	void executeCurrentTask(int a1)
	{
		((void(__thiscall*)(cTaskManager*, int))(shared::base + 0x9D8570))(this, a1);
	}

	BOOL startup(unsigned int taskCapacity, unsigned int taskStackSize, Hw::cHeapVariable* allocator)
	{
		return ((BOOL(__thiscall*)(cTaskManager*, unsigned int, unsigned int, Hw::cHeapVariable*))(shared::base + 0x9D8A10))(this, taskCapacity, taskStackSize, allocator);
	}

	void runTasks()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D8DA0))(this);
	}

	~cTaskManager()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D8A00))(this);
	}
};

struct cTaskManager::cTask
{
	cTaskManager* m_pCreator;
	void(__cdecl* m_pfnCallback)(LPVOID);
	LPVOID m_pCallbackParameter;
	int m_nTaskNum;
	int m_nTaskPriority;
	const char* m_TaskName;
	int m_nTaskStatus;
	int m_nTaskId;
	unsigned int m_nTaskStackSize;
	HANDLE m_hStartSemaphore;
	HANDLE m_hCompletionSemaphore;
	cTask* m_pNext;
	cTask* m_pPrev;
	void(__cdecl *m_pfnOnTaskDone)(unsigned long);

	void cleanup()
	{
		((void(__thiscall*)(cTask*))(shared::base + 0x9D8000))(this);
	}

	void run(int a1)
	{
		((void(__thiscall*)(cTask*, int))(shared::base + 0x9D80E0))(this, a1);
	}

	void setTaskFunction(void(__cdecl* callback)(LPVOID), LPVOID parameter)
	{
		((void(__thiscall*)(cTask*, void(__cdecl*)(LPVOID), LPVOID))(shared::base + 0x9D8090))(this, callback, parameter);
	}
};