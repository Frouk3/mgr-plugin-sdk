#include "cGameUIManager.h"
#include "plugin.h"

void ProcessHeightChange()
{
    Pl0000 *player = cGameUIManager::Instance.m_pPlayer;

    if (!player)
        return;

    if (shared::IsKeyPressed(VK_ADD, false))
        player->m_vecOffset.y += 5.0f;
    else if (shared::IsKeyPressed(VK_SUBTRACT, false))
        player->m_vecOffset.y -= 5.0f;
    
    if (shared::IsKeyPressed(VK_ADD) || shared::IsKeyPressed(VK_SUBTRACT))
        player->m_vecVelocity.y = 0.0f;
} 

void plugin::OnStartup()
{
    UpdateEvent::Add(ProcessHeightChange);
}