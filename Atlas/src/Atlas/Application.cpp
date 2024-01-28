#include "atpch.h"

#include "Application.h"

namespace Atlas
{
   #define BIND_EVENT_FN(x) std::bind(&CApplication::x,this,std::placeholders::_1)
   
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
      Atlas::CEventDispatcher dispatcher(e);
      dispatcher.Dispatch<CWindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

      AT_LOG_TRACE(e.ToString().c_str());
   }

   void CApplication::Run()
   {
      while (m_bRunning)
      {
         m_Window->OnUpdate();
      }
   }

   bool CApplication::OnWindowClose(Atlas::CWindowCloseEvent& e)
   {
      m_bRunning = false;
      return true;
   }
}