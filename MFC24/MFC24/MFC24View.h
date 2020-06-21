
// MFC24View.h : CMFC24View 类的接口
//

#pragma once


class CMFC24View : public CView
{
protected: // 仅从序列化创建
	CMFC24View();
	DECLARE_DYNCREATE(CMFC24View)

// 特性
public:
	CMFC24Doc* GetDocument() const;
	CRect a;
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
	virtual ~CMFC24View();
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
};

#ifndef _DEBUG  // MFC24View.cpp 中的调试版本
inline CMFC24Doc* CMFC24View::GetDocument() const
   { return reinterpret_cast<CMFC24Doc*>(m_pDocument); }
#endif

