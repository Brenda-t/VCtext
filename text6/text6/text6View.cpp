
// text6View.cpp : Ctext6View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text6.h"
#endif

#include "text6Doc.h"
#include "text6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext6View

IMPLEMENT_DYNCREATE(Ctext6View, CView)

BEGIN_MESSAGE_MAP(Ctext6View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext6View 构造/析构

Ctext6View::Ctext6View()
{
	// TODO: 在此处添加构造代码

}

Ctext6View::~Ctext6View()
{
}

BOOL Ctext6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext6View 绘制

void Ctext6View::OnDraw(CDC* /*pDC*/)
{
	Ctext6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext6View 诊断

#ifdef _DEBUG
void Ctext6View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext6Doc* Ctext6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext6Doc)));
	return (Ctext6Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext6View 消息处理程序


void Ctext6View::OnLButtonDown(UINT nFlags, CPoint point)
{
	Ctext6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	pDoc->count+=1;
	CView::OnLButtonDown(nFlags, point);
}


void Ctext6View::OnRButtonDown(UINT nFlags, CPoint point)
{
	Ctext6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s.Format(_T("%d"), pDoc->count);
	dc.TextOutW(20, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
