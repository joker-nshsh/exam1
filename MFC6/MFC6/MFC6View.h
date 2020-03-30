
// MFC6View.h : CMFC6View ��Ľӿ�
//

#pragma once


class CMFC6View : public CView
{
protected: // �������л�����
	CMFC6View();
	DECLARE_DYNCREATE(CMFC6View)

// ����
public:
	CMFC6Doc* GetDocument() const;

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
	virtual ~CMFC6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFC6View.cpp �еĵ��԰汾
inline CMFC6Doc* CMFC6View::GetDocument() const
   { return reinterpret_cast<CMFC6Doc*>(m_pDocument); }
#endif
