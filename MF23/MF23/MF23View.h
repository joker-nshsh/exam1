
// MF23View.h : CMF23View ��Ľӿ�
//

#pragma once


class CMF23View : public CView
{
protected: // �������л�����
	CMF23View();
	DECLARE_DYNCREATE(CMF23View)

// ����
public:
	CMF23Doc* GetDocument() const;
	CRect a;
	int a1, a2, a3, a4;
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
	virtual ~CMF23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MF23View.cpp �еĵ��԰汾
inline CMF23Doc* CMF23View::GetDocument() const
   { return reinterpret_cast<CMF23Doc*>(m_pDocument); }
#endif

