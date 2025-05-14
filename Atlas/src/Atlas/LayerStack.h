#pragma once

#include "Atlas/Core.h"
#include "Layer.h"

#include <vector>

namespace Atlas
{
    class CLayerStack
    {
        public:
            CLayerStack(void);
            ~CLayerStack(void);

            void PushLayer(CLayer *layer);
            void PushOverLay(CLayer *overlay);
            void PopLayer(CLayer *layer);
            void PopOverlay(CLayer *overlay);

            std::vector<CLayer*>::iterator begin() { return m_Layers.begin(); }
            std::vector<CLayer*>::iterator end() { return m_Layers.end(); }
        private:
            std::vector<CLayer*> m_Layers;
            unsigned int m_LayerInsertIndex = 0;
    };
}