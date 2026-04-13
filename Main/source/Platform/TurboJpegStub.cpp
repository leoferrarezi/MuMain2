#ifdef __ANDROID__

#include <turbojpeg/turbojpeg.h>
#include <turbojpeg/stb_image.h>

#include <algorithm>
#include <cstring>

extern "C" {

tjhandle tjInitDecompress(void)
{
	return reinterpret_cast<tjhandle>(1);
}

int tjDestroy(tjhandle handle)
{
	(void)handle;
	return 0;
}

int tjDecompressHeader3(tjhandle handle, const unsigned char* jpegBuf, unsigned long jpegSize,
	int* width, int* height, int* jpegSubsamp, int* jpegColorspace)
{
	(void)handle;

	int x = 0;
	int y = 0;
	int comp = 0;
	if (jpegBuf == nullptr || jpegSize == 0 ||
		!stbi_info_from_memory(jpegBuf, static_cast<int>(jpegSize), &x, &y, &comp))
	{
		return -1;
	}

	if (width) *width = x;
	if (height) *height = y;
	if (jpegSubsamp) *jpegSubsamp = TJSAMP_444;
	if (jpegColorspace) *jpegColorspace = TJCS_RGB;
	return 0;
}

int tjDecompress2(tjhandle handle, const unsigned char* jpegBuf, unsigned long jpegSize,
	unsigned char* dstBuf, int width, int pitch, int height, int pixelFormat, int flags)
{
	(void)handle;
	(void)flags;

	if (jpegBuf == nullptr || dstBuf == nullptr || width <= 0 || height <= 0)
	{
		return -1;
	}

	const int reqComp = (pixelFormat == TJPF_GRAY) ? 1 : 3;
	int x = 0;
	int y = 0;
	int comp = 0;
	unsigned char* decoded = stbi_load_from_memory(
		jpegBuf,
		static_cast<int>(jpegSize),
		&x,
		&y,
		&comp,
		reqComp);

	if (decoded == nullptr)
	{
		return -1;
	}

	if (pitch == 0)
	{
		pitch = width * reqComp;
	}

	const int copyW = std::min(width, x);
	const int copyH = std::min(height, y);
	const int srcStride = x * reqComp;
	const int copyBytes = copyW * reqComp;

	for (int row = 0; row < copyH; ++row)
	{
		std::memcpy(dstBuf + row * pitch, decoded + row * srcStride, static_cast<size_t>(copyBytes));
	}

	stbi_image_free(decoded);
	return 0;
}

char* tjGetErrorStr(void)
{
	static char kError[] = "TurboJPEG stub";
	return kError;
}

} // extern "C"

#endif // __ANDROID__
