
// usinglb2View.h : Cusinglb2View ��Ľӿ�
//

#pragma once


class Cusinglb2View : public CView
{
protected: // �������л�����
	Cusinglb2View();
	DECLARE_DYNCREATE(Cusinglb2View)

// ����
public:
	Cusinglb2Doc* GetDocument() const;

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
	virtual ~Cusinglb2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // usinglb2View.cpp �еĵ��԰汾
inline Cusinglb2Doc* Cusinglb2View::GetDocument() const
   { return reinterpret_cast<Cusinglb2Doc*>(m_pDocument); }
#endif

