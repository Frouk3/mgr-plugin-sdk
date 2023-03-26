#include "Pl0000.h"
#include "cGameUIManager.h"
#include "cSlowRateManager.h"
#include "Trigger.h"

void AdrenalineTime() noexcept
{
    cSlowRateManager* SlowRateManager = g_pcSlowRateManager;
    Pl0000 *player = (Pl0000*)g_cGameUIManager.m_pPlayer;
    static bool once = false;

    if (player->m_nHealth / player->GetMaxHealth() <= 0.4)
    {
        Trigger::GameFlags.GAME_MUGEN_ZANGEKI = true;
        player->EnableRipperMode();

        SlowRateManager->SetSlowRate(0, 0.6);
        SlowRateManager->SetSlowRate(1, 1.66667);
        SlowRateManager->SetSlowRate(2, 0.6);

        once = false;
    }
    else if (player->m_nHealth / player->GetMaxHealth() > 0.4 && !once)
    {
        Trigger::GameFlags.GAME_MUGEN_ZANGEKI = false;

        SlowRateManager->ResetSlowRate();

        once = true; 
    }
}