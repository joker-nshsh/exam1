
// MFC27View.cpp : CMFC27View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC27.h"
#endif

#include "MFC27Doc.h"
#include "MFC27View.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC27View

IMPLEMENT_DYNCREATE(CMFC27View, CView)

BEGIN_MESSAGE_MAP(CMFC27View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC27View::On32771)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC27View 构造/析构

CMFC27View::CMFC27View()
{
	// TODO:  在此处添加构造代码

}

CMFC27View::~CMFC27View()
{
}

BOOL CMFC27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC27View 绘制

void CMFC27View::OnDraw(CDC* /*pDC*/)
{
	CMFC27Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC27View 打印

BOOL CMFC27View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC27View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC27View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC27View 诊断

#ifdef _DEBUG
void CMFC27View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC27View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC27Doc* CMFC27View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC27Doc)));
	return (CMFC27Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC27View 消息处理程序


void CMFC27View::On32771()
{
	CMFC27Doc*pDoc = GetDocument();
	MyDlg1 md1;
	
	md1.s = pDoc->filename;
	int r = md1.DoModal();
	
	
	if (r == IDOK)
	{
		
	}
	// TODO:  在此添加命令处理程序代码
}


void CMFC27View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	CMFC27Doc*pDoc = GetDocument();
	if (r == IDOK)
	{
		pDoc->filename = cfd.GetPathName();
		dc.TextOutW(200, 300, pDoc->filename);

	}
	CView::OnLButtonDblClk(nFlags, point);
}
