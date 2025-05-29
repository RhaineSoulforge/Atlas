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
            case eRendererAPI::None: AT_ASSERT(true,"eRendererAPI::None currently not supported!"); return 0;
            case eRendererAPI::OpenGL: return new COpenGLVertexArray();
        }

        AT_ASSERT(true,"Unknown RendererAPI");
        return 0;
    }
}