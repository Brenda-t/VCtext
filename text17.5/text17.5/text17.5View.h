
// text17.5View.h : Ctext175View 类的接口
//

#pragma once


class Ctext175View : public CView
{
protected: // 仅从序列化创建
	Ctext175View();
	DECLARE_DYNCREATE(Ctext175View)

// 特性
public:
	Ctext175Doc* GetDocument() const;

// 操作
public:
	int a, b;
	CPoint mpt;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext175View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopdialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // text17.5View.cpp 中的调试版本
inline Ctext175Doc* Ctext175View::GetDocument() const
   { return reinterpret_cast<Ctext175Doc*>(m_pDocument); }
#endif

