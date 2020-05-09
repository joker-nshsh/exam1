
// MFC10View.cpp : CMFC10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC10.h"
#endif

#include "MFC10Doc.h"
#include "MFC10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC10View

IMPLEMENT_DYNCREATE(CMFC10View, CView)

BEGIN_MESSAGE_MAP(CMFC10View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC10View 构造/析构

CMFC10View::CMFC10View()
{
	// TODO:  在此处添加构造代码

}

CMFC10View::~CMFC10View()
{
}

BOOL CMFC10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC10View 绘制

void CMFC10View::OnDraw(CDC* pDC)
{
	CMFC10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&j);
	
	 pDC = GetDC(); // 得到DC
	CBrush brush(RGB(1, 255, 255));//根据自己需要填充颜问色
	CBrush *oldbrush;
	oldbrush = pDC->SelectObject(&brush);//选新的画答刷
	pDC->Ellipse(j);
	pDC->SelectObject(oldbrush);//将原来的画刷选回去
	 // 释放内DC

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC10View 打印

BOOL CMFC10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC10View 诊断

#ifdef _DEBUG
void CMFC10View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC10Doc* CMFC10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC10Doc)));
	return (CMFC10Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC10View 消息处理程序
