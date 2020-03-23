
// Win32Project2View.cpp : CWin32Project2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CWin32Project2View 构造/析构

CWin32Project2View::CWin32Project2View()
{
	// TODO:  在此处添加构造代码
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
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWin32Project2View 绘制

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
	// TODO:  在此处为本机数据添加绘制代码
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[0]);

	}
}


// CWin32Project2View 打印

BOOL CWin32Project2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CWin32Project2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CWin32Project2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CWin32Project2View 诊断

#ifdef _DEBUG
void CWin32Project2View::AssertValid() const
{
	CView::AssertValid();
}

void CWin32Project2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWin32Project2Doc* CWin32Project2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWin32Project2Doc)));
	return (CWin32Project2Doc*)m_pDocument;
}
#endif //_DEBUG


// CWin32Project2View 消息处理程序


void CWin32Project2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
