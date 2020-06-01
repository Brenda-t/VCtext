
// UsingLib3View.cpp : CUsingLib3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UsingLib3.h"
#endif

#include "UsingLib3Doc.h"
#include "UsingLib3View.h"
#include "Lib3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingLib3View

IMPLEMENT_DYNCREATE(CUsingLib3View, CView)

BEGIN_MESSAGE_MAP(CUsingLib3View, CView)
END_MESSAGE_MAP()

// CUsingLib3View 构造/析构

CUsingLib3View::CUsingLib3View()
{
	// TODO: 在此处添加构造代码

}

CUsingLib3View::~CUsingLib3View()
{
}

BOOL CUsingLib3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUsingLib3View 绘制

void CUsingLib3View::OnDraw(CDC* pDC)
{
	CUsingLib3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CString s;
	s.Format(_T("%d"), factorial(5));
	pDC->TextOutW(200, 100, s);
}


// CUsingLib3View 诊断

#ifdef _DEBUG
void CUsingLib3View::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLib3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLib3Doc* CUsingLib3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLib3Doc)));
	return (CUsingLib3Doc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLib3View 消息处理程序
