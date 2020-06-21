
// MF22View.h : CMF22View ��Ľӿ�
//

#pragma once


class CMF22View : public CView
{
protected: // �������л�����
	CMF22View();
	DECLARE_DYNCREATE(CMF22View)

// ����
public:
	CMF22Doc* GetDocument() const;

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
	virtual ~CMF22View();
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

#ifndef _DEBUG  // MF22View.cpp �еĵ��԰汾
inline CMF22Doc* CMF22View::GetDocument() const
   { return reinterpret_cast<CMF22Doc*>(m_pDocument); }
#endif

