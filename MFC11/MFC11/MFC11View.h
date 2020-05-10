
// MFC11View.h : CMFC11View 类的接口
//

#pragma once


class CMFC11View : public CView
{
protected: // 仅从序列化创建
	CMFC11View();
	DECLARE_DYNCREATE(CMFC11View)

// 特性
public:
	CMFC11Doc* GetDocument() const;

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
	virtual ~CMFC11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onmingzi();
};

#ifndef _DEBUG  // MFC11View.cpp 中的调试版本
inline CMFC11Doc* CMFC11View::GetDocument() const
   { return reinterpret_cast<CMFC11Doc*>(m_pDocument); }
#endif

