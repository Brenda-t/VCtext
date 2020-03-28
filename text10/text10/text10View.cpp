
// text10View.cpp : Ctext10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text10.h"
#endif

#include "text10Doc.h"
#include "text10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext10View

IMPLEMENT_DYNCREATE(Ctext10View, CView)

BEGIN_MESSAGE_MAP(Ctext10View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Ctext10View 构造/析构

Ctext10View::Ctext10View()
{
	// TODO: 在此处添加构造代码
	m_pt = 0;
	set = false;
}

Ctext10View::~Ctext10View()
{
}

BOOL Ctext10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext10View 绘制

void Ctext10View::OnDraw(CDC* pDC)
{
	Ctext10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}


// Ctext10View 诊断

#ifdef _DEBUG
void Ctext10View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext10Doc* Ctext10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext10Doc)));
	return (Ctext10Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext10View 消息处理程序


void Ctext10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pt = point;
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void Ctext10View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	dc.Rectangle(CRect(m_pt, point));
	set = false;
	//Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Ctext10View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set)
	{
		CClientDC dc(this);
		CString s;
		s.Format(_T("鼠标位置：%d,%d"), point.x, point.y);
		dc.TextOutW(100, 100, s);
	}
	CView::OnMouseMove(nFlags, point);
}
