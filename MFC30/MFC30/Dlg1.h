#pragma once
#include "afxwin.h"
#include "afxcoll.h"


// Dlg1 �Ի���

class Dlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg1)

public:
	Dlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox Box;
	CEdit edit;
	CStringArray j;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	int q;
	CString s;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
