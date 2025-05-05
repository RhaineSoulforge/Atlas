#pragma once

#include "Atlas/Core.h"
#include "Atlas/Events/Event.h"

namespace Atlas
{
    class CLayer
    {
        public:
            CLayer(const std::string &name = "Layer");
            virtual ~CLayer(void);

            virtual void OnAttach(void) {}
            virtual void OnDetach(void) {}
            virtual void OnUpdate(void) {}
            virtual void OnEvent(CEvent &event) {}

            inline const std::string GetName(void) const { return m_DebugName; }
        protected:
            std::string m_DebugName;
    };
}