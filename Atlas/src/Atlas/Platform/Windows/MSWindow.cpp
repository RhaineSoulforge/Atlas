#include "MSWindow.h"
#include "Atlas/KeyCodes.h"
#include "Atlas/MouseButtonCodes.h"

#include <glad/glad.h>

// There can be only One!!
Atlas::CMSWindow *Atlas::CMSWindow::m_pInstance = 0;

namespace Atlas
{
    CWindow *CWindow::Create(const SWindowProps &props)
    {
        CMSWindow *pWindow = CMSWindow::GetInstance();
        pWindow->Init(props);
        return pWindow;
    }

    CMSWindow::CMSWindow(void)
    {
        ZeroMemory(m_bKeyBuffer,KEYBUFFERSIZE);
        ZeroMemory(m_bMouseBuffer,MOUSEBUFFERSIZE);
        m_MousePosition.first = 0.0f;
        m_MousePosition.second = 0.0f;
    }

    CMSWindow::~CMSWindow(void)
    {
        UnregisterClassA(m_Data.m_sTitle.c_str(),m_Data.m_hInstance);
    }

    void *CMSWindow::GetNativeWindow(void) const
    {
        return (void*)this;
    }

    CMSWindow *CMSWindow::GetInstance(void)
    {
        if(!m_pInstance)
            m_pInstance = new CMSWindow();
        return m_pInstance;
    }

    void CMSWindow::DeleteInstance(void)
    {
        if(m_pInstance)
        {
            delete m_pInstance;
            AT_LOG_TRACE("CMSWindow::DeleteInstance")
        }
    }

    void CMSWindow::Init(const SWindowProps &props)
    {
        m_Data.m_unWidth = props.m_unWidth;
        m_Data.m_unHeight = props.m_unHeight;
        m_Data.m_sTitle = props.m_sTitle;

        m_Data.m_hInstance = GetModuleHandleA(0);

        WNDCLASSA wc;

        wc.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = MsgProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = m_Data.m_hInstance;
        wc.hIcon = LoadIcon(0,IDI_APPLICATION);
        wc.hCursor = LoadCursor(0,IDC_ARROW);
        wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        wc.lpszMenuName = 0;
        wc.lpszClassName = m_Data.m_sTitle.c_str();

        AT_ASSERT(RegisterClassA(&wc) == 0,"Unable to Register Window Class!!!");
        // if(RegisterClassA(&wc) == 0)
        // {
        //     AT_LOG_ERROR("Unable to Register Window class!!!")
        //     return;
        // }

        m_Data.m_hWnd = CreateWindowExA(0,
            m_Data.m_sTitle.c_str(),
            m_Data.m_sTitle.c_str(),
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            (GetSystemMetrics(SM_CXSCREEN) >> 1) - (m_Data.m_unWidth >> 1),
            (GetSystemMetrics(SM_CYSCREEN) >> 1) - (m_Data.m_unHeight >> 1),
            m_Data.m_unWidth,
            m_Data.m_unHeight,
            0,
            0,
            m_Data.m_hInstance,
            this);

        AT_ASSERT(m_Data.m_hWnd == 0,"Failed to create Window!!!");
        // if(m_Data.m_hWnd == 0)
        // {
        //     AT_LOG_ERROR("Failed to create Window!!!")
        //     return;
        // }
        
        AT_LOG_INFO("Created window Titled {s}:  {u}x{u}, VSync({b})",m_Data.m_sTitle,m_Data.m_unWidth,m_Data.m_unHeight,m_Data.m_bVSync)
    }

    void CMSWindow::Shutdown(void)
    {
        CMSWindow::DeleteInstance();
    }

    void CMSWindow::OnUpdate(void)
    {
        MSG message;
        ZeroMemory(&message,sizeof(MSG));

        if(PeekMessageA(&message,0,0,0,PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
    }

    LRESULT CALLBACK CMSWindow::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        CMSWindow *pWindow = CMSWindow::GetInstance();
        PAINTSTRUCT ps;
        HDC hdc;

        switch(msg)
        {
            case WM_CREATE:
                return 0;
            case WM_SIZE:            
            {
                Atlas::CWindowResizeEvent e(LOWORD(lParam),HIWORD(lParam));
                pWindow->m_Data.m_unWidth = LOWORD(lParam);
                pWindow->m_Data.m_unHeight = HIWORD(lParam);
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);
                return 0;
            }
            case WM_CLOSE:
            {
                Atlas::CWindowCloseEvent e;
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);
                return 0;
            }
            case WM_DESTROY:
            {
                PostQuitMessage(0);
                return 0;
            }
            case WM_SETFOCUS:
            {
                //TODO:  Implement behaivor on window gaining focus.
                return 0;
            }
            case WM_KILLFOCUS:
            {
                //TODO:  Implement behaivor on window losing focus.
                return 0;
            }
            case WM_KEYUP:
            {
                Atlas::CKeyReleasedEvent e(wParam);
                pWindow->SetKeyState(wParam,false);
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);
                return 0;
            }
            case WM_KEYDOWN:
            {
                Atlas::CKeyPressedEvent e(wParam,1);
                pWindow->SetKeyState(wParam,true);
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);                
                return 0;
            }
            case WM_MOUSEMOVE:
            {
                Atlas::CMouseMovedEvent e(LOWORD(lParam),HIWORD(lParam));
                pWindow->SetMousePosition(std::pair<float,float>(LOWORD(lParam), HIWORD(lParam)));
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);
                return 0;
            }
            case WM_MOUSEWHEEL:
            {
                Atlas::CMouseScrolledEvent e(0,GET_WHEEL_DELTA_WPARAM(wParam));
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);
                return 0;
            }
            case WM_LBUTTONDOWN:
            {
                Atlas::CMouseButtonPressedEvent e(AT_LBUTTON);
                pWindow->SetMouseButtonState(AT_LBUTTON,true);
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);
            } return 0;
            case WM_MBUTTONDOWN:
            {
                Atlas::CMouseButtonPressedEvent e(AT_MBUTTON);
                pWindow->SetMouseButtonState(AT_MBUTTON,true);
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);
            } return 0;
            case WM_RBUTTONDOWN:
            {
                Atlas::CMouseButtonPressedEvent e(AT_RBUTTON);
                pWindow->SetMouseButtonState(AT_RBUTTON,true);
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);
            } return 0;
            case WM_LBUTTONUP:
            {
                Atlas::CMouseButtonReleasedEvent e(AT_LBUTTON);
                pWindow->SetMouseButtonState(AT_LBUTTON,false);
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);
            } return 0;
            case WM_MBUTTONUP:
            {
                Atlas::CMouseButtonReleasedEvent e(AT_MBUTTON);
                pWindow->SetMouseButtonState(AT_MBUTTON,false);
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);                
            } return 0;
            case WM_RBUTTONUP:
            {
                Atlas::CMouseButtonReleasedEvent e(AT_RBUTTON);
                pWindow->SetMouseButtonState(AT_RBUTTON,false);
                if(pWindow->m_Data.m_EventCallback)
                    pWindow->m_Data.m_EventCallback(e);                
            } return 0;
            default:
                break;
        };

        return DefWindowProc(hWnd,msg,wParam,lParam);
    }
}