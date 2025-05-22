#include "atpch.h"
#include "Application.h"

#include <glad/glad.h>

namespace Atlas
{

    #define BIND_EVENT_FN(x) std::bind(&CApplication::x, this, std::placeholders::_1)

    CApplication::CApplication()
    {
        m_pWindow = CWindow::Create();
        m_pWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));

        //Apps first triangle!!!  ^_^
        {
            glGenVertexArrays(1,&m_VertexArray);
            glBindVertexArray(m_VertexArray);

            glGenBuffers(1,&m_VertexBuffer);
            glBindBuffer(GL_ARRAY_BUFFER,m_VertexBuffer);

            float vertices[9] ={
                -0.5f,0.0f,0.0f,
                 0.5f,0.0f,0.0f,
                 0.0f,1.0f,0.0f
            };

            glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),0);

            glGenBuffers(1,&m_IndexBuffer);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_IndexBuffer);

            unsigned int indices[3] = {0, 1, 2};
            glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);

            std::string vertexSrc = R"(
                #version 450 core

                layout(location = 0) in vec3 a_Position;

                out vec3 v_Position;

                void main()
                {
                    v_Position = a_Position;
                    gl_Position = vec4(a_Position,1.0);
                }
            )";

            std::string fragmentSrc = R"(
                #version 450 core

                layout(location = 0) out vec4 color;

                in vec3 v_Position;

                void main()
                {
                    color = vec4(v_Position * 0.5 + 0.5, 1.0);
                }
            )";

            m_pShader = new CShader(vertexSrc,fragmentSrc);
        }
    }

    CApplication::~CApplication()
    {
        m_pWindow->Shutdown();
        delete m_pShader;
    }

    void CApplication::PushLayer(CLayer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void CApplication::PushOverlay(CLayer *layer)
    {
        m_LayerStack.PushOverLay(layer);
    }

    void CApplication::OnEvent(CEvent &e)
    {
        CEventDispatcher dispatcher(e);

        dispatcher.Dispatch<CWindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        
        //AT_LOG_TRACE("{s}",e.ToString().c_str())

        for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if(e.m_Handled)
                break;
        }
    }

    bool CApplication::OnWindowClose(CWindowCloseEvent &e)
    {
        m_bRunning = false;
        return true;
    }

    void CApplication::Run()
    {
        AT_LOG_INFO("Atlas GE version Alpha online....")
        while(m_bRunning)
        {
            glClearColor(0.1f,0.1f,0.1f,1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_pShader->Bind();
            glBindVertexArray(m_VertexArray);
            glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,0);

            for(CLayer *layer : m_LayerStack)
                layer->OnUpdate();

            m_pWindow->OnUpdate();
        }
    }
}