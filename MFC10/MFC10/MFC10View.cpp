
// MFC10View.cpp : CMFC10View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC10.h"
#endif

#include "MFC10Doc.h"
#include "MFC10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC10View

IMPLEMENT_DYNCREATE(CMFC10View, CView)

BEGIN_MESSAGE_MAP(CMFC10View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC10View ����/����

CMFC10View::CMFC10View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC10View::~CMFC10View()
{
}

BOOL CMFC10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC10View ����

void CMFC10View::OnDraw(CDC* pDC)
{
	CMFC10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&j);
	
	 pDC = GetDC(); // �õ�DC
	CBrush brush(RGB(1, 255, 255));//�����Լ���Ҫ�������ɫ
	CBrush *oldbrush;
	oldbrush = pDC->SelectObject(&brush);//ѡ�µĻ���ˢ
	pDC->Ellipse(j);
	pDC->SelectObject(oldbrush);//��ԭ���Ļ�ˢѡ��ȥ
	 // �ͷ���DC

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC10View ��ӡ

BOOL CMFC10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC10View ���

#ifdef _DEBUG
void CMFC10View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC10Doc* CMFC10View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC10Doc)));
	return (CMFC10Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC10View ��Ϣ�������
