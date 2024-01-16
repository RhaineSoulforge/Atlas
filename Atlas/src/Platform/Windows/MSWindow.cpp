#include "atpch.h"
#include "MSWindow.h"

namespace Atlas
{
   CWindow* CWindow::Create(const SWindowProps& props)
   {
      return new CMSWindow(props);
   }

   CMSWindow::CMSWindow(const SWindowProps& props)
   {
      Init(props);
   }

   CMSWindow::~CMSWindow()
   {
      Shutdown();
   }

   void CMSWindow::Init(const SWindowProps& props)
   {
      m_wdData.m_sTitle = props.m_sTitle;
      m_wdData.m_unWidth = props.m_unWidth;
      m_wdData.m_unHeight = props.m_unHeight;

      GetModuleHandleExW(0, nullptr, &m_wdData.m_hInstance);

      std::wstring wsTitle = std::wstring(m_wdData.m_sTitle.begin(), m_wdData.m_sTitle.end());
      WNDCLASSEXW wc;

      wc.cbSize = sizeof(WNDCLASSEXW);
      wc.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
      wc.lpfnWndProc = MsgProc;
      wc.cbClsExtra = 0;
      wc.cbWndExtra = 0;
      wc.hInstance = m_wdData.m_hInstance;
      wc.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
      wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
      wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
      wc.lpszMenuName = nullptr;
      wc.lpszClassName = wsTitle.c_str();
      wc.hIconSm = nullptr;

      if (RegisterClassExW(&wc) == 0)
      {
         AT_LOG_ERROR("Failed to register Window class!!")
            return;
      }

      m_wdData.m_hwnd = CreateWindowExW(0,  // Extended Window style flags
         wsTitle.c_str(), // Window class name
         wsTitle.c_str(), // Window name
         WS_OVERLAPPEDWINDOW | WS_VISIBLE, // Window style flags for Window.
         (GetSystemMetrics(SM_CXSCREEN) >> 1) - (m_wdData.m_unWidth >> 1),  // X value of Top Left of our Window.
         (GetSystemMetrics(SM_CYSCREEN) >> 1) - (m_wdData.m_unHeight >> 1), // Y value of Top Left of our Window.
         m_wdData.m_unWidth, // Width of our Window.
         m_wdData.m_unHeight, // Height of our Window.
         nullptr,  // Window handle of our parent(Null if we are the parent).
         nullptr, // Handle to the Menu for this Window.
         m_wdData.m_hInstance,  // Handle to the module assciated with this Window.
         this);  // Pointer passed into CREATEWINDOW call.

      if (m_wdData.m_hwnd == NULL)
      {
         AT_LOG_ERROR("Failed to create Window!");
         return;
      }

      AT_LOG_INFO("Window Created using: {s} {u}x{u}", m_wdData.m_sTitle.c_str(), m_wdData.m_unWidth, m_wdData.m_unHeight);

      SetVSync(false);
   }

   void CMSWindow::Shutdown(void)
   {
      std::wstring wsTitle = std::wstring(m_wdData.m_sTitle.begin(), m_wdData.m_sTitle.end());
      UnregisterClassW(wsTitle.c_str(), m_wdData.m_hInstance);
   }

   void CMSWindow::OnUpdate(void)
   {
      MSG message;
      ZeroMemory(&message, sizeof(MSG));

      if (PeekMessageW(&message, nullptr, 0, 0, PM_REMOVE))
      {
         TranslateMessage(&message);
         DispatchMessageW(&message);
      }
   }

   void CMSWindow::SetVSync(bool bEnabled)
   {
      m_wdData.m_bVSync = bEnabled;
   }

   bool CMSWindow::IsVSync() const
   {
      return m_wdData.m_bVSync;
   }

   LRESULT CALLBACK CMSWindow::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
   {
      CMSWindow* pWindow;
      pWindow = (CMSWindow*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
      PAINTSTRUCT ps;
      HDC hDeviceContext;

      switch (msg)
      {
         case WM_CREATE:
         {
            CREATESTRUCTW* pcs = (CREATESTRUCTW*)lParam;
            CMSWindow* pWindow = (CMSWindow*)pcs->lpCreateParams;
            SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pWindow);
            return 0;
         }
         case WM_PAINT:
         {
            hDeviceContext = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
            return 0;
         }
         case WM_SIZE:
         {
            Atlas::CWindowResizeEvent e(LOWORD(lParam), HIWORD(lParam));
            pWindow->m_wdData.m_unWidth = LOWORD(lParam);
            pWindow->m_wdData.m_unHeight = HIWORD(lParam);
            if (pWindow->m_wdData.m_EventCallback)
               pWindow->m_wdData.m_EventCallback(e);
            return 0;
         }
         case WM_CLOSE:
         {
            Atlas::CWindowCloseEvent e;
            if (pWindow->m_wdData.m_EventCallback)
               pWindow->m_wdData.m_EventCallback(e);
            return 0;
         }
         case WM_DESTROY:
         {
            PostQuitMessage(0);
            return 0;
         }
         case WM_KEYDOWN:
         {
            Atlas::CKeyPressedEvent e(wParam,1);
            if (pWindow->m_wdData.m_EventCallback)
               pWindow->m_wdData.m_EventCallback(e);
            return 0;
         }
         case WM_KEYUP:
         {
            Atlas::CKeyReleasedEvent e(wParam);
            if (pWindow->m_wdData.m_EventCallback)
               pWindow->m_wdData.m_EventCallback(e);
            return 0;
         }
         case WM_MOUSEMOVE:
         {
            Atlas::CMouseMovedEvent e(LOWORD(lParam), HIWORD(lParam));
            if (pWindow->m_wdData.m_EventCallback)
               pWindow->m_wdData.m_EventCallback(e);
            return 0;
         }
         case WM_MOUSEWHEEL:
         {
            Atlas::CMouseScrolledEvent e(0, GET_WHEEL_DELTA_WPARAM(wParam));
            if (pWindow->m_wdData.m_EventCallback)
               pWindow->m_wdData.m_EventCallback(e);
            return 0;
         }
         default:
            break;
      }

      return DefWindowProc(hWnd, msg, wParam, lParam);
   }
}