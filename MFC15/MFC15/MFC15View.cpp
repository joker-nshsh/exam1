
// MFC15View.cpp : CMFC15View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC15.h"
#endif

#include "MFC15Doc.h"
#include "MFC15View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC15View

IMPLEMENT_DYNCREATE(CMFC15View, CView)

BEGIN_MESSAGE_MAP(CMFC15View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC15View ����/����

CMFC15View::CMFC15View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC15View::~CMFC15View()
{
}

BOOL CMFC15View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC15View ����

void CMFC15View::OnDraw(CDC* pDC)
{
	CMFC15Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString S,J;
	S = _T("��������ɽ");
	int A = 5;
	J.Format(S + _T("  %d"), A);
	pDC->TextOutW(200, 200, J);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC15View ��ӡ

BOOL CMFC15View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC15View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC15View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC15View ���

#ifdef _DEBUG
void CMFC15View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC15View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC15Doc* CMFC15View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC15Doc)));
	return (CMFC15Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC15View ��Ϣ�������
