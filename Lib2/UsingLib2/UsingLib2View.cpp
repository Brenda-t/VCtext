
// UsingLib2View.cpp : CUsingLib2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UsingLib2.h"
#endif

#include "UsingLib2Doc.h"
#include "UsingLib2View.h"
#include "w33.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingLib2View

IMPLEMENT_DYNCREATE(CUsingLib2View, CView)

BEGIN_MESSAGE_MAP(CUsingLib2View, CView)
END_MESSAGE_MAP()

// CUsingLib2View 构造/析构

CUsingLib2View::CUsingLib2View()
{
	// TODO: 在此处添加构造代码

}

CUsingLib2View::~CUsingLib2View()
{
}

BOOL CUsingLib2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUsingLib2View 绘制

void CUsingLib2View::OnDraw(CDC* pDC)
{
	CUsingLib2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	FAC fac;
	s.Format(_T("%0.2f"), fac.convert(30.0));
	pDC->TextOutW(200, 100, s);
}


// CUsingLib2View 诊断

#ifdef _DEBUG
void CUsingLib2View::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLib2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLib2Doc* CUsingLib2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLib2Doc)));
	return (CUsingLib2Doc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLib2View 消息处理程序
