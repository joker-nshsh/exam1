
// usinglb3View.cpp : Cusinglb3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "usinglb3.h"
#endif

#include "usinglb3Doc.h"
#include "usinglb3View.h"
#include"w32.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cusinglb3View

IMPLEMENT_DYNCREATE(Cusinglb3View, CView)

BEGIN_MESSAGE_MAP(Cusinglb3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cusinglb3View 构造/析构

Cusinglb3View::Cusinglb3View()
{
	// TODO:  在此处添加构造代码

}

Cusinglb3View::~Cusinglb3View()
{
}

BOOL Cusinglb3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cusinglb3View 绘制

void Cusinglb3View::OnDraw(CDC* pDC)
{
	Cusinglb3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString ss;
	float c = convert(30.0);
	ss.Format(_T("%lf,这是角度30.0经静态库转换得到的弧度。"), c);
	pDC->TextOutW(200, 180, ss);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cusinglb3View 打印

BOOL Cusinglb3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cusinglb3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Cusinglb3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// Cusinglb3View 诊断

#ifdef _DEBUG
void Cusinglb3View::AssertValid() const
{
	CView::AssertValid();
}

void Cusinglb3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cusinglb3Doc* Cusinglb3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cusinglb3Doc)));
	return (Cusinglb3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cusinglb3View 消息处理程序
