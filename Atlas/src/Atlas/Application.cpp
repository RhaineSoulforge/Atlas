#include "atpch.h"
#include "Application.h"

namespace Atlas
{
#define BIND_EVENT_FN(x) std::bind(&CApplication::x, this, std::placeholders::_1)

    CApplication::CApplication()
    {
        m_pWindow = CWindow::Create();
        m_pWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    CApplication::~CApplication()
    {
        m_pWindow->Shutdown();
    }

    void CApplication::OnEvent(CEvent &e)
    {
        CEventDispatcher dispatcher(e);
        
        AT_LOG_TRACE("{s}",e.ToString().c_str())
    }

    void CApplication::Run()
    {
        AT_LOG_INFO("Atlas GE version Alpha online....")
        while(m_bRunning)
        {
            m_pWindow->OnUpdate();
        }
    }
}