
// text17.2View.h : Ctext172View 类的接口
//

#pragma once


class Ctext172View : public CView
{
protected: // 仅从序列化创建
	Ctext172View();
	DECLARE_DYNCREATE(Ctext172View)

// 特性
public:
	Ctext172Doc* GetDocument() const;

// 操作
public:
	CPoint mpt1,mpt2;
	CRect re;
	bool set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext172View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // text17.2View.cpp 中的调试版本
inline Ctext172Doc* Ctext172View::GetDocument() const
   { return reinterpret_cast<Ctext172Doc*>(m_pDocument); }
#endif

