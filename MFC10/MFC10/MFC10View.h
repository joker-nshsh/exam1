
// MFC10View.h : CMFC10View ��Ľӿ�
//

#pragma once


class CMFC10View : public CView
{
protected: // �������л�����
	CMFC10View();
	DECLARE_DYNCREATE(CMFC10View)

// ����
public:
	CMFC10Doc* GetDocument() const;
	CRect j;
	
	
	int a1,a2,a;

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
	virtual ~CMFC10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC10View.cpp �еĵ��԰汾
inline CMFC10Doc* CMFC10View::GetDocument() const
   { return reinterpret_cast<CMFC10Doc*>(m_pDocument); }
#endif

