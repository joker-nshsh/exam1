
// MFC8View.cpp : CMFC8View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC8.h"
#endif

#include "MFC8Doc.h"
#include "MFC8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC8View

IMPLEMENT_DYNCREATE(CMFC8View, CView)

BEGIN_MESSAGE_MAP(CMFC8View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC8View ����/����

CMFC8View::CMFC8View()
{
	// TODO:  �ڴ˴���ӹ������
	j.top = 0; j.left = 0; j.right = 0; j.bottom = 0;
	int a1, a2, a = 0;

}

CMFC8View::~CMFC8View()
{
}

BOOL CMFC8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC8View ����

void CMFC8View::OnDraw(CDC* pDC)
{
	CMFC8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(j);

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC8View ���

#ifdef _DEBUG
void CMFC8View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC8Doc* CMFC8View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC8Doc)));
	return (CMFC8Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC8View ��Ϣ�������


void CMFC8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	a1 = point.x;
	a2 = point.y;
	a = rand() % 100+50;
	j.top = a2-a; j.left =a1-a ; j.right = a1+a; j.bottom = a2+a;



	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
