#include "Pl0000.h"
#include "cGameUIManager.h"
#include "shared/shared.h"

// i didn't check if it its works, just robbed a quick one :O
void RipperModeOnBladeMode()
{
    cGameUIManager& GameUIManager = *(cGameUIManager*)(shared::base + 0x19C1430);

    Pl0000 *player = (Pl0000*)GameUIManager.m_pPl;

    if (player)
    {
        if (player->m_nCurrentAction == 69 || player->m_nCurrentAction == 70) // Raiden only
            if (!player->m_nRipperModeEnabled)
                player->EnableRipperMode();
    }
}