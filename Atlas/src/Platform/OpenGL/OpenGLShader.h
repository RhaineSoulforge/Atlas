#pragma once
#include "Atlas/Renderer/Shader.h"

namespace Atlas
{
    class COpenGLShader : public CShader
    {
        public:
            COpenGLShader(const std::string vertexSrc, const std::string fragmentSrc);
            virtual ~COpenGLShader();

            virtual void Bind() const;
            virtual void Unbind() const;
        private:
            uint32_t m_unRendererID;
    };
}
