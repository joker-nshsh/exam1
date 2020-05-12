
// MFC001View.h : CMFC001View 类的接口
//

#pragma once


class CMFC001View : public CView
{
protected: // 仅从序列化创建
	CMFC001View();
	DECLARE_DYNCREATE(CMFC001View)

// 特性
public:
	CMFC001Doc* GetDocument() const;
	int k;
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
	virtual ~CMFC001View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC001View.cpp 中的调试版本
inline CMFC001Doc* CMFC001View::GetDocument() const
   { return reinterpret_cast<CMFC001Doc*>(m_pDocument); }
#endif

