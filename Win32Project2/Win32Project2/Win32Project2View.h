
// Win32Project2View.h : CWin32Project2View ��Ľӿ�
//

#pragma once


class CWin32Project2View : public CView
{
protected: // �������л�����
	CWin32Project2View();
	DECLARE_DYNCREATE(CWin32Project2View)

// ����
public:
	CWin32Project2Doc* GetDocument() const;

// ����
public:
	int N;
	CArray <CRect, CRect>cr;
	bool set;
	int j;
	CRect rc;
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
	virtual ~CWin32Project2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // Win32Project2View.cpp �еĵ��԰汾
inline CWin32Project2Doc* CWin32Project2View::GetDocument() const
   { return reinterpret_cast<CWin32Project2Doc*>(m_pDocument); }
#endif

