#ifdef __ANDROID__

#include "../stdafx.h"
#include "../ServerListManager.h"
#include "../WSclient.h"

bool runtime_load_protect()
{
	// Android bootstrap currently bypasses the legacy Windows protect loader path.
	return true;
}

bool LoadServerList()
{
	g_ServerListManager->LoadServerListScript();
	return true;
}

bool LoadEncryptionKeys()
{
	const bool encOk = (g_SimpleModulusCS.LoadEncryptionKey(const_cast<char*>("Data\\Enc1.dat")) == TRUE);
	const bool decOk = (g_SimpleModulusSC.LoadDecryptionKey(const_cast<char*>("Data\\Dec2.dat")) == TRUE);
	return encOk && decOk;
}

#endif // __ANDROID__
