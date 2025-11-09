#include <cGameUIManager.h>
#include <cSlowRateManager.h>
#include <Events.h>
#include <cGame.h>

class PlayerAdrenaline
{
    PlayerAdrenaline()
    {
        Events::OnTickEvent += []()
        {
            cSlowRateManager* SlowRateManager = cSlowRateManager::ms_pInstance;
            Pl0000 *player = g_GameUIManager.m_pPlayer;
            static bool once = false;

            if (player->m_Hp / player->getMaxHealth() <= 0.4f)
            {
                g_GameFlags.GAME_MUGEN_ZANGEKI = true;
                player->enableRipperMode();

                SlowRateManager->setSlowRate(SLOWRATE_GLOBAL, 0.6);
                SlowRateManager->setSlowRate(SLOWRATE_PL, 1.66667);
                SlowRateManager->setSlowRate(SLOWRATE_EM, 0.6);

                once = false;
            }
            else if (player->m_Hp / player->getMaxHealth() > 0.4f && !once)
            {
                g_GameFlags.GAME_MUGEN_ZANGEKI = false;

                SlowRateManager->resetSlowRate();

                once = true; 
            }
        };
    }
} example;