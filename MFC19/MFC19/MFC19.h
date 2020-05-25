
// MFC19.h : MFC19 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFC19App:
// 有关此类的实现，请参阅 MFC19.cpp
//

class CMFC19App : public CWinAppEx
{
public:
	CMFC19App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC19App theApp;
