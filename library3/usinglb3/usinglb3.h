
// usinglb3.h : usinglb3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cusinglb3App:
// �йش����ʵ�֣������ usinglb3.cpp
//

class Cusinglb3App : public CWinAppEx
{
public:
	Cusinglb3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cusinglb3App theApp;
