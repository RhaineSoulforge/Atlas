#include "atpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "../Platform/OpenGL/OpenGLBuffer.h"

namespace Atlas
{
    CVertexBuffer *CVertexBuffer::Create(float *vertices, uint32_t size)
    {
        switch(CRenderer::GetAPI())
        {
            case eRendererAPI::None:
            {
                AT_LOG_ERROR("[CVertexBuffer]  eRendererAPI::None currently not supported!");
                return 0;
            } break;
            case eRendererAPI::OpenGL:
            {
                return new COpenGLVertexBuffer(vertices,size);
            } break;
        }

        AT_LOG_ERROR("[CVertexBuffer]  Unknown Renderer API!!!");
        return 0;
    }

    CIndexBuffer *CIndexBuffer::Create(uint32_t *indices, uint32_t size)
    {
        switch(CRenderer::GetAPI())
        {
            case eRendererAPI::None:
            {
                AT_LOG_ERROR("[CIndexBuffer]  eRendererAPI::None currently not supported!");
                return 0;
            } break;
            case eRendererAPI::OpenGL:
            {
                return new COpenGLIndexBuffer(indices,size);
            } break;
        }

        AT_LOG_ERROR("[CIndexBuffer]  Unknow Renderer API!!!")
        return 0;
    }
}