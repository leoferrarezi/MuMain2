#ifdef __ANDROID__

#include "../stdafx.h"
#include "../SimpleModulus.h"

#include <cstring>

DWORD CSimpleModulus::s_dwSaveLoadXOR[SIZE_ENCRYPTION_KEY] = { 0, 0, 0, 0 };

CSimpleModulus::CSimpleModulus()
{
	Init();
}

CSimpleModulus::~CSimpleModulus() = default;

void CSimpleModulus::Init(void)
{
	std::memset(m_dwModulus, 0, sizeof(m_dwModulus));
	std::memset(m_dwEncryptionKey, 0, sizeof(m_dwEncryptionKey));
	std::memset(m_dwDecryptionKey, 0, sizeof(m_dwDecryptionKey));
	std::memset(m_dwXORKey, 0, sizeof(m_dwXORKey));
}

int CSimpleModulus::Encrypt(void* lpTarget, void* lpSource, int iSize)
{
	if (iSize <= 0)
	{
		return 0;
	}

	if (lpTarget == nullptr)
	{
		return iSize;
	}

	if (lpSource == nullptr)
	{
		return 0;
	}

	std::memcpy(lpTarget, lpSource, static_cast<size_t>(iSize));
	return iSize;
}

int CSimpleModulus::Decrypt(void* lpTarget, void* lpSource, int iSize)
{
	if (iSize <= 0 || lpSource == nullptr || lpTarget == nullptr)
	{
		return 0;
	}

	std::memcpy(lpTarget, lpSource, static_cast<size_t>(iSize));
	return iSize;
}

void CSimpleModulus::EncryptBlock(void* lpTarget, void* lpSource, int nSize)
{
	if (lpTarget != nullptr && lpSource != nullptr && nSize > 0)
	{
		std::memcpy(lpTarget, lpSource, static_cast<size_t>(nSize));
	}
}

int CSimpleModulus::DecryptBlock(void* lpTarget, void* lpSource)
{
	if (lpTarget == nullptr || lpSource == nullptr)
	{
		return 0;
	}

	std::memcpy(lpTarget, lpSource, SIZE_ENCRYPTION_BLOCK);
	return SIZE_ENCRYPTION_BLOCK;
}

int CSimpleModulus::AddBits(void* lpBuffer, int nNumBufferBits, void* lpBits, int nInitialBit, int nNumBits)
{
	(void)lpBuffer;
	(void)nNumBufferBits;
	(void)lpBits;
	(void)nInitialBit;
	return nNumBits;
}

void CSimpleModulus::Shift(void* lpBuffer, int nByte, int nShift)
{
	(void)lpBuffer;
	(void)nByte;
	(void)nShift;
}

int CSimpleModulus::GetByteOfBit(int nBit)
{
	if (nBit <= 0)
	{
		return 0;
	}
	return (nBit + 7) / 8;
}

BOOL CSimpleModulus::SaveAllKey(char* lpszFileName)
{
	(void)lpszFileName;
	return TRUE;
}

BOOL CSimpleModulus::LoadAllKey(char* lpszFileName)
{
	(void)lpszFileName;
	return TRUE;
}

BOOL CSimpleModulus::SaveEncryptionKey(char* lpszFileName)
{
	(void)lpszFileName;
	return TRUE;
}

BOOL CSimpleModulus::LoadEncryptionKey(char* lpszFileName)
{
	(void)lpszFileName;
	return TRUE;
}

BOOL CSimpleModulus::SaveDecryptionKey(char* lpszFileName)
{
	(void)lpszFileName;
	return TRUE;
}

BOOL CSimpleModulus::LoadDecryptionKey(char* lpszFileName)
{
	(void)lpszFileName;
	return TRUE;
}

BOOL CSimpleModulus::SaveKey(char* lpszFileName, unsigned short sID, BOOL bMod, BOOL bEnc, BOOL bDec, BOOL bXOR)
{
	(void)lpszFileName;
	(void)sID;
	(void)bMod;
	(void)bEnc;
	(void)bDec;
	(void)bXOR;
	return TRUE;
}

BOOL CSimpleModulus::LoadKey(char* lpszFileName, unsigned short sID, BOOL bMod, BOOL bEnc, BOOL bDec, BOOL bXOR)
{
	(void)lpszFileName;
	(void)sID;
	(void)bMod;
	(void)bEnc;
	(void)bDec;
	(void)bXOR;
	return TRUE;
}

BOOL CSimpleModulus::LoadKeyFromBuffer(BYTE* pbyBuffer, BOOL bMod, BOOL bEnc, BOOL bDec, BOOL bXOR)
{
	(void)pbyBuffer;
	(void)bMod;
	(void)bEnc;
	(void)bDec;
	(void)bXOR;
	return TRUE;
}

#endif // __ANDROID__
