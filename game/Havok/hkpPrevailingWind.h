#pragma once

#include <hkpWind.h>
#include <hkBaseTypes.h>
#include <hkpWorldPostSimulationListener.h>
#include <hkVector4.h>
#include <hkArray.h>

class hkpPrevailingWind : public hkpWind, public hkpWorldPostSimulationListener
{
public:
    class Oscillator
    {
    public:
        hkReal m_difference;
        hkReal m_period;

        virtual ~Oscillator() {};
    };

    struct Triple
    {
        hkVector4 m_diff;
        Oscillator m_oscillator;
        hkReal m_power;
    };

    int pad[1];
    hkVector4 m_mid;
    hkArray<Oscillator> m_oscillator;
    hkVector4 m_current;
};