
// MFC15View.cpp : CMFC15View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC15.h"
#endif

#include "MFC15Doc.h"
#include "MFC15View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC15View

IMPLEMENT_DYNCREATE(CMFC15View, CView)

BEGIN_MESSAGE_MAP(CMFC15View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC15View 构造/析构

CMFC15View::CMFC15View()
{
	// TODO:  在此处添加构造代码

}

CMFC15View::~CMFC15View()
{
}

BOOL CMFC15View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC15View 绘制

void CMFC15View::OnDraw(CDC* pDC)
{
	CMFC15Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString S,J;
	S = _T("我是宁绍山");
	int A = 5;
	J.Format(S + _T("  %d"), A);
	pDC->TextOutW(200, 200, J);
	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC15View 打印

BOOL CMFC15View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC15View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC15View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC15View 诊断

#ifdef _DEBUG
void CMFC15View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC15View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC15Doc* CMFC15View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC15Doc)));
	return (CMFC15Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC15View 消息处理程序
