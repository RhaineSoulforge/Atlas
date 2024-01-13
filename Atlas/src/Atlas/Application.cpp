#include "atpch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
//#include "ATLogger.h"

namespace Atlas
{
   CApplication::CApplication()
   {
      m_Window = std::unique_ptr<CWindow>(CWindow::Create());
   }

   CApplication::~CApplication()
   {
   }

   void CApplication::Run()
   {
      while (m_bRunning)
      {
         m_Window->OnUpdate();
      }
   }
}