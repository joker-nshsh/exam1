
// usinglbView.cpp : CusinglbView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "usinglb.h"
#endif
#include"W32D.h"
#include "usinglbDoc.h"
#include "usinglbView.h"
#include"w32.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CusinglbView

IMPLEMENT_DYNCREATE(CusinglbView, CView)

BEGIN_MESSAGE_MAP(CusinglbView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CusinglbView 构造/析构

CusinglbView::CusinglbView()
{
	// TODO:  在此处添加构造代码

}

CusinglbView::~CusinglbView()
{
}

BOOL CusinglbView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CusinglbView 绘制

void CusinglbView::OnDraw(CDC* pDC)
{
	CusinglbDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s = CString(pchar());
	pDC->TextOutW(200, 150, s);
	CString ss;
	ss.Format(_T("%d,这是从动态库返回的值。"),GetInt());
	pDC->TextOutW(200, 180, ss);
	// TODO:  在此处为本机数据添加绘制代码

}


// CusinglbView 打印

BOOL CusinglbView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CusinglbView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CusinglbView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CusinglbView 诊断

#ifdef _DEBUG
void CusinglbView::AssertValid() const
{
	CView::AssertValid();
}

void CusinglbView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CusinglbDoc* CusinglbView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CusinglbDoc)));
	return (CusinglbDoc*)m_pDocument;
}
#endif //_DEBUG


// CusinglbView 消息处理程序
