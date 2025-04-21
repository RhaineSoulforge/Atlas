#pragma once

#ifdef AT_PLATFORM_WINDOWS

    extern Atlas::CApplication *Atlas::CreateApplication(void);

    int main(int argc, char **argv)
    {
        auto app = Atlas::CreateApplication();
        app->Run();
        delete app;
        return 0;
    }
#else
    #error Atlas only supports Windows!
#endif