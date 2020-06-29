
// usinglb3View.cpp : Cusinglb3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "usinglb3.h"
#endif

#include "usinglb3Doc.h"
#include "usinglb3View.h"
#include"w32.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cusinglb3View

IMPLEMENT_DYNCREATE(Cusinglb3View, CView)

BEGIN_MESSAGE_MAP(Cusinglb3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cusinglb3View ����/����

Cusinglb3View::Cusinglb3View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cusinglb3View::~Cusinglb3View()
{
}

BOOL Cusinglb3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cusinglb3View ����

void Cusinglb3View::OnDraw(CDC* pDC)
{
	Cusinglb3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString ss;
	float c = convert(30.0);
	ss.Format(_T("%lf,���ǽǶ�30.0����̬��ת���õ��Ļ��ȡ�"), c);
	pDC->TextOutW(200, 180, ss);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cusinglb3View ��ӡ

BOOL Cusinglb3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cusinglb3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cusinglb3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Cusinglb3View ���

#ifdef _DEBUG
void Cusinglb3View::AssertValid() const
{
	CView::AssertValid();
}

void Cusinglb3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cusinglb3Doc* Cusinglb3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cusinglb3Doc)));
	return (Cusinglb3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cusinglb3View ��Ϣ�������
