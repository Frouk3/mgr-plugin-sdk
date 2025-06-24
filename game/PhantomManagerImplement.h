#pragma once

#include <PhantomManager.h>
#include <shared.h>

class PhantomManagerImplement : public PhantomManager
{
public:

    static inline PhantomManagerImplement *&ms_Instance = *(PhantomManagerImplement**)(shared::base + 0x1735DD8);
};