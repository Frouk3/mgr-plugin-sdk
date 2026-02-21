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

	cDvdReader() { CallMethod<0x9E85E0, Hw::cDvdReader *>(this); }
	~cDvdReader() { CallMethod<0x9EA7B0, Hw::cDvdReader *>(this); }

	int read(const char *pFilePath, void *pReadAddr, unsigned int Size, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ReturnCallMethod<int, 0x9EB160, Hw::cDvdReader *, const char *, void *, unsigned int, Hw::DVD_PRIO>(this, pFilePath, pReadAddr, Size, prio); }
	void cancel() { CallMethod<0x9E9860, Hw::cDvdReader *>(this); }
	void close() { CallMethod<0x9E98B0, Hw::cDvdReader *>(this); }
	void update() { CallMethod<0x9EA800, Hw::cDvdReader *>(this); }
	void updateSync() { CallMethod<0x9EA8B0, Hw::cDvdReader *>(this); }
	int isError() { return ReturnCallMethod<int, 0x9E8600, Hw::cDvdReader *>(this); }
	int canClose() { return ReturnCallMethod<int, 0x9E8610, Hw::cDvdReader *>(this); }
	DVD_PRIO getPrio() { return ReturnCallMethod<DVD_PRIO, 0x9E8650, Hw::cDvdReader *>(this); }
//	private:

    int updateOpened() { return ReturnCallMethod<int, 0x9E9900, Hw::cDvdReader *>(this); }
    int updateReading() { return ReturnCallMethod<int, 0x9E9A50, Hw::cDvdReader *>(this); }
    int updateCanceling() { return ReturnCallMethod<int, 0x9E9B30, Hw::cDvdReader *>(this); }
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

	int bindCpkFileAsync(const char *pFilePath, int __formal, int __unused, int prio) { return ReturnCallMethod<int, 0x9EAFB0, Hw::cDvdCriFsBinder *, const char *, int, int, int>(this, pFilePath, __formal, __unused, prio); }
	int bindCpkFileAsync(const char *pFilePath, int prio) { return ReturnCallMethod<int, 0x9EB0C0, Hw::cDvdCriFsBinder *, const char *, int>(this, pFilePath, prio); }
	int bindCpkFileSync(const char *pFilePath, int __formal, int __unused, int prio) { return ReturnCallMethod<int, 0x9EB530, Hw::cDvdCriFsBinder *, const char *, int, int, int>(this, pFilePath, __formal, __unused, prio); }
	int bindCpkFileSync(const char *pFilePath, int prio) { return ReturnCallMethod<int, 0x9EB5D0, Hw::cDvdCriFsBinder *, const char *, int>(this, pFilePath, prio); }
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

	~cDvdFstBuffer() { ReturnCallMethod<void, 0x9E92D0, Hw::cDvdFstBuffer *>(this); }

	void cleanup() { CallMethod<0x9E8100, Hw::cDvdFstBuffer *>(this); }
	int startup(Hw::cHeap& rHeap) { return ReturnCallMethod<int, 0x9E9330, Hw::cDvdFstBuffer *, Hw::cHeap &>(this, rHeap); }
	cDvdFstDir *createFstDir() { return ReturnCallMethod<cDvdFstDir*, 0x9E93D0, Hw::cDvdFstBuffer *>(this); }
	cDvdFstFile *createFstFile() { return ReturnCallMethod<cDvdFstFile*, 0x9E9400, Hw::cDvdFstBuffer *>(this); }
};

class Hw::cDvdFileFind
{
public:
	char m_pFindPath[260];
	_WIN32_FIND_DATAA m_FileFindData;
	void *m_Handle;
	int m_IsSucceed;

	cDvdFileFind() { ReturnCallMethod<void, 0x9E7E30, Hw::cDvdFileFind *>(this); }
	~cDvdFileFind() { ReturnCallMethod<void, 0x9E8FD0, Hw::cDvdFileFind *>(this); }

	int startup(const char *pFindPath) { return ReturnCallMethod<int, 0x9E7E50, Hw::cDvdFileFind *, const char *>(this, pFindPath); }
	int setNext() { return ReturnCallMethod<int, 0x9E7F00, Hw::cDvdFileFind *>(this); }
	void cleanup() { CallMethod<0x9E7F40, Hw::cDvdFileFind *>(this); }
	// rewind to the first file
	int rewind() { return ReturnCallMethod<int, 0x9E7F70, Hw::cDvdFileFind *>(this); }
	void getName(char *pOutName, unsigned int nameBufSize) { CallMethod<0x9E7FB0, Hw::cDvdFileFind *, char *, unsigned int>(this, pOutName, nameBufSize); }
	const char *refName() { return ReturnCallMethod<const char *, 0x9E7FE0, Hw::cDvdFileFind *>(this); }
	unsigned int getSize() { return ReturnCallMethod<unsigned int, 0x9E8000, Hw::cDvdFileFind *>(this); }
	int isValid() { return ReturnCallMethod<int, 0x9E8020, Hw::cDvdFileFind *>(this); }
	int isFile() { return ReturnCallMethod<int, 0x9E8030, Hw::cDvdFileFind *>(this); }
	int isDirectory() { return ReturnCallMethod<int, 0x9E8050, Hw::cDvdFileFind *>(this); }
	int isName(const char *pName) { return ReturnCallMethod<int, 0x9E8070, Hw::cDvdFileFind *, const char *>(this, pName); }
	int isSelf() { return ReturnCallMethod<int, 0x9E9000, Hw::cDvdFileFind *>(this); }
	int isParent() { return ReturnCallMethod<int, 0x9E9030, Hw::cDvdFileFind *>(this); }
}; // class is complete here

class Hw::cDvdFstFile
{
public:
	char *m_pName;
	cDvdFstFile *m_pNextFile;
	unsigned int m_Size;

	cDvdFstFile() { ReturnCallMethod<void, 0x9E8480, Hw::cDvdFstFile *>(this); }
	~cDvdFstFile() { ReturnCallMethod<void, 0x9E8490, Hw::cDvdFstFile *>(this); } // empty implementation
	
	int setName(const char *pName, cDvdFstBuffer &buffer) { ReturnCallMethod<int, 0x9E84A0, Hw::cDvdFstFile *, const char *, cDvdFstBuffer &>(this, pName, buffer); }
	const char *getName() { return ReturnCallMethod<const char *, 0x9E8510, Hw::cDvdFstFile *>(this); }
	void setNextFile(cDvdFstFile *pNextFile) { CallMethod<0x9E8520, Hw::cDvdFstFile *, cDvdFstFile *>(this, pNextFile); }
	cDvdFstFile *getNextFile() { return ReturnCallMethod<cDvdFstFile*, 0x9E8530, Hw::cDvdFstFile *>(this); }
	void setSize(unsigned int size) { CallMethod<0x9E8540, Hw::cDvdFstFile *, unsigned int>(this, size); }
	unsigned int getSize() { return ReturnCallMethod<unsigned int, 0x9E8550, Hw::cDvdFstFile *>(this); }
}; // class is complete here

class Hw::cDvdFstDir
{
public:
	char *m_pName;
	cDvdFstDir *m_pNextDir;
	cDvdFstDir *m_pFirstDir;
	cDvdFstFile *m_pFirstFile;

	cDvdFstDir() { ReturnCallMethod<void, 0x9E8240, Hw::cDvdFstDir *>(this); }
	~cDvdFstDir() { ReturnCallMethod<void, 0x9E8250, Hw::cDvdFstDir *>(this); } // empty implementation

	int isPathMatch(const char *pCurrentPath, const char *pTargetPath, const char **ppDirExclude, int dirExcludeNum) { return ReturnCallMethod<int, 0x9E8260, Hw::cDvdFstDir *, const char *, const char *, const char **, int>(this, pCurrentPath, pTargetPath, ppDirExclude, dirExcludeNum); }
	int setName(const char *pName, cDvdFstBuffer &buffer) { return ReturnCallMethod<int, 0x9E8360, Hw::cDvdFstDir *, const char *, cDvdFstBuffer &>(this, pName, buffer); }
	const char *getName() { return ReturnCallMethod<const char *, 0x9E8430, Hw::cDvdFstDir *>(this); }
	void setNextDir(cDvdFstDir *pNextDir) { CallMethod<0x9E8440, Hw::cDvdFstDir *, cDvdFstDir *>(this, pNextDir); }
	cDvdFstDir *getNextDir() { return ReturnCallMethod<cDvdFstDir*, 0x9E8450, Hw::cDvdFstDir *>(this); }
	cDvdFstDir *getFirstDir() { return ReturnCallMethod<cDvdFstDir*, 0x9E8460, Hw::cDvdFstDir *>(this); }
	cDvdFstFile *getFirstFile() { return ReturnCallMethod<cDvdFstFile*, 0x9E8470, Hw::cDvdFstDir *>(this); }
	int createFst(const char *pFilePath, cDvdFstBuffer &buffer, const char **ppDirExclude, int dirExcludeNum) { return ReturnCallMethod<int, 0x9E9430, Hw::cDvdFstDir *, const char *, cDvdFstBuffer &, const char **, int>(this, pFilePath, buffer, ppDirExclude, dirExcludeNum); }
	unsigned int getFileSize(const char *file) { return ReturnCallMethod<unsigned int, 0x9E9780, Hw::cDvdFstDir *, const char *>(this, file); }
	unsigned long long getDirSize() { return ReturnCallMethod<unsigned long long, 0x9E9810, Hw::cDvdFstDir *>(this); }		
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

	int read(const char *pFilePath, void *pReadAddr, unsigned int Size, DVD_PRIO prio = DVD_PRIO_DEFAULT) { return ReturnCallMethod<int, 0x9EB2F0, Hw::cDvdReadWork *, const char *, void *, unsigned int, DVD_PRIO>(this, pFilePath, pReadAddr, Size, prio); }
	void cancel() { CallMethod<0x9E9CE0, Hw::cDvdReadWork *>(this); }
	void close() { CallMethod<0x9E9D60, Hw::cDvdReadWork *>(this); }
    void update() { CallMethod<0x9EB7B0, Hw::cDvdReadWork *>(this); }
	void updateReader() { CallMethod<0x9EA970, Hw::cDvdReadWork *>(this); }
};

class Hw::cDvdFst
{
public:

	cDvdFst() { CallMethod<0x9E9F90, Hw::cDvdFst *>(this); }
	~cDvdFst() { CallMethod<0x9EA110, Hw::cDvdFst *>(this); }

	int startup(const char *pRootFilePath, const char *pPatchFilePath, Hw::cHeap &rHeap, const char **ppDirExclude, int dirExcludeNum) { return ReturnCallMethod<int, 0x9EAB30, Hw::cDvdFst *, const char *, const char *, Hw::cHeap &, const char **, int>(this, pRootFilePath, pPatchFilePath, rHeap, ppDirExclude, dirExcludeNum); }
};

class Hw::DvdEnv
{
public:

	static inline int Startup() { return ReturnCdeclCall<int, 0x9E8E40>(); }
	static inline void DebugRegistReader(Hw::cDvdReader *pReader) { CdeclCall<0x9E8E90, Hw::cDvdReader *>(pReader); }
    static inline void DebugUnregistReader(Hw::cDvdReader *pReader) { CdeclCall<0x9E8EE0, Hw::cDvdReader *>(pReader); }
    static inline int DebugSetCurrentReader(Hw::cDvdReader *pReader) { return ReturnCdeclCall<int, 0x9E8F70, Hw::cDvdReader *>(pReader); }
    static inline void DebugEndCurrentReader(Hw::cDvdReader *pReader) { CdeclCall<0x9E7C00, Hw::cDvdReader *>(pReader); }
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