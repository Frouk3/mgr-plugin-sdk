#include "cGameUIManager.h"
#include "Pl0000.h"
#include "shared.h"

void ChangeHeight()
{
    Pl0000 *player = (Pl0000*)g_cGameUIManager.m_pPl;

    if (!player)
        return;

    if (shared::IsKeyPressed(VK_ADD))
        player->m_vecPosition.y += 5.0f;
    else if (shared::IsKeyPressed(VK_SUBTRACT))
        player->m_vecPosition.y -= 5.0f;
    
    if (shared::IsKeyPressed(VK_ADD, true) || shared::IsKeyPressed(VK_SUBTRACT, true))
        player->m_vecVelocity.y = 0.0f;
}