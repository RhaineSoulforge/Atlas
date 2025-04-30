#pragma once

#include "Core.h"
#include "Window.h"

namespace Atlas
{
    class CApplication
    {
        public:
            CApplication();
            virtual ~CApplication();

            void Run();
            void OnEvent(CEvent &e);
        private:
            bool OnWindowClose(CWindowCloseEvent &e);
            
            CWindow *m_pWindow;
            bool m_bRunning = true;
    };

    // To be defined by CLIENT application!
    CApplication *CreateApplication(void);
}