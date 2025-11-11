#pragma once

#include <Hw.h>
#include <HwDvd.h>

enum eFileId
{
	eFileIdInvalid
};

namespace FileRead
{
	class Listener
	{
	public:

		virtual ~Listener() {};
	};

	class cPathStr
	{
	public:
		char m_pStr[32];

		const char *c_str() const { return m_pStr; }
	};


	class cWork
	{
	public:
		enum MOVE_RNO
		{
			MOVE_INVALID = 0x0,
			MOVE_ALLOC = 0x1,
			MOVE_READ_START = 0x2,
			MOVE_READ_WAIT = 0x3,
			MOVE_CANCEL_START = 0x4,
			MOVE_CANCEL_WAIT = 0x5,
			MOVE_FILE_VALID = 0x6,
			MOVE_FILE_NONE = 0x7,
			MOVE_RELEASE_START = 0x8,
			MOVE_RELEASE_WAIT = 0x9,
		};

		Hw::eDvdId m_DvdId;
		int m_FileType;
		cPathStr m_Path;
		eFileId m_FileId;
		int field_2C;
		void* m_pFileData;
		int m_NeedSize;
		Hw::cHeap* m_pHeap;
		int m_Flag;
		int m_RequestCount;
		int m_UseCount;
		int field_48;
		FileRead::cWork::MOVE_RNO m_MoveRno;
		int m_WaitCount;
		Hw::DVD_PRIO m_DvdPrio;
		FileRead::Listener* m_pListener;

		void removeRequest()
		{
			((void(__thiscall *)(cWork *))(shared::base + 0xA9CA30))(this);
		}

		void registerUsage()
		{
			((void(__thiscall *)(cWork *))(shared::base + 0xA9CB10))(this);
		}

		void unregisterUsage()
		{
			((void(__thiscall *)(cWork *))(shared::base + 0xA9CB60))(this);
		}

		void registerFile()
		{
			((void(__thiscall *)(cWork *))(shared::base + 0xA9CBC0))(this);
		}

		void unregisterFile()
		{
			((void(__thiscall *)(cWork *))(shared::base + 0xA9CC50))(this);
		}

		BOOL processReading()
		{
			((void(__thiscall *)(cWork *))(shared::base + 0xA9D1E0))(this);
		}

		BOOL cleanup()
		{
			return ((BOOL(__thiscall *)(cWork *))(shared::base + 0xA9D9A0))(this);
		}

		BOOL prepare()
		{
			return ((BOOL(__thiscall *)(cWork *))(shared::base + 0xA9E0A0))(this);
		}

		BOOL requestLoader()
		{
			return ((BOOL(__thiscall *)(cWork *))(shared::base + 0xA9E170))(this);
		}

		BOOL manageFilestate()
		{
			return ((BOOL(__thiscall *)(cWork *))(shared::base + 0xA9E260))(this);
		}

		void tick()
		{
			((void(__thiscall *)(cWork *))(shared::base + 0xA9E630))(this);
		}
	};

	class Manager
	{
	public:
		Hw::cFactoryFixed<cWork, 4> m_FileReadFactory;
		Hw::cFixedVector<cWork*> m_FileReaderVector;
		int field_7C;
		int field_80;
		int m_EmergencyCount;
		int m_IsEmergency;
		int field_8C;
		int field_90;
		int field_94;
		int field_98;
		int field_9C;

		cWork *getWorkByFilename(const char *filename)
		{
			return ((cWork *(__thiscall *)(Manager *, const char *))(shared::base + 0xA9C8F0))(this, filename);
		}

		cWork *getWorkByID(int id)
		{
			return ((cWork*(__thiscall *)(Manager *, int))(shared::base + 0xA9C940))(this, id);
		}

		BOOL startup()
		{
			return ((BOOL(__thiscall *)(Manager *))(shared::base + 0xA9CEE0))(this);
		}

		BOOL isReady(int id)
		{
			return ((BOOL(__thiscall *)(Manager*, int))(shared::base + 0xA9CF60))(this, id);
		}

		BOOL isIdle(int id)
		{
			return ((BOOL(__thiscall *)(Manager *, int))(shared::base + 0xA9CFE0))(this, id);
		}

		BOOL isRequested(int reader)
		{
			return ((BOOL(__thiscall *)(Manager *, int))(shared::base + 0xA9D060))(this, reader);
		}

		void *getFiledata(int reader)
		{
			return ((void*(__thiscall *)(Manager *, int))(shared::base + 0xA9D0B0))(this, reader);
		}

		BOOL isReady(const char *filename)
		{
			return ((BOOL(__thiscall *)(Manager *, const char *))(shared::base + 0xA9D4D0))(this, filename);
		}

		void *getFiledata(const char *filename)
		{
			return ((void*(__thiscall *)(Manager *, const char *))(shared::base + 0xA9D5D0))(this, filename);
		}

		BOOL requestWork(int reader)
		{
			return ((BOOL(__thiscall *)(Manager *, int))(shared::base + 0xA9D660))(this, reader);
		}

		void removeRequest(int reader)
		{
			((void(__thiscall *)(Manager *, int))(shared::base + 0xA9D6A0))(this, reader);
		}

		void setUse(int worker)
		{
			((void(__thiscall *)(Manager *, int))(shared::base + 0xA9D710))(this, worker);
		}

		void removeUse(int worker)
		{
			((void(__thiscall *)(Manager *, int))(shared::base + 0xA9D7A0))(this, worker);
		}

		void removeListener(int worker, Listener *listener)
		{
			((void(__thiscall *)(Manager *, int, Listener *))(shared::base + 0xA9D860))(this, worker, listener);
		}

		cWork *requestWork(int a2, const char *filename, Hw::cHeap *allocator, char a5, Listener *listener)
		{
			return ((cWork*(__thiscall *)(Manager*, int, const char *, Hw::cHeap *, char, Listener *))(shared::base + 0xA9DF40))(this, a2, filename, allocator, a5, listener);
		}

		int requestWorker(int a2, const char *filename, Hw::cHeap *allocator, char a5, Listener *listener)
		{
			return ((int(__thiscall *)(Manager *, int, const char *, Hw::cHeap *, char, Listener*))(shared::base + 0xA9E570))(this, a2, filename, allocator, a5, listener);
		}

		void tick()
		{
			((void(__thiscall *)(Manager *))(shared::base + 0xA9EFB0))(this);
		}

		void cleanup()
		{
			((void(__thiscall *)(Manager *))(shared::base + 0xA9F150))(this);
		}

		cWork *allocateWorker()
		{
			return ((cWork*(__thiscall *)(Manager *))(shared::base + 0xA9F7A0))(this);
		}
	};

	static inline Manager& g_FileReadManager = *(Manager*)(shared::base + 0x19DA840);
};