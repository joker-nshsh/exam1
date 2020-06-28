
// MFC30View.h : CMFC30View ��Ľӿ�
//

#pragma once


class CMFC30View : public CView
{
protected: // �������л�����
	CMFC30View();
	DECLARE_DYNCREATE(CMFC30View)

// ����
public:
	CMFC30Doc* GetDocument() const;

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
	virtual ~CMFC30View();
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
	afx_msg void On32772();
};

#ifndef _DEBUG  // MFC30View.cpp �еĵ��԰汾
inline CMFC30Doc* CMFC30View::GetDocument() const
   { return reinterpret_cast<CMFC30Doc*>(m_pDocument); }
#endif

