#pragma once

#include "Core.h"

namespace Atlas
{
   class ATLAS_API CApplication
   {
      public:
         CApplication();
         virtual ~CApplication();

         void Run();
   };

   // To be defined in CLIENT.
   CApplication* CreateApplication();
}