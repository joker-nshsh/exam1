
// MF23View.cpp : CMF23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MF23.h"
#endif

#include "MF23Doc.h"
#include "MF23View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMF23View

IMPLEMENT_DYNCREATE(CMF23View, CView)

BEGIN_MESSAGE_MAP(CMF23View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMF23View::On32771)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMF23View 构造/析构

CMF23View::CMF23View()
{
	// TODO:  在此处添加构造代码
	

}

CMF23View::~CMF23View()
{
}

BOOL CMF23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMF23View 绘制

void CMF23View::OnDraw(CDC* pDC)
{
	CMF23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(a);
	// TODO:  在此处为本机数据添加绘制代码
}


// CMF23View 打印

BOOL CMF23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMF23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMF23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMF23View 诊断

#ifdef _DEBUG
void CMF23View::AssertValid() const
{
	CView::AssertValid();
}

void CMF23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMF23Doc* CMF23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMF23Doc)));
	return (CMF23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMF23View 消息处理程序


void CMF23View::On32771()
{
	// TODO:  在此添加命令处理程序代码
	Invalidate();
}


void CMF23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	a.left = point.x;
	a.top = point.y;
	a1 = 1;
}


void CMF23View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
	a.right = point.x;
	a.bottom = point.y;
	Invalidate();
	a1 = 0;
}


void CMF23View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
	a.right = point.x;
	a.bottom = point.y;
	if(a1==1)
	{
		Invalidate();
	}
	
}
