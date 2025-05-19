#pragma once

namespace Atlas
{
    class CGraphicsContext
    {
        public:
            virtual void Init(void) = 0;
            virtual void SwapBuffer(void) = 0;
    };
}