
// MFCApplication1View.cpp : CMFCApplication1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Set.h"
#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include "ADD.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1View::OnBnClickeddele)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1View::OnBnClickedADD)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1View::修改数据库)
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View()
	: CRecordView(IDD_MFCAPPLICATION1_FORM)
	, name(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCApplication1View::~CMFCApplication1View()
{
}

void CMFCApplication1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication1Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication1View 打印

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 数据库支持
CRecordset* CMFCApplication1View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication1View 消息处理程序


void CMFCApplication1View::OnBnClickeddele()
{
	m_pSet->Delete();
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(FALSE);// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication1View::OnBnClickedADD()
{
	ADD diag;
	int result = diag.DoModal();
	if (result = IDOK)
	{

		CString s = diag.addstring;
		m_pSet->AddNew();
		m_pSet->m_1 = s;
		m_pSet->Update();
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication1View::修改数据库()
{
	ADD diag;
	int result = diag.DoModal();
	if (result = IDOK)
	{

		CString s = diag.addstring;
	
		m_pSet->m_1.SetString(s);
		
		UpdateData(FALSE);
	}
	// TODO: 在此添加控件通知处理程序代码
}
