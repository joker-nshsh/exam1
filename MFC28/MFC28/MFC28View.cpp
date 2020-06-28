
// MFC28View.cpp : CMFC28View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMFC28View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMFC28View::OnFileSaveAs)
	
	ON_COMMAND(ID_32771, &CMFC28View::On32771)
END_MESSAGE_MAP()

// CMFC28View ����/����

CMFC28View::CMFC28View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC28View::~CMFC28View()
{
}

BOOL CMFC28View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC28View ����

void CMFC28View::OnDraw(CDC* /*pDC*/)
{
	CMFC28Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC28View ��ӡ

BOOL CMFC28View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC28View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC28View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC28View ���

#ifdef _DEBUG
void CMFC28View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC28View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC28Doc* CMFC28View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC28Doc)));
	return (CMFC28Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC28View ��Ϣ�������


void CMFC28View::OnFileOpen()
{
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ���������������
	Dlg1 md1;
	md1.s3 = filename;
	int r = md1.DoModal();

	if (r == IDOK)
	{

	}
}
