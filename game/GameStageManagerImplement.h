#pragma once

#include <GameStageManager.h>
#include <Hw.h>

class GameStageManagerImplement : public GameStageManager
{
public:
    Hw::cHeapVariable *m_Allocator;
};