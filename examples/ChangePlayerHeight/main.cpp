#include "cGameUIManager.h"
#include "Pl0000.h"

void ChangeHeight()
{
    Pl0000 *player = (Pl0000*)g_cGameUIManager.m_pPl;

    if (!player)
        return;

    if (GetAsyncKeyState(VK_ADD) & 1)
        player->m_vecPosition.y += 5.0f;
    else if (GetAsyncKeyState(VK_SUBTRACT) & 1)
        player->m_vecPosition.y -= 5.0f;
    
    if ((GetAsyncKeyState(VK_ADD) & 0x8000) != 0 || (GetAsyncKeyState(VK_SUBTRACT) & 0x8000) != 0)
        player->m_vecVelocity.y = 0.0f;
}