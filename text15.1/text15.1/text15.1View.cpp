
// text15.1View.cpp : Ctext151View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text15.1.h"
#endif

#include "text15.1Doc.h"
#include "text15.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext151View

IMPLEMENT_DYNCREATE(Ctext151View, CView)

BEGIN_MESSAGE_MAP(Ctext151View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_HUAJUXING, &Ctext151View::OnHuajuxing)
END_MESSAGE_MAP()

// Ctext151View 构造/析构

Ctext151View::Ctext151View()
{
	// TODO: 在此处添加构造代码
	set = false;
	m_point.x = 200;
	m_point.y = 300;
	
}

Ctext151View::~Ctext151View()
{
}

BOOL Ctext151View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext151View 绘制

void Ctext151View::OnDraw(CDC* pDC)
{
	Ctext151Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//重绘
	CClientDC dc(this);
	rect.left = m_point.x - 10;
	rect.top = m_point.y - 20;
	rect.right = m_point.x + 15;
	rect.bottom = m_point.y + 30;
	dc.Rectangle(&rect);
}


// Ctext151View 诊断

#ifdef _DEBUG
void Ctext151View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext151View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext151Doc* Ctext151View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext151Doc)));
	return (Ctext151Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext151View 消息处理程序


void Ctext151View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void Ctext151View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void Ctext151View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set)
	{
	//	if (rect.PtInRect(point))      //判断鼠标点的位置是否在矩形中
		//{
			m_point = point;
			Invalidate();
		//}
	}
	CView::OnMouseMove(nFlags, point);
}


void Ctext151View::OnHuajuxing()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	rect.left = m_point.x - 10;
	rect.top = m_point.y - 20;
	rect.right = m_point.x+ 15;
	rect.bottom = m_point.y + 30;
	dc.Rectangle(&rect);
}
