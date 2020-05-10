
// MFC12View.h : CMFC12View ��Ľӿ�
//

#pragma once


class CMFC12View : public CView
{
protected: // �������л�����
	CMFC12View();
	DECLARE_DYNCREATE(CMFC12View)

// ����
public:
	CMFC12Doc* GetDocument() const;



// ����
public:
	CBitmap b;
	int width;
	int height;
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
	virtual ~CMFC12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC12View.cpp �еĵ��԰汾
inline CMFC12Doc* CMFC12View::GetDocument() const
   { return reinterpret_cast<CMFC12Doc*>(m_pDocument); }
#endif

