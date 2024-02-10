#pragma once

#include "Atlas/Events/ApplicationEvent.h"
#include "Atlas/Events/KeyEvent.h"
#include "Atlas/Events/MouseEvent.h"
#include "Atlas/Window.h"

namespace Atlas
{
   class CMSWindow : public CWindow
   {
      public:
         CMSWindow(const SWindowProps& props);
         virtual ~CMSWindow();

         void OnUpdate() override;

         inline unsigned int GetWidth() const override { return m_wdData.m_unWidth; }
         inline unsigned int GetHeight() const override { return m_wdData.m_unHeight; }

         inline void SetEventCallback(const EventCallbackFn& callback) override { m_wdData.m_EventCallback = callback; }
         void SetVSync(bool bEnabled);
         bool IsVSync() const;

         virtual void* GetNativeWindow() const override;

         inline void setKeyState(int nKeycode, bool bPressed) { m_bKeyboardBuffer[nKeycode] = bPressed; }
         inline void setMouseButtonState(int nButton, bool bPressed) { m_bMouseBuffer[nButton] = bPressed; }
         inline void setMousePosition(std::pair<float, float> prPosition) { m_fMouseX = prPosition.first; m_fMouseY = prPosition.second; }
         inline void setMouseX(float x) { m_fMouseX = x; }
         inline void setMouseY(float y) { m_fMouseY = y; }

         inline bool getKeyState(int nKeycode) { return m_bKeyboardBuffer[nKeycode]; }
         inline bool getMouseButtonState(int nButton) { return m_bMouseBuffer[nButton]; }
         inline std::pair<float, float> getMousePosition(void) { return std::pair<float, float>(m_fMouseX, m_fMouseY); }
         inline float getMouseX(void) { return m_fMouseX; }
         inline float getMouseY(void) { return m_fMouseY; }

      private:
         virtual void Init(const SWindowProps& props);
         virtual void Shutdown();

         static LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

      private:

         struct SWindowData
         {
            std::string m_sTitle;
            unsigned int m_unWidth, m_unHeight;
            bool m_bVSync;
            HINSTANCE m_hInstance;
            HWND m_hwnd;

            EventCallbackFn m_EventCallback;
         };

         SWindowData m_wdData;
         bool m_bMouseBuffer[MOUSEBUFFERSIZE];
         bool m_bKeyboardBuffer[KEYBOARDBUFFERSIZE];
         float m_fMouseX, m_fMouseY;
   };
}
