#pragma once

#include "Atlas/Renderer/GraphicsContext.h"

struct HWND__;
typedef HWND__* HWND;

namespace Atlas
{
    class COpenGLContext : public CGraphicsContext
    {
        public:
            COpenGLContext(HWND hWnd);

            virtual void Init(void) override;
            virtual void SwapBuffer(void) override;
        private:
            HWND m_hWnd;
    };
}
