#pragma once


// MyDlgo 对话框

class MyDlgo : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlgo)

public:
	MyDlgo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlgo();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString x;
	CString y;
	CString z;
	afx_msg void OnBnClickedButton1();
};
