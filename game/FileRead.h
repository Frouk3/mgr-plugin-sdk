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

		cPathStr() { CallMethod<0xA9C980, cPathStr *>(this); }
		cPathStr(const char *pStr) { CallMethod<0xA9C9A0, cPathStr *, const char *>(this, pStr); }
		void copy(const cPathStr &rOther) { CallMethod<0xA9C9C0, cPathStr *, const cPathStr &>(this, rOther); }
		void set(const char *pStr) { CallMethod<0xA9C120, cPathStr *, const char *>(this, pStr); }
		int isEqual(const cPathStr &rOther) const { return ReturnCallMethod<int, 0xA9C170, const cPathStr *, const cPathStr &>(this, rOther); }
		const char *c_str() const { return ReturnCallMethod<const char *, 0xA9C1F0, const cPathStr *>(this); } // wasn't even inlined lol
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

		cWork() { CallMethod<0xA9C9E0, cWork *>(this); }
		
		void requestStart() { CallMethod<0xA9C240, cWork *>(this); }
		void unsetListener(Listener *pListener) { CallMethod<0xA9C260, cWork *, Listener *>(this, pListener); }
		Listener *getListener() { return ReturnCallMethod<Listener*, 0xA9C290, cWork *>(this); }
		int isReadEnd() { return ReturnCallMethod<int, 0xA9C2A0, cWork *>(this); }
		int isReadSucceed() { return ReturnCallMethod<int, 0xA9C2E0, cWork *>(this); }
		void updateReservingTime() { CallMethod<0xA9C320, cWork *>(this); }
		void setMove(int a1, MOVE_RNO rno, int wait) { CallMethod<0xA9C350, cWork *, int, MOVE_RNO, int>(this, a1, rno, wait); }
		int isNeedFile() { return ReturnCallMethod<int, 0xA9C370, cWork *>(this); }
		int isAlive() { return ReturnCallMethod<int, 0xA9C390, cWork *>(this); }
		void getFileName(char *dst, unsigned int dstSize) { CallMethod<0xA9C3B0, cWork *, char *, unsigned int>(this, dst, dstSize); }
		void getResourceName(char *dst, unsigned int dstSize) { CallMethod<0xA9C3D0, cWork *, char *, unsigned int>(this, dst, dstSize); }
		void readyDestroyHeap() { CallMethod<0xA9C3F0, cWork *>(this); }
		int canDestroyHeap() { return ReturnCallMethod<int, 0xA9C400, cWork *>(this); }
		void requestCountDown() { CallMethod<0xA9CA30, cWork *>(this); }
		int moveCancelStart() { return ReturnCallMethod<int, 0xA9CA90, cWork *>(this); }
		int moveFileValid() { return ReturnCallMethod<int, 0xA9CAC0, cWork *>(this); }
		int moveReleaseStart() { return ReturnCallMethod<int, 0xA9CAF0, cWork *>(this); }
		void useCountUp() { CallMethod<0xA9CB10, cWork *>(this); }
		void useCountDown() { CallMethod<0xA9CB60, cWork *>(this); }
		void registResource() { CallMethod<0xA9CBC0, cWork *>(this); }
		void unregistResource() { CallMethod<0xA9CC50, cWork *>(this); }
		int moveReadWait() { return ReturnCallMethod<int, 0xA9D1E0, cWork *>(this); }
		int moveFileNone() { return ReturnCallMethod<int, 0xA9D9A0, cWork *>(this); }
		int moveAlloc() { return ReturnCallMethod<int, 0xA9E0A0, cWork *>(this); }
		int moveReadStart() { return ReturnCallMethod<int, 0xA9E170, cWork *>(this); }
		int moveCancelWait() { return ReturnCallMethod<int, 0xA9E1F0, cWork *>(this); }
		int moveReleaseWait() { return ReturnCallMethod<int, 0xA9E260, cWork *>(this); }
		void move() { CallMethod<0xA9E630, cWork *>(this); }
		void onDestroyHeap() { CallMethod<0xA9EE50, cWork *>(this); }
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

		void setEmergencyFlag(EMERGENCY_FLAG flag) { CallMethod<0xA9C100, Manager *, EMERGENCY_FLAG>(this, flag); }
		void unsetEmergencyFlag(EMERGENCY_FLAG flag) { CallMethod<0xA9C110, Manager *, EMERGENCY_FLAG>(this, flag); }
		void readyDestroyHeap(Hw::cHeap &rHeap) { CallMethod<0xA9C6C0, Manager *, Hw::cHeap &>(this, rHeap); }
		int canDestroyHeap(Hw::cHeap &rHeap) { return ReturnCallMethod<int, 0xA9C6F0, Manager *, Hw::cHeap &>(this, rHeap); }
		int startupWork(unsigned int workNum) { return ReturnCallMethod<int, 0xA9C760, Manager *, unsigned int>(this, workNum); }
		void updateEmergencyEnable() { CallMethod<0xA9C7B0, Manager *>(this); }
		void updateEmergencyDisable() { CallMethod<0xA9C8B0, Manager *>(this); }
		cWork *findWorkImpl(const cPathStr &rPath) { return ReturnCallMethod<cWork*, 0xA9C8F0, Manager *, const cPathStr &>(this, rPath); }
		cWork *findWork(eFileId fileId) { return ReturnCallMethod<cWork*, 0xA9C940, Manager *, eFileId>(this, fileId); }
		int startup() { return ReturnCallMethod<int, 0xA9CEE0, Manager *>(this); }
		int isReadEnd(eFileId fileId) { return ReturnCallMethod<int, 0xA9CF60, Manager *, eFileId>(this, fileId); }
		int isReadSucceed(eFileId fileId) { return ReturnCallMethod<int, 0xA9CFE0, Manager *, eFileId>(this, fileId); }
		int isOutOfMemory(eFileId fileId) { return ReturnCallMethod<int, 0xA9D060, Manager *, eFileId>(this, fileId); }
		void *getData(eFileId fileId) { return ReturnCallMethod<void*, 0xA9D0B0, Manager *, eFileId>(this, fileId); }
		void updateEmergency() { CallMethod<0xA9D120, Manager *>(this); }
		int isReadSucceed(const char *filePath) { return ReturnCallMethod<int, 0xA9D4D0, Manager *, const char *>(this, filePath); }
		void cleanup() { CallMethod<0xA9F150, Manager *>(this); }
		cWork *newWork() { return ReturnCallMethod<cWork*, 0xA9F7A0, Manager *>(this); }
	};

	static inline Manager& g_FileReadManager = *(Manager*)(shared::base + 0x19DA840);
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

	static inline int __cdecl registResource(void *pResourceData, unsigned int resource_size, const char *pResourceName) { return ReturnCdeclCall<int, 0x9E4420, void *, unsigned int, const char *>(pResourceData, resource_size, pResourceName); }
};

inline Hw::cFactoryFixed<Hw::ResourceManager::cWork, 4> &g_ResourceWorkFactory = *(Hw::cFactoryFixed<Hw::ResourceManager::cWork, 4>*)(shared::base + 0x19D0818);