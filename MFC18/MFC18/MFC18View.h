
// MFC18View.h : CMFC18View ��Ľӿ�
//

#pragma once


class CMFC18View : public CView
{
protected: // �������л�����
	CMFC18View();
	DECLARE_DYNCREATE(CMFC18View)

// ����
public:
	CMFC18Doc* GetDocument() const;

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
	virtual ~CMFC18View();
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

#ifndef _DEBUG  // MFC18View.cpp �еĵ��԰汾
inline CMFC18Doc* CMFC18View::GetDocument() const
   { return reinterpret_cast<CMFC18Doc*>(m_pDocument); }
#endif

