#pragma once

#ifdef AT_PLATFORM_WINDOWS

   extern Atlas::CApplication* Atlas::CreateApplication();

   int main()
   {
      Atlas::CATLogger::GetInstance()->Init(Atlas::CATLogger::eLevel::ALL, Atlas::CATLogger::eFlags::TIMESTAMP | Atlas::CATLogger::eFlags::CONSOLE);
      auto app = Atlas::CreateApplication();
      app->Run();
      delete app;
   }

#else
   #error Atlas only supports Windows at this time!
#endif // AT_PLATFORM_WINDOWS
