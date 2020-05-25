
// MFC19View.cpp : CMFC19View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC19.h"
#endif

#include "MFC19Doc.h"
#include "MFC19View.h"
#include"MyDlgo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC19View

IMPLEMENT_DYNCREATE(CMFC19View, CView)

BEGIN_MESSAGE_MAP(CMFC19View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC19View::On32771)
END_MESSAGE_MAP()

// CMFC19View 构造/析构

CMFC19View::CMFC19View()
{
	// TODO:  在此处添加构造代码

}

CMFC19View::~CMFC19View()
{
}

BOOL CMFC19View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC19View 绘制

void CMFC19View::OnDraw(CDC* /*pDC*/)
{
	CMFC19Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC19View 打印

BOOL CMFC19View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC19View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC19View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC19View 诊断

#ifdef _DEBUG
void CMFC19View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC19View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC19Doc* CMFC19View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC19Doc)));
	return (CMFC19Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC19View 消息处理程序


void CMFC19View::On32771()
{
	// TODO:  在此添加命令处理程序代码
	MyDlgo dlg;
	int t = dlg.DoModal();

}
