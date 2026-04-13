/*******************************************************************************
* File: Include Header
*******************************************************************************/

#pragma once

#pragma warning(disable : 4995)

#include <iostream>

#ifndef __ANDROID__
#include <Windows.h>
#include <Wininet.h>
#include <crtdbg.h>
#include <tchar.h>
#include <strsafe.h>
#pragma comment(lib, "Wininet.lib")
#else
#include "Platform/AndroidWin32Compat.h"
#endif

#include "GameShop/ShopListManager/interface/WZResult/WZResult.h"
#include "GameShop/ShopListManager/interface/DownloadInfo.h"
#include "GameShop/ShopListManager/interface/IDownloaderStateEvent.h"
