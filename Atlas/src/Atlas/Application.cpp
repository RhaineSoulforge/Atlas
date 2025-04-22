#include "atpch.h"
#include "Application.h"
#include "ATLogger.h"

namespace Atlas
{
    CApplication::CApplication()
    {

    }

    CApplication::~CApplication()
    {

    }

    void CApplication::Run()
    {
        AT_LOG_INFO("Atlas GE version Alpha online....")
        while(true);
    }
}