
// MF25View.cpp : CMF25View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MF25.h"
#endif

#include "MF25Doc.h"
#include "MF25View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMF25View

IMPLEMENT_DYNCREATE(CMF25View, CView)

BEGIN_MESSAGE_MAP(CMF25View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMF25View ����/����

CMF25View::CMF25View()
{
	// TODO:  �ڴ˴���ӹ������
	a.top = 200; a.left = 200;
	a.right = 500; a.bottom = 400;
}

CMF25View::~CMF25View()
{
}

BOOL CMF25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMF25View ����

void CMF25View::OnDraw(CDC* pDC)
{
	CMF25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC*dc = GetDC();
	CPen *oldpen = NULL;
	CPen pen;
	pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	dc->SelectObject(pen);
	dc->Rectangle(&b);
	dc->Ellipse(a);
	dc->SelectObject(oldpen);
	pen.DeleteObject();
	pDC->Ellipse(a);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMF25View ��ӡ

BOOL CMF25View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMF25View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMF25View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMF25View ���

#ifdef _DEBUG
void CMF25View::AssertValid() const
{
	CView::AssertValid();
}

void CMF25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMF25Doc* CMF25View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMF25Doc)));
	return (CMF25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMF25View ��Ϣ�������


void CMF25View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	BOOL b1 = a.PtInRect(point);
	CDC*dc = GetDC();
	if (b1==1)
	{
		b.top = a.top;
		b.left = a.left;
		b.bottom = a.bottom;
		b.right = a.right;
		Invalidate();
	}
	else
	{
		b.top = 0;
		b.left = 0;
		b.bottom = 0;
		b.right = 0;
		Invalidate();
	}
	CView::OnLButtonDown(nFlags, point);
}
