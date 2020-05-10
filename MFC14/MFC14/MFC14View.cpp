
// MFC14View.cpp : CMFC14View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMFC14View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC14View ����/����

CMFC14View::CMFC14View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC14View::~CMFC14View()
{
}

BOOL CMFC14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC14View ����

void CMFC14View::OnDraw(CDC* /*pDC*/)
{
	CMFC14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC14View ��ӡ

BOOL CMFC14View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC14View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC14View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC14View ���

#ifdef _DEBUG
void CMFC14View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC14Doc* CMFC14View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC14Doc)));
	return (CMFC14Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC14View ��Ϣ�������


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
	// TODO:  �ڴ���������������
}
