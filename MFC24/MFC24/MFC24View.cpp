
// MFC24View.cpp : CMFC24View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC24.h"
#endif
#include "MyDlg0.h"
#include "MFC24Doc.h"
#include "MFC24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC24View

IMPLEMENT_DYNCREATE(CMFC24View, CView)

BEGIN_MESSAGE_MAP(CMFC24View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC24View::On32771)
END_MESSAGE_MAP()

// CMFC24View ����/����

CMFC24View::CMFC24View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC24View::~CMFC24View()
{
}

BOOL CMFC24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC24View ����

void CMFC24View::OnDraw(CDC* /*pDC*/)
{
	CMFC24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC24View ��ӡ

BOOL CMFC24View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC24View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC24View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC24View ���

#ifdef _DEBUG
void CMFC24View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC24Doc* CMFC24View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC24Doc)));
	return (CMFC24Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC24View ��Ϣ�������


void CMFC24View::On32771()
{
	// TODO:  �ڴ���������������
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int E, F, G, H;
		E = dlg.top1;
		F = dlg.left1;
		G = dlg.bottom1;
		H = dlg.right1;
		CRect re(E, F, G, H);
		GetDC()->Ellipse(re);

	}
}
