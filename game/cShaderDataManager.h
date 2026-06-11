#pragma once

#include <Hw.h>

class cShaderDataManager
{
    Hw::cFixedList<Hw::cShader*> m_ShaderList; // A custom class, declared as Hw::cShader due to inheritance
    Hw::cFixedList<Hw::cPixelShader*> m_PixelDataList; // A custom class, declared as Hw::cPixelShader due to inheritance
    Hw::cHeapVariable* m_Allocator;

    virtual ~cShaderDataManager() {};  
};

inline cShaderDataManager& g_ShaderDataManager = *(cShaderDataManager*)(shared::base + 0x14E84D0);