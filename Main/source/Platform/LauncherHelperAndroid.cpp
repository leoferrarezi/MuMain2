#include "stdafx.h"
#include "LauncherHelper.h"

#ifdef __ANDROID__
bool wzRegisterConnectionKey()
{
    return true;
}

void wzUnregisterConnectionKey()
{
}

unsigned long wzGetConnectionKey()
{
    return 0;
}

bool wzPushLaunchInfo(const WZLAUNCHINFO&)
{
    return false;
}

bool wzPopLaunchInfo(WZLAUNCHINFO&)
{
    return false;
}
#endif
