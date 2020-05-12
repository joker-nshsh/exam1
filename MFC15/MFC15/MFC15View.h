
// MFC15View.h : CMFC15View 类的接口
//

#pragma once


class CMFC15View : public CView
{
protected: // 仅从序列化创建
	CMFC15View();
	DECLARE_DYNCREATE(CMFC15View)

// 特性
public:
	CMFC15Doc* GetDocument() const;

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
	virtual ~CMFC15View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC15View.cpp 中的调试版本
inline CMFC15Doc* CMFC15View::GetDocument() const
   { return reinterpret_cast<CMFC15Doc*>(m_pDocument); }
#endif

