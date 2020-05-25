
// MFC20View.h : CMFC20View 类的接口
//

#pragma once


class CMFC20View : public CView
{
protected: // 仅从序列化创建
	CMFC20View();
	DECLARE_DYNCREATE(CMFC20View)

// 特性
public:
	CMFC20Doc* GetDocument() const;
	CRect a;
	int b, c,d,e;
// 操作
public:

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
	virtual ~CMFC20View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC20View.cpp 中的调试版本
inline CMFC20Doc* CMFC20View::GetDocument() const
   { return reinterpret_cast<CMFC20Doc*>(m_pDocument); }
#endif

