
// MFC5View.cpp : CMFC5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC5.h"
#endif

#include "MFC5Doc.h"
#include "MFC5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC5View

IMPLEMENT_DYNCREATE(CMFC5View, CView)

BEGIN_MESSAGE_MAP(CMFC5View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC5View 构造/析构

CMFC5View::CMFC5View()
{
	// TODO:  在此处添加构造代码

}

CMFC5View::~CMFC5View()
{
}

BOOL CMFC5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC5View 绘制

void CMFC5View::OnDraw(CDC* /*pDC*/)
{
	CMFC5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC5View 诊断

#ifdef _DEBUG
void CMFC5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC5Doc* CMFC5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC5Doc)));
	return (CMFC5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC5View 消息处理程序

void CMFC5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CMFC5Doc*pDoc = GetDocument();
	
	pDoc->n = 0;
	pDoc->i = point.x;
	CView::OnLButtonDown(nFlags, point);
}



void CMFC5View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CMFC5Doc*pDoc = GetDocument();
	CClientDC clientDC(this);
	pDoc->j = point.x;
	int k = pDoc->j - pDoc->i;
	
	CString s;
	s.Format(_T("MouseMove共执行次%d ,横向移动%d个像素发生一次MouseMove "), pDoc->n, k / pDoc->n);
	clientDC.TextOut(20, 20, s);
	CView::OnLButtonUp(nFlags, point);
}



void CMFC5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CMFC5Doc*pDoc = GetDocument();
	CClientDC clientDC(this);


	CString s;

	pDoc->n = pDoc->n + 1;


	CView::OnMouseMove(nFlags, point);
}
