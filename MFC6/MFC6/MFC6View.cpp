
// MFC6View.cpp : CMFC6View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC6.h"
#endif

#include "MFC6Doc.h"
#include "MFC6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC6View

IMPLEMENT_DYNCREATE(CMFC6View, CView)

BEGIN_MESSAGE_MAP(CMFC6View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFC6View ����/����

CMFC6View::CMFC6View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC6View::~CMFC6View()
{
}

BOOL CMFC6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC6View ����

void CMFC6View::OnDraw(CDC* pDC)
{
	CMFC6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_tagRec1);
}


// CMFC6View ��ӡ

BOOL CMFC6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC6View ���

#ifdef _DEBUG
void CMFC6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC6Doc* CMFC6View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC6Doc)));
	return (CMFC6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC6View ��Ϣ�������


void CMFC6View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CMFC6Doc*pDoc = GetDocument(); CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->m_tagRec1.left > 0)
		{
			pDoc->m_tagRec1.left -= 5;
			pDoc->m_tagRec1.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->m_tagRec1.right <= (pDoc->m_tagRec1.right - clientRec.left))
		{
			pDoc->m_tagRec1.left += 5;
			pDoc->m_tagRec1.right += 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_tagRec1.bottom <= (pDoc->m_tagRec1.bottom - clientRec.top))
		{
			pDoc->m_tagRec1.top += 5;
			pDoc->m_tagRec1.bottom += 5;
		}
		break;
	case VK_UP:
		if (pDoc->m_tagRec1.top > 0)
		{
			pDoc->m_tagRec1.top -= 5;
			pDoc->m_tagRec1.bottom -= 5;
		}
		break;
	case VK_HOME:
		if (pDoc->m_tagRec1.top > 0 && pDoc->m_tagRec1.left>0)
		{
			pDoc->m_tagRec1.top -= 5;
			pDoc->m_tagRec1.left -= 5;
		}
		break;
	case VK_END:
		if (pDoc->m_tagRec1.bottom - pDoc->m_tagRec1.top  > 0 && pDoc->m_tagRec1.right - pDoc->m_tagRec1.left>0)
		{
			pDoc->m_tagRec1.left += 5;
			pDoc->m_tagRec1.top += 5;
		}
		break;
	}
	InvalidateRect(NULL, TRUE);


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}