#include "atpch.h"
#include "OpenGLVertexBuffer.h"

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
}
