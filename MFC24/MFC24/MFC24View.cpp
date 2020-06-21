
// MFC24View.cpp : CMFC24View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC24.h"
#endif
#include "MyDlg0.h"
#include "MFC24Doc.h"
#include "MFC24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC24View

IMPLEMENT_DYNCREATE(CMFC24View, CView)

BEGIN_MESSAGE_MAP(CMFC24View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC24View::On32771)
END_MESSAGE_MAP()

// CMFC24View 构造/析构

CMFC24View::CMFC24View()
{
	// TODO:  在此处添加构造代码

}

CMFC24View::~CMFC24View()
{
}

BOOL CMFC24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC24View 绘制

void CMFC24View::OnDraw(CDC* /*pDC*/)
{
	CMFC24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC24View 打印

BOOL CMFC24View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC24View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC24View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC24View 诊断

#ifdef _DEBUG
void CMFC24View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC24Doc* CMFC24View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC24Doc)));
	return (CMFC24Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC24View 消息处理程序


void CMFC24View::On32771()
{
	// TODO:  在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int E, F, G, H;
		E = dlg.top1;
		F = dlg.left1;
		G = dlg.bottom1;
		H = dlg.right1;
		CRect re(E, F, G, H);
		GetDC()->Ellipse(re);

	}
}
