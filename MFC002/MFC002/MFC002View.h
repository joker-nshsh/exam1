
// MFC002View.h : CMFC002View ��Ľӿ�
//

#pragma once


class CMFC002View : public CView
{
protected: // �������л�����
	CMFC002View();
	DECLARE_DYNCREATE(CMFC002View)

// ����
public:
	CMFC002Doc* GetDocument() const;

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
	virtual ~CMFC002View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC002View.cpp �еĵ��԰汾
inline CMFC002Doc* CMFC002View::GetDocument() const
   { return reinterpret_cast<CMFC002Doc*>(m_pDocument); }
#endif

