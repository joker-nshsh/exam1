
// MFC16View.h : CMFC16View ��Ľӿ�
//

#pragma once


class CMFC16View : public CView
{
protected: // �������л�����
	CMFC16View();
	DECLARE_DYNCREATE(CMFC16View)

// ����
public:
	CMFC16Doc* GetDocument() const;
	CString s;
	CDialog dlg;
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
	virtual ~CMFC16View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On10();
	afx_msg void OnBnClickedOk();
};

#ifndef _DEBUG  // MFC16View.cpp �еĵ��԰汾
inline CMFC16Doc* CMFC16View::GetDocument() const
   { return reinterpret_cast<CMFC16Doc*>(m_pDocument); }
#endif

