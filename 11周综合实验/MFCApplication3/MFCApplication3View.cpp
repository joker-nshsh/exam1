
// MFCApplication3View.cpp : CMFCApplication3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Set.h"
#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3View

IMPLEMENT_DYNCREATE(CMFCApplication3View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication3View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCApplication3View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication3View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication3View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCApplication3View::OnRecordLast)
END_MESSAGE_MAP()

// CMFCApplication3View 构造/析构

CMFCApplication3View::CMFCApplication3View()
	: CRecordView(IDD_MFCAPPLICATION3_FORM)
	, s(_T(""))
{
	m_pSet = NULL;
	path = _T("E:\\HTML\\image\\");
	// TODO: 在此处添加构造代码

}

CMFCApplication3View::~CMFCApplication3View()
{
}

void CMFCApplication3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication3Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication3View 打印

BOOL CMFCApplication3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication3View 诊断

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View 数据库支持
CRecordset* CMFCApplication3View::OnGetRecordset()
{
	return m_pSet;
}

void CMFCApplication3View::draw(CString file)
{
	CClientDC dc(this);
	CImage img;
	img.Load(file);
	CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
	CRect rect;
	int sx, sy, w, h;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_radio = 1.0*rect.Width() / rect.Height();
	float img_radio = 1.0*img.GetWidth() / img.GetWidth();
	if (rect_radio > img_radio)
	{
		h = rect.Height();
		w = img_radio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;

	}
	img.Draw(dc.m_hDC, sx, sy, w, h);
}
// CMFCApplication3View 消息处理程序



void CMFCApplication3View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
	CString filename, s,s1;
	s1 = _T(".jpg");
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s+s1;
	draw(filename);
}


void CMFCApplication3View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}// TODO: 在此添加命令处理程序代码
	UpdateData(false);
	CString filename, s, s1;
	s1 = _T(".jpg");
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s + s1;
	draw(filename);
}


void CMFCApplication3View::OnRecordNext()
{

	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveLast();
	}// TODO: 在此添加命令处理程序代码
	UpdateData(false);// TODO: 在此添加命令处理程序代码
	CString filename, s, s1;
	s1 = _T(".jpg");
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s + s1;
	draw(filename);
}


void CMFCApplication3View::OnRecordLast()
{
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s, s1;
	s1 = _T(".jpg");
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s + s1;
	draw(filename);
}
