
// Win32Project2View.cpp : CWin32Project2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Win32Project2.h"
#endif

#include "Win32Project2Doc.h"
#include "Win32Project2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWin32Project2View

IMPLEMENT_DYNCREATE(CWin32Project2View, CView)

BEGIN_MESSAGE_MAP(CWin32Project2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_COMMAND(ID_huayuan, &CWin32Project2View::Onhuayuan)
END_MESSAGE_MAP()

// CWin32Project2View ����/����

CWin32Project2View::CWin32Project2View()
{
	// TODO:  �ڴ˴���ӹ������
	set = true;
	N = 5;
	j = 1;
	/*for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t+40, 40);
		cr.Add(rect);
	}*/
	rc.top = 0; rc.left = 0; rc.right =0; rc.bottom = 0;
	dc.top = 0; dc.left = 0; dc.right = 0; dc.bottom = 0;
	red = 255; green = 0; blue = 0;
	
	
}

CWin32Project2View::~CWin32Project2View()
{
}

BOOL CWin32Project2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CWin32Project2View ����

void CWin32Project2View::OnDraw(CDC* pDC)
{
	CWin32Project2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CPen cPen;
	cPen.CreatePen(PS_SOLID, 1,RGB(red,green,blue));

	CPen* oldpen = pDC->SelectObject(&cPen);

		pDC->Ellipse(rc);
		pDC->SelectObject(oldpen);

	
}


// CWin32Project2View ��ӡ

BOOL CWin32Project2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CWin32Project2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CWin32Project2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CWin32Project2View ���

#ifdef _DEBUG
void CWin32Project2View::AssertValid() const
{
	CView::AssertValid();
}

void CWin32Project2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWin32Project2Doc* CWin32Project2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWin32Project2Doc)));
	return (CWin32Project2Doc*)m_pDocument;
}
#endif //_DEBUG


// CWin32Project2View ��Ϣ�������


void CWin32Project2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int i = nIDEvent;
	CClientDC clientDC(this);
	//GetClientRect(&rc);
	int s1 = GetSystemMetrics(SM_CXSCREEN);
	CString s;
	int x = dc.Height();
	
	
	int s2 = GetSystemMetrics(SM_CYSCREEN);
	if (rc.bottom < x)
	{
		rc.top = rc.top - 10; rc.left = rc.left-10; rc.right = rc.right + 10; rc.bottom = rc.bottom + 10;
		
		if (red>0)
		{
			red -= 30;
			green += 30;

		}
		if (green >= 255)
		{
			green -= 30;
			blue += 30;
		}
		Invalidate();
	}

	
	
	CView::OnTimer(nIDEvent);
}


void CWin32Project2View::Onhuayuan()
{
	// TODO:  �ڴ���������������
	N = 5;
	j = 1;
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 400 + 300, NULL);
			set = false;
		}

	}
	GetClientRect(&dc);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	rc.top = dc.bottom / 2 - 30; rc.left = dc.right / 2 - 30; rc.right = dc.right / 2 + 30; rc.bottom = dc.bottom / 2 + 30;
		
		Invalidate();
	

}
