
// JPG02View.h : CJPG02View 类的接口
//

#pragma once


class CJPG02View : public CView
{
protected: // 仅从序列化创建
	CJPG02View();
	DECLARE_DYNCREATE(CJPG02View)

// 特性
public:
	CJPG02Doc* GetDocument() const;

// 操作
public:
	bool set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CJPG02View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // JPG02View.cpp 中的调试版本
inline CJPG02Doc* CJPG02View::GetDocument() const
   { return reinterpret_cast<CJPG02Doc*>(m_pDocument); }
#endif

