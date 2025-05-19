#include "atpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GL/GL.h>

#ifdef AT_PLATFORM_WINDOWS
    #include "Atlas\Platform\Windows\MSWindow.h"
#endif

namespace Atlas
{
    COpenGLContext::COpenGLContext(void)
    {

    }

    void COpenGLContext::Init(void)
    {
        #ifdef AT_PLATFORM_WINDOWS
            CMSWindow *pWindow = CMSWindow::GetInstance();

            PIXELFORMATDESCRIPTOR pfd = 
            {
                sizeof(PIXELFORMATDESCRIPTOR),
                1,
                PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
                PFD_TYPE_RGBA,
                32,
                0, 0, 0, 0, 0, 0,
                0,
                0,
                0,
                0, 0, 0, 0,
                24,
                8,
                0,
                PFD_MAIN_PLANE,
                0,
                0, 0, 0
            };

            HDC ourDC = GetDC(pWindow->GetHandle());

            int pixelformat;
            pixelformat = ChoosePixelFormat(ourDC,&pfd);
            SetPixelFormat(ourDC,pixelformat,&pfd);

            HGLRC ourOGLContext = wglCreateContext(ourDC);
            wglMakeCurrent(ourDC,ourOGLContext);
        #endif

        int result = gladLoadGL();
        AT_ASSERT(!result,"Failed to initialize GLAD!")

        AT_LOG_INFO("Initializing OpenGL:")
        AT_LOG_INFO("\tVendor: {s}",glGetString(GL_VENDOR))
        AT_LOG_INFO("\tRenderer: {s}",glGetString(GL_RENDERER))
        AT_LOG_INFO("\tVersion: {s}",glGetString(GL_VERSION))
    }

    void COpenGLContext::SwapBuffer(void)
    {
        glFlush();
        #ifdef AT_PLATFORM_WINDOWS
            CMSWindow *pWindow = CMSWindow::GetInstance();
            SwapBuffers(GetDC(pWindow->GetHandle()));
        #endif
    }
}