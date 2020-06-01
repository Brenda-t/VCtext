
// UsingLib4View.h : CUsingLib4View 类的接口
//

#pragma once


class CUsingLib4View : public CView
{
protected: // 仅从序列化创建
	CUsingLib4View();
	DECLARE_DYNCREATE(CUsingLib4View)

// 特性
public:
	CUsingLib4Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CUsingLib4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UsingLib4View.cpp 中的调试版本
inline CUsingLib4Doc* CUsingLib4View::GetDocument() const
   { return reinterpret_cast<CUsingLib4Doc*>(m_pDocument); }
#endif

