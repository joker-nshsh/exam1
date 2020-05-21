
// MFC16View.h : CMFC16View 类的接口
//

#pragma once


class CMFC16View : public CView
{
protected: // 仅从序列化创建
	CMFC16View();
	DECLARE_DYNCREATE(CMFC16View)

// 特性
public:
	CMFC16Doc* GetDocument() const;
	CString s;
	CDialog dlg;
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
	virtual ~CMFC16View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On10();
	afx_msg void OnBnClickedOk();
};

#ifndef _DEBUG  // MFC16View.cpp 中的调试版本
inline CMFC16Doc* CMFC16View::GetDocument() const
   { return reinterpret_cast<CMFC16Doc*>(m_pDocument); }
#endif

