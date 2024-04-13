#pragma once

#include "Atlas/Renderer/Buffer.h"
#include <vector>
#include <memory>

namespace Atlas
{
    class CVertexArray
    {
        public:
            virtual ~CVertexArray() {}

            virtual void Bind(void) const = 0;
            virtual void Unbind(void) const = 0;

            virtual void AddVertexBuffer(const std::shared_ptr<CVertexBuffer> &pVertexBuffer) = 0;
            virtual void SetIndexBuffer(const std::shared_ptr<CIndexBuffer> &pIndexBuffer) = 0;

            virtual const std::vector<std::shared_ptr<CVertexBuffer>> &GetVertexBuffers(void) = 0;
            virtual const std::shared_ptr<CIndexBuffer> GetIndexBuffer(void) = 0;

            static CVertexArray *Create(void);
    };
}
