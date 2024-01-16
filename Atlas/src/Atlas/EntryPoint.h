#pragma once

#ifdef AT_PLATFORM_WINDOWS

   extern Atlas::CApplication* Atlas::CreateApplication();

   int main()
   {
      auto app = Atlas::CreateApplication();
      app->Run();
      delete app;
   }

#else
   #error Atlas only supports Windows at this time!
#endif // AT_PLATFORM_WINDOWS
