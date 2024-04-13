#pragma once

#include "Core.h"
#include "Window.h"

#include "Atlas/LayerStack.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Atlas/Renderer/Shader.h"
#include "Atlas/Renderer/Buffer.h"
#include "Atlas/Renderer/VertexArray.h"


namespace Atlas
{
   class ATLAS_API CApplication
   {
      public:
         CApplication();
         virtual ~CApplication();

         void Run();
         void OnEvent(CEvent& e);

         void PushLayer(CLayer* layer);
         void PushOverLay(CLayer* overlay);

         inline CWindow &getWindow() { return *m_Window; }
         inline static CApplication* Get() { return m_pInstance; }
      private:
         bool OnWindowClose(Atlas::CWindowCloseEvent &e);

         std::unique_ptr<CWindow> m_Window;
         bool                     m_bRunning = true;
         CLayerStack              m_LayerStack;

         static CApplication*     m_pInstance;

         std::shared_ptr<CShader> m_pShader;
         std::shared_ptr<CVertexBuffer> m_pVertexBuffer;
         std::shared_ptr<CIndexBuffer> m_pIndexBuffer;
         std::shared_ptr<CVertexArray> m_pVertexArray;
   };

   // To be defined in CLIENT.
   CApplication* CreateApplication();
}
