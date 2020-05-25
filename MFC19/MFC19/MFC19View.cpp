
// MFC19View.cpp : CMFC19View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC19.h"
#endif

#include "MFC19Doc.h"
#include "MFC19View.h"
#include"MyDlgo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC19View

IMPLEMENT_DYNCREATE(CMFC19View, CView)

BEGIN_MESSAGE_MAP(CMFC19View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC19View::On32771)
END_MESSAGE_MAP()

// CMFC19View ����/����

CMFC19View::CMFC19View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC19View::~CMFC19View()
{
}

BOOL CMFC19View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC19View ����

void CMFC19View::OnDraw(CDC* /*pDC*/)
{
	CMFC19Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC19View ��ӡ

BOOL CMFC19View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC19View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC19View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC19View ���

#ifdef _DEBUG
void CMFC19View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC19View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC19Doc* CMFC19View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC19Doc)));
	return (CMFC19Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC19View ��Ϣ�������


void CMFC19View::On32771()
{
	// TODO:  �ڴ���������������
	MyDlgo dlg;
	int t = dlg.DoModal();

}
