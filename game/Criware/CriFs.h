#pragma once

#include <CriBase.h>

struct CriFsConfig
{
    CriUint32 thread_model;
    CriSint32 num_binders;
    CriSint32 num_loaders;
    CriSint32 num_group_loaders;
    CriSint32 num_stdio_handles;
    CriSint32 num_installers;
    CriSint32 max_binds;
    CriSint32 max_files;
    CriSint32 max_path; // Only for MGR?
};

enum CriFsBinderStatus
{
    CRIFSBINDER_STATUS_NONE = 0x0,
    CRIFSBINDER_STATUS_ANALYZE = 0x1,
    CRIFSBINDER_STATUS_COMPLETE = 0x2,
    CRIFSBINDER_STATUS_UNBIND = 0x3,
    CRIFSBINDER_STATUS_REMOVED = 0x4,
    CRIFSBINDER_STATUS_INVALID = 0x5,
    CRIFSBINDER_STATUS_ERROR = 0x6,
    CRIFSBINDER_STATUS_ENUM_BE_SINT32 = 0x7FFFFFFF
};

enum CriFsLoaderStatus
{
    CRIFSLOADER_STATUS_STOP = 0x0,
    CRIFSLOADER_STATUS_LOADING = 0x1,
    CRIFSLOADER_STATUS_COMPLETE = 0x2,
    CRIFSLOADER_STATUS_ERROR = 0x3,
    CRIFSLOADER_STATUS_ENUM_BE_SINT32 = 0x7FFFFFFF
};

enum CriFsDeviceIdTag
{
    CRIFS_DEVICE_00 = 0x0,
    CRIFS_DEVICE_01 = 0x1,
    CRIFS_DEVICE_02 = 0x2,
    CRIFS_DEVICE_03 = 0x3,
    CRIFS_DEVICE_04 = 0x4,
    CRIFS_DEVICE_05 = 0x5,
    CRIFS_DEVICE_06 = 0x6,
    CRIFS_DEVICE_07 = 0x7,
    CRIFS_DEVICE_MAX = 0x8,
    CRIFS_DEVICE_INVALID = 0xFFFFFFFF,
    CRIFS_DEVICE_ENUM_BE_SINT32 = 0x7FFFFFFF
};

enum CriFsIoError
{
    CRIFS_IO_ERROR_OK = 0x0,
    CRIFS_IO_ERROR_NG = 0xFFFFFFFF,
    CRIFS_IO_ERROR_TRY_AGAIN = 0xFFFFFFFE,
    CRIFS_IO_ERROR_NG_NO_ENTRY = 0xFFFFFFF5,
    CRIFS_IO_ERROR_NG_INVALID_DATA = 0xFFFFFFF4,
    CRIFS_IO_ERROR_ENUM_BE_SINT32 = 0x7FFFFFFF
};

enum CriFsFileAccess
{
    CRIFS_FILE_ACCESS_READ = 0x0,
    CRIFS_FILE_ACCESS_WRITE = 0x1,
    CRIFS_FILE_ACCESS_READ_WRITE = 0x2,
    CRIFS_FILE_ACCESS_ENUM_BE_SINT32 = 0x7FFFFFFF
};

enum CriFsFileMode
{
    CRIFS_FILE_MODE_APPEND = 0x0,
    CRIFS_FILE_MODE_CREATE = 0x1,
    CRIFS_FILE_MODE_CREATE_NEW = 0x2,
    CRIFS_FILE_MODE_OPEN = 0x3,
    CRIFS_FILE_MODE_OPEN_OR_CREATE = 0x4,
    CRIFS_FILE_MODE_TRUNCATE = 0x5,
    CRIFS_FILE_MODE_OPEN_WITHOUT_DECRYPTING = 0xA,
    CRIFS_FILE_MODE_ENUM_BE_SINT32 = 0x7FFFFFFF
};

typedef enum CriFsDeviceIdTag CriFsDeviceId;

typedef CriUint32 CriFsBindId;

struct CriFsBinderHn;

struct CriFsLoaderHn
{
    int field_0;
    int field_4;
    int field_8;
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
    void *m_Filebuffer;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int m_Loader;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    CriFsBinderHn *m_Binder;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
    int field_150;
    int field_154;
    int field_158;
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    int field_16C;
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    int field_218;
    int field_21C;
    int field_220;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    int field_284;
    int field_288;
    int field_28C;
    int field_290;
    int field_294;
    int field_298;
    int field_29C;
    int field_2A0;
    int field_2A4;
    int field_2A8;
    int field_2AC;
    int field_2B0;
    int field_2B4;
    int field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;
    int field_2C8;
    int field_2CC;
    int field_2D0;
    int field_2D4;
    int field_2D8;
    int field_2DC;
    int field_2E0;
    int field_2E4;
    int field_2E8;
    int field_2EC;
    int field_2F0;
    int field_2F4;
    int field_2F8;
    int field_2FC;
    int field_300;
    int field_304;
    int field_308;
    int field_30C;
    int field_310;
    int field_314;
    int field_318;
    int field_31C;
    int field_320;
    int field_324;
    int field_328;
    int field_32C;
    int field_330;
    int field_334;
    int field_338;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
};

struct CriFsBinderWork // Platinum addon
{
    int m_nStatus;
    CriFsBinderHn *m_CriBinderHn;
    CriFsBindId m_BinderId;
    int m_BindStatus;
    int m_nPriority;

    BOOL bindCpkFileSync(const char* path, int a3, int a4, int priority)
    {
        return ((BOOL(__thiscall*)(CriFsBinderWork*, const char*, int, int, int))(shared::base + 0x9EAFB0))(this, path, a3, a4, priority);
    }

    BOOL bindCpk(const char* path, int a3, int a4, int priority)
    {
        return ((BOOL(__thiscall*)(CriFsBinderWork*, const char*, int, int, int))(shared::base + 0x9EB530))(this, path, a3, a4, priority);
    }
};

struct CriFsBinderHn
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
};

inline int CRIAPI criFsBinder_GetStatus(int binderId, int* bindStatus)
{
    return ((int(CRIAPI*)(int, int*))(shared::base + 0xE97D56))(binderId, bindStatus);
}

inline int CRIAPI criFsBinder_UnBind(int binderId)
{
    return ((int(CRIAPI*)(int))(shared::base + 0xE97543))(binderId);
}

inline int CRIAPI CriFsBinderHn_free(CriFsBinderHn* binderHn)
{
    return ((int(CRIAPI*)(CriFsBinderHn*))(shared::base + 0xE97C59))(binderHn);
}