
// MFC27View.h : CMFC27View ��Ľӿ�
//

#pragma once


class CMFC27View : public CView
{
protected: // �������л�����
	CMFC27View();
	DECLARE_DYNCREATE(CMFC27View)

// ����
public:
	CMFC27Doc* GetDocument() const;

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
	virtual ~CMFC27View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC27View.cpp �еĵ��԰汾
inline CMFC27Doc* CMFC27View::GetDocument() const
   { return reinterpret_cast<CMFC27Doc*>(m_pDocument); }
#endif

