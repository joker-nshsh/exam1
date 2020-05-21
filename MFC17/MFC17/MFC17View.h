
// MFC17View.h : CMFC17View 类的接口
//

#pragma once


class CMFC17View : public CView
{
protected: // 仅从序列化创建
	CMFC17View();
	DECLARE_DYNCREATE(CMFC17View)

// 特性
public:
	CMFC17Doc* GetDocument() const;

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
	virtual ~CMFC17View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onzifu();
};

#ifndef _DEBUG  // MFC17View.cpp 中的调试版本
inline CMFC17Doc* CMFC17View::GetDocument() const
   { return reinterpret_cast<CMFC17Doc*>(m_pDocument); }
#endif

