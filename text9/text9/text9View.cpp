
// text9View.cpp : Ctext9View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text9.h"
#endif

#include "text9Doc.h"
#include "text9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext9View

IMPLEMENT_DYNCREATE(Ctext9View, CView)

BEGIN_MESSAGE_MAP(Ctext9View, CView)
	ON_COMMAND(ID_xian, &Ctext9View::Onxian)
	ON_COMMAND(ID_juxing, &Ctext9View::Onjuxing)
	ON_COMMAND(ID_tuoyuan, &Ctext9View::Ontuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Ctext9View 构造/析构

Ctext9View::Ctext9View()
{
	// TODO: 在此处添加构造代码
	m_pt= 0;
	m_nd = 0;
}

Ctext9View::~Ctext9View()
{
}

BOOL Ctext9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext9View 绘制

void Ctext9View::OnDraw(CDC* pDC)
{
	Ctext9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
}


// Ctext9View 诊断

#ifdef _DEBUG
void Ctext9View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext9Doc* Ctext9View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext9Doc)));
	return (Ctext9Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext9View 消息处理程序


void Ctext9View::Onxian()
{
	// TODO: 在此添加命令处理程序代码
	m_nd = 1;
}


void Ctext9View::Onjuxing()
{
	// TODO: 在此添加命令处理程序代码
	m_nd = 2;
}


void Ctext9View::Ontuoyuan()
{
	// TODO: 在此添加命令处理程序代码
	m_nd = 3;
	
}


void Ctext9View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pt= point;

	CView::OnLButtonDown(nFlags, point);
}


void Ctext9View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	switch (m_nd)
	{
	case 1:
		dc.MoveTo(m_pt);
		dc.LineTo(point);
		break;
	case 2:
		dc.Rectangle(CRect(m_pt, point));
		break;
	case 3:
		dc.Ellipse(CRect(m_pt, point));
		break;

		break;
	}
}


void Ctext9View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
}
