#pragma once

#include "../Core.h"

#include <string>
#include <functional>

namespace Atlas
{
   enum class eEventType
   {
      None = 0,
      WindowClose,WindowResize,WindowFocus,WindowLostFocus,WindowMoved,
      Tick,Update,Render,
      KeyPressed,KeyReleased,
      MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled
   };

   enum eEventCategory
   {
      None = 0,
      EventCategoryApplication   = BIT(0),
      EventCategoryInput         = BIT(1),
      EventCategoryKeyboard      = BIT(2),
      EventCategoryMouse         = BIT(3),
      EventCategoryMouseButton   = BIT(4)
   };

#define EVENT_CLASS_TYPE(type) static eEventType GetStaticType() { return eEventType::##type; }\
                               virtual eEventType GetEventType() const override { return GetStaticType(); }\
                               virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

   class ATLAS_API CEvent
   {
         friend class CEventDispatcher;
      public:
         virtual eEventType GetEventType() const = 0;
         virtual const char* GetName() const = 0;
         virtual int GetCategoryFlags() const = 0;
         virtual std::string ToString() const { return GetName(); }

         inline bool isInCategory(eEventCategory category)
         {
            return CHECK_BIT(GetCategoryFlags(), category);
         }
      protected:
         bool m_bHandled = false;
   };

   class CEventDispatcher
   {
      template<typename T>
      using EventFn = std::function<bool(T&)>;

      public:
         CEventDispatcher(CEvent& event) : m_Event(event) {}

         template<typename T>
         bool Dispatch(EventFn<T> func)
         {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
               m_Event.m_bHandled = func(*(T*)&m_Event);
               return true;
            }
            return false;
         }
      private:
         CEvent& m_Event;
   };

   inline std::ostream& operator<<(std::ostream& os, const CEvent& e)   
   {
      return os << e.ToString();
   }
}