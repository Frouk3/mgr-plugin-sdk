#pragma once

#include <Hw.h>
#include <CriFs.h>

namespace Hw
{
    enum eDvdId { eDvdInvalid = 0 };
    enum DVD_CONST { DVD_MAX_PATH = 0x40 };
    enum DVD_PRIO
    {
        DVD_PRIO_LOWEST = 0xFFFFFFFE,
        DVD_PRIO_LOW = 0xFFFFFFFF,
        DVD_PRIO_NORMAL = 0x0,
        DVD_PRIO_HIGH = 0x1,
        DVD_PRIO_HIGHEST = 0x2,
        DVD_PRIO_DEFAULT = 0x0,
        DVD_PRIO_MAX = 0x2,
        DVD_PRIO_MIN = 0xFFFFFFFE,
    };

    class cDvdCriFsBinder;
    class cDvdFst;
    class cDvdFstBuffer;
    class cDvdFstDir;
    class cDvdFstFile;
    class cDvdReader;
    class cDvdReadWork;
	class DvdCriFs;
    class DvdEnv;
	class DvdSystem;
	class DvdReadManager;
}

class Hw::cDvdReader
{
public:
    enum STATE { STATE_NONE = 0, STATE_OPEN, STATE_READING, STATE_COMPLETE, STATE_CANCELING, STATE_CANCELED, STATE_ERROR };

	Hw::cDvdReader::STATE m_State;
	Hw::cDvdCriFsBinder *m_pBinder;
	CriFsLoaderHn *m_LoaderHandle;
	char m_pFilePath[64];
	unsigned int m_EmulateTime;
	unsigned int m_ReadStartTime;
	void *m_pReadAddr;
	int m_Size;
	Hw::DVD_PRIO m_Prio;
	int field_60;
	int field_64;
	int m_Sync;
	Hw::cDvdReader *m_pPrevReader;
	Hw::cDvdReader *m_pNextReader;

	cDvdReader() { ((void(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9E85E0))(this); }
	~cDvdReader() { ((void(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9EA7B0))(this); }

	int read(const char *pFilePath, void *pReadAddr, unsigned int Size, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__thiscall *)(Hw::cDvdReader*, const char*, void*, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EB160))(this, pFilePath, pReadAddr, Size, prio); }
	void cancel() { ((void(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9E9860))(this); }
	void close() { ((void(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9E98B0))(this); }
	void update() { ((void(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9EA800))(this); }
	void updateSync() { ((void(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9EA8B0))(this); }
	int isError() { return ((int(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9E8600))(this); }
	int canClose() { return ((int(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9E8610))(this); }
	DVD_PRIO getPrio() { return ((DVD_PRIO(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9E8650))(this); }

//	private:

    int updateOpened() { return ((int(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9E9900))(this); }
    int updateReading() { return ((int(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9E9A50))(this); }
    int updateCanceling() { return ((int(__thiscall *)(Hw::cDvdReader*))(shared::base + 0x9E9B30))(this); }
};

class Hw::cDvdCriFsBinder
{
public:
	enum TYPE { TYPE_INVALID = 0, TYPE_ROOT, TYPE_FILE, TYPE_CPK };

	int bindCpkFileSync(const char *pFilePath, int __formal, int __unused, int prio) { return ((int(__thiscall *)(Hw::cDvdCriFsBinder*, const char*, int, int, int))(shared::base + 0x9EAFB0))(this, pFilePath, __formal, __unused, prio); }
	int bindCpkFileSync(const char *pFilePath, int prio) { return ((int(__thiscall *)(Hw::cDvdCriFsBinder*, const char*, int))(shared::base + 0x9EB0C0))(this, pFilePath, prio); }
	int bindCpkFileAsync(const char *pFilePath, int __formal, int __unused, int prio) { return ((int(__thiscall *)(Hw::cDvdCriFsBinder*, const char*, int, int, int))(shared::base + 0x9EB530))(this, pFilePath, __formal, __unused, prio); }
	int bindCpkFileAsync(const char *pFilePath, int prio) { return ((int(__thiscall *)(Hw::cDvdCriFsBinder*, const char*, int))(shared::base + 0x9EB5D0))(this, pFilePath, prio); }
};

class Hw::cDvdReadWork
{
public:
    cDvdReader m_Reader;

	int read(const char *pFilePath, void *pReadAddr, unsigned int Size, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__thiscall *)(Hw::cDvdReadWork*, const char*, void*, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EB2F0))(this, pFilePath, pReadAddr, Size, prio); }
	void cancel() { ((void(__thiscall *)(Hw::cDvdReadWork*))(shared::base + 0x9E9CE0))(this); }
	void close() { ((void(__thiscall *)(Hw::cDvdReadWork*))(shared::base + 0x9E9D60))(this); }
    void update() { ((void(__thiscall *)(Hw::cDvdReadWork*))(shared::base + 0x9EB7B0))(this); }
	void updateReader() { ((void(__thiscall *)(Hw::cDvdReadWork*))(shared::base + 0x9EA970))(this); }
};

class Hw::DvdEnv
{
public:

	static inline void DebugRegistReader(Hw::cDvdReader *pReader) { ((void(__cdecl *)(Hw::cDvdReader*))(shared::base + 0x9E8E90))(pReader); }
    static inline void DebugUnregistReader(Hw::cDvdReader *pReader) { ((void(__cdecl *)(Hw::cDvdReader*))(shared::base + 0x9E8EE0))(pReader); }
    static inline int DebugSetCurrentReader(Hw::cDvdReader *pReader) { return ((int(__cdecl *)(Hw::cDvdReader*))(shared::base + 0x9E8F70))(pReader); }
    static inline void DebugEndCurrentReader(Hw::cDvdReader *pReader) { ((void(__cdecl *)(Hw::cDvdReader*))(shared::base + 0x9E7C00))(pReader); }
};

class Hw::DvdSystem
{
public:

	static inline eDvdId ReadAllocSync(void **ppFileData, unsigned int &size, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((eDvdId(__cdecl *)(void**, unsigned int&, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EBD10))(ppFileData, size, pFilePath, rHeap, align, prio); }
	static inline eDvdId ReadAllocSync(void **ppFileData, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((eDvdId(__cdecl *)(void**, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EC3F0))(ppFileData, pFilePath, rHeap, align, prio); }
	static inline eDvdId ReadAsync(unsigned int& filesize, void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((eDvdId(__cdecl *)(unsigned int&, void*, unsigned int, const char*, Hw::DVD_PRIO))(shared::base + 0x9EBE10))(filesize, pReadAddr, Size, pFilePath, prio); }
	static inline eDvdId ReadAsync(void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((eDvdId(__cdecl *)(void*, unsigned int, const char*, Hw::DVD_PRIO))(shared::base + 0x9EC420))(pReadAddr, Size, pFilePath, prio); }
	static inline void ReadCancel(Hw::eDvdId dvdId) { ((void(__cdecl *)(Hw::eDvdId))(shared::base + 0x9EBF10))(dvdId); }
	static inline int IsReading(Hw::eDvdId dvdId) { return ((int(__cdecl *)(Hw::eDvdId))(shared::base + 0x9EBF70))(dvdId); }
	static inline void WaitReadEnd(Hw::eDvdId dvdId) { ((void(__cdecl *)(Hw::eDvdId))(shared::base + 0x9EBF20))(dvdId); }
	static inline int ReadAllocWait(void **ppFileData, unsigned int &size, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void**, unsigned int&, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EBF80))(ppFileData, size, pFilePath, rHeap, align, prio); }
	static inline int ReadAllocWait(void **ppFileData, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void**, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EC450))(ppFileData, pFilePath, rHeap, align, prio); }
	static inline int ReadWait(unsigned int& filesize, void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(unsigned int&, void*, unsigned int, const char*, Hw::DVD_PRIO))(shared::base + 0x9EBFC0))(filesize, pReadAddr, Size, pFilePath, prio); }
	static inline int ReadWait(void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void*, unsigned int, const char*, Hw::DVD_PRIO))(shared::base + 0x9EC490))(pReadAddr, Size, pFilePath, prio); }
	static inline int ReadAllocAsync(void **ppFileData, unsigned int &size, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void**, unsigned int&, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EC000))(ppFileData, size, pFilePath, rHeap, align, prio); }
	static inline int ReadAllocAsync(void **ppFileData, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void**, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EC4D0))(ppFileData, pFilePath, rHeap, align, prio); }
	static inline int ReadSync(unsigned int& filesize, void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(unsigned int&, void*, unsigned int, const char*, Hw::DVD_PRIO))(shared::base + 0x9EC1D0))(filesize, pReadAddr, Size, pFilePath, prio); }
	static inline int ReadSync(void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void*, unsigned int, const char*, Hw::DVD_PRIO))(shared::base + 0x9EC500))(pReadAddr, Size, pFilePath, prio); }
};

class Hw::DvdReadManager
{
public:

	static inline int Startup(size_t workNum, Hw::cHeap& rHeap) { return ((int(__cdecl *)(size_t, Hw::cHeap&))(shared::base + 0x9E9C80))(workNum, rHeap); }
	static inline int CanAlloc() { return ((int(__cdecl *)())(shared::base + 0x9E9E40))(); }
	static inline int Read(const char *pFilePath, void *pReadAddr, unsigned int Size, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(const char*, void*, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EB690))(pFilePath, pReadAddr, Size, prio); }
	static inline void Cancel(Hw::eDvdId dvdId) { ((void(__cdecl *)(Hw::eDvdId))(shared::base + 0x9EBC30))(dvdId); }
	static inline int IsAlive(Hw::eDvdId dvdId) { return ((int(__cdecl *)(Hw::eDvdId))(shared::base + 0x9EBC80))(dvdId); }
//  private:	

	static inline Hw::cDvdReadWork *FindWork(Hw::eDvdId dvdId) { return ((cDvdReadWork*(__cdecl *)(Hw::eDvdId))(shared::base + 0x9EB770))(dvdId); }
	static inline Hw::eDvdId CycleDvdId() { return ((eDvdId(__cdecl *)())(shared::base + 0x9E8670))(); }
//  public:
	// origin of m_NextDvdId from anonymous namespace

	static inline Hw::eDvdId& m_NextDvdId = *(Hw::eDvdId*)(shared::base + 0x19D0880);
};

class Dvd : public Hw::DvdSystem
{
public:

	// these fields down below are in anonymous namespace originally, but moved here to avoid linker errors

    static inline Hw::cFactoryFixed<Hw::cDvdReadWork, 4> &m_WorkFactory = *(Hw::cFactoryFixed<Hw::cDvdReadWork, 4>*)(shared::base + 0x19D45B8);
    static inline Hw::cDvdCriFsBinder *m_pBinderCpk = (Hw::cDvdCriFsBinder*)(shared::base + 0x19D45BC); // cDvdCriFsBinder[24];
    static inline Hw::cDvdReader *&m_pReaderFirst = *(Hw::cDvdReader**)(shared::base + 0x19D4128);
    static inline Hw::cDvdReader *&m_pReaderLast = *(Hw::cDvdReader**)(shared::base + 0x19D412C);
};

namespace Hw
{
	inline Hw::cDvdFst& g_DvdFileSizeTable = *(Hw::cDvdFst*)(shared::base + 0x19D4470);
}

VALIDATE_SIZE(Hw::cDvdReader, 0x74);