#include "atpch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"

namespace Atlas
{
   #define BIND_EVENT_FN(x) std::bind(&x,this,std::placeholders::_1)
   
   CApplication::CApplication()
   {
      m_Window = std::unique_ptr<CWindow>(CWindow::Create());
      m_Window->SetEventCallback(BIND_EVENT_FN(CApplication::OnEvent));
   }

   CApplication::~CApplication()
   {
      CATLogger::DeleteInstance();
   }

   void CApplication::OnEvent(CEvent& e)
   {
      AT_LOG_INFO(e.ToString().c_str());
   }

   void CApplication::Run()
   {
      while (m_bRunning)
      {
         m_Window->OnUpdate();
      }
   }
}