#include "cGameUIManager.h"
#include "Events.h"

class OnBladeModeRipper
{
public:
    OnBladeModeRipper()
    {
        Events::OnTickEvent += []()
        {
            auto player = cGameUIManager::Instance.m_pPlayer;

            if (player)
            {
                if (player->m_nCurrentAction == 69 || player->m_nCurrentAction == 70) // Raiden only
                    if (!player->m_nRipperModeEnabled)
                        player->EnableRipperMode();
            }
        };
    }
} example;