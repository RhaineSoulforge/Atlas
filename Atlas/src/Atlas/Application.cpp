#include "atpch.h"

#include "Application.h"
#include "Input.h"

#include <glad/glad.h>

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

      glGenVertexArrays(1, &m_unVertexArray);
      glBindVertexArray(m_unVertexArray);

      glGenBuffers(1, &m_unVertexBuffer);
      glBindBuffer(GL_ARRAY_BUFFER,m_unVertexBuffer);

      float vertices[9] = {
         -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f, 0.5f, 0.0f
      };

      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

      glGenBuffers(1, &m_unIndexBuffer);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unIndexBuffer);

      unsigned int indices[3] = { 0, 1, 2 };
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
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
         glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         glBindVertexArray(m_unVertexArray);
         glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

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
