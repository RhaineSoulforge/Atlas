#pragma once

namespace Atlas
{
    enum class eRendererAPI
    {
        None = 0, OpenGL = 1
    };

    class CRenderer
    {
        public:
            inline static eRendererAPI GetAPI(void) { return s_RendererAPI; }
        private:
            static eRendererAPI s_RendererAPI;
    }
}