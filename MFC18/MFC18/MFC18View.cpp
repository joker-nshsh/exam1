
// MFC18View.cpp : CMFC18View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC18.h"
#endif

#include "MFC18Doc.h"
#include "MFC18View.h"
#include"MyDlgo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC18View

IMPLEMENT_DYNCREATE(CMFC18View, CView)

BEGIN_MESSAGE_MAP(CMFC18View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC18View::On32771)
END_MESSAGE_MAP()

// CMFC18View ����/����

CMFC18View::CMFC18View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC18View::~CMFC18View()
{
}

BOOL CMFC18View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC18View ����

void CMFC18View::OnDraw(CDC* /*pDC*/)
{
	CMFC18Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC18View ��ӡ

BOOL CMFC18View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC18View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC18View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC18View ���

#ifdef _DEBUG
void CMFC18View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC18View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC18Doc* CMFC18View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC18Doc)));
	return (CMFC18Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC18View ��Ϣ�������


void CMFC18View::On32771()
{
	// TODO:  �ڴ���������������
	MyDlgo dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int A, B, C;
		A = dlg.a;
		B = dlg.b;
		

	}
}
