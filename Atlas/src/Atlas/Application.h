#pragma once

#include "Core.h"
#include "Window.h"

#include "Atlas/LayerStack.h"
#include "Atlas/Input.h"
#include "Atlas/Renderer/Shader.h"
#include "Atlas/Renderer/Buffer.h"

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

            unsigned int m_VertexArray;
            CVertexBuffer *m_pVertexBuffer;
            CIndexBuffer *m_pIndexBuffer;
            CShader *m_pShader;
    };

    // To be defined by CLIENT application!
    CApplication *CreateApplication(void);
}