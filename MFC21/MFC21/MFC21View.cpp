
// MFC21View.cpp : CMFC21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_XBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC21View 构造/析构

CMFC21View::CMFC21View()
{
	// TODO:  在此处添加构造代码
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
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC21View 绘制

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
	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC21View 打印

BOOL CMFC21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC21View 诊断

#ifdef _DEBUG
void CMFC21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC21Doc* CMFC21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC21Doc)));
	return (CMFC21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC21View 消息处理程序


void CMFC21View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//DWORD st = GetTickCount();
	
		j = 0;
	
	
	CView::OnLButtonDown(nFlags, point);
}





void CMFC21View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	j = 1;
	CView::OnLButtonDblClk(nFlags, point);
}
