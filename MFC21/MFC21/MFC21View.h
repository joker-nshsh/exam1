
// MFC21View.h : CMFC21View 类的接口
//

#pragma once


class CMFC21View : public CView
{
protected: // 仅从序列化创建
	CMFC21View();
	DECLARE_DYNCREATE(CMFC21View)

// 特性
public:
	CMFC21Doc* GetDocument() const;

// 操作
public:
	CRect a;
	int set;
	int j;
	int k;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFC21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC21View.cpp 中的调试版本
inline CMFC21Doc* CMFC21View::GetDocument() const
   { return reinterpret_cast<CMFC21Doc*>(m_pDocument); }
#endif

