#pragma once

#include "Event.h"

#include <sstream>

namespace Atlas
{
   class ATLAS_API CWindowResizeEvent : public CEvent
   {
      public:
         CWindowResizeEvent(unsigned int unwidth, unsigned int unheight) : m_unWidth(unwidth), m_unHeight(unheight) {}

         inline unsigned int GetWidth() const { return m_unWidth; }
         inline unsigned int GetHeight() const { return m_unHeight; }

         std::string ToString() const override
         {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_unWidth << ", " << m_unHeight;
            return ss.str();
         }

         EVENT_CLASS_TYPE(WindowResize);
         EVENT_CLASS_CATEGORY(EventCategoryApplication);
      private:
         unsigned int m_unWidth, m_unHeight;
   };

   class ATLAS_API CWindowCloseEvent : public CEvent
   {
      public:
         CWindowCloseEvent() {};

         EVENT_CLASS_TYPE(WindowClose)
         EVENT_CLASS_CATEGORY(EventCategoryApplication)
   };
}