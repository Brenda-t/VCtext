
// text17.4View.cpp : Ctext174View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text17.4.h"
#endif

#include "text17.4Doc.h"
#include "text17.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext174View

IMPLEMENT_DYNCREATE(Ctext174View, CView)

BEGIN_MESSAGE_MAP(Ctext174View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext174View 构造/析构

Ctext174View::Ctext174View()
{
	// TODO: 在此处添加构造代码
	mpt.x = 300;
	mpt.y = 300;
	a = rand() % 100 + 10;
	b = rand() % 50 + 5;
}

Ctext174View::~Ctext174View()
{
}

BOOL Ctext174View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext174View 绘制

void Ctext174View::OnDraw(CDC* pDC)
{
	Ctext174Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
//	CRect re(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
	pDC->Ellipse(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);                             //GetDC()->Ellipse(re);
}


// Ctext174View 诊断

#ifdef _DEBUG
void Ctext174View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext174View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext174Doc* Ctext174View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext174Doc)));
	return (Ctext174Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext174View 消息处理程序


void Ctext174View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//set = true;
	//Invalidate();
	
	CClientDC dc(this);
	CRect re(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
	if (re.PtInRect(point))
	{
	//	mpt=point;
		int color = RGB(0, 255, 0);
		CPen newpen(PS_DASH, 1, color);
		CPen *oldpen = dc.SelectObject(&newpen);
		dc.Rectangle(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
		dc.SelectObject(oldpen);

		dc.Ellipse(re);                             //GetDC()->Ellipse(re);
	}
	

	CView::OnLButtonDown(nFlags, point);
}
