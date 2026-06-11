#pragma once

#include <PhantomManager.h>
#include <shared.h>

class PhantomManagerImplement : public PhantomManager
{
public:
};

inline PhantomManagerImplement *&g_PhantomManager = *(PhantomManagerImplement**)(shared::base + 0x1735DD8);