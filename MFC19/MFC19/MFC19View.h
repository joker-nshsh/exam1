
// MFC19View.h : CMFC19View ��Ľӿ�
//

#pragma once


class CMFC19View : public CView
{
protected: // �������л�����
	CMFC19View();
	DECLARE_DYNCREATE(CMFC19View)

// ����
public:
	CMFC19Doc* GetDocument() const;

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
	virtual ~CMFC19View();
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

#ifndef _DEBUG  // MFC19View.cpp �еĵ��԰汾
inline CMFC19Doc* CMFC19View::GetDocument() const
   { return reinterpret_cast<CMFC19Doc*>(m_pDocument); }
#endif

