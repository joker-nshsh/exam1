
// usinglb2View.cpp : Cusinglb2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "usinglb2.h"
#endif
#include"w32.h"
#include "usinglb2Doc.h"
#include "usinglb2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cusinglb2View

IMPLEMENT_DYNCREATE(Cusinglb2View, CView)

BEGIN_MESSAGE_MAP(Cusinglb2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cusinglb2View ����/����

Cusinglb2View::Cusinglb2View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cusinglb2View::~Cusinglb2View()
{
}

BOOL Cusinglb2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cusinglb2View ����

void Cusinglb2View::OnDraw(CDC* pDC)
{
	Cusinglb2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CString ss;
	int c = Fact(5);
	ss.Format(_T("%d,����5�Ľ׳˾���̬��õ��ġ�"),c);
	pDC->TextOutW(200, 180, ss);

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cusinglb2View ��ӡ

BOOL Cusinglb2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cusinglb2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cusinglb2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Cusinglb2View ���

#ifdef _DEBUG
void Cusinglb2View::AssertValid() const
{
	CView::AssertValid();
}

void Cusinglb2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cusinglb2Doc* Cusinglb2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cusinglb2Doc)));
	return (Cusinglb2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cusinglb2View ��Ϣ�������
