#include "atpch.h"
#include "Application.h"

namespace Atlas
{
    CApplication::CApplication()
    {
        m_pWindow = CWindow::Create();
    }

    CApplication::~CApplication()
    {
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