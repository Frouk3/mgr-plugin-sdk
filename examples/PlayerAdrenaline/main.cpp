#include <cGameUIManager.h>
#include <cSlowRateManager.h>
#include <Trigger.h>
#include <Events.h>

class PlayerAdrenaline
{
    PlayerAdrenaline()
    {
        Events::OnTickEvent += []()
        {
            cSlowRateManager* SlowRateManager = cSlowRateManager::pInstance;
            Pl0000 *player = cGameUIManager::Instance.m_pPlayer;
            static bool once = false;

            if (player->m_nHealth / player->GetMaxHealth() <= 0.4f)
            {
                Trigger::GameFlags.GAME_MUGEN_ZANGEKI = true;
                player->EnableRipperMode();

                SlowRateManager->SetSlowRate(SLOWRATE_GLOBAL, 0.6);
                SlowRateManager->SetSlowRate(SLOWRATE_PL, 1.66667);
                SlowRateManager->SetSlowRate(SLOWRATE_EM, 0.6);

                once = false;
            }
            else if (player->m_nHealth / player->GetMaxHealth() > 0.4f && !once)
            {
                Trigger::GameFlags.GAME_MUGEN_ZANGEKI = false;

                SlowRateManager->ResetSlowRate();

                once = true; 
            }
        };
    }
} example;