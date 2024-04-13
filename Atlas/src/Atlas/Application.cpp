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

      float vertices[21] = {
         -0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
         0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
         0.0f, 0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f
      };

      m_pVertexBuffer.reset(CVertexBuffer::Create(vertices,sizeof(vertices)));

      CBufferLayout layout = {
          { eCShaderDataType::Float3, "a_Position" },
          { eCShaderDataType::Float4, "a_Color" }
      };

      m_pVertexBuffer->SetLayout(layout);

      m_pVertexArray.reset(CVertexArray::Create());
      m_pVertexArray->AddVertexBuffer(m_pVertexBuffer);

      unsigned int indices[3] = { 0, 1, 2 };
      m_pIndexBuffer.reset(CIndexBuffer::Create(indices,3));
      m_pVertexArray->SetIndexBuffer(m_pIndexBuffer);

      std::string vertexSrc = R"(

        #version 460 core

        layout(location=0) in vec3 a_Position;
        layout(location=1) in vec4 a_Color;

        out vec4 v_Color;

        void main()
        {
            gl_Position = vec4(a_Position,1.0f);
            v_Color = a_Color;
        }

      )";

      std::string fragmentSrc = R"(

        #version 460 core

        layout(location=0) out vec4 Color;

        in vec4 v_Color;

        void main()
        {
            Color = v_Color;
        }
      )";

      m_pShader.reset(CShader::Create(vertexSrc,fragmentSrc));
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

         m_pShader->Bind();
         m_pVertexArray->Bind();
         glDrawElements(GL_TRIANGLES, m_pIndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

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
