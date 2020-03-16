
// MFC4View.cpp : CMFC4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC4.h"
#endif

#include "MFC4Doc.h"
#include "MFC4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4View

IMPLEMENT_DYNCREATE(CMFC4View, CView)

BEGIN_MESSAGE_MAP(CMFC4View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC4View ����/����

CMFC4View::CMFC4View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC4View::~CMFC4View()
{
}

BOOL CMFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC4View ����

void CMFC4View::OnDraw(CDC* pDC)
{

	
	CMFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMFC4View ��ӡ

BOOL CMFC4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC4View ���

#ifdef _DEBUG
void CMFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4Doc* CMFC4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4Doc)));
	return (CMFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4View ��Ϣ�������


void CMFC4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC4Doc*pDoc=GetDocument();
	pDoc->m_tagRec.left = point.x;
	pDoc->m_tagRec.top = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFC4View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC4Doc*pDoc = GetDocument();
	CClientDC clientDC(this);
	int a = point.x; int b = point.y;
	CString s;
	
	s.Format(_T("X=%d  Y=%d"),a, b);
	clientDC.TextOut(20, 20, s);
	CView::OnMouseMove(nFlags, point);
}


void CMFC4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC4Doc*pDoc = GetDocument();
	pDoc->m_tagRec.right = point.x ;
	pDoc->m_tagRec.bottom = point.y ;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonUp(nFlags, point);
}
