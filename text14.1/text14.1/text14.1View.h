
// text14.1View.h : Ctext141View 类的接口
//

#pragma once


class Ctext141View : public CView
{
protected: // 仅从序列化创建
	Ctext141View();
	DECLARE_DYNCREATE(Ctext141View)

// 特性
public:
	Ctext141Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext141View();
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
};

#ifndef _DEBUG  // text14.1View.cpp 中的调试版本
inline Ctext141Doc* Ctext141View::GetDocument() const
   { return reinterpret_cast<Ctext141Doc*>(m_pDocument); }
#endif

