
// MFC30View.h : CMFC30View 类的接口
//

#pragma once


class CMFC30View : public CView
{
protected: // 仅从序列化创建
	CMFC30View();
	DECLARE_DYNCREATE(CMFC30View)

// 特性
public:
	CMFC30Doc* GetDocument() const;

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
	virtual ~CMFC30View();
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
	afx_msg void On32772();
};

#ifndef _DEBUG  // MFC30View.cpp 中的调试版本
inline CMFC30Doc* CMFC30View::GetDocument() const
   { return reinterpret_cast<CMFC30Doc*>(m_pDocument); }
#endif

