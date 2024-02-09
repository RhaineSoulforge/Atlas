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
         AT_LOG_TRACE("{s}", event.ToString().c_str());
      }
};

class CSandbox : public Atlas::CApplication
{
   public:
      CSandbox()
      {
         //PushLayer(new CTestLayer());
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