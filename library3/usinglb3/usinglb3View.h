
// usinglb3View.h : Cusinglb3View ��Ľӿ�
//

#pragma once


class Cusinglb3View : public CView
{
protected: // �������л�����
	Cusinglb3View();
	DECLARE_DYNCREATE(Cusinglb3View)

// ����
public:
	Cusinglb3Doc* GetDocument() const;

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
	virtual ~Cusinglb3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // usinglb3View.cpp �еĵ��԰汾
inline Cusinglb3Doc* Cusinglb3View::GetDocument() const
   { return reinterpret_cast<Cusinglb3Doc*>(m_pDocument); }
#endif

