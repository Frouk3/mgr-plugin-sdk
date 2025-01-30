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
        int m_ReaderId;
        int field_2C;
        void *m_Filedata;
        int m_Filesize;
        Hw::cHeapPhysical *m_Allocator;
        int m_nFileflags;
        int m_nRequests;
        int m_nUsageCount;
        int field_48;
        int m_WorkerState;
        int m_WaitAmount;
        int field_54;
        FileRead::Listener *m_Listener;
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
    };
};