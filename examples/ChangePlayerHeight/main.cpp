#include <cGameUIManager.h>
#include <Hw.h> // for cInput
#include <Events.h>

class ChangeHeightExample
{
public:
    ChangeHeightExample()
    {
        Events::OnTickEvent += []()
        {
            Pl0000 *player = cGameUIManager::ms_Instance.m_pPlayer;

            if (!player)
                return;

            if (cInput::ms_KeyInput.isKeyPressed('K'))
                player->m_vecTransPos.y += 5.0f;
            else if (cInput::ms_KeyInput.isKeyPressed('L'))
                player->m_vecTransPos.y -= 5.0f;
            
            if (cInput::ms_KeyInput.isKeyDown('K') || cInput::ms_KeyInput.isKeyDown('L'))
                player->m_vecVelocity.y = 0.0f;
        };
    }
} example;