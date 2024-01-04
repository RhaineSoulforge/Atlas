#pragma once

#include "Event.h"

namespace Atlas
{
   class ATLAS_API CMouseMovedEvent : public CEvent
   {
      public:
         CMouseMovedEvent(float x, float y) : m_fX(x),m_fY(y) {}

         inline float GetX() const { return m_fX; }
         inline float GetY() const { return m_fY; }

         std::string ToString() const override
         {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_fX << ", " << m_fY << m_fY;
            return ss.str();
         }

         EVENT_CLASS_TYPE(MouseMoved)
         EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

      private:
         float m_fX, m_fY;
   };

   class ATLAS_API CMouseScrolledEvent : public CEvent
   {
      public:
         CMouseScrolledEvent(float fXoffset, float fYoffset)
            : m_fXOffset(fXoffset), m_fYOffset(fYoffset) {}

         inline float GetXOffset() const { return m_fXOffset; }
         inline float GetYOffset() const { return m_fYOffset; }

         std::string ToString() const override
         {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset << ", " << GetYOffset();
            return ss.str();
         }

         EVENT_CLASS_TYPE(MouseScrolled)
         EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

      private:
         float m_fXOffset, m_fYOffset;
   };

   class ATLAS_API CMouseButtonEvent : public CEvent
   {
      public:
         inline int GetMouseButton() const { return m_nButton; }

         EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
      
      protected:
         CMouseButtonEvent(int nButton) : m_nButton(nButton) {}
         int m_nButton;
   };

   class ATLAS_API CMouseButtonPressedEvent : public CMouseButtonEvent
   {
      public:
         CMouseButtonPressedEvent(int nButton) : CMouseButtonEvent(nButton) {}

         std::string ToString() const override
         {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_nButton;
            return ss.str();
         }

         EVENT_CLASS_TYPE(MouseButtonPressed)
   };

   class ATLAS_API CMouseButtonReleasedEvent : public CMouseButtonEvent
   {
   public:
      CMouseButtonReleasedEvent(int nButton) : CMouseButtonEvent(nButton) {}

      std::string ToString()const override
      {
         std::stringstream ss;
         ss << "MouseButtonReleasedEvent: " << m_nButton;
         return ss.str();
      }

      EVENT_CLASS_TYPE(MouseButtonReleased)
   };
}