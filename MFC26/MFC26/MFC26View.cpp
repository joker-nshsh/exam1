
// MFC26View.cpp : CMFC26View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC26.h"
#endif

#include "MFC26Doc.h"
#include "MFC26View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC26View

IMPLEMENT_DYNCREATE(CMFC26View, CView)

BEGIN_MESSAGE_MAP(CMFC26View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC26View::On32771)
END_MESSAGE_MAP()

// CMFC26View 构造/析构

CMFC26View::CMFC26View()
{
	// TODO:  在此处添加构造代码
	a.top = 200, a.left = 200;
	a.bottom = 400;
	a.right = 500;
}

CMFC26View::~CMFC26View()
{
}

BOOL CMFC26View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC26View 绘制

void CMFC26View::OnDraw(CDC* pDC)
{
	CMFC26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush brush(RGB(R, X, Y));//根据自己需要填充颜问色
	CBrush *oldbrush;
	oldbrush = pDC->SelectObject(&brush);//选新的画答刷
	pDC->Ellipse(a);
	pDC->SelectObject(oldbrush);
	

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC26View 打印

BOOL CMFC26View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC26View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC26View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC26View 诊断

#ifdef _DEBUG
void CMFC26View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC26View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC26Doc* CMFC26View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC26Doc)));
	return (CMFC26Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC26View 消息处理程序


void CMFC26View::On32771()
{
	// TODO:  在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
	
		R = dlg.a1;
		X = dlg.a2;
		Y = dlg.a3;
		Invalidate();
	}
}
