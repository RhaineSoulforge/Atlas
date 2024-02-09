#pragma once

#include "Core.h"
#include "Window.h"

#include "Atlas/LayerStack.h"
#include "Events/ApplicationEvent.h"


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
      private:
         bool OnWindowClose(Atlas::CWindowCloseEvent &e);

         std::unique_ptr<CWindow> m_Window;
         bool                     m_bRunning = true;
         CLayerStack              m_LayerStack;
   };

   // To be defined in CLIENT.
   CApplication* CreateApplication();
}