#include "atpch.h"
#include "Application.h"

#include <glad/glad.h>

namespace Atlas
{
    #define BIND_EVENT_FN(x) std::bind(&CApplication::x, this, std::placeholders::_1)

    static GLenum ShaderDataTypeToOpenGLBaseType(eShaderDataType type)
    {
        switch(type)
        {
            case eShaderDataType::Float: return GL_FLOAT;
            case eShaderDataType::Float2: return GL_FLOAT;
            case eShaderDataType::Float3: return GL_FLOAT;
            case eShaderDataType::Float4: return GL_FLOAT;
            case eShaderDataType::Mat3: return GL_FLOAT;
            case eShaderDataType::Mat4: return GL_FLOAT;
            case eShaderDataType::Int: return GL_INT;
            case eShaderDataType::Int2: return GL_INT;
            case eShaderDataType::Int3: return GL_INT;
            case eShaderDataType::Int4: return GL_INT;
            case eShaderDataType::Bool: return GL_BOOL;
        }

        AT_ASSERT(true,"Unknown eShaderDataType!!!")
        return 0;
    }

    CApplication::CApplication()
    {
        m_pWindow = CWindow::Create();
        m_pWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));

        //Apps first triangle!!!  ^_^
        {
            glGenVertexArrays(1,&m_VertexArray);
            glBindVertexArray(m_VertexArray);

            float vertices[3 * 7] ={
                -0.5f,0.0f,0.0f,0.8f,0.2f,0.8f,1.0f,
                 0.5f,0.0f,0.0f,0.2f,0.3f,0.8f,1.0f,
                 0.0f,1.0f,0.0f,0.8f,0.8f,0.2f,1.0f
            };

            m_pVertexBuffer = CVertexBuffer::Create(vertices,sizeof(vertices));

            {
                CBufferLayout layout = {
                    {eShaderDataType::Float3,"a_Position"},                    
                    {eShaderDataType::Float4,"a_Color"}
                };

                m_pVertexBuffer->SetLayout(layout);
            }

            uint32_t index = 0;
            const auto &layout = m_pVertexBuffer->GetLayout();
            for(const auto &element : layout)
            {                
                glEnableVertexAttribArray(index);
                glVertexAttribPointer(index,
                    element.GetComponentCount(),
                    ShaderDataTypeToOpenGLBaseType(element.m_Type),
                    element.m_bNormalized ? GL_TRUE : GL_FALSE,
                    layout.GetStride(),
                    (const void*)element.m_unOffset);
                index++;
            }

            uint32_t indices[3] = {0, 1, 2};
            m_pIndexBuffer = CIndexBuffer::Create(indices,sizeof(indices) / sizeof(uint32_t));

            std::string vertexSrc = R"(
                #version 450 core

                layout(location = 0) in vec3 a_Position;
                layout(location = 1) in vec4 a_Color;

                out vec3 v_Position;
                out vec4 v_Color;

                void main()
                {
                    v_Position = a_Position;
                    v_Color = a_Color;
                    gl_Position = vec4(a_Position,1.0);
                }
            )";

            std::string fragmentSrc = R"(
                #version 450 core

                layout(location = 0) out vec4 color;

                in vec3 v_Position;
                in vec4 v_Color;

                void main()
                {
                    color = v_Color;
                }
            )";

            m_pShader = new CShader(vertexSrc,fragmentSrc);
        }
    }

    CApplication::~CApplication()
    {
        m_pWindow->Shutdown();
        delete m_pShader;
        delete m_pVertexBuffer;
        delete m_pIndexBuffer;
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
            glDrawElements(GL_TRIANGLES,m_pIndexBuffer->GetCount(),GL_UNSIGNED_INT,0);

            for(CLayer *layer : m_LayerStack)
                layer->OnUpdate();

            m_pWindow->OnUpdate();
        }
    }
}