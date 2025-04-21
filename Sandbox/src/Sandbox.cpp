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

int main(int argc, char **argv)
{
    CSandbox *app = new CSandbox();
    app->Run();
    delete app;
    return 0;
}