#pragma once

#include "Core.h"
#include "Window.h"

#include "Atlas/LayerStack.h"

namespace Atlas
{
    class CApplication
    {
        public:
            CApplication();
            virtual ~CApplication();

            void Run();
            void OnEvent(CEvent &e);

            void PushLayer(CLayer *layer);
            void PushOverlay(CLayer *layer);
        private:
            bool OnWindowClose(CWindowCloseEvent &e);
            
            CWindow *m_pWindow;
            bool m_bRunning = true;
            CLayerStack m_LayerStack;
    };

    // To be defined by CLIENT application!
    CApplication *CreateApplication(void);
}