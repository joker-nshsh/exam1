
// Win32Project2.h : Win32Project2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CWin32Project2App:
// �йش����ʵ�֣������ Win32Project2.cpp
//

class CWin32Project2App : public CWinApp
{
public:
	CWin32Project2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWin32Project2App theApp;
