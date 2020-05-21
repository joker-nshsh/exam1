
// MFC17View.h : CMFC17View ��Ľӿ�
//

#pragma once


class CMFC17View : public CView
{
protected: // �������л�����
	CMFC17View();
	DECLARE_DYNCREATE(CMFC17View)

// ����
public:
	CMFC17Doc* GetDocument() const;

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
	virtual ~CMFC17View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onzifu();
};

#ifndef _DEBUG  // MFC17View.cpp �еĵ��԰汾
inline CMFC17Doc* CMFC17View::GetDocument() const
   { return reinterpret_cast<CMFC17Doc*>(m_pDocument); }
#endif

