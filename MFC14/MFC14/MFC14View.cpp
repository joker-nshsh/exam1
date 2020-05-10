
// MFC14View.cpp : CMFC14View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC14.h"
#endif

#include "MFC14Doc.h"
#include "MFC14View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC14View

IMPLEMENT_DYNCREATE(CMFC14View, CView)

BEGIN_MESSAGE_MAP(CMFC14View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMFC14View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC14View 构造/析构

CMFC14View::CMFC14View()
{
	// TODO:  在此处添加构造代码

}

CMFC14View::~CMFC14View()
{
}

BOOL CMFC14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC14View 绘制

void CMFC14View::OnDraw(CDC* /*pDC*/)
{
	CMFC14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC14View 打印

BOOL CMFC14View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC14View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC14View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC14View 诊断

#ifdef _DEBUG
void CMFC14View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC14Doc* CMFC14View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC14Doc)));
	return (CMFC14Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC14View 消息处理程序


void CMFC14View::OnFileOpen()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		CImage img;
		img.Load(filename);
		CRect rect;
		GetClientRect(&rect);
		int w, h, sx, sy;
		float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
		if (rect_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Height();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}





		
		img.Draw(dc.m_hDC, sx, sy, w, h);

	}
	// TODO:  在此添加命令处理程序代码
}
