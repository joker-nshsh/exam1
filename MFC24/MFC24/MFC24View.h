
// MFC24View.h : CMFC24View ��Ľӿ�
//

#pragma once


class CMFC24View : public CView
{
protected: // �������л�����
	CMFC24View();
	DECLARE_DYNCREATE(CMFC24View)

// ����
public:
	CMFC24Doc* GetDocument() const;
	CRect a;
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
	virtual ~CMFC24View();
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

#ifndef _DEBUG  // MFC24View.cpp �еĵ��԰汾
inline CMFC24Doc* CMFC24View::GetDocument() const
   { return reinterpret_cast<CMFC24Doc*>(m_pDocument); }
#endif

