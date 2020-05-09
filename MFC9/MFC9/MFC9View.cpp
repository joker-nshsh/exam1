
// MFC9View.cpp : CMFC9View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC9.h"
#endif

#include "MFC9Doc.h"
#include "MFC9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC9View

IMPLEMENT_DYNCREATE(CMFC9View, CView)

BEGIN_MESSAGE_MAP(CMFC9View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC9View 构造/析构

CMFC9View::CMFC9View()
{
	// TODO:  在此处添加构造代码
	// TODO:  在此处添加构造代码
	j.top = 0; j.left = 0; j.right = 0; j.bottom = 0;
	int a1, a2, a = 0;
}

CMFC9View::~CMFC9View()
{
}

BOOL CMFC9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC9View 绘制

void CMFC9View::OnDraw(CDC* pDC)
{
	CMFC9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&j);
	pDC->Ellipse(j);

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC9View 打印

BOOL CMFC9View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC9View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC9View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC9View 诊断

#ifdef _DEBUG
void CMFC9View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC9Doc* CMFC9View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC9Doc)));
	return (CMFC9Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC9View 消息处理程序
