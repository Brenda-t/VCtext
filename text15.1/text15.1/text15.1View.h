
// text15.1View.h : Ctext151View 类的接口
//

#pragma once


class Ctext151View : public CView
{
protected: // 仅从序列化创建
	Ctext151View();
	DECLARE_DYNCREATE(Ctext151View)

// 特性
public:
	Ctext151Doc* GetDocument() const;

// 操作
public:
	bool set;
	CPoint m_point;
	CRect rect;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext151View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnHuajuxing();
};

#ifndef _DEBUG  // text15.1View.cpp 中的调试版本
inline Ctext151Doc* Ctext151View::GetDocument() const
   { return reinterpret_cast<Ctext151Doc*>(m_pDocument); }
#endif

