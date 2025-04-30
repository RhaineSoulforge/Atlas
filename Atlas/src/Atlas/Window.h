#pragma once

#include "atpch.h"

#include "Atlas/Core.h"
#include "Atlas/Events/ApplicationEvent.h"
#include "Atlas/Events/Event.h"
#include "Atlas/Events/KeyEvent.h"
#include "Atlas/Events/MouseEvent.h"

namespace Atlas
{
    struct SWindowProps
    {
        std::string m_sTitle;
        uint32_t m_unWidth;
        uint32_t m_unHeight;

        SWindowProps(const std::string &title = "Atlas Engine", uint32_t width = 1024, uint32_t height = 768)
            : m_sTitle(title), m_unWidth(width), m_unHeight(height)
        {

        }
    };

    class CWindow
    {
        public:
            using EventCallbackFn = std::function<void(CEvent&)>;

            virtual ~CWindow() = default;
            
            virtual void OnUpdate() = 0;

            virtual uint32_t GetWidth(void) const = 0;
            virtual uint32_t GetHeight(void) const = 0;

            // Window attributes
            virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
            virtual void SetVSync(bool enabled) = 0;
            virtual bool IsVSync(void) const = 0;

            virtual void Init(const SWindowProps &props) = 0;
            virtual void Shutdown(void) = 0;

            virtual void *GetNativeWindow(void) const = 0;

            static CWindow *Create(const SWindowProps &props = SWindowProps());
    };
}