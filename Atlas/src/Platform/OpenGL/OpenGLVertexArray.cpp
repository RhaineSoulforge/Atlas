#include "atpch.h"
#include "OpenGLVertexArray.h"

#include "Atlas/Renderer/Buffer.h"

#include <glad/glad.h>

namespace Atlas
{
    static GLenum ShaderDataTypeToOpenGLBaseType(eCShaderDataType type)
    {
        switch(type)
        {
            case eCShaderDataType::Float: return GL_FLOAT;
            case eCShaderDataType::Float2: return GL_FLOAT;
            case eCShaderDataType::Float3: return GL_FLOAT;
            case eCShaderDataType::Float4: return GL_FLOAT;
            case eCShaderDataType::Int: return GL_INT;
            case eCShaderDataType::Int2: return GL_INT;
            case eCShaderDataType::Int3: return GL_INT;
            case eCShaderDataType::Int4: return GL_INT;
            case eCShaderDataType::Mat3: return GL_FLOAT;
            case eCShaderDataType::Mat4: return GL_FLOAT;
            case eCShaderDataType::Bool: return GL_BOOL;
        };

        AT_ASSERT(false,"Unknow ShaderDataType!!!");
        return 0;
    }

    COpenGLVertexArray::COpenGLVertexArray(void)
    {
        glCreateVertexArrays(1, &m_unRendererID);
    }

    COpenGLVertexArray::~COpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_unRendererID);
    }

    void COpenGLVertexArray::Bind(void) const
    {
        glBindVertexArray(m_unRendererID);
    }

    void COpenGLVertexArray::Unbind(void) const
    {
        glBindVertexArray(0);
    }

    void COpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<CVertexBuffer> &pVertexBuffer)
    {
        AT_ASSERT(pVertexBuffer->GetLayout().GetElements().size(), "This buffer has no layout!!!!");

        glBindVertexArray(m_unRendererID);
        pVertexBuffer->Bind();

        uint32_t index = 0;
        for(const auto &element : pVertexBuffer->GetLayout())
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, element.GetComponentCount(),
                                  ShaderDataTypeToOpenGLBaseType(element.m_sdtType),
                                  element.m_bNormalized ? GL_TRUE : GL_FALSE,
                                  pVertexBuffer->GetLayout().GetStride(), (const void*)element.m_unOffset);
            index++;
        }

        m_vVertexBuffers.push_back(pVertexBuffer);
    }

    void COpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<CIndexBuffer> &pIndexBuffer)
    {
        glBindVertexArray(m_unRendererID);
        pIndexBuffer->Bind();

        m_pIndexBuffer = pIndexBuffer;
    }
}
