
// MFC20View.cpp : CMFC20View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC20.h"
#endif

#include "MFC20Doc.h"
#include "MFC20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC20View

IMPLEMENT_DYNCREATE(CMFC20View, CView)

BEGIN_MESSAGE_MAP(CMFC20View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC20View ����/����

CMFC20View::CMFC20View()
{
	// TODO:  �ڴ˴���ӹ������
	a.bottom = 200;
	a.left = 150;
	a.right = 250;
	a.top = 100;

}

CMFC20View::~CMFC20View()
{
}

BOOL CMFC20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC20View ����

void CMFC20View::OnDraw(CDC* pDC)
{
	CMFC20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(a);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC20View ��ӡ

BOOL CMFC20View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC20View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC20View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC20View ���

#ifdef _DEBUG
void CMFC20View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC20View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC20Doc* CMFC20View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC20Doc)));
	return (CMFC20Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC20View ��Ϣ�������


void CMFC20View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	b = point.x; c = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC20View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	d = point.x; e = point.y;
	a.left += d - b; a.right += d - b;
	a.bottom += e - c; a.top += e - c;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
