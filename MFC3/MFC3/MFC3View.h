
// MFC3View.h : CMFC3View ��Ľӿ�
//

#pragma once


class CMFC3View : public CView
{
protected: // �������л�����
	CMFC3View();
	DECLARE_DYNCREATE(CMFC3View)

// ����
public:
	CMFC3Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC3View();
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

#ifndef _DEBUG  // MFC3View.cpp �еĵ��԰汾
inline CMFC3Doc* CMFC3View::GetDocument() const
   { return reinterpret_cast<CMFC3Doc*>(m_pDocument); }
#endif

