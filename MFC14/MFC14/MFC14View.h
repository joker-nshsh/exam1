
// MFC14View.h : CMFC14View ��Ľӿ�
//

#pragma once


class CMFC14View : public CView
{
protected: // �������л�����
	CMFC14View();
	DECLARE_DYNCREATE(CMFC14View)

// ����
public:
	CMFC14Doc* GetDocument() const;

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
	virtual ~CMFC14View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC14View.cpp �еĵ��԰汾
inline CMFC14Doc* CMFC14View::GetDocument() const
   { return reinterpret_cast<CMFC14Doc*>(m_pDocument); }
#endif

