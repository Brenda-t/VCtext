
// text9View.h : Ctext9View 类的接口
//

#pragma once


class Ctext9View : public CView
{
protected: // 仅从序列化创建
	Ctext9View();
	DECLARE_DYNCREATE(Ctext9View)

// 特性
public:
	Ctext9Doc* GetDocument() const;

// 操作
public:
	CPoint m_pt;
	UINT m_nd;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onxian();
	afx_msg void Onjuxing();
	afx_msg void Ontuoyuan();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // text9View.cpp 中的调试版本
inline Ctext9Doc* Ctext9View::GetDocument() const
   { return reinterpret_cast<Ctext9Doc*>(m_pDocument); }
#endif

