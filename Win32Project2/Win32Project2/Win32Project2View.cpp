
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
	ON_COMMAND(ID_huayuan, &CWin32Project2View::Onhuayuan)
END_MESSAGE_MAP()

// CWin32Project2View 构造/析构

CWin32Project2View::CWin32Project2View()
{
	// TODO:  在此处添加构造代码
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
	
	CPen cPen;
	cPen.CreatePen(PS_SOLID, 1,RGB(red,green,blue));

	CPen* oldpen = pDC->SelectObject(&cPen);

		pDC->Ellipse(rc);
		pDC->SelectObject(oldpen);

	
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
	// TODO:  在此添加命令处理程序代码
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
	// TODO:  在此处为本机数据添加绘制代码
	rc.top = dc.bottom / 2 - 30; rc.left = dc.right / 2 - 30; rc.right = dc.right / 2 + 30; rc.bottom = dc.bottom / 2 + 30;
		
		Invalidate();
	

}
