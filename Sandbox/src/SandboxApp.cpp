#include <Atlas.h>

class CTestLayer : public Atlas::CLayer
{
   public:
      CTestLayer() : CLayer("Test Layer") {}

      void OnUpdate() override
      {

         //AT_LOG_TRACE("CTestLayer::OnUpdate");
      }

      void OnEvent(Atlas::CEvent &event) override
      {
         
         if (event.GetEventType() == Atlas::eEventType::KeyPressed)
         {
            Atlas::CKeyPressedEvent& e = (Atlas::CKeyPressedEvent&)event;
            AT_LOG_INFO("CTestLayer::OnEvent {c} was pressed!", e.GetKeyCode());
         }

         if (event.GetEventType() == Atlas::eEventType::MouseButtonPressed)
         {
            Atlas::CMouseButtonPressedEvent& e = (Atlas::CMouseButtonPressedEvent&)event;
            if (e.GetMouseButton() == AT_LBUTTON)
            {
               AT_LOG_INFO("Left mouse button clicked.");
            }
            else if (e.GetMouseButton() == AT_RBUTTON)
            {
               AT_LOG_INFO("Right mouse button clicked.");
            }
            else if (e.GetMouseButton() == AT_MBUTTON)
            {
               AT_LOG_INFO("Middle mouse button clicked.");
            }

         }
         //AT_LOG_TRACE("{s}", event.ToString().c_str());
      }
};

class CSandbox : public Atlas::CApplication
{
   public:
      CSandbox()
      {
         PushLayer(new CTestLayer());
      }

      ~CSandbox()
      {
      }
};

Atlas::CApplication* Atlas::CreateApplication()
{
   Atlas::CATLogger::GetInstance()->Init(Atlas::CATLogger::eLevel::ALL,
      Atlas::CATLogger::eFlags::CONSOLE | Atlas::CATLogger::eFlags::TIMESTAMP);
   return new CSandbox();
}