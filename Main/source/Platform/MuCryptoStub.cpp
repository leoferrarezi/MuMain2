#ifdef __ANDROID__

#include "../stdafx.h"
#include "../MuCrypto/MuCrypto.h"

#include <cstring>

#ifndef KERNEL_KEY

MuCrypto gMuCrypto;

MuCrypto::MuCrypto()
	: m_cipher(nullptr)
{
}

MuCrypto::~MuCrypto() = default;

bool MuCrypto::InitModulusCrypto(DWORD algorithm, BYTE* key, size_t keyLength)
{
	(void)algorithm;
	(void)key;
	(void)keyLength;
	return true;
}

int MuCrypto::BlockEncrypt(BYTE* inBuf, size_t len, BYTE* outBuf)
{
	if (inBuf == nullptr || outBuf == nullptr || len == 0)
	{
		return 0;
	}

	std::memcpy(outBuf, inBuf, len);
	return static_cast<int>(len);
}

int MuCrypto::BlockDecrypt(BYTE* inBuf, size_t len, BYTE* outBuf)
{
	if (inBuf == nullptr || outBuf == nullptr || len == 0)
	{
		return 0;
	}

	std::memcpy(outBuf, inBuf, len);
	return static_cast<int>(len);
}

int MuCrypto::ModulusDecrypt(BYTE* pbyDst, BYTE* pbySrc, int iSize)
{
	if (iSize <= 0)
	{
		return 0;
	}

	if (pbyDst != nullptr && pbySrc != nullptr)
	{
		std::memcpy(pbyDst, pbySrc, static_cast<size_t>(iSize));
	}

	return iSize;
}

BOOL MuCrypto::ModulusDecryptv2(std::vector<BYTE>& buf)
{
	(void)buf;
	return TRUE;
}

BOOL MuCrypto::ModulusEncrypt(std::vector<BYTE>& buf)
{
	(void)buf;
	return TRUE;
}

#endif // !KERNEL_KEY

#endif // __ANDROID__
