
// text13.1View.h : Ctext131View 类的接口
//

#pragma once


class Ctext131View : public CView
{
protected: // 仅从序列化创建
	Ctext131View();
	DECLARE_DYNCREATE(Ctext131View)

// 特性
public:
	Ctext131Doc* GetDocument() const;

// 操作
public:
	CRect A;                 //定义矩形A
	CString m_strLine,n_strLine;       //定义一个字符对象
	CPoint m_pt;
	bool set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // text13.1View.cpp 中的调试版本
inline Ctext131Doc* Ctext131View::GetDocument() const
   { return reinterpret_cast<Ctext131Doc*>(m_pDocument); }
#endif

