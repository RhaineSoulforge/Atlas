#pragma once
#include "Atlas/Renderer/Buffer.h"

namespace Atlas
{
    class COpenGLVertexBuffer : public CVertexBuffer
    {
        public:
            COpenGLVertexBuffer(float *vertices, uint32_t size);
            virtual ~COpenGLVertexBuffer(void);

            virtual void Bind(void) const;
            virtual void Unbind(void) const;

            virtual const CBufferLayout &GetLayout(void) const override { return m_blLayout; }
            virtual void SetLayout(const CBufferLayout &layout) override { m_blLayout = layout; }
        private:
            uint32_t m_unRendererID;
            CBufferLayout m_blLayout;
    };

    class COpenGLIndexBuffer : public CIndexBuffer
    {
       public:
          COpenGLIndexBuffer(uint32_t* indices, uint32_t count);
          ~COpenGLIndexBuffer(void);

          virtual void Bind(void) const;
          virtual void Unbind(void) const;

          virtual inline uint32_t GetCount(void) const { return m_unCount; }
       private:
          uint32_t m_unRendererID;
          uint32_t m_unCount;
    };

}
