
// MFC002View.cpp : CMFC002View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC002.h"
#endif

#include "MFC002Doc.h"
#include "MFC002View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC002View

IMPLEMENT_DYNCREATE(CMFC002View, CView)

BEGIN_MESSAGE_MAP(CMFC002View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC002View ����/����

CMFC002View::CMFC002View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC002View::~CMFC002View()
{
}

BOOL CMFC002View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC002View ����

void CMFC002View::OnDraw(CDC* pDC)
{
	CMFC002Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString J;
	J.Format(pDoc->S + _T("  %d"), pDoc->A);
	pDC->TextOutW(200, 200, J);
		
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC002View ��ӡ

BOOL CMFC002View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC002View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC002View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC002View ���

#ifdef _DEBUG
void CMFC002View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC002View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC002Doc* CMFC002View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC002Doc)));
	return (CMFC002Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC002View ��Ϣ�������
