
// MFC2View.h : CMFC2View ��Ľӿ�
//

#pragma once


class CMFC2View : public CView
{
protected: // �������л�����
	CMFC2View();
	DECLARE_DYNCREATE(CMFC2View)

// ����
public:
	CMFC2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC2View();
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

#ifndef _DEBUG  // MFC2View.cpp �еĵ��԰汾
inline CMFC2Doc* CMFC2View::GetDocument() const
   { return reinterpret_cast<CMFC2Doc*>(m_pDocument); }
#endif

