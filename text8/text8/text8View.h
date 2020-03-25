
// text8View.h : Ctext8View 类的接口
//

#pragma once


class Ctext8View : public CView
{
protected: // 仅从序列化创建
	Ctext8View();
	DECLARE_DYNCREATE(Ctext8View)

// 特性
public:
	Ctext8Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;     //位图对象
	int m_nWidth;          //存储位图宽的数据成员
	int m_nHeight;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // text8View.cpp 中的调试版本
inline Ctext8Doc* Ctext8View::GetDocument() const
   { return reinterpret_cast<Ctext8Doc*>(m_pDocument); }
#endif

