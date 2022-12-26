#include "Pl0000.h"
#include "shared/shared.h"

void RipperModeOnBladeMode()
{
    Pl0000 *player = *(Pl0000**)(shared::base + 0x19C1490);

    if (player)
    {
        if (player->m_nCurrentAction == 69 || player->m_nCurrentAction == 70) // Raiden only
            if (!player->m_nRipperModeEnabled)
                player->EnableRipperMode();
    }
}