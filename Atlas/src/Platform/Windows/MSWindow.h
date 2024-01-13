#pragma once

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

      private:

         struct SWindowData
         {
            std::string m_sTitle;
            unsigned int m_unWidth, m_unHeight;
            bool m_bVSync;

            EventCallbackFn m_EventCallback;
         };

         SWindowData m_wdData;
   };
}
