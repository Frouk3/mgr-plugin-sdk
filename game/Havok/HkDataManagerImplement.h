#pragma once

#include <HkDataManager.h>
#include <lib.h>

struct DataArchiveEntry
{
    char magic[4];
    size_t m_nAmountOfFiles;
    size_t m_nPositionOffset;
    size_t m_nExtensionOffset;
    size_t m_nNamesOffset;
    size_t m_nSizesOffset;
    size_t m_nHashMapOffset;
};

struct DataArchiveHolder
{
    char* m_data;

    DataArchiveHolder()
    {
        ((void(__thiscall*)(DataArchiveHolder*))(shared::base + 0x9E3530))(this);
    }

    DataArchiveEntry* asEntry()
    {
        return (DataArchiveEntry*)m_data;
    }

    size_t getFileAmount()
    {
        return ((size_t(__thiscall *)(DataArchiveHolder*))(shared::base + 0x9E3590))(this);
    }

    size_t getSizeByFileIndex(size_t fileIndex)
    {
        return ((size_t(__thiscall *)(DataArchiveHolder*, size_t))(shared::base + 0x9E3670))(this, fileIndex);
    }

    // returns -1 if haven't found any
    size_t getFileIndexByExtension(BOOL bBigEndian, const char *ext, unsigned int matchLimit)
    {
        return ((size_t(__thiscall *)(DataArchiveHolder*, BOOL, const char *, unsigned int))(shared::base + 0x9E36A0))(this, bBigEndian, ext, matchLimit);
    }

    // returns -1 if haven't found any
    size_t getFileIndex(BOOL bBigEndian, const char* name)
    {
        return ((size_t(__thiscall *)(DataArchiveHolder *, BOOL, const char *))(shared::base + 0x9E3730))(this, bBigEndian, name);
    }

    // returns -1 if haven't found any
    size_t getFileIndexByHash(BOOL bBigEndian, unsigned int crc32Hash)
    {
        return ((size_t(__thiscall *)(DataArchiveHolder*, BOOL, unsigned int))(shared::base + 0x9E37A0))(this, bBigEndian, crc32Hash);
    }

    size_t getFileIndexBySubStr(BOOL bBigEndian, const char *name, unsigned int matchLimit)
    {
        return ((size_t(__thiscall *)(DataArchiveHolder *, BOOL, const char *, unsigned int))(shared::base + 0x9E3850))(this, bBigEndian, name, matchLimit);
    }

    const char *getNameByFileIndex(size_t fileIndex)
    {
        return ((const char*(__thiscall *)(DataArchiveHolder *, size_t))(shared::base + 0x9E38D0))(this, fileIndex);
    }

    BOOL getExtension(char *pExt, size_t fileIndex)
    {
        return ((BOOL(__thiscall *)(DataArchiveHolder*, char *, size_t))(shared::base + 0x9E3C20))(this, pExt, fileIndex);
    }

    void *getFiledata(size_t fileIndex)
    {
        return ((void*(__thiscall *)(DataArchiveHolder*, size_t))(shared::base + 0x9E3CF0))(this, fileIndex);
    }

    void *getFiledataByExtension(BOOL bBigEndian, const char *ext, unsigned int matchLimit)
    {
        return ((void*(__thiscall *)(DataArchiveHolder *, BOOL, const char*, unsigned int))(shared::base + 0x9E3D30))(this, bBigEndian, ext, matchLimit);
    }

    void *getFiledata(BOOL bBigEndian, const char *name)
    {
        return ((void*(__thiscall *)(DataArchiveHolder*, BOOL, const char *))(shared::base + 0x9E3D80))(this, bBigEndian, name);
    }

    void *getFiledata(BOOL bBigEndian, unsigned int crc32Hash)
    {
        return ((void*(__thiscall *)(DataArchiveHolder *, BOOL, unsigned int))(shared::base + 0x9E3E90))(this, bBigEndian, crc32Hash);
    }

    size_t getSize(size_t fileIndex)
    {
        return ((size_t(__thiscall *)(DataArchiveHolder*, size_t))(shared::base + 0x9E3EE0))(this, fileIndex);
    }

    size_t getFileIndexByExtension(const char* ext, unsigned int matchLimit)
    {
        return ((size_t(__thiscall *)(DataArchiveHolder *, const char *, unsigned int))(shared::base + 0x9E3F20))(this, ext, matchLimit);
    }

    // has automatic detection if it's big endian + uses _stricmp
    size_t getFileIndexLoc(const char *name)
    {
        return ((size_t(__thiscall *)(DataArchiveHolder *, const char*))(shared::base + 0x9E3FD0))(this, name);
    }

    size_t getAnyFileIndex(const char *name, unsigned int matchLimit)
    {
        return ((size_t(__thiscall *)(DataArchiveHolder *, const char *, unsigned int))(shared::base + 0x9E4130))(this, name, matchLimit);
    }

    // automatic big endian detection
    void* _getFiledataByExtension(const char *name, unsigned int matchLimit)
    {
        return ((void*(__thiscall *)(DataArchiveHolder*, const char *, unsigned int))(shared::base + 0x9E44B0))(this, name, matchLimit);
    }
    
    // automatic big endian detection + uses _stricmp
    void* getFiledataLoc(const char *name)
    {
        return ((void*(__thiscall *)(DataArchiveHolder *, const char *))(shared::base + 0x9E4500))(this, name);
    }

    void *getAnyFiledata(const char *name, unsigned int matchLimit)
    {
        return ((void*(__thiscall *)(DataArchiveHolder*, const char*, unsigned int))(shared::base + 0x9E4550))(this, name, matchLimit);
    }

    size_t getAnySize(const char *name, unsigned int matchLimit)
    {
        return ((size_t(__thiscall *)(DataArchiveHolder *, const char *, unsigned int))(shared::base + 0x9E46D0))(this, name, matchLimit);
    }
};

class HkDataManagerImplement : public HkDataManager
{
public:
    struct ReserveUnit
    {
        void *m_nFilePos;
        size_t m_nFileSize;
        int m_nFileSubPhase;
        int field_C;
        int field_10;
        int field_14;
        int field_18;
        int field_1C;
        int field_20;
        int field_24;
        int field_28;
        int field_2C;
        int field_30;
        int field_34;
        int field_38;
        int field_3C;
        int field_40;
        int field_44;
        int field_48;
        int field_4C;
        int field_50;
        int field_54;
        int field_58;
        int field_5C;
        int field_60;
        int field_64;
        int field_68;
        int field_6C;
        int field_70;
        int field_74;
        int field_78;
        int field_7C;
        int field_80;
        int field_84;
        int field_88;
    };

    int field_4;
    int field_8;
    int field_C;
    Hw::cHeapFixed m_HkxFactory;
    int field_70;
    lib::AllocatedArray<ReserveUnit> *m_ReservedData;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;

    static inline HkDataManagerImplement *& ms_Instance = *(HkDataManagerImplement**)(shared::base + 0x1735FA0);
};