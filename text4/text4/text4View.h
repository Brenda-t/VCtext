
// text4View.h : Ctext4View 类的接口
//

#pragma once


class Ctext4View : public CView
{
protected: // 仅从序列化创建
	Ctext4View();
	DECLARE_DYNCREATE(Ctext4View)

// 特性
public:
	Ctext4Doc* GetDocument() const;

// 操作
public:
	CString s;
	int A;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // text4View.cpp 中的调试版本
inline Ctext4Doc* Ctext4View::GetDocument() const
   { return reinterpret_cast<Ctext4Doc*>(m_pDocument); }
#endif

