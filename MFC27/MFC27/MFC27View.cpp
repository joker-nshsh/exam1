
// MFC27View.cpp : CMFC27View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC27.h"
#endif

#include "MFC27Doc.h"
#include "MFC27View.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC27View

IMPLEMENT_DYNCREATE(CMFC27View, CView)

BEGIN_MESSAGE_MAP(CMFC27View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC27View::On32771)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC27View ����/����

CMFC27View::CMFC27View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC27View::~CMFC27View()
{
}

BOOL CMFC27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC27View ����

void CMFC27View::OnDraw(CDC* /*pDC*/)
{
	CMFC27Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC27View ��ӡ

BOOL CMFC27View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC27View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC27View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC27View ���

#ifdef _DEBUG
void CMFC27View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC27View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC27Doc* CMFC27View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC27Doc)));
	return (CMFC27Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC27View ��Ϣ�������


void CMFC27View::On32771()
{
	CMFC27Doc*pDoc = GetDocument();
	MyDlg1 md1;
	
	md1.s = pDoc->filename;
	int r = md1.DoModal();
	
	
	if (r == IDOK)
	{
		
	}
	// TODO:  �ڴ���������������
}


void CMFC27View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	CMFC27Doc*pDoc = GetDocument();
	if (r == IDOK)
	{
		pDoc->filename = cfd.GetPathName();
		dc.TextOutW(200, 300, pDoc->filename);

	}
	CView::OnLButtonDblClk(nFlags, point);
}
