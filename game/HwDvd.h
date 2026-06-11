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

	cDvdReader() { MAKE_CALL(shared::base + 0x9E85E0, void(__thiscall *)(Hw::cDvdReader *), this); }
	~cDvdReader() { MAKE_CALL(shared::base + 0x9EA7B0, void(__thiscall *)(Hw::cDvdReader *), this); }

	int read(const char *pFilePath, void *pReadAddr, unsigned int Size, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EB160, int(__thiscall *)(Hw::cDvdReader *, const char *, void *, unsigned int, Hw::DVD_PRIO), this, pFilePath, pReadAddr, Size, prio); }
	void cancel() { MAKE_CALL(shared::base + 0x9E9860, void(__thiscall *)(Hw::cDvdReader *), this); }
	void close() { MAKE_CALL(shared::base + 0x9E98B0, void(__thiscall *)(Hw::cDvdReader *), this); }
	void update() { MAKE_CALL(shared::base + 0x9EA800, void(__thiscall *)(Hw::cDvdReader *), this); }
	void updateSync() { MAKE_CALL(shared::base + 0x9EA8B0, void(__thiscall *)(Hw::cDvdReader *), this); }
	int isError() { return MAKE_CALL(shared::base + 0x9E8600, int(__thiscall *)(Hw::cDvdReader *), this); }
	int canClose() { return MAKE_CALL(shared::base + 0x9E8610, int(__thiscall *)(Hw::cDvdReader *), this); }
	DVD_PRIO getPrio() { return MAKE_CALL(shared::base + 0x9E8650, DVD_PRIO(__thiscall *)(Hw::cDvdReader *), this); }
//	private:

    int updateOpened() { return MAKE_CALL(shared::base + 0x9E9900, int(__thiscall *)(Hw::cDvdReader *), this); }
    int updateReading() { return MAKE_CALL(shared::base + 0x9E9A50, int(__thiscall *)(Hw::cDvdReader *), this); }
    int updateCanceling() { return MAKE_CALL(shared::base + 0x9E9B30, int(__thiscall *)(Hw::cDvdReader *), this); }
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

	int bindCpkFileAsync(const char *pFilePath, int __formal, int __unused, int prio) { return MAKE_CALL(shared::base + 0x9EAFB0, int(__thiscall *)(Hw::cDvdCriFsBinder *, const char *, int, int, int), this, pFilePath, __formal, __unused, prio); }
	int bindCpkFileAsync(const char *pFilePath, int prio) { return MAKE_CALL(shared::base + 0x9EB0C0, int(__thiscall *)(Hw::cDvdCriFsBinder *, const char *, int), this, pFilePath, prio); }
	int bindCpkFileSync(const char *pFilePath, int __formal, int __unused, int prio) { return MAKE_CALL(shared::base + 0x9EB530, int(__thiscall *)(Hw::cDvdCriFsBinder *, const char *, int, int, int), this, pFilePath, __formal, __unused, prio); }
	int bindCpkFileSync(const char *pFilePath, int prio) { return MAKE_CALL(shared::base + 0x9EB5D0, int(__thiscall *)(Hw::cDvdCriFsBinder *, const char *, int), this, pFilePath, prio); }
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

	~cDvdFstBuffer() { MAKE_CALL(shared::base + 0x9E92D0, void(__thiscall *)(Hw::cDvdFstBuffer *), this); }

	void cleanup() { MAKE_CALL(shared::base + 0x9E8100, void(__thiscall *)(Hw::cDvdFstBuffer *), this); }
	int startup(Hw::cHeap& rHeap) { return MAKE_CALL(shared::base + 0x9E9330, int(__thiscall *)(Hw::cDvdFstBuffer *, Hw::cHeap &), this, rHeap); }
	cDvdFstDir *createFstDir() { return MAKE_CALL(shared::base + 0x9E93D0, cDvdFstDir*(__thiscall *)(Hw::cDvdFstBuffer *), this); }
	cDvdFstFile *createFstFile() { return MAKE_CALL(shared::base + 0x9E9400, cDvdFstFile*(__thiscall *)(Hw::cDvdFstBuffer *), this); }
};

class Hw::cDvdFileFind
{
public:
	char m_pFindPath[260];
	_WIN32_FIND_DATAA m_FileFindData;
	void *m_Handle;
	int m_IsSucceed;

	cDvdFileFind() { MAKE_CALL(shared::base + 0x9E7E30, void(__thiscall *)(Hw::cDvdFileFind *), this); }
	~cDvdFileFind() { MAKE_CALL(shared::base + 0x9E8FD0, void(__thiscall *)(Hw::cDvdFileFind *), this); }

	int startup(const char *pFindPath) { return MAKE_CALL(shared::base + 0x9E7E50, int(__thiscall *)(Hw::cDvdFileFind *, const char *), this, pFindPath); }
	int setNext() { return MAKE_CALL(shared::base + 0x9E7F00, int(__thiscall *)(Hw::cDvdFileFind *), this); }
	void cleanup() { MAKE_CALL(shared::base + 0x9E7F40, void(__thiscall *)(Hw::cDvdFileFind *), this); }
	// rewind to the first file
	int rewind() { return MAKE_CALL(shared::base + 0x9E7F70, int(__thiscall *)(Hw::cDvdFileFind *), this); }
	void getName(char *pOutName, unsigned int nameBufSize) { MAKE_CALL(shared::base + 0x9E7FB0, void(__thiscall *)(Hw::cDvdFileFind *, char *, unsigned int), this, pOutName, nameBufSize); }
	const char *refName() { return MAKE_CALL(shared::base + 0x9E7FE0, const char*(__thiscall *)(Hw::cDvdFileFind *), this); }
	unsigned int getSize() { return MAKE_CALL(shared::base + 0x9E8000, unsigned int(__thiscall *)(Hw::cDvdFileFind *), this); }
	int isValid() { return MAKE_CALL(shared::base + 0x9E8020, int(__thiscall *)(Hw::cDvdFileFind *), this); }
	int isFile() { return MAKE_CALL(shared::base + 0x9E8030, int(__thiscall *)(Hw::cDvdFileFind *), this); }
	int isDirectory() { return MAKE_CALL(shared::base + 0x9E8050, int(__thiscall *)(Hw::cDvdFileFind *), this); }
	int isName(const char *pName) { return MAKE_CALL(shared::base + 0x9E8070, int(__thiscall *)(Hw::cDvdFileFind *, const char *), this, pName); }
	int isSelf() { return MAKE_CALL(shared::base + 0x9E9000, int(__thiscall *)(Hw::cDvdFileFind *), this); }
	int isParent() { return MAKE_CALL(shared::base + 0x9E9030, int(__thiscall *)(Hw::cDvdFileFind *), this); }
}; // class is complete here

class Hw::cDvdFstFile
{
public:
	char *m_pName;
	cDvdFstFile *m_pNextFile;
	unsigned int m_Size;

	cDvdFstFile() { MAKE_CALL(shared::base + 0x9E8480, void(__thiscall *)(Hw::cDvdFstFile *), this); }
	~cDvdFstFile() { MAKE_CALL(shared::base + 0x9E8490, void(__thiscall *)(Hw::cDvdFstFile *), this); } // empty implementation
	
	int setName(const char *pName, cDvdFstBuffer &buffer) { MAKE_CALL(shared::base + 0x9E84A0, int(__thiscall *)(Hw::cDvdFstFile *, const char *, cDvdFstBuffer &), this, pName, buffer); }
	const char *getName() { return MAKE_CALL(shared::base + 0x9E8510, const char*(__thiscall *)(Hw::cDvdFstFile *), this); }
	void setNextFile(cDvdFstFile *pNextFile) { MAKE_CALL(shared::base + 0x9E8520, void(__thiscall *)(Hw::cDvdFstFile *, cDvdFstFile *), this, pNextFile); }
	cDvdFstFile *getNextFile() { return MAKE_CALL(shared::base + 0x9E8530, cDvdFstFile*(__thiscall *)(Hw::cDvdFstFile *), this); }
	void setSize(unsigned int size) { MAKE_CALL(shared::base + 0x9E8540, void(__thiscall *)(Hw::cDvdFstFile *, unsigned int), this, size); }
	unsigned int getSize() { return MAKE_CALL(shared::base + 0x9E8550, unsigned int(__thiscall *)(Hw::cDvdFstFile *), this); }
}; // class is complete here

class Hw::cDvdFstDir
{
public:
	char *m_pName;
	cDvdFstDir *m_pNextDir;
	cDvdFstDir *m_pFirstDir;
	cDvdFstFile *m_pFirstFile;

	cDvdFstDir() { MAKE_CALL(shared::base + 0x9E8240, void(__thiscall *)(Hw::cDvdFstDir *), this); }
	~cDvdFstDir() { MAKE_CALL(shared::base + 0x9E8250, void(__thiscall *)(Hw::cDvdFstDir *), this); } // empty implementation

	int isPathMatch(const char *pCurrentPath, const char *pTargetPath, const char **ppDirExclude, int dirExcludeNum) { return MAKE_CALL(shared::base + 0x9E8260, int(__thiscall *)(Hw::cDvdFstDir *, const char *, const char *, const char **, int), this, pCurrentPath, pTargetPath, ppDirExclude, dirExcludeNum); }
	int setName(const char *pName, cDvdFstBuffer &buffer) { return MAKE_CALL(shared::base + 0x9E8360, int(__thiscall *)(Hw::cDvdFstDir *, const char *, cDvdFstBuffer &), this, pName, buffer); }
	const char *getName() { return MAKE_CALL(shared::base + 0x9E8430, const char*(__thiscall *)(Hw::cDvdFstDir *), this); }
	void setNextDir(cDvdFstDir *pNextDir) { MAKE_CALL(shared::base + 0x9E8440, void(__thiscall *)(Hw::cDvdFstDir *, cDvdFstDir *), this, pNextDir); }
	cDvdFstDir *getNextDir() { return MAKE_CALL(shared::base + 0x9E8450, cDvdFstDir*(__thiscall *)(Hw::cDvdFstDir *), this); }
	cDvdFstDir *getFirstDir() { return MAKE_CALL(shared::base + 0x9E8460, cDvdFstDir*(__thiscall *)(Hw::cDvdFstDir *), this); }
	cDvdFstFile *getFirstFile() { return MAKE_CALL(shared::base + 0x9E8470, cDvdFstFile*(__thiscall *)(Hw::cDvdFstDir *), this); }
	int createFst(const char *pFilePath, cDvdFstBuffer &buffer, const char **ppDirExclude, int dirExcludeNum) { return MAKE_CALL(shared::base + 0x9E9430, int(__thiscall *)(Hw::cDvdFstDir *, const char *, cDvdFstBuffer &, const char **, int), this, pFilePath, buffer, ppDirExclude, dirExcludeNum); }
	unsigned int getFileSize(const char *file) { return MAKE_CALL(shared::base + 0x9E9780, unsigned int(__thiscall *)(Hw::cDvdFstDir *, const char *), this, file); }
	unsigned long long getDirSize() { return MAKE_CALL(shared::base + 0x9E9810, unsigned long long(__thiscall *)(Hw::cDvdFstDir *), this); }		
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

	int read(const char *pFilePath, void *pReadAddr, unsigned int Size, DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EB2F0, int(__thiscall *)(Hw::cDvdReadWork *, const char *, void *, unsigned int, DVD_PRIO), this, pFilePath, pReadAddr, Size, prio); }
	void cancel() { MAKE_CALL(shared::base + 0x9E9CE0, void(__thiscall *)(Hw::cDvdReadWork *), this); }
	void close() { MAKE_CALL(shared::base + 0x9E9D60, void(__thiscall *)(Hw::cDvdReadWork *), this); }
    void update() { MAKE_CALL(shared::base + 0x9EB7B0, void(__thiscall *)(Hw::cDvdReadWork *), this); }
	void updateReader() { MAKE_CALL(shared::base + 0x9EA970, void(__thiscall *)(Hw::cDvdReadWork *), this); }
};

class Hw::cDvdFst
{
public:

	cDvdFst() { MAKE_CALL(shared::base + 0x9E9F90, void(__thiscall *)(Hw::cDvdFst *), this); }
	~cDvdFst() { MAKE_CALL(shared::base + 0x9EA110, void(__thiscall *)(Hw::cDvdFst *), this); }

	int startup(const char *pRootFilePath, const char *pPatchFilePath, Hw::cHeap &rHeap, const char **ppDirExclude, int dirExcludeNum) { return MAKE_CALL(shared::base + 0x9EAB30, int(__thiscall *)(Hw::cDvdFst *, const char *, const char *, Hw::cHeap &, const char **, int), this, pRootFilePath, pPatchFilePath, rHeap, ppDirExclude, dirExcludeNum); }
};

class Hw::DvdEnv
{
public:

	static inline int Startup() { return MAKE_CALL(shared::base + 0x9E8E40, int(__cdecl *)()); }
	static inline void DebugRegistReader(Hw::cDvdReader *pReader) { MAKE_CALL(shared::base + 0x9E8E90, void(__cdecl *)(Hw::cDvdReader *), pReader); }
    static inline void DebugUnregistReader(Hw::cDvdReader *pReader) { MAKE_CALL(shared::base + 0x9E8EE0, void(__cdecl *)(Hw::cDvdReader *), pReader); }
    static inline int DebugSetCurrentReader(Hw::cDvdReader *pReader) { return MAKE_CALL(shared::base + 0x9E8F70, int(__cdecl *)(Hw::cDvdReader *), pReader); }
    static inline void DebugEndCurrentReader(Hw::cDvdReader *pReader) { MAKE_CALL(shared::base + 0x9E7C00, void(__cdecl *)(Hw::cDvdReader *), pReader); }
};

class Hw::DvdSystem
{
public:

	static inline eDvdId ReadAllocAsync(void **ppFileData, unsigned int &size, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EBD10, eDvdId(__cdecl *)(void**, unsigned int&, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO), ppFileData, size, pFilePath, rHeap, align, prio); }
	static inline eDvdId ReadAllocAsync(void **ppFileData, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EC3F0, eDvdId(__cdecl *)(void**, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO), ppFileData, pFilePath, rHeap, align, prio); }
	static inline eDvdId ReadAsync(unsigned int& filesize, void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EBE10, eDvdId(__cdecl *)(unsigned int&, void*, unsigned int, const char*, Hw::DVD_PRIO), filesize, pReadAddr, Size, pFilePath, prio); }
	static inline eDvdId ReadAsync(void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EC420, eDvdId(__cdecl *)(void*, unsigned int, const char*, Hw::DVD_PRIO), pReadAddr, Size, pFilePath, prio); }
	static inline void ReadCancel(Hw::eDvdId dvdId) { MAKE_CALL(shared::base + 0x9EBF10, void(__cdecl *)(Hw::eDvdId), dvdId); }
	static inline int IsReading(Hw::eDvdId dvdId) { return MAKE_CALL(shared::base + 0x9EBF70, int(__cdecl *)(Hw::eDvdId), dvdId); }
	static inline void WaitReadEnd(Hw::eDvdId dvdId) { MAKE_CALL(shared::base + 0x9EBF20, void(__cdecl *)(Hw::eDvdId), dvdId); }
	static inline int ReadAllocWait(void **ppFileData, unsigned int &size, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EBF80, int(__cdecl *)(void**, unsigned int&, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO), ppFileData, size, pFilePath, rHeap, align, prio); }
	static inline int ReadAllocWait(void **ppFileData, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EC450, int(__cdecl *)(void**, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO), ppFileData, pFilePath, rHeap, align, prio); }
	static inline int ReadWait(unsigned int& filesize, void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EBFC0, int(__cdecl *)(unsigned int&, void*, unsigned int, const char*, Hw::DVD_PRIO), filesize, pReadAddr, Size, pFilePath, prio); }
	static inline int ReadWait(void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EC490, int(__cdecl *)(void*, unsigned int, const char*, Hw::DVD_PRIO), pReadAddr, Size, pFilePath, prio); }
	static inline int ReadAllocSync(void **ppFileData, unsigned int &size, const char *pFilePath, Hw::cHeap& rHeap, unsigned int align, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EC000, int(__cdecl *)(void**, unsigned int&, const char*, Hw::cHeap&, unsigned int, Hw::DVD_PRIO), ppFileData, size, pFilePath, rHeap, align, prio); }
	static inline int ReadSync(void *pReadAddr, unsigned int Size, const char *pFilePath, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EC500, int(__cdecl *)(void*, unsigned int, const char*, Hw::DVD_PRIO), pReadAddr, Size, pFilePath, prio); }
};

class Hw::DvdReadManager
{
public:

	static inline int Startup(size_t workNum, Hw::cHeap& rHeap) { return MAKE_CALL(shared::base + 0x9E9C80, int(__cdecl *)(size_t, Hw::cHeap&), workNum, rHeap); }
	static inline int CanAlloc() { return MAKE_CALL(shared::base + 0x9E9E40, int(__cdecl *)(), ); }
	static inline int Read(const char *pFilePath, void *pReadAddr, unsigned int Size, Hw::DVD_PRIO prio = DVD_PRIO_DEFAULT) { return MAKE_CALL(shared::base + 0x9EB690, int(__cdecl *)(const char*, void*, unsigned int, Hw::DVD_PRIO), pFilePath, pReadAddr, Size, prio); }
	static inline void Cancel(Hw::eDvdId dvdId) { MAKE_CALL(shared::base + 0x9EBC30, void(__cdecl *)(Hw::eDvdId), dvdId); }
	static inline int IsAlive(Hw::eDvdId dvdId) { return MAKE_CALL(shared::base + 0x9EBC80, int(__cdecl *)(Hw::eDvdId), dvdId); }
//  private:	

	static inline Hw::cDvdReadWork *FindWork(Hw::eDvdId dvdId) { return MAKE_CALL(shared::base + 0x9EB770, cDvdReadWork*(__cdecl *)(Hw::eDvdId), dvdId); }
	static inline Hw::eDvdId CycleDvdId() { return MAKE_CALL(shared::base + 0x9E8670, Hw::eDvdId(__cdecl *)(), ); }
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