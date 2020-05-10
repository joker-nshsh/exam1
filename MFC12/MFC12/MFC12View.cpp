
// MFC12View.cpp : CMFC12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC12.h"
#endif

#include "MFC12Doc.h"
#include "MFC12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC12View

IMPLEMENT_DYNCREATE(CMFC12View, CView)

BEGIN_MESSAGE_MAP(CMFC12View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC12View ����/����

CMFC12View::CMFC12View()
{
	// TODO:  �ڴ˴���ӹ������
	BITMAP BM;
	b.LoadBitmap(IDB_BITMAP1);
	b.GetBitmap(&BM);
	width = BM.bmWidth;
	height = BM.bmHeight;

}

CMFC12View::~CMFC12View()
{
}

BOOL CMFC12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC12View ����

void CMFC12View::OnDraw(CDC* pDC)
{
	CMFC12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(b);
	pDC->BitBlt(0, 0, width, height, &MemDC, 0, 0, SRCCOPY);


	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC12View ��ӡ

BOOL CMFC12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC12View ���

#ifdef _DEBUG
void CMFC12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC12Doc* CMFC12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC12Doc)));
	return (CMFC12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC12View ��Ϣ�������
