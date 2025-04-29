#pragma once

#include "Atlas/Events/Event.h"
#include "Atlas/MouseButtonCodes.h"

namespace Atlas
{
    class CMouseMovedEvent : public CEvent
    {
        public:
            CMouseMovedEvent(const float x, const float y)
                : m_fMouseX(x), m_fMouseY(y)
            {

            }

            float GetX(void) const { return m_fMouseX; }
            float GetY(void) const { return m_fMouseY; }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << "MouseMovedEvent: " << m_fMouseX << ", " << m_fMouseY;
                return ss.str();
            }

            EVENT_CLASS_TYPE(MouseMoved)
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

        private:
            float m_fMouseX;
            float m_fMouseY;
    };

    class CMouseScrolledEvent : public CEvent
    {
        public:
            CMouseScrolledEvent(const float xOffset, const float yOffset)
                : m_fXOffset(xOffset), m_fYOffset(yOffset)
            {

            }

            float GetXOffset(void) const { return m_fXOffset; }
            float GetYOffset(void) const { return m_fYOffset; }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << "MouseScrolledEvent: " << m_fXOffset << ", " << m_fYOffset;
                return ss.str();
            }

            EVENT_CLASS_TYPE(MouseScrolled)
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

        private:
            float m_fXOffset;
            float m_fYOffset;
    };

    class CMouseButtonEvent : public CEvent
    {
        public:
            int GetMouseButton(void) const { return m_nButton; }

            EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput | EventCategoryMouseButton)
        protected:
            CMouseButtonEvent(const int button) : m_nButton(button)
            {

            }

            int m_nButton;
    };

    class CMouseButtonPressedEvent : public CMouseButtonEvent
    {
        public:
            CMouseButtonPressedEvent(const int button) : m_nButton(button)
            {

            }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << "MouseButtonPressedEvent: " << m_nButton;
                return ss.str();
            }

            EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class CMouseButtonReleasedEvent : public CMouseButtonEvent
    {
        public:
            CMouseButtonReleasedEvent(const int button) : m_nButton(button)
            {

            }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << "MouseButtonReleasedEvent: " << m_nButton;
                return ss.str();
            }

            EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}