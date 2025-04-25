#pragma once

#include "atpch.h"

#include "Atlas/Events/ApplicationEvent.h"
#include "Atlas/Events/KeyEvent.h"
#include "Atlas/Events/MouseEvent.h"
#include "Atlas/Window.h"

namespace Atlas
{
    class CMSWindow : public CWindow
    {
        public:
            static CMSWindow *GetInstance(void);
            static void DeleteInstance(void);
            
            void OnUpdate(void) override;

            inline uint32_t GetWidth(void) const override { return m_Data.m_unWidth; }
            inline uint32_t GetHeight(void) const override { return m_Data.m_unHeight; }

            // Window attributes
            inline void SetEventCallback(const EventCallbackFn &callback) override { m_Data.m_EventCallback = callback; }
            void SetVSync(bool enabled) override;
            bool IsVSync(void) const override;

            virtual void Init(const SWindowProps &props);
            virtual void Shutdown(void);

        private:
            static CMSWindow *m_pInstance;

            struct SWindowData
            {
                std::string m_sTitle;
                uint32_t m_unWidth, m_unHeight;
                bool m_bVSync;
                HWND m_hWnd;
                HINSTANCE m_hInstance;

                EventCallbackFn m_EventCallback;
            };

            SWindowData m_Data;

            CMSWindow(void);
            CMSWindow(const CMSWindow&);
            CMSWindow *operator=(const CMSWindow&);
            ~CMSWindow(void);
    };
}