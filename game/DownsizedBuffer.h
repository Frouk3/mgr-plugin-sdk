#pragma once

#include <Hw.h>

namespace DownsizedBuffer
{
    class ShaderComposition : public Hw::cShader{};
    
    class ShaderDownSample : public Hw::cShader{};

    class ShaderDownSampleZ : public Hw::cShader{};

    class ShaderDownSampleMRT : public Hw::cShader{};

    class ShaderDrawZMap : public Hw::cShader{};

    class ShaderResolve : public Hw::cShader
    {
    public:
        int field_4C;
        int field_50;
        int field_54;
    };
};