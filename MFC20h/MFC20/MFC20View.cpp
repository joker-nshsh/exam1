
// MFC20View.cpp : CMFC20View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC20.h"
#endif

#include "MFC20Doc.h"
#include "MFC20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC20View

IMPLEMENT_DYNCREATE(CMFC20View, CView)

BEGIN_MESSAGE_MAP(CMFC20View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC20View 构造/析构

CMFC20View::CMFC20View()
{
	// TODO:  在此处添加构造代码
	a.bottom = 200;
	a.left = 150;
	a.right = 250;
	a.top = 100;

}

CMFC20View::~CMFC20View()
{
}

BOOL CMFC20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC20View 绘制

void CMFC20View::OnDraw(CDC* pDC)
{
	CMFC20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(a);
	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC20View 打印

BOOL CMFC20View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC20View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC20View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC20View 诊断

#ifdef _DEBUG
void CMFC20View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC20View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC20Doc* CMFC20View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC20Doc)));
	return (CMFC20Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC20View 消息处理程序


void CMFC20View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	b = point.x; c = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC20View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	d = point.x; e = point.y;
	a.left += d - b; a.right += d - b;
	a.bottom += e - c; a.top += e - c;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
