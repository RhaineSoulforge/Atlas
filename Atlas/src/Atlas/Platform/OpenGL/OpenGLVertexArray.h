#pragma once

#include "Atlas/Renderer/VertexArray.h"

namespace Atlas
{
    class COpenGLVertexArray : public CVertexArray
    {
        public:
        private:
            uint32_t m_RendererID;
            std::vector<std::shared_ptr<CVertexBuffer>> m_VertexBuffers;
            std::shared_ptr<CIndexBuffer> m_IndexBuffer;
    };
}