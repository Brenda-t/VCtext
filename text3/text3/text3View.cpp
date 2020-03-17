
// text3View.cpp : Ctext3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text3.h"
#endif

#include "text3Doc.h"
#include "text3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext3View

IMPLEMENT_DYNCREATE(Ctext3View, CView)

BEGIN_MESSAGE_MAP(Ctext3View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext3View 构造/析构

Ctext3View::Ctext3View()
{
	// TODO: 在此处添加构造代码

}

Ctext3View::~Ctext3View()
{
}

BOOL Ctext3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext3View 绘制

void Ctext3View::OnDraw(CDC* /*pDC*/)
{
	Ctext3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext3View 诊断

#ifdef _DEBUG
void Ctext3View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext3Doc* Ctext3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext3Doc)));
	return (Ctext3Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext3View 消息处理程序


void Ctext3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	Ctext3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s.Format(_T("A+B=%d"), pDoc->A+pDoc->B);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
