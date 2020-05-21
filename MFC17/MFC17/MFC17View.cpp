
// MFC17View.cpp : CMFC17View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC17.h"
#endif

#include "MFC17Doc.h"
#include "MFC17View.h"
#include "MyDlgo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC17View

IMPLEMENT_DYNCREATE(CMFC17View, CView)

BEGIN_MESSAGE_MAP(CMFC17View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_zifu, &CMFC17View::Onzifu)
END_MESSAGE_MAP()

// CMFC17View ����/����

CMFC17View::CMFC17View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC17View::~CMFC17View()
{
}

BOOL CMFC17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC17View ����

void CMFC17View::OnDraw(CDC* /*pDC*/)
{
	CMFC17Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC17View ��ӡ

BOOL CMFC17View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC17View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC17View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC17View ���

#ifdef _DEBUG
void CMFC17View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC17View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC17Doc* CMFC17View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC17Doc)));
	return (CMFC17Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC17View ��Ϣ�������


void CMFC17View::Onzifu()
{
	// TODO:  �ڴ���������������
	MyDlgo dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		CString X, Y;
		X = dlg.x;
		Y = dlg.y;
	}
}
