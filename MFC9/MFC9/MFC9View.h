
// MFC9View.h : CMFC9View ��Ľӿ�
//

#pragma once


class CMFC9View : public CView
{
protected: // �������л�����
	CMFC9View();
	DECLARE_DYNCREATE(CMFC9View)

// ����
public:
	CMFC9Doc* GetDocument() const;
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
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC9View.cpp �еĵ��԰汾
inline CMFC9Doc* CMFC9View::GetDocument() const
   { return reinterpret_cast<CMFC9Doc*>(m_pDocument); }
#endif

