#include "Pl0000.h"
#include "cGameUIManager.h"
#include "cSlowRateManager.h"
#include "GameFlags.h"

void AdrenalineTime() noexcept
{
    cSlowRateManager* SlowRateManager = g_pcSlowRateManager;
    Pl0000 *player = (Pl0000*)g_cGameUIManager.m_pPl;
    static bool once = false;

    if (player->m_nHealth / player->GetMaxHealth() <= 0.4)
    {
        g_GameFlags |= MugenZangeki;
        player->EnableRipperMode();

        SlowRateManager->SetSlowRate(0, 0.6);
        SlowRateManager->SetSlowRate(1, 1.66667);
        SlowRateManager->SetSlowRate(2, 0.6);

        once = false;
    }
    else if (player->m_nHealth / player->GetMaxHealth() > 0.4 && !once)
    {
        g_GameFlags &= ~MugenZangeki;

        SlowRateManager->ResetSlowRate();

        once = true; 
    }
}