#pragma once

#include "Atlas/Events/Event.h"
#include "Atlas/KeyCodes.h"

namespace Atlas
{
    class CKeyEvent : public CEvent
    {
        public:
            int GetKeyCode(void) const { return m_nKeyCode; }

            EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
         protected:
            CKeyEvent(const int keycode)
                : m_nKeyCode(keycode)
            {

            }

            int m_nKeyCode;
    };

    class CKeyPressedEvent : public CKeyEvent
    {
        public:
            CKeyPressedEvent(const int keycode, bool isRepeat = false)
                : CKeyEvent(keycode), m_bRepeat(isRepeat)
            {

            }

            bool IsRepeat(void) const { return m_bRepeat; }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << "KeyPressedEvent: " << m_nKeyCode << "(repeat = " << m_bRepeat << ")";
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyPressed)
        private:
            bool m_bRepeat;
    };

    class CKeyReleasedEvent : public CKeyEvent
    {
        public:
            CKeyReleasedEvent(const int keycode)
                : CKeyEvent(keycode)
            {

            }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << "KeyReleasedEvent: " << m_nKeyCode;
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyReleased)
    };

    class CKeyTypedEvent : public CKeyEvent
    {
        public:
            CKeyTypedEvent(const int keycode)
                : CKeyEvent(keycode)
            {

            }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << "KeyTypedEvent: " << m_nKeyCode;
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyTyped)
    };
}