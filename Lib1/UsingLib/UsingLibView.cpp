
// UsingLibView.cpp : CUsingLibView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UsingLib.h"
#endif

#include "UsingLibDoc.h"
#include "UsingLibView.h"
#include "w32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingLibView

IMPLEMENT_DYNCREATE(CUsingLibView, CView)

BEGIN_MESSAGE_MAP(CUsingLibView, CView)
END_MESSAGE_MAP()

// CUsingLibView 构造/析构

CUsingLibView::CUsingLibView()
{
	// TODO: 在此处添加构造代码

}

CUsingLibView::~CUsingLibView()
{
}

BOOL CUsingLibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUsingLibView 绘制

void CUsingLibView::OnDraw(CDC* pDC)
{
	CUsingLibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s.Format(_T("%d"), factorial(5));
	pDC->TextOutW(200, 100, s);
}


// CUsingLibView 诊断

#ifdef _DEBUG
void CUsingLibView::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLibDoc* CUsingLibView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLibDoc)));
	return (CUsingLibDoc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLibView 消息处理程序
