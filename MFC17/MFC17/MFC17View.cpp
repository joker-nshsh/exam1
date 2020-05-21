
// MFC17View.cpp : CMFC17View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC17.h"
#endif

#include "MFC17Doc.h"
#include "MFC17View.h"
#include "MyDlgo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC17View

IMPLEMENT_DYNCREATE(CMFC17View, CView)

BEGIN_MESSAGE_MAP(CMFC17View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_zifu, &CMFC17View::Onzifu)
END_MESSAGE_MAP()

// CMFC17View 构造/析构

CMFC17View::CMFC17View()
{
	// TODO:  在此处添加构造代码

}

CMFC17View::~CMFC17View()
{
}

BOOL CMFC17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC17View 绘制

void CMFC17View::OnDraw(CDC* /*pDC*/)
{
	CMFC17Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC17View 打印

BOOL CMFC17View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC17View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC17View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC17View 诊断

#ifdef _DEBUG
void CMFC17View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC17View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC17Doc* CMFC17View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC17Doc)));
	return (CMFC17Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC17View 消息处理程序


void CMFC17View::Onzifu()
{
	// TODO:  在此添加命令处理程序代码
	MyDlgo dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		CString X, Y;
		X = dlg.x;
		Y = dlg.y;
	}
}
