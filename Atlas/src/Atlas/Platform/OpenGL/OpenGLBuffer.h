#pragma once

#include "Atlas/Renderer/Buffer.h"

namespace Atlas
{
    class COpenGLVertexBuffer : public CVertexBuffer
    {
        public:
            COpenGLVertexBuffer(float *vertices, uint32_t size);
            virtual ~COpenGLVertexBuffer();

            virtual void Bind(void) const override;
            virtual void Unbind(void) const override;

            virtual const CBufferLayout &GetLayout(void) const override { return m_Layout; }
            virtual void SetLayout(const CBufferLayout &layout) override { m_Layout = layout; }
        private:
            uint32_t m_RendererID;
            CBufferLayout m_Layout;
    };

    class COpenGLIndexBuffer : public CIndexBuffer
    {
        public:
            COpenGLIndexBuffer(uint32_t *indices, uint32_t count);
            virtual ~COpenGLIndexBuffer(void);

            virtual void Bind(void) const;
            virtual void Unbind(void) const;

            virtual uint32_t GetCount(void) const { return m_Count; }
        private:
            uint32_t m_RendererID;
            uint32_t m_Count;
    };
}