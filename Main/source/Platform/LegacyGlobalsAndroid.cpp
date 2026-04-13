#ifdef __ANDROID__

#include "../stdafx.h"
#include "../Time/Timer.h"
#include "../ZzzBMD.h"

#include <string>

class CUITextInputBox;
class CUIManager;
class CUIMapName;
class CChatRoomSocketList;
class JewelHarmonyInfo;

CUITextInputBox* g_pSingleTextInputBox = nullptr;
CUITextInputBox* g_pSinglePasswdInputBox = nullptr;
int g_iChatInputType = 0;

CUIManager* g_pUIManager = nullptr;
CUIMapName* g_pUIMapName = nullptr;
CChatRoomSocketList* g_pChatRoomSocketList = nullptr;

std::string g_strSelectedML = "Eng";

static CTimer s_androidTimer;
CTimer* g_pTimer = &s_androidTimer;

bool g_bEnterPressed = false;
char m_ExeVersion[11] = "0.00";

namespace SEASON4A
{
	int g_iLimitAttackTime = 15;
	float IntensityTransform[MAX_MESH][MAX_VERTICES] = { 0 };
}

namespace SEASON3B
{
	int g_iCancelSkillTarget = 0;
	float g_fScreenRate_x = 1.0f;
	float g_fScreenRate_y = 1.0f;
	int g_iLengthAuthorityCode = 20;
	JewelHarmonyInfo* g_pUIJewelHarmonyinfo = nullptr;
	int SelectedCharacter = -1;
}

#endif // __ANDROID__
