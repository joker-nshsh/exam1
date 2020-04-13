
// MFC7View.cpp : CMFC7View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7.h"
#endif

#include "MFC7Doc.h"
#include "MFC7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC7View

IMPLEMENT_DYNCREATE(CMFC7View, CView)

BEGIN_MESSAGE_MAP(CMFC7View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC7View 构造/析构

CMFC7View::CMFC7View()
{
	// TODO:  在此处添加构造代码
	set = true;
	rc.top = 60; rc.left = 60; rc.right = 120; rc.bottom = 120;
	dc.top = 60; rc.left = 60; rc.right = 120; rc.bottom = 120;
	j = 1;

}

CMFC7View::~CMFC7View()
{
}

BOOL CMFC7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC7View 绘制

void CMFC7View::OnDraw(CDC* pDC)
{
	CMFC7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		
			SetTimer(0, rand() % 400 + 300, NULL);
			set = false;
		

	}
	pDC->Ellipse(rc);
	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC7View 打印

BOOL CMFC7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC7View 诊断

#ifdef _DEBUG
void CMFC7View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC7Doc* CMFC7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC7Doc)));
	return (CMFC7Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC7View 消息处理程序


void CMFC7View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	GetClientRect(&dc);
	if (j==1&&rc.bottom < dc.bottom   )
	{
		rc.top += 10;  rc.bottom += 10;
		Invalidate();
	}
	if ( rc.bottom >=dc.bottom)
	{
		j = 0;
	}
	if (j == 0)
	{
		rc.top -= 10;  rc.bottom -= 10;
		Invalidate();
	}


	
	

	CView::OnTimer(nIDEvent);
}
