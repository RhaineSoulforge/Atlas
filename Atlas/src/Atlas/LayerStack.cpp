#include "atpch.h"
#include "LayerStack.h"

namespace Atlas
{
    CLayerStack::CLayerStack(void)
    {
        m_LayerInsert = m_Layers.begin();
    }

    CLayerStack::~CLayerStack(void)
    {
        for(CLayer *layer : m_Layers)
            delete layer;
    }

    void CLayerStack::PushLayer(CLayer *layer)
    {
        m_LayerInsert = m_Layers.emplace(m_LayerInsert,layer);
        layer->OnAttach();
    }

    void CLayerStack::PushOverLay(CLayer *overlay)
    {
        m_Layers.emplace_back(overlay);
        overlay->OnAttach();
    }

    void CLayerStack::PopLayer(CLayer *layer)
    {
        auto it = std::find(m_Layers.begin(),m_Layers.end(),layer);
        if(it != m_Layers.end())
        {
            m_Layers.erase(it);
            m_LayerInsert--;
            layer->OnDetach();
        }
    }

    void CLayerStack::PopOverlay(CLayer *overlay)
    {
        auto it = std::find(m_Layers.begin(),m_Layers.end(),overlay);
        if(it != m_Layers.end())
        {
            m_Layers.erase(it);
            overlay->OnDetach();
        }
    }
}