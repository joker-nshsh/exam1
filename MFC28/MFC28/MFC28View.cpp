
// MFC28View.cpp : CMFC28View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC28.h"
#endif
#include"Dlg1.h"
#include "MFC28Doc.h"
#include "MFC28View.h"
#include"fstream"
#include "string"
#include"iostream"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC28View

IMPLEMENT_DYNCREATE(CMFC28View, CView)

BEGIN_MESSAGE_MAP(CMFC28View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMFC28View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMFC28View::OnFileSaveAs)
	
	ON_COMMAND(ID_32771, &CMFC28View::On32771)
END_MESSAGE_MAP()

// CMFC28View 构造/析构

CMFC28View::CMFC28View()
{
	// TODO:  在此处添加构造代码

}

CMFC28View::~CMFC28View()
{
}

BOOL CMFC28View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC28View 绘制

void CMFC28View::OnDraw(CDC* /*pDC*/)
{
	CMFC28Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC28View 打印

BOOL CMFC28View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC28View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC28View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC28View 诊断

#ifdef _DEBUG
void CMFC28View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC28View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC28Doc* CMFC28View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC28Doc)));
	return (CMFC28Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC28View 消息处理程序


void CMFC28View::OnFileOpen()
{
	// TODO:  在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		 filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		CClientDC dc(this);
		int x = 20, y = 10;
		/*while (ifs >> s)
		{
			dc.TextOutW(x, y, CString(s.c_str()));
			y += 30;
		}*/
	}
}


void CMFC28View::OnFileSaveAs()
{
	// TODO:  在此添加命令处理程序代码
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(cfd.GetPathName());
		ofs << "OK" << endl;
		CString s = filename;

		ofs << CT2A(s.GetString())<< endl;
	}
}





void CMFC28View::On32771()
{
	// TODO:  在此添加命令处理程序代码
	Dlg1 md1;
	md1.s3 = filename;
	int r = md1.DoModal();

	if (r == IDOK)
	{

	}
}
