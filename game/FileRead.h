#pragma once

#include <Hw.h>

namespace FileRead
{
    class Listener
    {
    public:

        virtual ~Listener() {};
    };

    class Work
    {
    public:
        int field_0; // also reader id
        int field_4;
        char m_Filename[32];
        int m_nWorkerID;
        int field_2C;
        void *m_Filedata;
        int m_nFilesize;
        Hw::cHeapPhysical *m_Allocator;
        int m_FileFlags;
        int m_nRequests;
        int m_nUsageCount;
        int field_48;
        enum WorkState
        {
            FILEWORK_REQUEST = 1,
            FILEWORK_READ_REQUEST,
            FILEWORK_READING,
            FILEWORK_REMOVE_READER,
            FILEWORK_RESTART,
            FILEWORK_FINISHED,
            FILEWORK_NOT_FOUND,
            FILEWORK_REQUEST_CLEANUP,
            FILEWORK_VERIFY_FILESTATE
        } m_WorkerState;
        int m_nWaitAmount;
        int field_54;
        FileRead::Listener *m_Listener;

        void removeRequest()
        {
            ((void(__thiscall *)(Work *))(shared::base + 0xA9CA30))(this);
        }

        void registerUsage()
        {
            ((void(__thiscall *)(Work *))(shared::base + 0xA9CB10))(this);
        }

        void unregisterUsage()
        {
            ((void(__thiscall *)(Work *))(shared::base + 0xA9CB60))(this);
        }

        void registerFile()
        {
            ((void(__thiscall *)(Work *))(shared::base + 0xA9CBC0))(this);
        }

        void unregisterFile()
        {
            ((void(__thiscall *)(Work *))(shared::base + 0xA9CC50))(this);
        }

        BOOL processReading()
        {
            ((void(__thiscall *)(Work *))(shared::base + 0xA9D1E0))(this);
        }

        BOOL cleanup()
        {
            return ((BOOL(__thiscall *)(Work *))(shared::base + 0xA9D9A0))(this);
        }

        BOOL prepare()
        {
            return ((BOOL(__thiscall *)(Work *))(shared::base + 0xA9E0A0))(this);
        }

        BOOL requestLoader()
        {
            return ((BOOL(__thiscall *)(Work *))(shared::base + 0xA9E170))(this);
        }

        BOOL manageFilestate()
        {
            return ((BOOL(__thiscall *)(Work *))(shared::base + 0xA9E260))(this);
        }

        void tick()
        {
            ((void(__thiscall *)(Work *))(shared::base + 0xA9E630))(this);
        }
    };

    class Manager
    {
    public:
        int field_0;
        int field_4;
        Hw::cHeapFixed m_FileReadFactory;
        Hw::cFixedVector<Work*> m_FileReaderVector;
        int field_7C;
        int field_80;
        int field_84;
        int field_88;
        int field_8C;
        int field_90;
        int field_94;
        int field_98;
        int field_9C;

        Work *getWorkByFilename(const char *filename)
        {
            return ((Work *(__thiscall *)(Manager *, const char *))(shared::base + 0xA9C8F0))(this, filename);
        }

        Work *getWorkByID(int id)
        {
            return ((Work*(__thiscall *)(Manager *, int))(shared::base + 0xA9C940))(this, id);
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

        Work *requestWork(int a2, const char *filename, Hw::cHeap *allocator, char a5, Listener *listener)
        {
            return ((Work*(__thiscall *)(Manager*, int, const char *, Hw::cHeap *, char, Listener *))(shared::base + 0xA9DF40))(this, a2, filename, allocator, a5, listener);
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

        Work *allocateWorker()
        {
            return ((Work*(__thiscall *)(Manager *))(shared::base + 0xA9F7A0))(this);
        }
    };

    static inline Manager& FileReadManager = *(Manager*)(shared::base + 0x19DA840);
};