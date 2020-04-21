
// text15.3View.h : Ctext153View 类的接口
//

#pragma once


class Ctext153View : public CView
{
protected: // 仅从序列化创建
	Ctext153View();
	DECLARE_DYNCREATE(Ctext153View)

// 特性
public:
	Ctext153Doc* GetDocument() const;

// 操作
public:
	CPoint mpt;
	CRect rect;
	bool set,a;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext153View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // text15.3View.cpp 中的调试版本
inline Ctext153Doc* Ctext153View::GetDocument() const
   { return reinterpret_cast<Ctext153Doc*>(m_pDocument); }
#endif

