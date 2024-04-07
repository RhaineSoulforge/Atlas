#pragma once
#include <string>

namespace Atlas
{
    class CShader
    {
        public:
            virtual ~CShader() {}

            virtual void Bind() const = 0;
            virtual void Unbind() const = 0;

            static CShader *Create(const std::string vertexSrc, const std::string fragmentSrc);
    };
}
