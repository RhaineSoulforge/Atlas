#pragma once

#include "Atlas/Core.h"
#include "Layer.h"

#include <vector>

namespace Atlas
{
   class ATLAS_API CLayerStack
   {
      public:
         CLayerStack();  // Constructor
         ~CLayerStack(); // Destructor

         void PushLayer(CLayer* layer);  // Pushes layer onto stack.
         void PushOverlay(CLayer* overlay); // Push overlay onto stack.
         void PopLayer(CLayer* layer);  // Removes layer from stack.
         void PopOverlay(CLayer* overlay);  // Remove overlay from stack.

         std::vector<CLayer*>::iterator begin() { return m_vecLayers.begin(); }  // Returns iterator to beginning of LayerStack.
         std::vector<CLayer*>::iterator end() { return m_vecLayers.end(); }  // Returns iterator to end of LayerStack.

      private:
         std::vector<CLayer*>             m_vecLayers;  // Our LayerStack
         std::vector<CLayer*>::iterator   m_iterLayerInsert;  // Iterator to current insert position.
   };
}