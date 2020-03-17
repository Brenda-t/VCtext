
// text2View.h : Ctext2View 类的接口
//

#pragma once


class Ctext2View : public CView
{
protected: // 仅从序列化创建
	Ctext2View();
	DECLARE_DYNCREATE(Ctext2View)

// 特性
public:
	Ctext2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext2View();
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
};

#ifndef _DEBUG  // text2View.cpp 中的调试版本
inline Ctext2Doc* Ctext2View::GetDocument() const
   { return reinterpret_cast<Ctext2Doc*>(m_pDocument); }
#endif

