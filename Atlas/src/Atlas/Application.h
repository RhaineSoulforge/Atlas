#pragma once

#include "Core.h"
#include "Window.h"

#include "Atlas/LayerStack.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"


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

         unsigned int m_unVertexArray;
         unsigned int m_unVertexBuffer;
         unsigned int m_unIndexBuffer;
   };

   // To be defined in CLIENT.
   CApplication* CreateApplication();
}