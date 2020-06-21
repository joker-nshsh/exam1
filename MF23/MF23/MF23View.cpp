
// MF23View.cpp : CMF23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MF23.h"
#endif

#include "MF23Doc.h"
#include "MF23View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMF23View

IMPLEMENT_DYNCREATE(CMF23View, CView)

BEGIN_MESSAGE_MAP(CMF23View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMF23View::On32771)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMF23View ����/����

CMF23View::CMF23View()
{
	// TODO:  �ڴ˴���ӹ������
	

}

CMF23View::~CMF23View()
{
}

BOOL CMF23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMF23View ����

void CMF23View::OnDraw(CDC* pDC)
{
	CMF23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(a);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMF23View ��ӡ

BOOL CMF23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMF23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMF23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMF23View ���

#ifdef _DEBUG
void CMF23View::AssertValid() const
{
	CView::AssertValid();
}

void CMF23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMF23Doc* CMF23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMF23Doc)));
	return (CMF23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMF23View ��Ϣ�������


void CMF23View::On32771()
{
	// TODO:  �ڴ���������������
	Invalidate();
}


void CMF23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);
	a.left = point.x;
	a.top = point.y;
	a1 = 1;
}


void CMF23View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonUp(nFlags, point);
	a.right = point.x;
	a.bottom = point.y;
	Invalidate();
	a1 = 0;
}


void CMF23View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnMouseMove(nFlags, point);
	a.right = point.x;
	a.bottom = point.y;
	if(a1==1)
	{
		Invalidate();
	}
	
}
