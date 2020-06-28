
// MFC30View.cpp : CMFC30View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC30.h"
#endif
#include "afxwin.h"
#include "afxcoll.h"
#include "MFC30Doc.h"
#include "MFC30View.h"
#include"Dlg1.h"
#include"fstream"
#include "string"
#include"iostream"
#include"vector"
#include"windows.h"
using namespace std;
#include "MFC30Doc.h"
#include "MFC30View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC30View

IMPLEMENT_DYNCREATE(CMFC30View, CView)

BEGIN_MESSAGE_MAP(CMFC30View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC30View::On32771)
	ON_COMMAND(ID_32772, &CMFC30View::On32772)
END_MESSAGE_MAP()

// CMFC30View 构造/析构

CMFC30View::CMFC30View()
{
	// TODO:  在此处添加构造代码

}

CMFC30View::~CMFC30View()
{
}

BOOL CMFC30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC30View 绘制

void CMFC30View::OnDraw(CDC* /*pDC*/)
{
	CMFC30Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC30View 打印

BOOL CMFC30View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC30View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC30View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC30View 诊断

#ifdef _DEBUG
void CMFC30View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC30View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC30Doc* CMFC30View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC30Doc)));
	return (CMFC30Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC30View 消息处理程序


void CMFC30View::On32771()
{
	ifstream ifs;

	ifs.open("学生名单.txt");
	ifs.close();
	ofstream outfile("学生名单.txt", ios::ate);
	outfile << "宁绍山\n";
	outfile << "宁绍8\n";
	outfile.close();
	
	// TODO:  在此添加命令处理程序代码
}


void CMFC30View::On32772()
{
	Dlg1 md;
	//md.Lbox.AddString(_T("djaks"));
	ifstream ifs;

	ifs.open("学生名单.txt");
	string s;



	string k;
	while (!ifs.eof())
	{

		getline(ifs, k);
		md.j.Add(CString(k.c_str()));




	}
	ifs.close();

	int r = md.DoModal();

	if (r == IDOK)
	{

	}
	// TODO:  在此添加命令处理程序代码
}
