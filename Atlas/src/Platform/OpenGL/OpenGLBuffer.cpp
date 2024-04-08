#include "atpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Atlas
{
    COpenGLVertexBuffer::COpenGLVertexBuffer(float *vertices, uint32_t size)
    {
        glCreateBuffers(1,&m_unRendererID);
        glBindBuffer(GL_ARRAY_BUFFER,m_unRendererID);
        glBufferData(GL_ARRAY_BUFFER,size,vertices,GL_STATIC_DRAW);
    }

    COpenGLVertexBuffer::~COpenGLVertexBuffer(void)
    {
        glDeleteBuffers(1,&m_unRendererID);
    }

    void COpenGLVertexBuffer::Bind(void) const
    {
        glBindBuffer(GL_ARRAY_BUFFER,m_unRendererID);
    }

    void COpenGLVertexBuffer::Unbind(void) const
    {
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

    COpenGLIndexBuffer::COpenGLIndexBuffer(uint32_t* indices, uint32_t count)
       :m_unCount(count)
    {
       glCreateBuffers(1, &m_unRendererID);
       glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRendererID);

       glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    }

    COpenGLIndexBuffer::~COpenGLIndexBuffer(void)
    {
       glDeleteBuffers(1, &m_unRendererID);
    }

    void COpenGLIndexBuffer::Bind(void) const
    {
       glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRendererID);
    }

    void COpenGLIndexBuffer::Unbind(void) const
    {
       glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
