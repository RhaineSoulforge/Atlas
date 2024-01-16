#pragma once

#include "Event.h"

namespace Atlas
{
   class ATLAS_API CKeyEvent : public CEvent
   {
      public:
         inline int GetKeyCode() const { return m_nKeyCode; }

         EVENT_CLASS_CATEGORY(eEventCategory::EventCategoryKeyboard | eEventCategory::EventCategoryInput)

      protected:
         CKeyEvent(int nkeycode) : m_nKeyCode(nkeycode) {}

         int m_nKeyCode;
   };

   class ATLAS_API CKeyPressedEvent : public CKeyEvent
   {
      public:
         CKeyPressedEvent(int nkeycode, int nrepeatcount) : CKeyEvent(nkeycode), m_nRepeatCount(nrepeatcount) {}

         inline int GetRepeatCount() const { return m_nRepeatCount; }

         std::string ToString() const override
         {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_nKeyCode <<" (" << m_nRepeatCount << " repeats)";
            return ss.str();
         }

         EVENT_CLASS_TYPE(KeyPressed)
      protected:
         int m_nRepeatCount;
   };

   class ATLAS_API CKeyReleasedEvent : public CKeyEvent
   {
      public:
         CKeyReleasedEvent(int nkeycode) : CKeyEvent(nkeycode) {}

         std::string ToString() const override
         {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_nKeyCode;
            return ss.str();
         }

         EVENT_CLASS_TYPE(KeyReleased);
   };
}