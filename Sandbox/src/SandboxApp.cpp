#include <Atlas.h>

class CSandbox : public Atlas::CApplication
{
   public:
      CSandbox()
      {
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