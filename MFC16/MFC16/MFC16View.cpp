
// MFC16View.cpp : CMFC16View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_10, &CMFC16View::On10)
	ON_BN_CLICKED(IDOK, &CMFC16View::OnBnClickedOk)
END_MESSAGE_MAP()

// CMFC16View ����/����

CMFC16View::CMFC16View()
{
	// TODO:  �ڴ˴���ӹ������
	
}

CMFC16View::~CMFC16View()
{
}

BOOL CMFC16View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC16View ����

void CMFC16View::OnDraw(CDC* pDC)
{
	CMFC16Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC16View ��ӡ

BOOL CMFC16View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC16View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC16View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC16View ���

#ifdef _DEBUG
void CMFC16View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC16View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC16Doc* CMFC16View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC16Doc)));
	return (CMFC16Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC16View ��Ϣ�������


void CMFC16View::On10()
{
	// TODO:  �ڴ���������������
	MyDlgo dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		CString s = _T("djfk");

		CClientDC clientDC(this);
		s = _T("�����˳��Ի���");
		clientDC.TextOutW(200, 300, s);

	}
}


void CMFC16View::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	

}
