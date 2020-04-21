
// text15.4View.h : Ctext154View 类的接口
//

#pragma once


class Ctext154View : public CView
{
protected: // 仅从序列化创建
	Ctext154View();
	DECLARE_DYNCREATE(Ctext154View)

// 特性
public:
	Ctext154Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext154View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // text15.4View.cpp 中的调试版本
inline Ctext154Doc* Ctext154View::GetDocument() const
   { return reinterpret_cast<Ctext154Doc*>(m_pDocument); }
#endif

