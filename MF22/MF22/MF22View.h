
// MF22View.h : CMF22View 类的接口
//

#pragma once


class CMF22View : public CView
{
protected: // 仅从序列化创建
	CMF22View();
	DECLARE_DYNCREATE(CMF22View)

// 特性
public:
	CMF22Doc* GetDocument() const;

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
	virtual ~CMF22View();
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

#ifndef _DEBUG  // MF22View.cpp 中的调试版本
inline CMF22Doc* CMF22View::GetDocument() const
   { return reinterpret_cast<CMF22Doc*>(m_pDocument); }
#endif

