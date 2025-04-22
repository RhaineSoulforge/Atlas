#pragma once

#include "atpch.h"
#include "Atlas/Core.h"

namespace Atlas
{
    enum class eEventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum eEventCategory
    {
        None = 0,
        EventCategoryApplication = 2,
        EventCategoryInput = 4,
        EventCategoryKeyboard = 8,
        EventCategoryMouse = 16,
        EventCategoryMouseButton = 32
    };

    #define EVENT_CLASS_TYPE(type) static eEventType GetStaticType(void) { return eEventType::##type; }\
                                    virtual eEventType GetEventType(void) const override { return GetStaticType(); }\
                                    virtual const char *GetName(void) const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtural int GetCategoryFlags(void) const override { return category; }

    class CEvent
    {
        friend class CEventDispatcher;
        public:
            virtual eEventType GetEventType(void) const = 0;
            virtual const char *GetName(void) const = 0;
            virtual int GetCategoryFlags(void) const = 0;
            virtual std::string ToString(void) const { return GetName(); }

            inline bool IsInCategory(eEventCategory category)
            {
                return GetCategoryFlags() & category;
            }

        protected:
            bool m_Handled = false;
    };

    class CEventDispatcher
    {
        public:
            CEventDispatcher(CEvent &event) : m_Event(event) {}

            template<typename T, typename F>
            bool Dispatch(const F &func)
            {
                if(m_Event.GetEventType() == T::GetStaticType())
                {
                    m_Event.m_Handled = func(static_cast<T&>(m_Event));
                    return true;
                }

                return false;
            }
        private:
            CEvent &m_Event;
    };

    inline std::ostream &operator<<(std::ostream &out, const CEvent &e)
    {
        return out << e.ToString();
    }
}