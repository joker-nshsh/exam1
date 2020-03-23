
// MFC1View.cpp : CMFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC1.h"
#endif

#include "MFC1Doc.h"
#include "MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC1View

IMPLEMENT_DYNCREATE(CMFC1View, CView)

BEGIN_MESSAGE_MAP(CMFC1View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC1View ����/����

CMFC1View::CMFC1View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC1View::~CMFC1View()
{
}

BOOL CMFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC1View ����

void CMFC1View::OnDraw(CDC* pDC)
{
	CMFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_tagRec1);
	pDC->Rectangle(pDoc->m_tagRec2);
	pDC->Rectangle(pDoc->m_tagRec3);
}


// CMFC1View ���

#ifdef _DEBUG
void CMFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC1Doc* CMFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC1Doc)));
	return (CMFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC1View ��Ϣ�������


void CMFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CMFC1Doc*pDoc = GetDocument();
	CClientDC clientDC(this);
	/*pDoc->m_tagRec.left = point.x;
	pDoc->m_tagRec.top = point.y;*/
	BOOL a = pDoc->m_tagRec1.PtInRect(point);
	BOOL b = pDoc->m_tagRec2.PtInRect(point);
	BOOL z = pDoc->m_tagRec3.PtInRect(point);
	srand(int(time(NULL)));
	int n = rand() % 50;

	if (a == 1)
	{
		CString s;

		s.Format(_T("a=%d  "), n);;
		pDoc->a1 = n;
		clientDC.TextOut(pDoc->m_tagRec1.top + 20, pDoc->m_tagRec1.left + 20, s);
		s.Format(_T("                    "));
		clientDC.TextOut(600, 200, s);
	}
	else if (b == 1)
	{
		CString s;

		s.Format(_T("b=%d  "), n);
		pDoc->a2 = n;
		clientDC.TextOut(pDoc->m_tagRec2.top + 20, pDoc->m_tagRec2.left + 20, s);
		s.Format(_T("                    "));
		clientDC.TextOut(600, 200, s);
	}
	else if (z == 1)
	{
		CString s;
		int a3 = pDoc->a1 + pDoc->a2;
		s.Format(_T("c=%d  "), a3);

		clientDC.TextOut(pDoc->m_tagRec3.top + 240, pDoc->m_tagRec3.left - 50, s);
		s.Format(_T("                    "));
		clientDC.TextOut(600, 200, s);
	}
	else
	{
		CString s;
		s.Format(_T("�����Ч"));
		clientDC.TextOut(600, 200, s);
	}
	CView::OnLButtonDown(nFlags, point);
}
