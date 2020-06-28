
// usinglb2View.cpp : Cusinglb2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "usinglb2.h"
#endif
#include"w32.h"
#include "usinglb2Doc.h"
#include "usinglb2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cusinglb2View

IMPLEMENT_DYNCREATE(Cusinglb2View, CView)

BEGIN_MESSAGE_MAP(Cusinglb2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cusinglb2View 构造/析构

Cusinglb2View::Cusinglb2View()
{
	// TODO:  在此处添加构造代码

}

Cusinglb2View::~Cusinglb2View()
{
}

BOOL Cusinglb2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cusinglb2View 绘制

void Cusinglb2View::OnDraw(CDC* pDC)
{
	Cusinglb2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CString ss;
	int c = Fact(5);
	ss.Format(_T("%d,这是5的阶乘经静态库得到的。"),c);
	pDC->TextOutW(200, 180, ss);

	// TODO:  在此处为本机数据添加绘制代码
}


// Cusinglb2View 打印

BOOL Cusinglb2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cusinglb2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Cusinglb2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// Cusinglb2View 诊断

#ifdef _DEBUG
void Cusinglb2View::AssertValid() const
{
	CView::AssertValid();
}

void Cusinglb2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cusinglb2Doc* Cusinglb2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cusinglb2Doc)));
	return (Cusinglb2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cusinglb2View 消息处理程序
