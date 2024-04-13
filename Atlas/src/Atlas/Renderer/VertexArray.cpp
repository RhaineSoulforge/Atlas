#include "atpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Atlas
{
    CVertexArray *CVertexArray::Create(void)
    {
        switch(CRenderer::GetAPI())
        {
            case RendererAPI::eNone:
                {
                    AT_ASSERT(false,"eNone currently not supported!");
                    return nullptr;
                }
            case RendererAPI::eOpenGL:
                return new COpenGLVertexArray();
        }

        AT_ASSERT(false,"Unknown RendererAPI!!!");
        return nullptr;
    }
}
