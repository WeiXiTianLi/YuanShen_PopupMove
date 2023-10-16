#include "YuanShen_Fun.h"

#include <Windows.h>

// 获取或更新原神窗口句柄
HWND getYuanShenHandle()
{
	static HWND giHandle = nullptr;
	if (!IsWindow(giHandle))
	{
		LPCWSTR giWindowName = {L"原神"};
		giHandle = FindWindowW(L"UnityWndClass", giWindowName); /* 匹配名称：原神 */
		if (giHandle == NULL)
		{
			giWindowName = L"Genshin Impact";
			giHandle = FindWindowW(L"UnityWndClass", giWindowName); /* 匹配名称：Genshin Impact */
		}
		if (giHandle == NULL)
		{
			giWindowName = L"\u539F\u795E";
			giHandle = FindWindowW(L"UnityWndClass", giWindowName); /* 匹配名称：原神 */
		}
		if (giHandle == NULL)
		{
			giWindowName = L"\uC6D0\uC2E0";
			giHandle = FindWindowW(L"UnityWndClass", giWindowName); /* 匹配名称：?? */
		}
	}
#ifdef _DEBUG
	// cout << "giHandle: " << giHandle << endl;
#endif
	return giHandle;
}

bool getYuanShenRect(HWND giHandle, RECT &giRect)
{
	if (!IsWindow(giHandle))
		return false;
	// GetClientRect(giHandle, &giRect);
	GetWindowRect(giHandle, &giRect);
	return true;
}

void setThisTop(HWND thisHandle)
{
	static HWND HW_TopMods = HWND_TOP;
	static bool isShow = true;
	static bool isTopMost = true;
	// HWND HW_Now = HWND_TOPMOST;
	bool isChanged = false;
	if (isShow)
	{
	}
	else
	{
	}

	if (isTopMost)
	{
		if (HW_TopMods != HWND_TOPMOST)
		{
			HW_TopMods = HWND_TOPMOST;
			isChanged = true;
		}
	}
	else
	{
		if (HW_TopMods != HWND_NOTOPMOST)
		{
			HW_TopMods = HWND_NOTOPMOST;
			isChanged = true;
		}
	}

	// SetWindowPos((HWND)this->winId(), HW_TopMods, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);

	if (isChanged)
	{
		SetWindowPos(thisHandle, HW_TopMods, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	}
}
