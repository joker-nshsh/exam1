
// MF23View.h : CMF23View 类的接口
//

#pragma once


class CMF23View : public CView
{
protected: // 仅从序列化创建
	CMF23View();
	DECLARE_DYNCREATE(CMF23View)

// 特性
public:
	CMF23Doc* GetDocument() const;
	CRect a;
	int a1, a2, a3, a4;
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
	virtual ~CMF23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MF23View.cpp 中的调试版本
inline CMF23Doc* CMF23View::GetDocument() const
   { return reinterpret_cast<CMF23Doc*>(m_pDocument); }
#endif

