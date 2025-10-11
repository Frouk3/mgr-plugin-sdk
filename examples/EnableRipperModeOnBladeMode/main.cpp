#include <cGameUIManager.h>
#include <Events.h>

class OnBladeModeRipper
{
public:
    OnBladeModeRipper()
    {
        Events::OnTickEvent += []()
        {
            Pl0000* player = cGameUIManager::ms_Instance.m_pPlayer;

            if (player)
            {
                if (player->isBladeModeActive()) // Raiden only
                    if (!player->m_bRipperModeEnabled)
                        player->enableRipperMode();
            }
        };
    }
} example;