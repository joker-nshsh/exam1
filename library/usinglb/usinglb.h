
// usinglb.h : usinglb Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CusinglbApp:
// �йش����ʵ�֣������ usinglb.cpp
//

class CusinglbApp : public CWinAppEx
{
public:
	CusinglbApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CusinglbApp theApp;
