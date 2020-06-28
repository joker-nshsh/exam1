#pragma once


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
	afx_msg void OnBnClickedButton2();
	CString s3;
	void foo2(CImage& img, int &sx, int& sy, int& w, int& h);
};
