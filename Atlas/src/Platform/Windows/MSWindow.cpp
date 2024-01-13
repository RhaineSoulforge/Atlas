#include "atpch.h"
#include "MSWindow.h"

namespace Atlas
{
   CWindow* CWindow::Create(const SWindowProps& props)
   {
      return new CMSWindow(props);
   }

   CMSWindow::CMSWindow(const SWindowProps& props)
   {
      Init(props);
   }

   CMSWindow::~CMSWindow()
   {
      Shutdown();
   }

   void CMSWindow::Init(const SWindowProps& props)
   {
      m_wdData.m_sTitle = props.m_sTitle;
      m_wdData.m_unWidth = props.m_unWidth;
      m_wdData.m_unHeight = props.m_unHeight;

      AT_LOG_INFO("Creating window {s} {u}x{u}", m_wdData.m_sTitle.c_str(), m_wdData.m_unWidth, m_wdData.m_unHeight);

      SetVSync(false);
   }

   void CMSWindow::Shutdown()
   {
      //TODO:  Clean up for end of Window life!
   }

   void CMSWindow::OnUpdate()
   {
   }

   void CMSWindow::SetVSync(bool bEnabled)
   {
      m_wdData.m_bVSync = bEnabled;
   }

   bool CMSWindow::IsVSync() const
   {
      return m_wdData.m_bVSync;
   }
}