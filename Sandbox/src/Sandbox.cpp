#include <Atlas.h>

class CSandbox : public Atlas::CApplication
{
    public:
        CSandbox(void)
        {
            Atlas::CATLogger::GetInstance()->Init(Atlas::CATLogger::eLevel::ALL,
                Atlas::CATLogger::eFlags::CONSOLE | Atlas::CATLogger::eFlags::TIMESTAMP);
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