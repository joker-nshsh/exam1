
// MFC11View.cpp : CMFC11View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC11.h"
#endif

#include "MFC11Doc.h"
#include "MFC11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC11View

IMPLEMENT_DYNCREATE(CMFC11View, CView)

BEGIN_MESSAGE_MAP(CMFC11View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(mingzi, &CMFC11View::Onmingzi)
END_MESSAGE_MAP()

// CMFC11View 构造/析构

CMFC11View::CMFC11View()
{
	// TODO:  在此处添加构造代码

}

CMFC11View::~CMFC11View()
{
}

BOOL CMFC11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC11View 绘制

void CMFC11View::OnDraw(CDC* /*pDC*/)
{
	CMFC11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC11View 打印

BOOL CMFC11View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC11View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC11View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC11View 诊断

#ifdef _DEBUG
void CMFC11View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC11Doc* CMFC11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC11Doc)));
	return (CMFC11Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC11View 消息处理程序


void CMFC11View::Onmingzi()
{
	// TODO:  在此添加命令处理程序代码
	CString s = _T("宁绍山");
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);

}
