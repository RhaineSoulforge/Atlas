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
   return new CSandbox();
}