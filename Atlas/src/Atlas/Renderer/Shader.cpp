#include "atpch.h"
#include "Shader.h"
#include "Atlas/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Atlas
{
    CShader *CShader::Create(const std::string vertexSrc, const std::string fragmentSrc)
    {
        switch(CRenderer::GetAPI())
        {
            case RendererAPI::eNone:
            {
                AT_ASSERT(false,"RendererAPI::eNone not supported at this time!!!");
                return nullptr;
            }
            case RendererAPI::eOpenGL:
                return new COpenGLShader(vertexSrc,fragmentSrc);
        }
        
        AT_ASSERT(false,"Unknown RendererAPI!!!");
        return nullptr;
    }
}
