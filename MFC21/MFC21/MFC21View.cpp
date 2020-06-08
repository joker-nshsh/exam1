
// MFC21View.cpp : CMFC21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC21.h"
#endif

#include "MFC21Doc.h"
#include "MFC21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC21View

IMPLEMENT_DYNCREATE(CMFC21View, CView)

BEGIN_MESSAGE_MAP(CMFC21View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_XBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC21View ����/����

CMFC21View::CMFC21View()
{
	// TODO:  �ڴ˴���ӹ������
	a.top = 100; a.bottom = 200;
	a.left = 150; a.right = 250;
	set = true;
	j = 3;
	k = 0;

}

CMFC21View::~CMFC21View()
{
}

BOOL CMFC21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC21View ����

void CMFC21View::OnDraw(CDC* pDC)
{
	CMFC21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		SetTimer(0, rand() % 400 + 100, NULL);
		set = false;
	}
	pDC->Ellipse(a);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC21View ��ӡ

BOOL CMFC21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC21View ���

#ifdef _DEBUG
void CMFC21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC21Doc* CMFC21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC21Doc)));
	return (CMFC21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC21View ��Ϣ�������


void CMFC21View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect b;
	GetClientRect(&b);
	if (j == 0&&a.right<=b.right/2&&k==0)
	{
		a.left += 30;
		a.right += 30;
		Invalidate();
	}
	if (a.right > b.right / 2)

	{
		k = 1;
	}
	if (j == 0  && k == 1)
	{
		a.left -= 30;
		a.right -= 30;
		Invalidate();
	}

	
	CView::OnTimer(nIDEvent);
	
}


void CMFC21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//DWORD st = GetTickCount();
	
		j = 0;
	
	
	CView::OnLButtonDown(nFlags, point);
}





void CMFC21View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	j = 1;
	CView::OnLButtonDblClk(nFlags, point);
}
