#pragma once
#include "afxwin.h"


// MyDlg1 �Ի���

class MyDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg1)

public:
	MyDlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox Box;
	CString s;
	virtual BOOL OnInitDialog();
	CEdit edit;
};
