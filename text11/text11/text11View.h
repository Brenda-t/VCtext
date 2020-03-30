
// text11View.h : Ctext11View 类的接口
//

#pragma once


class Ctext11View : public CView
{
protected: // 仅从序列化创建
	Ctext11View();
	DECLARE_DYNCREATE(Ctext11View)

// 特性
public:
	Ctext11Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext11View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // text11View.cpp 中的调试版本
inline Ctext11Doc* Ctext11View::GetDocument() const
   { return reinterpret_cast<Ctext11Doc*>(m_pDocument); }
#endif

