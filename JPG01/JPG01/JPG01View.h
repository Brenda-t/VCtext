
// JPG01View.h : CJPG01View 类的接口
//

#pragma once


class CJPG01View : public CView
{
protected: // 仅从序列化创建
	CJPG01View();
	DECLARE_DYNCREATE(CJPG01View)

// 特性
public:
	CJPG01Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CJPG01View();
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

#ifndef _DEBUG  // JPG01View.cpp 中的调试版本
inline CJPG01Doc* CJPG01View::GetDocument() const
   { return reinterpret_cast<CJPG01Doc*>(m_pDocument); }
#endif

