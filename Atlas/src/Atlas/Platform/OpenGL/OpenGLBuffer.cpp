#include "atpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Atlas
{
    // VertexBuffer

    COpenGLVertexBuffer::COpenGLVertexBuffer(float *vertices, uint32_t size)
    {
        glCreateBuffers(1,&m_RendererID);
        glBindBuffer(GL_ARRAY_BUFFER,m_RendererID);
        glBufferData(GL_ARRAY_BUFFER,size,vertices,GL_STATIC_DRAW);
    }

    COpenGLVertexBuffer::~COpenGLVertexBuffer(void)
    {
        glDeleteBuffers(1,&m_RendererID);
    }

    void COpenGLVertexBuffer::Bind(void) const
    {
        glBindBuffer(GL_ARRAY_BUFFER,m_RendererID);
    }

    void COpenGLVertexBuffer::Unbind(void) const
    {
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

    // IndexBuffer

    COpenGLIndexBuffer::COpenGLIndexBuffer(uint32_t *indices, uint32_t count)
        : m_Count(count)
    {
        glCreateBuffers(1,&m_RendererID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,count * sizeof(uint32_t),indices,GL_STATIC_DRAW);
    }

    COpenGLIndexBuffer::~COpenGLIndexBuffer(void)
    {
        glDeleteBuffers(1,&m_RendererID);
    }

    void COpenGLIndexBuffer::Bind(void) const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererID);
    }

    void COpenGLIndexBuffer::Unbind(void) const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    }
}