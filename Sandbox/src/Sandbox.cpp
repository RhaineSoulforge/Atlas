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
            if(Atlas::CInput::IsKeyPressed(AT_KEY_TAB))
                AT_LOG_TRACE("Tab has been pressed!")
        }

        void OnEvent(Atlas::CEvent &event)
        {
            //AT_LOG_TRACE("{s}",event.ToString().c_str())
            if(event.GetEventType() == Atlas::eEventType::MouseButtonPressed)
            {
                Atlas::CMouseButtonPressedEvent &e = (Atlas::CMouseButtonPressedEvent&)event;
                if(e.GetMouseButton() == AT_LBUTTON)
                {
                    AT_LOG_TRACE("Left Mouse button pressed!")
                }
            }
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
            PushLayer(new CExampleLayer());
        }

        ~CSandbox(void)
        {
            Atlas::CATLogger::DeleteInstance();
        }
};

Atlas::CApplication *Atlas::CreateApplication(void)
{
            Atlas::CATLogger::GetInstance()->Init(Atlas::CATLogger::eLevel::ALL,
                Atlas::CATLogger::eFlags::CONSOLE | Atlas::CATLogger::eFlags::TIMESTAMP);
            return new CSandbox();
}