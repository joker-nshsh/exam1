
// MFC28View.h : CMFC28View 类的接口
//

#pragma once


class CMFC28View : public CView
{
protected: // 仅从序列化创建
	CMFC28View();
	DECLARE_DYNCREATE(CMFC28View)

// 特性
public:
	CMFC28Doc* GetDocument() const;
	CString filename;
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
	virtual ~CMFC28View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
	afx_msg void OnBnClickedButton1();
	afx_msg void On32771();
};

#ifndef _DEBUG  // MFC28View.cpp 中的调试版本
inline CMFC28Doc* CMFC28View::GetDocument() const
   { return reinterpret_cast<CMFC28Doc*>(m_pDocument); }
#endif

