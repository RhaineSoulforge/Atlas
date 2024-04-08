#pragma once

namespace Atlas
{
    class CVertexBuffer
    {
        public:
            virtual ~CVertexBuffer() {}

            virtual void Bind(void) const = 0;
            virtual void Unbind(void) const = 0;

            static CVertexBuffer *Create(float *vertices, uint32_t size);
    };

    class CIndexBuffer
    {
        public:
            virtual ~CIndexBuffer() {}

            virtual void Bind(void) const = 0;
            virtual void Unbind(void) const = 0;

            virtual uint32_t GetCount(void) const = 0;

            static CIndexBuffer *Create(uint32_t *indicies, uint32_t count);
    };
}
