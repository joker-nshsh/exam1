#pragma once
#include "afxwin.h"
#include "afxcoll.h"


// Dlg1 对话框

class Dlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg1)

public:
	Dlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
