
// MFC28View.h : CMFC28View ��Ľӿ�
//

#pragma once


class CMFC28View : public CView
{
protected: // �������л�����
	CMFC28View();
	DECLARE_DYNCREATE(CMFC28View)

// ����
public:
	CMFC28Doc* GetDocument() const;
	CString filename;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC28View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
	afx_msg void OnBnClickedButton1();
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFC28View.cpp �еĵ��԰汾
inline CMFC28Doc* CMFC28View::GetDocument() const
   { return reinterpret_cast<CMFC28Doc*>(m_pDocument); }
#endif

