
// MFC15View.h : CMFC15View ��Ľӿ�
//

#pragma once


class CMFC15View : public CView
{
protected: // �������л�����
	CMFC15View();
	DECLARE_DYNCREATE(CMFC15View)

// ����
public:
	CMFC15Doc* GetDocument() const;

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
	virtual ~CMFC15View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC15View.cpp �еĵ��԰汾
inline CMFC15Doc* CMFC15View::GetDocument() const
   { return reinterpret_cast<CMFC15Doc*>(m_pDocument); }
#endif

