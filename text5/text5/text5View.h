
// text5View.h : Ctext5View 类的接口
//

#pragma once


class Ctext5View : public CView
{
protected: // 仅从序列化创建
	Ctext5View();
	DECLARE_DYNCREATE(Ctext5View)

// 特性
public:
	Ctext5Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // text5View.cpp 中的调试版本
inline Ctext5Doc* Ctext5View::GetDocument() const
   { return reinterpret_cast<Ctext5Doc*>(m_pDocument); }
#endif

