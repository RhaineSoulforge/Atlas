#pragma once

#include "Atlas/Renderer/GraphicsContext.h"

namespace Atlas
{
    class COpenGLContext : public CGraphicsContext
    {
        public:
            COpenGLContext(void);

            virtual void Init(void) override;
            virtual void SwapBuffer(void) override;
        private:
    };
}