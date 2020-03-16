
// MFC4View.cpp : CMFC4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4.h"
#endif

#include "MFC4Doc.h"
#include "MFC4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4View

IMPLEMENT_DYNCREATE(CMFC4View, CView)

BEGIN_MESSAGE_MAP(CMFC4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC4View 构造/析构

CMFC4View::CMFC4View()
{
	// TODO:  在此处添加构造代码

}

CMFC4View::~CMFC4View()
{
}

BOOL CMFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4View 绘制

void CMFC4View::OnDraw(CDC* pDC)
{

	
	CMFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMFC4View 打印

BOOL CMFC4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC4View 诊断

#ifdef _DEBUG
void CMFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4Doc* CMFC4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4Doc)));
	return (CMFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4View 消息处理程序


void CMFC4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CMFC4Doc*pDoc=GetDocument();
	pDoc->m_tagRec.left = point.x;
	pDoc->m_tagRec.top = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFC4View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CMFC4Doc*pDoc = GetDocument();
	CClientDC clientDC(this);
	int a = point.x; int b = point.y;
	CString s;
	
	s.Format(_T("X=%d  Y=%d"),a, b);
	clientDC.TextOut(20, 20, s);
	CView::OnMouseMove(nFlags, point);
}


void CMFC4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CMFC4Doc*pDoc = GetDocument();
	pDoc->m_tagRec.right = point.x ;
	pDoc->m_tagRec.bottom = point.y ;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonUp(nFlags, point);
}
