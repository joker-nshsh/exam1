
// MFC18View.cpp : CMFC18View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC18.h"
#endif

#include "MFC18Doc.h"
#include "MFC18View.h"
#include"MyDlgo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC18View

IMPLEMENT_DYNCREATE(CMFC18View, CView)

BEGIN_MESSAGE_MAP(CMFC18View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC18View::On32771)
END_MESSAGE_MAP()

// CMFC18View 构造/析构

CMFC18View::CMFC18View()
{
	// TODO:  在此处添加构造代码

}

CMFC18View::~CMFC18View()
{
}

BOOL CMFC18View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC18View 绘制

void CMFC18View::OnDraw(CDC* /*pDC*/)
{
	CMFC18Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC18View 打印

BOOL CMFC18View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC18View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC18View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC18View 诊断

#ifdef _DEBUG
void CMFC18View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC18View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC18Doc* CMFC18View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC18Doc)));
	return (CMFC18Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC18View 消息处理程序


void CMFC18View::On32771()
{
	// TODO:  在此添加命令处理程序代码
	MyDlgo dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int A, B, C;
		A = dlg.a;
		B = dlg.b;
		

	}
}
