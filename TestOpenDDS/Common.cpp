#include "stdafx.h"
#include "Common.h"

int GenRGBHex(int r, int g, int b)
{
	int rgb = 0;
	rgb += (r << 16);
	rgb += (g << 8);
	rgb += b;

	return rgb;
}

CString GetModuleDir()
{
	WCHAR buf[MAX_PATH];
	HINSTANCE hInstance = AfxGetApp()->m_hInstance;
	GetModuleFileName(NULL, buf, MAX_PATH * sizeof(WCHAR));
	GetLongPathName(buf, buf, MAX_PATH * sizeof(WCHAR));
	PathRemoveFileSpec(buf);
	return buf;
}