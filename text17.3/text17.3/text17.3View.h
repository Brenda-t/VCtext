
// text17.3View.h : Ctext173View 类的接口
//

#pragma once


class Ctext173View : public CView
{
protected: // 仅从序列化创建
	Ctext173View();
	DECLARE_DYNCREATE(Ctext173View)

// 特性
public:
	Ctext173Doc* GetDocument() const;

// 操作
public:
	int A, B, X, Y;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext173View();
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

#ifndef _DEBUG  // text17.3View.cpp 中的调试版本
inline Ctext173Doc* Ctext173View::GetDocument() const
   { return reinterpret_cast<Ctext173Doc*>(m_pDocument); }
#endif

