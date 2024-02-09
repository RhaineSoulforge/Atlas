#pragma once

#include "Atlas/Core.h"
#include "Atlas/Events/Event.h"

namespace Atlas
{
   class ATLAS_API CLayer
   {
      public:
         CLayer(const std::string& name);
         virtual ~CLayer();

         virtual void OnAttach() {}
         virtual void OnDeattch() {}
         virtual void OnUpdate() {}
         virtual void OnEvent(CEvent &event) {}

         inline const std::string& getName() { return m_sDebugName; }
      protected:
         std::string m_sDebugName;
   };
}