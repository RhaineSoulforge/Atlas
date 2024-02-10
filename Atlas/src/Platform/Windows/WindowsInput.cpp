#include "atpch.h"
#include "WindowsInput.h"
#include "MSWindow.h"
#include "Atlas/Application.h"

namespace Atlas
{
   CInput* CInput::m_pInstance = new CWindowsInput();

   bool CWindowsInput::IsKeyPressedImpl(int keycode)
   {
      auto window = static_cast<CMSWindow&>(CApplication::Get()->getWindow());
      return window.getKeyState(keycode);
   }
   bool CWindowsInput::IsMouseButtonPressedImpl(int nButton)
   {
      auto window = static_cast<CMSWindow&>(CApplication::Get()->getWindow());
      return window.getMouseButtonState(nButton);
   }
   std::pair<float, float> CWindowsInput::GetMousePositionImpl(void)
   {
      auto window = static_cast<CMSWindow&>(CApplication::Get()->getWindow());
      return window.getMousePosition();
   }
   float CWindowsInput::GetMouseXImpl(void)
   {
      auto window = static_cast<CMSWindow&>(CApplication::Get()->getWindow());
      return window.getMousePosition().first;
   }
   float CWindowsInput::GetMouseYImpl(void)
   {
      auto window = static_cast<CMSWindow&>(CApplication::Get()->getWindow());
      return window.getMousePosition().second;
   }
}