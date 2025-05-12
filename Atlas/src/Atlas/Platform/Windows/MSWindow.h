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
            inline void SetVSync(bool enabled) override { m_Data.m_bVSync = enabled; }
            inline bool IsVSync(void) const override { return m_Data.m_bVSync; }
            inline HWND GetHandle(void) const { return m_Data.m_hWnd; }
            inline HINSTANCE GetHInstance(void) const { return m_Data.m_hInstance; }

            inline bool GetKeyState(int keycode) const { return m_bKeyBuffer[keycode]; }
            inline bool GetMouseButtonState(int button) const { return m_bMouseBuffer[button]; }
            inline std::pair<float,float> GetMousePosition(void) const { return m_MousePosition; }

            inline void SetKeyState(int keycode, bool state) { m_bKeyBuffer[keycode] = state; }
            inline void SetMouseButtonState(int button, bool state) { m_bMouseBuffer[button] = state; }
            inline void SetMousePosition(std::pair<float,float> &position) { m_MousePosition.first = position.first; m_MousePosition.second = position.second; }

            virtual void *GetNativeWindow(void) const override;

            virtual void Init(const SWindowProps &props) override;
            virtual void Shutdown(void) override;

        private:
            static CMSWindow *m_pInstance;

            static LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

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
            bool m_bKeyBuffer[KEYBUFFERSIZE];
            bool m_bMouseBuffer[MOUSEBUFFERSIZE];
            std::pair<float,float> m_MousePosition;

            CMSWindow(void);
            CMSWindow(const CMSWindow&);
            CMSWindow *operator=(const CMSWindow&);
            ~CMSWindow(void);
    };
}