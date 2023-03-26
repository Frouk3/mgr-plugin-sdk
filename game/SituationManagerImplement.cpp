#include "SituationManagerImplement.h"
#include "shared.h"

SituationManagerImplement *GetSituationManagerImplement()
{
    return ((SituationManagerImplement *(__cdecl *)())(shared::base + 0x8206D0))();
}

SituationManagerImplement*& g_pSituationManagerImplement = *(SituationManagerImplement**)(shared::base + 0x17EA1A4);