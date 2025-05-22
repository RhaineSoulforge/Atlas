#pragma once

namespace Atlas
{
    class CVertexBuffer
    {
        public:
            virtual ~CVertexBuffer(void) {}

            virtual void Bind(void) const = 0;
            virtual void Unbind(void) const = 0;

            static CVertexBuffer *Create(float *vertices, uint32_t size);
        private:
    };

    class CIndexBuffer
    {
        public:
            virtual ~CIndexBuffer(void) {}

            virtual void Bind(void) = 0;
            virtual void Unbind(void) = 0;

            virtual uint32_t GetCount() const = 0;

            static CIndexBuffer *Create(uint32_t *indices, uint32_t size);
        private:
    };
}