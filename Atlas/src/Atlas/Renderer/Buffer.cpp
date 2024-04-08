#include "atpch.h"
#include "Buffer.h"
#include "Atlas/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Atlas
{
    CVertexBuffer *CVertexBuffer::Create(float *vertices, uint32_t size)
    {
        switch(CRenderer::GetAPI())
        {
            case RendererAPI::eNone:
                {
                    AT_ASSERT(false,"eNone currently not supported!");
                    return nullptr;
                }
            case RendererAPI::eOpenGL:
                return new COpenGLVertexBuffer(vertices,size);
        }

        AT_ASSERT(false,"Unknown RendererAPI!!!");
        return nullptr;
    }

    CIndexBuffer *CIndexBuffer::Create(uint32_t *indices, uint32_t count)
    {
        switch(CRenderer::GetAPI())
        {
            case RendererAPI::eNone:
                {
                    AT_ASSERT(false,"eNone currently not supported!");
                    return nullptr;
                }
            case RendererAPI::eOpenGL:
                return new COpenGLIndexBuffer(indices,count);
        }

        AT_ASSERT(false,"Unknown RendererAPI!!!");
        return nullptr;

    }
}
