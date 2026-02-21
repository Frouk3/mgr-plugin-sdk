#include <cScene.h>
#include <Hw.h> // for input
#include <Events.h>

class ChangeHeightExample
{
public:
    ChangeHeightExample()
    {
        Events::OnTickEvent += []()
        {
            Pl0000 *player = g_Scene.m_pPlayer;

            if (!player)
                return;

            if (g_Keyboard.trig(Hw::KB_K))
                player->m_TransPos.y += 5.0f;
            else if (g_Keyboard.trig(Hw::KB_L))
                player->m_TransPos.y -= 5.0f;
            
            if (g_Keyboard.on(Hw::KB_K) || g_Keyboard.on(Hw::KB_L))
                player->m_TransSpeed.y = 0.0f;
        };
    }
} example;