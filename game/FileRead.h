#pragma once

#include <Hw.h>
#include <HwDvd.h>

enum EMERGENCY_FLAG { EMERGENCY_FLAG_HOOK = 0x1, EMERGENCY_FLAG_EVENT = 0x2 };
enum eFileId { eFileIdInvalid = 0 };
enum FILE_TYPE { FILE_TYPE_INVALID = 0, FILE_TYPE_CORE, FILE_TYPE_ROOM, FILE_TYPE_OBJ, FILE_TYPE_EVENT, FILE_TYPE_ID };

namespace FileRead
{
	enum { FILE_PATH_MAX = 32, RESOURCE_NAME_MAX = 32 }; // do NOT edit any of these values
	class Listener
	{
	public:

		virtual ~Listener() {};
	};

	class cPathStr
	{
	public:
		char m_pStr[FILE_PATH_MAX];

		cPathStr() { MAKE_CALL(shared::base + 0xA9C980, void(__thiscall *)(cPathStr *), this); }
		cPathStr(const char *pStr) { MAKE_CALL(shared::base + 0xA9C9A0, void(__thiscall *)(cPathStr *, const char *), this, pStr); }
		void copy(const cPathStr &rOther) { MAKE_CALL(shared::base + 0xA9C9C0, void(__thiscall *)(cPathStr *, const cPathStr &), this, rOther); }
		void set(const char *pStr) { MAKE_CALL(shared::base + 0xA9C120, void(__thiscall *)(cPathStr *, const char *), this, pStr); }
		int isEqual(const cPathStr &rOther) const { return MAKE_CALL(shared::base + 0xA9C170, int(__thiscall *)(const cPathStr *, const cPathStr &), this, rOther); }
		const char *c_str() const { return MAKE_CALL(shared::base + 0xA9C1F0, const char *(__thiscall *)(const cPathStr *), this); } // wasn't even inlined lol
	}; // Class is complete


	class cWork
	{
	public:
		enum MOVE_RNO { MOVE_INVALID = 0x0, MOVE_ALLOC, MOVE_READ_START, MOVE_READ_WAIT, MOVE_CANCEL_START, MOVE_CANCEL_WAIT, MOVE_FILE_VALID, MOVE_FILE_NONE, MOVE_RELEASE_START, MOVE_RELEASE_WAIT };
		enum FLAG { FLAG_DESTROY_HEAP = 0x1, FLAG_SET_RESOURCE = 0x2, FLAG_OUT_OF_MEMORY = 0x4, FLAG_EMERGENCY_RELEASE = 0x8, FLAG_ALLOC_BACK = 0x20 };

		Hw::eDvdId m_DvdId;
		FILE_TYPE m_FileType;
		cPathStr m_Path;
		eFileId m_FileId;
		int field_2C;
		void* m_pFileData;
		int m_NeedSize;
		Hw::cHeap* m_pHeap;
		unsigned int m_Flag;
		int m_RequestCount;
		int m_UseCount;
		int m_ReservingTime;
		MOVE_RNO m_MoveRno;
		int m_WaitCount;
		Hw::DVD_PRIO m_Prio;
		Listener* m_pListener;

		cWork() { MAKE_CALL(shared::base + 0xA9C9E0, void(__thiscall *)(cWork *), this); }
		
		void requestStart() { MAKE_CALL(shared::base + 0xA9C240, void(__thiscall *)(cWork *), this); }
		void unsetListener(Listener *pListener) { MAKE_CALL(shared::base + 0xA9C260, void(__thiscall *)(cWork *, Listener *), this, pListener); }
		Listener *getListener() { return MAKE_CALL(shared::base + 0xA9C290, Listener*(__thiscall *)(cWork *), this); }
		int isReadEnd() { return MAKE_CALL(shared::base + 0xA9C2A0, int(__thiscall *)(cWork *), this); }
		int isReadSucceed() { return MAKE_CALL(shared::base + 0xA9C2E0, int(__thiscall *)(cWork *), this); }
		void updateReservingTime() { MAKE_CALL(shared::base + 0xA9C320, void(__thiscall *)(cWork *), this); }
		void setMove(int a1, MOVE_RNO rno, int wait) { MAKE_CALL(shared::base + 0xA9C350, void(__thiscall *)(cWork *, int, MOVE_RNO, int), this, a1, rno, wait); }
		int isNeedFile() { return MAKE_CALL(shared::base + 0xA9C370, int(__thiscall *)(cWork *), this); }
		int isAlive() { return MAKE_CALL(shared::base + 0xA9C390, int(__thiscall *)(cWork *), this); }
		void getFileName(char *dst, unsigned int dstSize) { MAKE_CALL(shared::base + 0xA9C3B0, void(__thiscall *)(cWork *, char *, unsigned int), this, dst, dstSize); }
		void getResourceName(char *dst, unsigned int dstSize) { MAKE_CALL(shared::base + 0xA9C3D0, void(__thiscall *)(cWork *, char *, unsigned int), this, dst, dstSize); }
		void readyDestroyHeap() { MAKE_CALL(shared::base + 0xA9C3F0, void(__thiscall *)(cWork *), this); }
		int canDestroyHeap() { return MAKE_CALL(shared::base + 0xA9C400, int(__thiscall *)(cWork *), this); }
		void requestCountDown() { MAKE_CALL(shared::base + 0xA9CA30, void(__thiscall *)(cWork *), this); }
		int moveCancelStart() { return MAKE_CALL(shared::base + 0xA9CA90, int(__thiscall *)(cWork *), this); }
		int moveFileValid() { return MAKE_CALL(shared::base + 0xA9CAC0, int(__thiscall *)(cWork *), this); }
		int moveReleaseStart() { return MAKE_CALL(shared::base + 0xA9CAF0, int(__thiscall *)(cWork *), this); }
		void useCountUp() { MAKE_CALL(shared::base + 0xA9CB10, void(__thiscall *)(cWork *), this); }
		void useCountDown() { MAKE_CALL(shared::base + 0xA9CB60, void(__thiscall *)(cWork *), this); }
		void registResource() { MAKE_CALL(shared::base + 0xA9CBC0, void(__thiscall *)(cWork *), this); }
		void unregistResource() { MAKE_CALL(shared::base + 0xA9CC50, void(__thiscall *)(cWork *), this); }
		int moveReadWait() { return MAKE_CALL(shared::base + 0xA9D1E0, int(__thiscall *)(cWork *), this); }
		int moveFileNone() { return MAKE_CALL(shared::base + 0xA9D9A0, int(__thiscall *)(cWork *), this); }
		int moveAlloc() { return MAKE_CALL(shared::base + 0xA9E0A0, int(__thiscall *)(cWork *), this); }
		int moveReadStart() { return MAKE_CALL(shared::base + 0xA9E170, int(__thiscall *)(cWork *), this); }
		int moveCancelWait() { return MAKE_CALL(shared::base + 0xA9E1F0, int(__thiscall *)(cWork *), this); }
		int moveReleaseWait() { return MAKE_CALL(shared::base + 0xA9E260, int(__thiscall *)(cWork *), this); }
		void move() { MAKE_CALL(shared::base + 0xA9E630, void(__thiscall *)(cWork *), this); }
		void onDestroyHeap() { MAKE_CALL(shared::base + 0xA9EE50, void(__thiscall *)(cWork *), this); }
	};

	class Manager
	{
	public:
		Hw::cFactoryFixed<cWork, 4> m_FileReadFactory;
		Hw::cFixedVector<cWork*> m_FileReaderVector;
		unsigned int m_RotateFileId; // next file id to assign
		unsigned int m_EmergencyFlag;
		int m_EmergencyCount;
		int m_IsEmergency;
		int field_8C;
		int field_90;
		int field_94;
		int field_98;
		int field_9C;

		void setEmergencyFlag(EMERGENCY_FLAG flag) { MAKE_CALL(shared::base + 0xA9C100, void(__thiscall *)(Manager *, EMERGENCY_FLAG), this, flag); }
		void unsetEmergencyFlag(EMERGENCY_FLAG flag) { MAKE_CALL(shared::base + 0xA9C110, void(__thiscall *)(Manager *, EMERGENCY_FLAG), this, flag); }
		void readyDestroyHeap(Hw::cHeap &rHeap) { MAKE_CALL(shared::base + 0xA9C6C0, void(__thiscall *)(Manager *, Hw::cHeap &), this, rHeap); }
		int canDestroyHeap(Hw::cHeap &rHeap) { return MAKE_CALL(shared::base + 0xA9C6F0, int(__thiscall *)(Manager *, Hw::cHeap &), this, rHeap); }
		int startupWork(unsigned int workNum) { return MAKE_CALL(shared::base + 0xA9C760, int(__thiscall *)(Manager *, unsigned int), this, workNum); }
		void updateEmergencyEnable() { MAKE_CALL(shared::base + 0xA9C7B0, void(__thiscall *)(Manager *), this); }
		void updateEmergencyDisable() { MAKE_CALL(shared::base + 0xA9C8B0, void(__thiscall *)(Manager *), this); }
		cWork *findWorkImpl(const cPathStr &rPath) { return MAKE_CALL(shared::base + 0xA9C8F0, cWork*(__thiscall *)(Manager *, const cPathStr &), this, rPath); }
		cWork *findWork(eFileId fileId) { return MAKE_CALL(shared::base + 0xA9C940, cWork*(__thiscall *)(Manager *, eFileId), this, fileId); }
		int startup() { return MAKE_CALL(shared::base + 0xA9CEE0, int(__thiscall *)(Manager *), this); }
		int isReadEnd(eFileId fileId) { return MAKE_CALL(shared::base + 0xA9CF60, int(__thiscall *)(Manager *, eFileId), this, fileId); }
		int isReadSucceed(eFileId fileId) { return MAKE_CALL(shared::base + 0xA9CFE0, int(__thiscall *)(Manager *, eFileId), this, fileId); }
		int isOutOfMemory(eFileId fileId) { return MAKE_CALL(shared::base + 0xA9D060, int(__thiscall *)(Manager *, eFileId), this, fileId); }
		void *getData(eFileId fileId) { return MAKE_CALL(shared::base + 0xA9D0B0, void*(__thiscall *)(Manager *, eFileId), this, fileId); }
		void updateEmergency() { MAKE_CALL(shared::base + 0xA9D120, void(__thiscall *)(Manager *), this); }
		int isReadSucceed(const char *filePath) { return MAKE_CALL(shared::base + 0xA9D4D0, int(__thiscall *)(Manager *, const char *), this, filePath); }
		void cleanup() { MAKE_CALL(shared::base + 0xA9F150, void(__thiscall *)(Manager *), this); }
		cWork *newWork() { return MAKE_CALL(shared::base + 0xA9F7A0, cWork*(__thiscall *)(Manager *), this); }
	};

	inline Manager& g_FileReadManager = *(Manager*)(shared::base + 0x19DA840);
};

class Hw::ResourceManager
{
public:
	class cWork
	{
	public:
		void *m_pResourceData;
		unsigned int m_ResourceSize;
		char m_pResourceName[FileRead::RESOURCE_NAME_MAX];
	};

	static inline int __cdecl registResource(void *pResourceData, unsigned int resource_size, const char *pResourceName) { return MAKE_CALL(shared::base + 0x9E4420, int(__cdecl *)(void *, unsigned int, const char *), pResourceData, resource_size, pResourceName); }
};

inline Hw::cFactoryFixed<Hw::ResourceManager::cWork, 4> &g_ResourceWorkFactory = *(Hw::cFactoryFixed<Hw::ResourceManager::cWork, 4>*)(shared::base + 0x19D0818);