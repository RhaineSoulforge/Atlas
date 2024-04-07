
namespace Atlas
{
    enum class RendererAPI
    {
        eNone = 0, eOpenGL = 1
    };

    class CRenderer
    {
        public:
            static inline RendererAPI GetAPI(void) { return sm_RendererAPI; }
        private:
            static RendererAPI sm_RendererAPI;
    };
}
