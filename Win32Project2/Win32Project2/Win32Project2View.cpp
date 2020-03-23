
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
END_MESSAGE_MAP()

// CWin32Project2View ����/����

CWin32Project2View::CWin32Project2View()
{
	// TODO:  �ڴ˴���ӹ������
	set = true;
	N = 5;
	j = 1;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 40,40);
		cr.Add(rect);
	}
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
	if (set)
	{
		for (int i = 0; i < N; i++)
		{ 
			SetTimer(i, rand() % 400 + 100, NULL);
			set = false;
		}
		
	}
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[0]);

	}
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
	GetClientRect(&rc);
	int s1 = GetSystemMetrics(SM_CXSCREEN);
	CString s;
	int x = rc.Height();
	s.Format(_T("%d"),x);
	//clientDC.TextOut(50,50,s);
	int s2 = GetSystemMetrics(SM_CYSCREEN);
	if (j == 1)
	{
		cr[i].top += 10;
		cr[i].bottom += 10;
		Invalidate();
	}
	if (cr[i].bottom >= x)
	{
		j = 0;
	}
	if (j == 0)
	{
		cr[i].top -= 20;
		cr[i].bottom -= 20;
		Invalidate();
	}
	

	
	
	CView::OnTimer(nIDEvent);
}
