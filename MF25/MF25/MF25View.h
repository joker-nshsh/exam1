
// MF25View.h : CMF25View ��Ľӿ�
//

#pragma once


class CMF25View : public CView
{
protected: // �������л�����
	CMF25View();
	DECLARE_DYNCREATE(CMF25View)

// ����
public:
	CMF25Doc* GetDocument() const;
	CRect a,b;
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
	virtual ~CMF25View();
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
};

#ifndef _DEBUG  // MF25View.cpp �еĵ��԰汾
inline CMF25Doc* CMF25View::GetDocument() const
   { return reinterpret_cast<CMF25Doc*>(m_pDocument); }
#endif

