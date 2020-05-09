
// MFC9View.cpp : CMFC9View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC9.h"
#endif

#include "MFC9Doc.h"
#include "MFC9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC9View

IMPLEMENT_DYNCREATE(CMFC9View, CView)

BEGIN_MESSAGE_MAP(CMFC9View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC9View ����/����

CMFC9View::CMFC9View()
{
	// TODO:  �ڴ˴���ӹ������
	// TODO:  �ڴ˴���ӹ������
	j.top = 0; j.left = 0; j.right = 0; j.bottom = 0;
	int a1, a2, a = 0;
}

CMFC9View::~CMFC9View()
{
}

BOOL CMFC9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC9View ����

void CMFC9View::OnDraw(CDC* pDC)
{
	CMFC9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&j);
	pDC->Ellipse(j);

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC9View ��ӡ

BOOL CMFC9View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC9View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC9View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC9View ���

#ifdef _DEBUG
void CMFC9View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC9Doc* CMFC9View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC9Doc)));
	return (CMFC9Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC9View ��Ϣ�������
