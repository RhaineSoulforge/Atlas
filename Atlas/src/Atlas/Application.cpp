#include "atpch.h"

#include "Application.h"
#include "Input.h"

namespace Atlas
{
   #define BIND_EVENT_FN(x) std::bind(&CApplication::x,this,std::placeholders::_1)
 
   CApplication* CApplication::m_pInstance = nullptr;

   CApplication::CApplication()
   {
      AT_ASSERT(!m_pInstance, "Application already exists!!!");
      m_pInstance = this;
      m_Window = std::unique_ptr<CWindow>(CWindow::Create());
      m_Window->SetEventCallback(BIND_EVENT_FN(CApplication::OnEvent));
   }

   CApplication::~CApplication()
   {
      CATLogger::DeleteInstance();
   }

   void CApplication::PushLayer(CLayer* layer)   
   {
      m_LayerStack.PushLayer(layer);
   }

   void CApplication::PushOverLay(CLayer* overlay)
   {
      m_LayerStack.PushOverlay(overlay);
   }

   void CApplication::OnEvent(CEvent& e)
   {
      Atlas::CEventDispatcher dispatcher(e);
      dispatcher.Dispatch<CWindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

      //AT_LOG_TRACE(e.ToString().c_str());

      for (auto iter = m_LayerStack.end(); iter != m_LayerStack.begin();)
      {
         (*--iter)->OnEvent(e);
         if (e.m_bHandled)
            break;
      }
   }

   void CApplication::Run()
   {
      while (m_bRunning)
      {
         for (CLayer* layer : m_LayerStack)
            layer->OnUpdate();

         //std::pair<float, float> position = CInput::GetMousePosition();
         //AT_LOG_TRACE("CApplication::Run() := {f}, {f}", position.first, position.second);

         m_Window->OnUpdate();
      }
   }

   bool CApplication::OnWindowClose(Atlas::CWindowCloseEvent& e)
   {
      m_bRunning = false;
      return true;
   }
}