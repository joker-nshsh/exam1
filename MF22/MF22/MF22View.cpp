
// MF22View.cpp : CMF22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MF22.h"
#endif

#include "MF22Doc.h"
#include "MF22View.h"
#include "Mydlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMF22View

IMPLEMENT_DYNCREATE(CMF22View, CView)

BEGIN_MESSAGE_MAP(CMF22View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMF22View::On32771)
END_MESSAGE_MAP()

// CMF22View ����/����

CMF22View::CMF22View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMF22View::~CMF22View()
{
}

BOOL CMF22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMF22View ����

void CMF22View::OnDraw(CDC* /*pDC*/)
{
	CMF22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMF22View ��ӡ

BOOL CMF22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMF22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMF22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMF22View ���

#ifdef _DEBUG
void CMF22View::AssertValid() const
{
	CView::AssertValid();
}

void CMF22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMF22Doc* CMF22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMF22Doc)));
	return (CMF22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMF22View ��Ϣ�������


void CMF22View::On32771()
{
	// TODO:  �ڴ���������������
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int A, B, C;
		A = dlg.a;
		B = dlg.b;
		C = dlg.c;

	}
}
