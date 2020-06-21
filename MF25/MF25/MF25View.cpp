
// MF25View.cpp : CMF25View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MF25.h"
#endif

#include "MF25Doc.h"
#include "MF25View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMF25View

IMPLEMENT_DYNCREATE(CMF25View, CView)

BEGIN_MESSAGE_MAP(CMF25View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMF25View 构造/析构

CMF25View::CMF25View()
{
	// TODO:  在此处添加构造代码
	a.top = 200; a.left = 200;
	a.right = 500; a.bottom = 400;
}

CMF25View::~CMF25View()
{
}

BOOL CMF25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMF25View 绘制

void CMF25View::OnDraw(CDC* pDC)
{
	CMF25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC*dc = GetDC();
	CPen *oldpen = NULL;
	CPen pen;
	pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	dc->SelectObject(pen);
	dc->Rectangle(&b);
	dc->Ellipse(a);
	dc->SelectObject(oldpen);
	pen.DeleteObject();
	pDC->Ellipse(a);
	// TODO:  在此处为本机数据添加绘制代码
}


// CMF25View 打印

BOOL CMF25View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMF25View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMF25View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMF25View 诊断

#ifdef _DEBUG
void CMF25View::AssertValid() const
{
	CView::AssertValid();
}

void CMF25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMF25Doc* CMF25View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMF25Doc)));
	return (CMF25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMF25View 消息处理程序


void CMF25View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	BOOL b1 = a.PtInRect(point);
	CDC*dc = GetDC();
	if (b1==1)
	{
		b.top = a.top;
		b.left = a.left;
		b.bottom = a.bottom;
		b.right = a.right;
		Invalidate();
	}
	else
	{
		b.top = 0;
		b.left = 0;
		b.bottom = 0;
		b.right = 0;
		Invalidate();
	}
	CView::OnLButtonDown(nFlags, point);
}
