#pragma once

#include "Core.h"

namespace Atlas
{
    class CApplication
    {
        public:
            CApplication();
            virtual ~CApplication();

            void Run();
    };

    // To be defined by CLIENT application!
    CApplication *CreateApplication(void);
}