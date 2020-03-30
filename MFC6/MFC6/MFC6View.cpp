
// MFC6View.cpp : CMFC6View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC6.h"
#endif

#include "MFC6Doc.h"
#include "MFC6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC6View

IMPLEMENT_DYNCREATE(CMFC6View, CView)

BEGIN_MESSAGE_MAP(CMFC6View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFC6View 构造/析构

CMFC6View::CMFC6View()
{
	// TODO:  在此处添加构造代码

}

CMFC6View::~CMFC6View()
{
}

BOOL CMFC6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC6View 绘制

void CMFC6View::OnDraw(CDC* pDC)
{
	CMFC6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec1);
}


// CMFC6View 打印

BOOL CMFC6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC6View 诊断

#ifdef _DEBUG
void CMFC6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC6Doc* CMFC6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC6Doc)));
	return (CMFC6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC6View 消息处理程序


void CMFC6View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CMFC6Doc*pDoc = GetDocument(); CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->m_tagRec1.left > 0)
		{
			pDoc->m_tagRec1.left -= 5;
			pDoc->m_tagRec1.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->m_tagRec1.right <= (pDoc->m_tagRec1.right - clientRec.left))
		{
			pDoc->m_tagRec1.left += 5;
			pDoc->m_tagRec1.right += 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_tagRec1.bottom <= (pDoc->m_tagRec1.bottom - clientRec.top))
		{
			pDoc->m_tagRec1.top += 5;
			pDoc->m_tagRec1.bottom += 5;
		}
		break;
	case VK_UP:
		if (pDoc->m_tagRec1.top > 0)
		{
			pDoc->m_tagRec1.top -= 5;
			pDoc->m_tagRec1.bottom -= 5;
		}
		break;
	case VK_HOME:
		if (pDoc->m_tagRec1.top > 0 && pDoc->m_tagRec1.left>0)
		{
			pDoc->m_tagRec1.top -= 5;
			pDoc->m_tagRec1.left -= 5;
		}
		break;
	case VK_END:
		if (pDoc->m_tagRec1.bottom - pDoc->m_tagRec1.top  > 0 && pDoc->m_tagRec1.right - pDoc->m_tagRec1.left>0)
		{
			pDoc->m_tagRec1.left += 5;
			pDoc->m_tagRec1.top += 5;
		}
		break;
	}
	InvalidateRect(NULL, TRUE);


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}