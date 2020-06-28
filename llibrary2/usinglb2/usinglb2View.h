
// usinglb2View.h : Cusinglb2View 类的接口
//

#pragma once


class Cusinglb2View : public CView
{
protected: // 仅从序列化创建
	Cusinglb2View();
	DECLARE_DYNCREATE(Cusinglb2View)

// 特性
public:
	Cusinglb2Doc* GetDocument() const;

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
	virtual ~Cusinglb2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // usinglb2View.cpp 中的调试版本
inline Cusinglb2Doc* Cusinglb2View::GetDocument() const
   { return reinterpret_cast<Cusinglb2Doc*>(m_pDocument); }
#endif

