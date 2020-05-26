
// text18View.h : Ctext18View 类的接口
//

#pragma once


class Ctext18View : public CView
{
protected: // 仅从序列化创建
	Ctext18View();
	DECLARE_DYNCREATE(Ctext18View)

// 特性
public:
	Ctext18Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext18View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopfiledlg();
	afx_msg void OnPopdlg();
};

#ifndef _DEBUG  // text18View.cpp 中的调试版本
inline Ctext18Doc* Ctext18View::GetDocument() const
   { return reinterpret_cast<Ctext18Doc*>(m_pDocument); }
#endif

