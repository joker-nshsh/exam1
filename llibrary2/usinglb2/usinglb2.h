
// usinglb2.h : usinglb2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cusinglb2App:
// �йش����ʵ�֣������ usinglb2.cpp
//

class Cusinglb2App : public CWinAppEx
{
public:
	Cusinglb2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cusinglb2App theApp;
