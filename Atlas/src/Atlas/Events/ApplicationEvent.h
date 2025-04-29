#pragma once

#include "Atlas/Events/Event.h"

namespace Atlas
{
    class CWindowResizeEvent : public CEvent
    {
        public:
            CWindowResizeEvent(unsigned int width, unsigned int height) : m_unWidth(width), m_unHeight(height)
            {

            }

            unsigned int GetWidth(void) const { return m_unWidth; }
            unsigned int GetHeight(void) const { return m_unHeight; }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << "WindowResizeEvent: " << m_unWidth << ", " << m_unHeight;
                return ss.str();
            }

            EVENT_CLASS_TYPE(WindowResize)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
        private:
            unsigned int m_unWidth, m_unHeight;
    };

    class CWindowCloseEvent : public CEvent
    {
        public:
            CWindowCloseEvent() = default;

            EVENT_CLASS_TYPE(WindowClose)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CAppTickEvent : public CEvent
    {
        public:
            CAppTickEvent() = default;

            EVENT_CLASS_TYPE(AppTick)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CAppUpdateEvent : public CEvent
    {
        public:
            CAppUpdateEvent() = default;

            EVENT_CLASS_TYPE(AppUpdate)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CAppRenderEvent : public CEvent
    {
        public:
            CAppRenderEvent() = default;

            EVENT_CLASS_TYPE(AppRender)
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}