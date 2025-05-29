#pragma once

#include <memory>
#include "Atlas/Renderer/Buffer.h"

namespace Atlas
{
    class CVertexArray
    {
        public:
            virtual ~CVertexArray() {}

            virtual void Bind(void) const = 0;
            virtual void Unbind(void) const = 0;

            virtual void AddVertexBuffer(const std::shared_ptr<CVertexBuffer> &vertexBuffer) = 0;
            virtual void SetIndexBuffer(const std::shared_ptr<CIndexBuffer> &indexBuffer) = 0;

            virtual const std::vector<std::shared_ptr<CVertexBuffer>> &GetVertexBuffers(void) const = 0;
            virtual const std::shared_ptr<CIndexBuffer> &GetIndexBuffer(void) const = 0;

            static CVertexArray *Create(void);
        private:
    };
}