#pragma once



// MyDlgo �Ի���

class MyDlgo : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlgo)

public:
	MyDlgo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlgo();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();
};
