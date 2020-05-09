
// MFC8View.cpp : CMFC8View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC8.h"
#endif

#include "MFC8Doc.h"
#include "MFC8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC8View

IMPLEMENT_DYNCREATE(CMFC8View, CView)

BEGIN_MESSAGE_MAP(CMFC8View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC8View 构造/析构

CMFC8View::CMFC8View()
{
	// TODO:  在此处添加构造代码
	j.top = 0; j.left = 0; j.right = 0; j.bottom = 0;
	int a1, a2, a = 0;

}

CMFC8View::~CMFC8View()
{
}

BOOL CMFC8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC8View 绘制

void CMFC8View::OnDraw(CDC* pDC)
{
	CMFC8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(j);

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC8View 诊断

#ifdef _DEBUG
void CMFC8View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC8Doc* CMFC8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC8Doc)));
	return (CMFC8Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC8View 消息处理程序


void CMFC8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	a1 = point.x;
	a2 = point.y;
	a = rand() % 100+50;
	j.top = a2-a; j.left =a1-a ; j.right = a1+a; j.bottom = a2+a;



	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
