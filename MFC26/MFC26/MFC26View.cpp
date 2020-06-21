
// MFC26View.cpp : CMFC26View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC26.h"
#endif

#include "MFC26Doc.h"
#include "MFC26View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC26View

IMPLEMENT_DYNCREATE(CMFC26View, CView)

BEGIN_MESSAGE_MAP(CMFC26View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC26View::On32771)
END_MESSAGE_MAP()

// CMFC26View ����/����

CMFC26View::CMFC26View()
{
	// TODO:  �ڴ˴���ӹ������
	a.top = 200, a.left = 200;
	a.bottom = 400;
	a.right = 500;
}

CMFC26View::~CMFC26View()
{
}

BOOL CMFC26View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC26View ����

void CMFC26View::OnDraw(CDC* pDC)
{
	CMFC26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush brush(RGB(R, X, Y));//�����Լ���Ҫ�������ɫ
	CBrush *oldbrush;
	oldbrush = pDC->SelectObject(&brush);//ѡ�µĻ���ˢ
	pDC->Ellipse(a);
	pDC->SelectObject(oldbrush);
	

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC26View ��ӡ

BOOL CMFC26View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC26View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC26View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC26View ���

#ifdef _DEBUG
void CMFC26View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC26View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC26Doc* CMFC26View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC26Doc)));
	return (CMFC26Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC26View ��Ϣ�������


void CMFC26View::On32771()
{
	// TODO:  �ڴ���������������
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
	
		R = dlg.a1;
		X = dlg.a2;
		Y = dlg.a3;
		Invalidate();
	}
}
