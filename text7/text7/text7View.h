
// text7View.h : Ctext7View 类的接口
//

#pragma once


class Ctext7View : public CView
{
protected: // 仅从序列化创建
	Ctext7View();
	DECLARE_DYNCREATE(Ctext7View)

// 特性
public:
	Ctext7Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // text7View.cpp 中的调试版本
inline Ctext7Doc* Ctext7View::GetDocument() const
   { return reinterpret_cast<Ctext7Doc*>(m_pDocument); }
#endif

