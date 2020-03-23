
// Win32Project2View.h : CWin32Project2View 类的接口
//

#pragma once


class CWin32Project2View : public CView
{
protected: // 仅从序列化创建
	CWin32Project2View();
	DECLARE_DYNCREATE(CWin32Project2View)

// 特性
public:
	CWin32Project2Doc* GetDocument() const;

// 操作
public:
	int N;
	CArray <CRect, CRect>cr;
	bool set;
	int j;
	CRect rc;
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
	virtual ~CWin32Project2View();
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
};

#ifndef _DEBUG  // Win32Project2View.cpp 中的调试版本
inline CWin32Project2Doc* CWin32Project2View::GetDocument() const
   { return reinterpret_cast<CWin32Project2Doc*>(m_pDocument); }
#endif

