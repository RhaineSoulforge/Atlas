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
        private:
            uint32_t m_unRendererID;
    };
}
