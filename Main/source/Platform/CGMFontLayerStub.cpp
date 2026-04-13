#ifdef __ANDROID__

#include "../stdafx.h"
#include "../CGMFontLayer.h"

#include <cstring>

CGMFontLayer::CGMFontLayer()
{
	BitmapFontIndex = static_cast<FT_UInt>(-1);
}

CGMFontLayer::~CGMFontLayer() = default;

_FT_Bitmap* CGMFontLayer::GetULongChar(FT_ULong charcode)
{
	(void)charcode;
	return nullptr;
}

void CGMFontLayer::runtime_load_bitmap(GLuint* textures, GLsizei _width, GLsizei _height, BYTE* data)
{
	(void)textures;
	(void)_width;
	(void)_height;
	(void)data;
}

void CGMFontLayer::runtime_font_property(HFONT hFont, int PixelSize)
{
	(void)hFont;
	(void)PixelSize;
}

void CGMFontLayer::runtime_font_property(HDC hdc, HFONT hFont, DWORD dwTable, FT_Library library, BitmapFont* FontType, int FontIndex, int PixelSize)
{
	(void)hdc;
	(void)hFont;
	(void)dwTable;
	(void)library;
	(void)FontType;
	(void)FontIndex;
	(void)PixelSize;
}

void CGMFontLayer::runtime_font_property(const char* file_base, FT_Library library, BitmapFont* FontType, int FontIndex, int PixelSize, FT_Encoding encoding)
{
	(void)file_base;
	(void)library;
	(void)FontType;
	(void)FontIndex;
	(void)PixelSize;
	(void)encoding;
}

BOOL CGMFontLayer::_GetTextExtentPoint32(std::wstring wstrText, LPSIZE lpSize)
{
	if (lpSize)
	{
		lpSize->cx = static_cast<LONG>(wstrText.size() * 8);
		lpSize->cy = static_cast<LONG>(getmetrics());
	}
	return TRUE;
}

BOOL CGMFontLayer::_GetTextExtentPoint32(LPCSTR lpString, int cbString, LPSIZE lpSize)
{
	if (lpSize)
	{
		int length = 0;
		if (lpString != nullptr)
		{
			length = (cbString > 0) ? cbString : static_cast<int>(std::strlen(lpString));
		}
		lpSize->cx = static_cast<LONG>(length * 8);
		lpSize->cy = static_cast<LONG>(getmetrics());
	}
	return TRUE;
}

void CGMFontLayer::_TextOut(std::wstring wstrText, int& pen_x, int& pen_y)
{
	pen_x += static_cast<int>(wstrText.size() * 8);
	(void)pen_y;
}

void CGMFontLayer::runtime_writebuffer(int off_x, int off_y, _FT_Bitmap* pBitmap)
{
	(void)off_x;
	(void)off_y;
	(void)pBitmap;
}

void CGMFontLayer::runtime_render_map(int pen_x, int pen_y, int RealTextX, int RealTextY, int Width, int Height, bool background)
{
	(void)pen_x;
	(void)pen_y;
	(void)RealTextX;
	(void)RealTextY;
	(void)Width;
	(void)Height;
	(void)background;
}

void CGMFontLayer::RenderText(int iPos_x, int iPos_y, const unicode::t_char* pszText, int iWidth, int iHeight, int iSort, OUT SIZE* lpTextSize, bool background)
{
	(void)iPos_x;
	(void)iPos_y;
	(void)iWidth;
	(void)iHeight;
	(void)iSort;
	(void)background;

	size_t length = 0;
	if (pszText != nullptr)
	{
		while (pszText[length] != 0)
		{
			++length;
		}
	}

	if (lpTextSize)
	{
		lpTextSize->cx = static_cast<LONG>(length * 8);
		lpTextSize->cy = static_cast<LONG>(getmetrics());
	}
}

void CGMFontLayer::RenderWave(int iPos_x, int iPos_y, const unicode::t_char* pszText, int iWidth, int iHeight, int iSort, OUT SIZE* lpTextSize)
{
	RenderText(iPos_x, iPos_y, pszText, iWidth, iHeight, iSort, lpTextSize, false);
}

void CGMFontLayer::runtime_render_map()
{
}

int CGMFontLayer::getmetrics()
{
	return 16;
}

CGMFontLayer* CGMFontLayer::Instance()
{
	static CGMFontLayer s_instance;
	return &s_instance;
}

#endif // __ANDROID__
