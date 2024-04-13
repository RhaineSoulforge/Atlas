#pragma once

#include "Atlas/Renderer/VertexArray.h"

namespace Atlas
{
    class COpenGLVertexArray : public CVertexArray
    {
        public:
            COpenGLVertexArray();
            virtual ~COpenGLVertexArray();

            virtual void Bind(void) const override;
            virtual void Unbind(void) const override;

            virtual void AddVertexBuffer(const std::shared_ptr<CVertexBuffer> &pVertexBuffer) override;
            virtual void SetIndexBuffer(const std::shared_ptr<CIndexBuffer> &pIndexBuffer) override;

            virtual const std::vector<std::shared_ptr<CVertexBuffer>> &GetVertexBuffers(void) override { return m_vVertexBuffers; }
            virtual const std::shared_ptr<CIndexBuffer> GetIndexBuffer(void) { return m_pIndexBuffer; }
        private:
            uint32_t m_unRendererID;
            std::vector<std::shared_ptr<CVertexBuffer>> m_vVertexBuffers;
            std::shared_ptr<CIndexBuffer> m_pIndexBuffer;
    };

}
