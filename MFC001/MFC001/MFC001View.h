
// MFC001View.h : CMFC001View ��Ľӿ�
//

#pragma once


class CMFC001View : public CView
{
protected: // �������л�����
	CMFC001View();
	DECLARE_DYNCREATE(CMFC001View)

// ����
public:
	CMFC001Doc* GetDocument() const;
	int k;
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
	virtual ~CMFC001View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC001View.cpp �еĵ��԰汾
inline CMFC001Doc* CMFC001View::GetDocument() const
   { return reinterpret_cast<CMFC001Doc*>(m_pDocument); }
#endif

