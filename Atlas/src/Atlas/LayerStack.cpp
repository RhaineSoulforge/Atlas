#include "atpch.h"
#include "LayerStack.h"

namespace Atlas
{
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // Function: CLayerStack
   // Last Modified:  February 9th, 2024
   // Author:  Jason A Biddle
   //
   // Purpose:  Constructor for CLayerStack
   //
   // In:  None
   //
   // Out:  None
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   CLayerStack::CLayerStack()
   {
      m_iterLayerInsert = m_vecLayers.begin();  // Set to beginning of Stack.
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // Function: ~CLayerStack
   // Last Modified:  February 9th, 2024
   // Author:  Jason A Biddle
   //
   // Purpose:  Destructor for CLayerStack
   //
   // In:  None
   //
   // Out:  None
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   CLayerStack::~CLayerStack()
   {
      int size = static_cast<int>(m_vecLayers.size());  // # of Layers/Overlays to be deleted.
      for (int i = 0; i < size; i++)
         delete m_vecLayers[i];  // Deletes Layer/Overlay.
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // Function: PushLayer
   // Last Modified:  February 9th, 2024
   // Author:  Jason A Biddle
   //
   // Purpose:  Push the given Layer onto the Stack.
   //
   // In:  layer - The Layer to be added to the stack.
   //
   // Out:  None
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void CLayerStack::PushLayer(CLayer* layer)
   {
      // Inserts Layer into front half of the Stack.
      m_iterLayerInsert = m_vecLayers.emplace(m_iterLayerInsert, layer);
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // Function: PushOverLay
   // Last Modified:  February 9th, 2024
   // Author:  Jason A Biddle
   //
   // Purpose:  Pushes the desired Overlay onto the Stack.
   //
   // In:  overlay - The Overlay to be added to the Stack.
   //
   // Out:  None
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void CLayerStack::PushOverlay(CLayer* overlay)
   {
      // Inserts Overlay into back of Stack.
      m_vecLayers.emplace_back(overlay);
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // Function: PopLayer
   // Last Modified:  February 9th, 2024
   // Author:  Jason A Biddle
   //
   // Purpose:  Removes given Layer from Stack.
   //
   // In:  layer - The Layer to be removed.
   //
   // Out:  None
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void CLayerStack::PopLayer(CLayer* layer)
   {
      // Finds location of Layer within stack.
      auto iter = std::find(m_vecLayers.begin(), m_vecLayers.end(), layer);
      if (iter != m_vecLayers.end())
      {
         m_vecLayers.erase(iter);  // Removes Layer from stack.
         m_iterLayerInsert--;  // Decrement Insert iterator.
      }
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // Function: PopOverlay
   // Last Modified:  February 9th, 2024
   // Author:  Jason A Biddle
   //
   // Purpose:  Removes given Overlay from Stack.
   //
   // In:  overlay - The Overlay to be removed.
   //
   // Out:  None
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void CLayerStack::PopOverlay(CLayer* overlay)
   {
      // Finds location of Overlay within Stack.
      auto iter = std::find(m_vecLayers.begin(), m_vecLayers.end(), overlay);
      if (iter != m_vecLayers.end())
         m_vecLayers.erase(iter);  // Removes Overlay from Stack.
   }
}