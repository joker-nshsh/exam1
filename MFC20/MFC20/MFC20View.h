
// MFC20View.h : CMFC20View ��Ľӿ�
//

#pragma once


class CMFC20View : public CView
{
protected: // �������л�����
	CMFC20View();
	DECLARE_DYNCREATE(CMFC20View)

// ����
public:
	CMFC20Doc* GetDocument() const;
	CRect a;
	int b, c,d,e;
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
	virtual ~CMFC20View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC20View.cpp �еĵ��԰汾
inline CMFC20Doc* CMFC20View::GetDocument() const
   { return reinterpret_cast<CMFC20Doc*>(m_pDocument); }
#endif

