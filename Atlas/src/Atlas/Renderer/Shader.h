#pragma once

#include <string>

namespace Atlas
{
    class CShader
    {
        public:
            CShader(const std::string &vertexSrc, const std::string &fragmentSrc);
            ~CShader(void);

            void Bind(void) const;
            void Unbind(void) const;
        private:
            uint32_t m_RendererID;
    };
}