
// MFC8View.h : CMFC8View 类的接口
//

#pragma once


class CMFC8View : public CView
{
protected: // 仅从序列化创建
	CMFC8View();
	DECLARE_DYNCREATE(CMFC8View)

// 特性
public:
	CMFC8Doc* GetDocument() const;
	CRect j;
	int a1;
	int a2;
	int a;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC8View();
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
};

#ifndef _DEBUG  // MFC8View.cpp 中的调试版本
inline CMFC8Doc* CMFC8View::GetDocument() const
   { return reinterpret_cast<CMFC8Doc*>(m_pDocument); }
#endif

