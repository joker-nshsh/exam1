
// MFC26View.h : CMFC26View ��Ľӿ�
//

#pragma once


class CMFC26View : public CView
{
protected: // �������л�����
	CMFC26View();
	DECLARE_DYNCREATE(CMFC26View)

// ����
public:
	CMFC26Doc* GetDocument() const;
	CRect a;
	int R, X, Y;
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
	virtual ~CMFC26View();
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
};

#ifndef _DEBUG  // MFC26View.cpp �еĵ��԰汾
inline CMFC26Doc* CMFC26View::GetDocument() const
   { return reinterpret_cast<CMFC26Doc*>(m_pDocument); }
#endif

