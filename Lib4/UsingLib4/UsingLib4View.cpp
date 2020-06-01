
// UsingLib4View.cpp : CUsingLib4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UsingLib4.h"
#endif

#include "UsingLib4Doc.h"
#include "UsingLib4View.h"
#include "Lib4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingLib4View

IMPLEMENT_DYNCREATE(CUsingLib4View, CView)

BEGIN_MESSAGE_MAP(CUsingLib4View, CView)
END_MESSAGE_MAP()

// CUsingLib4View 构造/析构

CUsingLib4View::CUsingLib4View()
{
	// TODO: 在此处添加构造代码

}

CUsingLib4View::~CUsingLib4View()
{
}

BOOL CUsingLib4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUsingLib4View 绘制

void CUsingLib4View::OnDraw(CDC* pDC)
{
	CUsingLib4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	FAC fac;
	s.Format(_T("%0.2f"), fac.convert(30.0));       //在其他地方调用类中的成员函数，必须先创建类对象，再由类对象调用该成员函数
	pDC->TextOutW(200, 100, s);
}


// CUsingLib4View 诊断

#ifdef _DEBUG
void CUsingLib4View::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLib4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLib4Doc* CUsingLib4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLib4Doc)));
	return (CUsingLib4Doc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLib4View 消息处理程序
