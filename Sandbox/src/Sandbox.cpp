#include <Atlas.h>

class CSandbox : public Atlas::CApplication
{
    public:
        CSandbox(void)
        {

        }

        ~CSandbox(void)
        {

        }
};

Atlas::CApplication *Atlas::CreateApplication(void)
{
    return new CSandbox();
}