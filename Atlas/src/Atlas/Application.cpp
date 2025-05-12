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

    void CApplication::PushLayer(CLayer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void CApplication::PushOverlay(CLayer *layer)
    {
        m_LayerStack.PushOverLay(layer);
    }

    void CApplication::OnEvent(CEvent &e)
    {
        CEventDispatcher dispatcher(e);

        dispatcher.Dispatch<CWindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        
        //AT_LOG_TRACE("{s}",e.ToString().c_str())

        for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if(e.m_Handled)
                break;
        }
    }

    bool CApplication::OnWindowClose(CWindowCloseEvent &e)
    {
        m_bRunning = false;
        return true;
    }

    void CApplication::Run()
    {
        AT_LOG_INFO("Atlas GE version Alpha online....")
        while(m_bRunning)
        {
            for(CLayer *layer : m_LayerStack)
                layer->OnUpdate();

            m_pWindow->OnUpdate();
        }
    }
}