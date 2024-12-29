#include <Events.h>
#include <Hw.h>
#include "d3dx9.h"
#include <shared.h>
#include <Windows.h>

#pragma comment(lib, "d3dx9.lib")
LPD3DXFONT font;
bool canRender = false;
tagPOINT &res = *(tagPOINT*)(shared::base + 0x14CE9A4);

class RenderTextD3DX9
{
public:
    RenderTextD3DX9()
    {
        Events::OnGameStartupEvent += []()
        {
            if (D3DXCreateFont(Hw::GraphicDevice, 17, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &font) == S_OK)
                canRender = true;
        };
        Events::OnEndScene += []()
        {
            if (!canRender)
                return;
                
            RECT rect;
            rect.left = 20;
            rect.right = res.x;
            rect.top = 20;
            rect.bottom = rect.top + 200;
            font->DrawTextA(NULL, "TEST RENDER TEXT\0", -1, &rect, 0, 0xFFFFFF00);
        };

        Events::OnDeviceReset.before += []()
        {
            font->OnLostDevice();
        };

        Events::OnDeviceReset.after += []()
        {
            font->OnResetDevice();
        };
    }
} example;