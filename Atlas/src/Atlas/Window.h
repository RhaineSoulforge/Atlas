#pragma once

#include "atpch.h"

#include "Atlas/Core.h"
#include "Atlas/Events/Event.h"

namespace Atlas
{
   struct SWindowProps
   {
      std::string m_sTitle;
      unsigned int m_unWidth;
      unsigned int m_unHeight;

      SWindowProps(const std::string& sTitle = "Atlas Engine v.Alpha",
         unsigned int unWidth = 1280,
         unsigned int unHeight = 720)
         : m_sTitle(sTitle), m_unWidth(unWidth), m_unHeight(unHeight)
      {
      }
   };

   class ATLAS_API CWindow
   {
      public:
         using EventCallbackFn = std::function<void(CEvent&)>;

         virtual ~CWindow() {}

         virtual void OnUpdate() = 0;

         virtual unsigned int GetWidth() const = 0;
         virtual unsigned int GetHeight() const = 0;

         virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
         virtual void SetVSync(bool bEnabled) = 0;
         virtual bool IsVSync() const = 0;

         static CWindow* Create(const SWindowProps& props = SWindowProps());
   };
}