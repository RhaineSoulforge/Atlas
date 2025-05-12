#include "atpch.h"
#include "WindowsInput.h"

#include "Atlas/Platform/Windows/MSWindow.h"

namespace Atlas
{
    CInput *CInput::m_pInstance = new CWindowsInput();

    bool CWindowsInput::IsKeyPressedImpl(int keycode)
    {
        CMSWindow *window = CMSWindow::GetInstance();
        return window->GetKeyState(keycode);
    }

    bool CWindowsInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = CMSWindow::GetInstance();
        return window->GetMouseButtonState(button);
    }

    std::pair<float,float> CWindowsInput::GetMousePositionImpl(void)
    {
        auto window = CMSWindow::GetInstance();
        return window->GetMousePosition();
    }
}