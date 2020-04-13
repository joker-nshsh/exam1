
// MFC7View.cpp : CMFC7View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC7.h"
#endif

#include "MFC7Doc.h"
#include "MFC7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC7View

IMPLEMENT_DYNCREATE(CMFC7View, CView)

BEGIN_MESSAGE_MAP(CMFC7View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC7View ����/����

CMFC7View::CMFC7View()
{
	// TODO:  �ڴ˴���ӹ������
	set = true;
	rc.top = 60; rc.left = 60; rc.right = 120; rc.bottom = 120;
	dc.top = 60; rc.left = 60; rc.right = 120; rc.bottom = 120;
	j = 1;

}

CMFC7View::~CMFC7View()
{
}

BOOL CMFC7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC7View ����

void CMFC7View::OnDraw(CDC* pDC)
{
	CMFC7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		
			SetTimer(0, rand() % 400 + 300, NULL);
			set = false;
		

	}
	pDC->Ellipse(rc);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC7View ��ӡ

BOOL CMFC7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC7View ���

#ifdef _DEBUG
void CMFC7View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC7Doc* CMFC7View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC7Doc)));
	return (CMFC7Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC7View ��Ϣ�������


void CMFC7View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	GetClientRect(&dc);
	if (j==1&&rc.bottom < dc.bottom   )
	{
		rc.top += 10;  rc.bottom += 10;
		Invalidate();
	}
	if ( rc.bottom >=dc.bottom)
	{
		j = 0;
	}
	if (j == 0)
	{
		rc.top -= 10;  rc.bottom -= 10;
		Invalidate();
	}


	
	

	CView::OnTimer(nIDEvent);
}
