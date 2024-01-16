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
   };
}
