
// MFC001View.cpp : CMFC001View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC001.h"
#endif

#include "MFC001Doc.h"
#include "MFC001View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC001View

IMPLEMENT_DYNCREATE(CMFC001View, CView)

BEGIN_MESSAGE_MAP(CMFC001View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC001View 构造/析构

CMFC001View::CMFC001View()
{
	// TODO:  在此处添加构造代码
	k = 1;

}

CMFC001View::~CMFC001View()
{
}

BOOL CMFC001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC001View 绘制

void CMFC001View::OnDraw(CDC* pDC)
{
	CMFC001Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString c;

	c.Format( _T(" %d"), pDoc->count);

	pDC->TextOutW(200, 200, c);

	// TODO:  在此处为本机数据添加绘制代码
}



// CMFC001View 打印

BOOL CMFC001View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC001View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC001View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC001View 诊断

#ifdef _DEBUG
void CMFC001View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC001View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC001Doc* CMFC001View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC001Doc)));
	return (CMFC001Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC001View 消息处理程序


void CMFC001View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值


	CMFC001Doc* pDoc = GetDocument();
	
	k += 1;

	pDoc->count= k;
	CView::OnLButtonDown(nFlags, point);

}


void CMFC001View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//CMFC001Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s;

	/*s.Format(_T("%d", pDoc->z));
	
	dc.TextOutW(200,200,s);*/
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
