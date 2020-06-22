#pragma once
#include "afxwin.h"


// MyDlg1 对话框

class MyDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg1)

public:
	MyDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox Box;
	CString s;
	virtual BOOL OnInitDialog();
	CEdit edit;
};
