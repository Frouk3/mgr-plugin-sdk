#include <cGameUIManager.h>
#include <Events.h>

class ChangeHeightExample
{
public:
    ChangeHeightExample()
    {
        Events::OnTickEvent += []()
        {
            Pl0000 *player = cGameUIManager::Instance.m_pPlayer;

            if (!player)
                return;

            if (shared::IsKeyPressed(VK_ADD, false))
                player->m_vecTransPos.y += 5.0f;
            else if (shared::IsKeyPressed(VK_SUBTRACT, false))
                player->m_vecTransPos.y -= 5.0f;
            
            if (shared::IsKeyPressed(VK_ADD) || shared::IsKeyPressed(VK_SUBTRACT))
                player->m_vecVelocity.y = 0.0f;
        };
    }
} example;