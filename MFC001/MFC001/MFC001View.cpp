
// MFC001View.cpp : CMFC001View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC001.h"
#endif

#include "MFC001Doc.h"
#include "MFC001View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC001View

IMPLEMENT_DYNCREATE(CMFC001View, CView)

BEGIN_MESSAGE_MAP(CMFC001View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC001View ����/����

CMFC001View::CMFC001View()
{
	// TODO:  �ڴ˴���ӹ������
	k = 1;

}

CMFC001View::~CMFC001View()
{
}

BOOL CMFC001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC001View ����

void CMFC001View::OnDraw(CDC* pDC)
{
	CMFC001Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString c;

	c.Format( _T(" %d"), pDoc->count);

	pDC->TextOutW(200, 200, c);

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}



// CMFC001View ��ӡ

BOOL CMFC001View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC001View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC001View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC001View ���

#ifdef _DEBUG
void CMFC001View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC001View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC001Doc* CMFC001View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC001Doc)));
	return (CMFC001Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC001View ��Ϣ�������


void CMFC001View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ


	CMFC001Doc* pDoc = GetDocument();
	
	k += 1;

	pDoc->count= k;
	CView::OnLButtonDown(nFlags, point);

}


void CMFC001View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CMFC001Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s;

	/*s.Format(_T("%d", pDoc->z));
	
	dc.TextOutW(200,200,s);*/
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
