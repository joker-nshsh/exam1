
// MFC002View.cpp : CMFC002View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC002.h"
#endif

#include "MFC002Doc.h"
#include "MFC002View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC002View

IMPLEMENT_DYNCREATE(CMFC002View, CView)

BEGIN_MESSAGE_MAP(CMFC002View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC002View 构造/析构

CMFC002View::CMFC002View()
{
	// TODO:  在此处添加构造代码

}

CMFC002View::~CMFC002View()
{
}

BOOL CMFC002View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC002View 绘制

void CMFC002View::OnDraw(CDC* pDC)
{
	CMFC002Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString J;
	J.Format(pDoc->S + _T("  %d"), pDoc->A);
	pDC->TextOutW(200, 200, J);
		
	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC002View 打印

BOOL CMFC002View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC002View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC002View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC002View 诊断

#ifdef _DEBUG
void CMFC002View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC002View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC002Doc* CMFC002View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC002Doc)));
	return (CMFC002Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC002View 消息处理程序
