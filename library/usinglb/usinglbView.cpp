
// usinglbView.cpp : CusinglbView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "usinglb.h"
#endif
#include"W32D.h"
#include "usinglbDoc.h"
#include "usinglbView.h"
#include"w32.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CusinglbView

IMPLEMENT_DYNCREATE(CusinglbView, CView)

BEGIN_MESSAGE_MAP(CusinglbView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CusinglbView ����/����

CusinglbView::CusinglbView()
{
	// TODO:  �ڴ˴���ӹ������

}

CusinglbView::~CusinglbView()
{
}

BOOL CusinglbView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CusinglbView ����

void CusinglbView::OnDraw(CDC* pDC)
{
	CusinglbDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s = CString(pchar());
	pDC->TextOutW(200, 150, s);
	CString ss;
	ss.Format(_T("%d,���ǴӶ�̬�ⷵ�ص�ֵ��"),GetInt());
	pDC->TextOutW(200, 180, ss);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���

}


// CusinglbView ��ӡ

BOOL CusinglbView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CusinglbView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CusinglbView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CusinglbView ���

#ifdef _DEBUG
void CusinglbView::AssertValid() const
{
	CView::AssertValid();
}

void CusinglbView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CusinglbDoc* CusinglbView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CusinglbDoc)));
	return (CusinglbDoc*)m_pDocument;
}
#endif //_DEBUG


// CusinglbView ��Ϣ�������
