#include <cScene.h>
#include <cSlowRateManager.h>
#include <Events.h>
#include <cGame.h>

class PlayerAdrenaline
{
    PlayerAdrenaline()
    {
        Events::OnTickEvent += []()
        {
            cSlowRateManager* SlowRateManager = &g_RateMan;
            Pl0000 *player = g_Scene.m_pPlayer;
            static bool once = false;

            if (player->m_Hp / player->getMaxHealth() <= 0.4f)
            {
                g_GameFlags.GAME_MUGEN_ZANGEKI = true;
                player->enableRipperMode();

                SlowRateManager->setSlowRate(eRateType_Scene, 0.6);
                SlowRateManager->setSlowRate(eRateType_Pl, 1.66667);
                SlowRateManager->setSlowRate(eRateType_Em, 0.6);

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