#include <Atlas.h>

class CExampleLayer : public Atlas::CLayer
{
    public:
        CExampleLayer() : CLayer("Example")
        {

        }

        void OnUpdate(void) override
        {
            //AT_LOG_INFO("ExampleLayer::OnUpdate!")
        }

        void OnEvent(Atlas::CEvent &event)
        {
            AT_LOG_TRACE("{s}",event.ToString().c_str())
        }

        void OnAttach(void)
        {
            AT_LOG_TRACE("Layer {s} has been attached.",m_DebugName)
        }
};

class CSandbox : public Atlas::CApplication
{
    public:
        CSandbox(void)
        {
            Atlas::CATLogger::GetInstance()->Init(Atlas::CATLogger::eLevel::ALL,
                Atlas::CATLogger::eFlags::CONSOLE | Atlas::CATLogger::eFlags::TIMESTAMP);
            PushLayer(new CExampleLayer());
        }

        ~CSandbox(void)
        {
            Atlas::CATLogger::DeleteInstance();
        }
};

Atlas::CApplication *Atlas::CreateApplication(void)
{
    return new CSandbox();
}