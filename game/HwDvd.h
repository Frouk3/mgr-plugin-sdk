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
	class cDvdFileFind;
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

	TYPE m_Type;
	CriFsBinderHn* m_BinderHandle;
	CriFsBindId m_BinderId;
	CriFsBinderStatus m_BindStatus;
	int m_Prio;

	int bindCpkFileAsync(const char *pFilePath, int __formal, int __unused, int prio) { return ((int(__thiscall *)(Hw::cDvdCriFsBinder*, const char*, int, int, int))(shared::base + 0x9EAFB0))(this, pFilePath, __formal, __unused, prio); }
	int bindCpkFileAsync(const char *pFilePath, int prio) { return ((int(__thiscall *)(Hw::cDvdCriFsBinder*, const char*, int))(shared::base + 0x9EB0C0))(this, pFilePath, prio); }
	int bindCpkFileSync(const char *pFilePath, int __formal, int __unused, int prio) { return ((int(__thiscall *)(Hw::cDvdCriFsBinder*, const char*, int, int, int))(shared::base + 0x9EB530))(this, pFilePath, __formal, __unused, prio); }
	int bindCpkFileSync(const char *pFilePath, int prio) { return ((int(__thiscall *)(Hw::cDvdCriFsBinder*, const char*, int))(shared::base + 0x9EB5D0))(this, pFilePath, prio); }
};

class Hw::cDvdFstBuffer
{
public:
	cDvdFstDir *m_pDirBuffer;
	unsigned int m_DirBufferSize;
	unsigned int m_DirBufferPos;
	cDvdFstFile *m_pFileBuffer;
	unsigned int m_FileBufferSize;
	unsigned int m_FileBufferPos;
	char *m_pNameBuffer;
	unsigned int m_NameBufferSize;
	unsigned int m_NameBufferPos;

	~cDvdFstBuffer() { ((void(__thiscall *)(Hw::cDvdFstBuffer*))(shared::base + 0x9E92D0))(this); }

	void cleanup() { ((void(__thiscall *)(Hw::cDvdFstBuffer*))(shared::base + 0x9E8100))(this); }
	int startup(Hw::cHeap& rHeap) { return ((int(__thiscall *)(Hw::cDvdFstBuffer*, Hw::cHeap&))(shared::base + 0x9E9330))(this, rHeap); }
	cDvdFstDir *createFstDir() { return ((cDvdFstDir*(__thiscall *)(Hw::cDvdFstBuffer*))(shared::base + 0x9E93D0))(this); }
	cDvdFstFile *createFstFile() { return ((cDvdFstFile*(__thiscall *)(Hw::cDvdFstBuffer*))(shared::base + 0x9E9400))(this); }
};

class Hw::cDvdFileFind
{
public:
	char m_pFindPath[260];
	_WIN32_FIND_DATAA m_FileFindData;
	void *m_Handle;
	int m_IsSucceed;

	cDvdFileFind() { ((void(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E7E30))(this); }
	~cDvdFileFind() { ((void(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E8FD0))(this); }

	int startup(const char *pFindPath) { return ((int(__thiscall *)(Hw::cDvdFileFind*, const char*))(shared::base + 0x9E7E50))(this, pFindPath); }
	int setNext() { return ((int(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E7F00))(this); }
	void cleanup() { ((void(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E7F40))(this); }
	// rewind to the first file
	int rewind() { return ((int(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E7F70))(this); }
	void getName(char *pOutName, unsigned int nameBufSize) { ((void(__thiscall *)(Hw::cDvdFileFind*, char*, unsigned int))(shared::base + 0x9E7FB0))(this, pOutName, nameBufSize); }
	const char *refName() { return ((const char*(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E7FE0))(this); }
	unsigned int getSize() { return ((unsigned int(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E8000))(this); }
	int isValid() { return ((int(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E8020))(this); }
	int isFile() { return ((int(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E8030))(this); }
	int isDirectory() { return ((int(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E8050))(this); }
	int isName(const char *pName) { return ((int(__thiscall *)(Hw::cDvdFileFind*, const char*))(shared::base + 0x9E8070))(this, pName); }
	int isSelf() { return ((int(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E9000))(this); }
	int isParent() { return ((int(__thiscall *)(Hw::cDvdFileFind*))(shared::base + 0x9E9030))(this); }
}; // class is complete here

class Hw::cDvdFstFile
{
public:
	char *m_pName;
	cDvdFstFile *m_pNextFile;
	unsigned int m_Size;

	cDvdFstFile() { ((void(__thiscall *)(Hw::cDvdFstFile*))(shared::base + 0x9E8480))(this); }
	~cDvdFstFile() { ((void(__thiscall *)(Hw::cDvdFstFile*))(shared::base + 0x9E8490))(this); } // empty implementation
	
	int setName(const char *pName, cDvdFstBuffer &buffer) { ((void(__thiscall *)(Hw::cDvdFstFile*, const char*, cDvdFstBuffer&))(shared::base + 0x9E84A0))(this, pName, buffer); }
	const char *getName() { return ((const char*(__thiscall *)(Hw::cDvdFstFile*))(shared::base + 0x9E8510))(this); }
	void setNextFile(cDvdFstFile *pNextFile) { ((void(__thiscall *)(Hw::cDvdFstFile*, cDvdFstFile*))(shared::base + 0x9E8520))(this, pNextFile); }
	cDvdFstFile *getNextFile() { return ((cDvdFstFile*(__thiscall *)(Hw::cDvdFstFile*))(shared::base + 0x9E8530))(this); }
	void setSize(unsigned int size) { ((void(__thiscall *)(Hw::cDvdFstFile*, unsigned int))(shared::base + 0x9E8540))(this, size); }
	unsigned int getSize() { return ((unsigned int(__thiscall *)(Hw::cDvdFstFile*))(shared::base + 0x9E8550))(this); }
}; // class is complete here

class Hw::cDvdFstDir
{
public:
	char *m_pName;
	cDvdFstDir *m_pNextDir;
	cDvdFstDir *m_pFirstDir;
	cDvdFstFile *m_pFirstFile;

	cDvdFstDir() { ((void(__thiscall *)(Hw::cDvdFstDir*))(shared::base + 0x9E8240))(this); }
	~cDvdFstDir() { ((void(__thiscall *)(Hw::cDvdFstDir*))(shared::base + 0x9E8250))(this); } // empty implementation

	int isPathMatch(const char *pCurrentPath, const char *pTargetPath, const char **ppDirExclude, int dirExcludeNum) { return ((int(__thiscall *)(Hw::cDvdFstDir*, const char*, const char*, const char**, int))(shared::base + 0x9E8260))(this, pCurrentPath, pTargetPath, ppDirExclude, dirExcludeNum); }
	int setName(const char *pName, cDvdFstBuffer &buffer) { return ((int(__thiscall *)(Hw::cDvdFstDir*, const char*, cDvdFstBuffer&))(shared::base + 0x9E8360))(this, pName, buffer); }
	const char *getName() { return ((const char*(__thiscall *)(Hw::cDvdFstDir*))(shared::base + 0x9E8430))(this); }
	void setNextDir(cDvdFstDir *pNextDir) { ((void(__thiscall *)(Hw::cDvdFstDir*, cDvdFstDir*))(shared::base + 0x9E8440))(this, pNextDir); }
	cDvdFstDir *getNextDir() { return ((cDvdFstDir*(__thiscall *)(Hw::cDvdFstDir*))(shared::base + 0x9E8450))(this); }
	cDvdFstDir *getFirstDir() { return ((cDvdFstDir*(__thiscall *)(Hw::cDvdFstDir*))(shared::base + 0x9E8460))(this); }
	cDvdFstFile *getFirstFile() { return ((cDvdFstFile*(__thiscall *)(Hw::cDvdFstDir*))(shared::base + 0x9E8470))(this); }
	int createFst(const char *pFilePath, cDvdFstBuffer &buffer, const char **ppDirExclude, int dirExcludeNum) { return ((int(__thiscall *)(Hw::cDvdFstDir*, const char*, cDvdFstBuffer&, const char**, int))(shared::base + 0x9E9430))(this, pFilePath, buffer, ppDirExclude, dirExcludeNum); }
	unsigned int getFileSize(const char *file) { return ((unsigned int(__thiscall *)(Hw::cDvdFstDir*, const char*))(shared::base + 0x9E9780))(this, file); }
	unsigned long long getDirSize() { return ((unsigned long long(__thiscall *)(Hw::cDvdFstDir*))(shared::base + 0x9E9810))(this); }
}; // class is complete here

class Hw::cDvdReadWork
{
public:
    cDvdReader m_Reader;
	char m_pFilePath[64];
	void* m_pData;
	int m_Size;
	eDvdId m_DvdId;
	int m_ErrCount;
	int m_Flag;
	DVD_PRIO m_Prio;

	int read(const char *pFilePath, void *pReadAddr, unsigned int Size, DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__thiscall *)(Hw::cDvdReadWork*, const char*, void*, unsigned int, DVD_PRIO))(shared::base + 0x9EB2F0))(this, pFilePath, pReadAddr, Size, prio); }
	void cancel() { ((void(__thiscall *)(Hw::cDvdReadWork*))(shared::base + 0x9E9CE0))(this); }
	void close() { ((void(__thiscall *)(Hw::cDvdReadWork*))(shared::base + 0x9E9D60))(this); }
    void update() { ((void(__thiscall *)(Hw::cDvdReadWork*))(shared::base + 0x9EB7B0))(this); }
	void updateReader() { ((void(__thiscall *)(Hw::cDvdReadWork*))(shared::base + 0x9EA970))(this); }
};

class Hw::cDvdFst
{
public:

	cDvdFst() { ((void(__thiscall *)(Hw::cDvdFst*))(shared::base + 0x9E9F90))(this); }
	~cDvdFst() { ((void(__thiscall *)(Hw::cDvdFst*))(shared::base + 0x9EA110))(this); }

	int startup(const char *pRootFilePath, const char *pPatchFilePath, Hw::cHeap &rHeap, const char **ppDirExclude, int dirExcludeNum) { return ((int(__thiscall *)(Hw::cDvdFst*, const char*, const char*, Hw::cHeap&, const char**, int))(shared::base + 0x9EAB30))(this, pRootFilePath, pPatchFilePath, rHeap, ppDirExclude, dirExcludeNum); }
};

class Hw::DvdEnv
{
public:

	static inline int Startup() { return ((int(__cdecl *)())(shared::base + 0x9E8E40))(); }
	static inline void DebugRegistReader(Hw::cDvdReader *pReader) { ((void(__cdecl *)(Hw::cDvdReader*))(shared::base + 0x9E8E90))(pReader); }
    static inline void DebugUnregistReader(Hw::cDvdReader *pReader) { ((void(__cdecl *)(Hw::cDvdReader*))(shared::base + 0x9E8EE0))(pReader); }
    static inline int DebugSetCurrentReader(Hw::cDvdReader *pReader) { return ((int(__cdecl *)(Hw::cDvdReader*))(shared::base + 0x9E8F70))(pReader); }
    static inline void DebugEndCurrentReader(Hw::cDvdReader *pReader) { ((void(__cdecl *)(Hw::cDvdReader*))(shared::base + 0x9E7C00))(pReader); }
};

class Hw::DvdSystem
{
public:

	static inline eDvdId ReadAllocAsync(void **ppFileData, unsigned int &size, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((eDvdId(__cdecl *)(void**, unsigned int&, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EBD10))(ppFileData, size, pFilePath, rHeap, align, prio); }
	static inline eDvdId ReadAllocAsync(void **ppFileData, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((eDvdId(__cdecl *)(void**, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EC3F0))(ppFileData, pFilePath, rHeap, align, prio); }
	static inline eDvdId ReadAsync(unsigned int& filesize, void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((eDvdId(__cdecl *)(unsigned int&, void*, unsigned int, const char*, Hw::DVD_PRIO))(shared::base + 0x9EBE10))(filesize, pReadAddr, Size, pFilePath, prio); }
	static inline eDvdId ReadAsync(void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((eDvdId(__cdecl *)(void*, unsigned int, const char*, Hw::DVD_PRIO))(shared::base + 0x9EC420))(pReadAddr, Size, pFilePath, prio); }
	static inline void ReadCancel(Hw::eDvdId dvdId) { ((void(__cdecl *)(Hw::eDvdId))(shared::base + 0x9EBF10))(dvdId); }
	static inline int IsReading(Hw::eDvdId dvdId) { return ((int(__cdecl *)(Hw::eDvdId))(shared::base + 0x9EBF70))(dvdId); }
	static inline void WaitReadEnd(Hw::eDvdId dvdId) { ((void(__cdecl *)(Hw::eDvdId))(shared::base + 0x9EBF20))(dvdId); }
	static inline int ReadAllocWait(void **ppFileData, unsigned int &size, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void**, unsigned int&, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EBF80))(ppFileData, size, pFilePath, rHeap, align, prio); }
	static inline int ReadAllocWait(void **ppFileData, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void**, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EC450))(ppFileData, pFilePath, rHeap, align, prio); }
	static inline int ReadWait(unsigned int& filesize, void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(unsigned int&, void*, unsigned int, const char*, Hw::DVD_PRIO))(shared::base + 0x9EBFC0))(filesize, pReadAddr, Size, pFilePath, prio); }
	static inline int ReadWait(void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void*, unsigned int, const char*, Hw::DVD_PRIO))(shared::base + 0x9EC490))(pReadAddr, Size, pFilePath, prio); }
	static inline int ReadAllocSync(void **ppFileData, unsigned int &size, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void**, unsigned int&, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EC000))(ppFileData, size, pFilePath, rHeap, align, prio); }
	static inline int ReadAllocSync(void **ppFileData, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ((int(__cdecl *)(void**, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO))(shared::base + 0x9EC4D0))(ppFileData, pFilePath, rHeap, align, prio); }
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