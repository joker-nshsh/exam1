
// MFC8View.h : CMFC8View ��Ľӿ�
//

#pragma once


class CMFC8View : public CView
{
protected: // �������л�����
	CMFC8View();
	DECLARE_DYNCREATE(CMFC8View)

// ����
public:
	CMFC8Doc* GetDocument() const;
	CRect j;
	int a1;
	int a2;
	int a;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC8View();
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

#ifndef _DEBUG  // MFC8View.cpp �еĵ��԰汾
inline CMFC8Doc* CMFC8View::GetDocument() const
   { return reinterpret_cast<CMFC8Doc*>(m_pDocument); }
#endif

