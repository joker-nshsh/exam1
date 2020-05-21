
// MFC16View.cpp : CMFC16View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC16.h"
#endif

#include "MFC16Doc.h"
#include "MFC16View.h"
#include"MyDlgo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC16View

IMPLEMENT_DYNCREATE(CMFC16View, CView)

BEGIN_MESSAGE_MAP(CMFC16View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_10, &CMFC16View::On10)
	ON_BN_CLICKED(IDOK, &CMFC16View::OnBnClickedOk)
END_MESSAGE_MAP()

// CMFC16View 构造/析构

CMFC16View::CMFC16View()
{
	// TODO:  在此处添加构造代码
	
}

CMFC16View::~CMFC16View()
{
}

BOOL CMFC16View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC16View 绘制

void CMFC16View::OnDraw(CDC* pDC)
{
	CMFC16Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	
	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC16View 打印

BOOL CMFC16View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC16View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC16View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC16View 诊断

#ifdef _DEBUG
void CMFC16View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC16View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC16Doc* CMFC16View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC16Doc)));
	return (CMFC16Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC16View 消息处理程序


void CMFC16View::On10()
{
	// TODO:  在此添加命令处理程序代码
	MyDlgo dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		CString s = _T("djfk");

		CClientDC clientDC(this);
		s = _T("您已退出对话框");
		clientDC.TextOutW(200, 300, s);

	}
}


void CMFC16View::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	
	

}
