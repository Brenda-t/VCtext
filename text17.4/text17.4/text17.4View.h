
// text17.4View.h : Ctext174View 类的接口
//

#pragma once


class Ctext174View : public CView
{
protected: // 仅从序列化创建
	Ctext174View();
	DECLARE_DYNCREATE(Ctext174View)

// 特性
public:
	Ctext174Doc* GetDocument() const;

// 操作
public:
	CPoint mpt;
	int a, b;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext174View();
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
};

#ifndef _DEBUG  // text17.4View.cpp 中的调试版本
inline Ctext174Doc* Ctext174View::GetDocument() const
   { return reinterpret_cast<Ctext174Doc*>(m_pDocument); }
#endif

