
// MFC30View.cpp : CMFC30View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFC30View::On32771)
	ON_COMMAND(ID_32772, &CMFC30View::On32772)
END_MESSAGE_MAP()

// CMFC30View ����/����

CMFC30View::CMFC30View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC30View::~CMFC30View()
{
}

BOOL CMFC30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC30View ����

void CMFC30View::OnDraw(CDC* /*pDC*/)
{
	CMFC30Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC30View ��ӡ

BOOL CMFC30View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC30View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC30View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC30View ���

#ifdef _DEBUG
void CMFC30View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC30View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC30Doc* CMFC30View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC30Doc)));
	return (CMFC30Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC30View ��Ϣ�������


void CMFC30View::On32771()
{
	ifstream ifs;

	ifs.open("ѧ������.txt");
	ifs.close();
	ofstream outfile("ѧ������.txt", ios::ate);
	outfile << "����ɽ\n";
	outfile << "����8\n";
	outfile.close();
	
	// TODO:  �ڴ���������������
}


void CMFC30View::On32772()
{
	Dlg1 md;
	//md.Lbox.AddString(_T("djaks"));
	ifstream ifs;

	ifs.open("ѧ������.txt");
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
	// TODO:  �ڴ���������������
}
