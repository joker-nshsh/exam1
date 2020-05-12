
// MFC002View.h : CMFC002View 类的接口
//

#pragma once


class CMFC002View : public CView
{
protected: // 仅从序列化创建
	CMFC002View();
	DECLARE_DYNCREATE(CMFC002View)

// 特性
public:
	CMFC002Doc* GetDocument() const;

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
	virtual ~CMFC002View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC002View.cpp 中的调试版本
inline CMFC002Doc* CMFC002View::GetDocument() const
   { return reinterpret_cast<CMFC002Doc*>(m_pDocument); }
#endif

