
// MFC13View.cpp : CMFC13View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC13.h"
#endif

#include "MFC13Doc.h"
#include "MFC13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC13View

IMPLEMENT_DYNCREATE(CMFC13View, CView)

BEGIN_MESSAGE_MAP(CMFC13View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_juxing, &CMFC13View::Onjuxing)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_yuan, &CMFC13View::Onyuan)
	ON_COMMAND(ID_zhixian, &CMFC13View::Onzhixian)
END_MESSAGE_MAP()

// CMFC13View ����/����

CMFC13View::CMFC13View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC13View::~CMFC13View()
{
}

BOOL CMFC13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC13View ����

void CMFC13View::OnDraw(CDC* pDC)
{
	CMFC13Doc* pDoc = GetDocument();
	int width = 2;
	int red = 0,green = 0, blue = 0;
	ASSERT_VALID(pDoc);
	int color = RGB(red, green, blue);
	CPen newpen(PS_SOLID, width, color);
	CPen*oldpen = pDC ->SelectObject(&newpen);
	if (!pDoc)
		return;
	if (e == 1)
	{
		pDC->Rectangle(aa);
	}
	if (e == 2)
	{
		pDC->Ellipse(aa);
	}
	if (e == 3)
	{
		pDC->MoveTo(pt1);
		pDC->LineTo(pt2);
		pDC->SelectObject(oldpen);
	}
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC13View ��ӡ

BOOL CMFC13View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC13View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC13View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC13View ���

#ifdef _DEBUG
void CMFC13View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC13Doc* CMFC13View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC13Doc)));
	return (CMFC13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC13View ��Ϣ�������


void CMFC13View::Onjuxing()
{
	// TODO:  �ڴ���������������
	e = 1;
	aa.top = b; aa.left = a; aa.right = c; aa.bottom = d;
	;
	Invalidate();


}


void CMFC13View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);
	if (e == 1)
	{
		a = point.x, b = point.y;
		aa.top = b; aa.left = a;
	}
	if (e == 2)
	{
		aa.left = point.x, aa.top = point.y;
	}
	if (e == 3)
	{
		pt1.x = point.x; pt1.y = point.y;
	}
}


void CMFC13View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if (e == 1)
	{
	
	c = point.x, d = point.y;
	aa.right = c; aa.bottom = d;
	;
	Invalidate();
}
	if (e == 2)
	{
		aa.right = point.x, aa.bottom = point.y;
		Invalidate();
	}
	if (e == 3)
	{
		pt2.x = point.x; pt2.y = point.y;
		Invalidate();
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMFC13View::Onyuan()
{
	e = 2;
	// TODO:  �ڴ���������������
}


void CMFC13View::Onzhixian()
{
	// TODO:  �ڴ���������������
	e = 3;
	
}
