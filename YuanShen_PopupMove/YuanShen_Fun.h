#pragma once

#include <Windows.h>

//获取或更新原神窗口句柄
HWND getYuanShenHandle();

//获取原神窗口位置和大小
bool getYuanShenRect(HWND giHandle, RECT &giRect);

//设置自身置顶
void setThisTop(HWND thisHandle);
