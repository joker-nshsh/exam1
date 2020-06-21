
// MF22View.cpp : CMF22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MF22.h"
#endif

#include "MF22Doc.h"
#include "MF22View.h"
#include "Mydlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMF22View

IMPLEMENT_DYNCREATE(CMF22View, CView)

BEGIN_MESSAGE_MAP(CMF22View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMF22View::On32771)
END_MESSAGE_MAP()

// CMF22View 构造/析构

CMF22View::CMF22View()
{
	// TODO:  在此处添加构造代码

}

CMF22View::~CMF22View()
{
}

BOOL CMF22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMF22View 绘制

void CMF22View::OnDraw(CDC* /*pDC*/)
{
	CMF22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMF22View 打印

BOOL CMF22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMF22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMF22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMF22View 诊断

#ifdef _DEBUG
void CMF22View::AssertValid() const
{
	CView::AssertValid();
}

void CMF22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMF22Doc* CMF22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMF22Doc)));
	return (CMF22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMF22View 消息处理程序


void CMF22View::On32771()
{
	// TODO:  在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int A, B, C;
		A = dlg.a;
		B = dlg.b;
		C = dlg.c;

	}
}
