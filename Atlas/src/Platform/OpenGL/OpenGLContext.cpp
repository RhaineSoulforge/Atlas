#include "atpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>

namespace Atlas
{
    COpenGLContext::COpenGLContext(HWND hWnd)
        :m_hWnd(hWnd)
    {
    }

    void COpenGLContext::Init(void)
    {
        //Opengl setup!                                                         
        PIXELFORMATDESCRIPTOR pfd =
        {                                                                       
           sizeof(PIXELFORMATDESCRIPTOR),  //Size                               
           1,  //Version                                                        
           PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, //Flags  
           PFD_TYPE_RGBA, //Pixeltype                                           
           32, // ColorBits
           0, 0, 0, 0, 0, 0,
           0,
           0,
           0,
           0, 0, 0, 0,
           24,  //DepthBits
           8,  //stencilDepth
           0,
           PFD_MAIN_PLANE,  //LayerType
           0,
           0, 0, 0
        };
  
        HDC hdc = GetDC(m_hWnd);
  
        int nPixelFormat = ChoosePixelFormat(hdc, &pfd);
        SetPixelFormat(hdc, nPixelFormat, &pfd);
  
        HGLRC oglRC = wglCreateContext(hdc);
        wglMakeCurrent(hdc, oglRC);
  
        int status = gladLoadGL();
        AT_ASSERT(status, "Failed to initialize Glad!!!");
  
        AT_LOG_INFO("openGL online:");
        AT_LOG_INFO("  Vendor: {s}", glGetString(GL_VENDOR));
        AT_LOG_INFO("  Renderer: {s}", glGetString(GL_RENDERER));
        AT_LOG_INFO("  Version: {s}", glGetString(GL_VERSION));
    }

    void COpenGLContext::SwapBuffer(void)
    {
        glFlush();
        SwapBuffers(GetDC(m_hWnd));
    }
}
