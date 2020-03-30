
// text12View.cpp : Ctext12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text12.h"
#endif

#include "text12Doc.h"
#include "text12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext12View

IMPLEMENT_DYNCREATE(Ctext12View, CView)

BEGIN_MESSAGE_MAP(Ctext12View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext12View 构造/析构

Ctext12View::Ctext12View()
{
	// TODO: 在此处添加构造代码

}

Ctext12View::~Ctext12View()
{
}

BOOL Ctext12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext12View 绘制

void Ctext12View::OnDraw(CDC* pDC)
{
	Ctext12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);
	pDC->Rectangle(pDoc->D);
}


// Ctext12View 诊断

#ifdef _DEBUG
void Ctext12View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext12Doc* Ctext12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext12Doc)));
	return (Ctext12Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext12View 消息处理程序


void Ctext12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ctext12Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s, ss, cs;
	pDoc->m_pt = point;
	s.Format(_T("%d"), pDoc->a);             
	ss.Format(_T("%d"), pDoc->b);
	cs = _T("点击无效");
	
	if (pDoc->A.left < point.x &&point.x< pDoc->A.right  && pDoc->A.top< point.y &&point.y<pDoc->A.bottom)
		dc.TextOutW(point.x, point.y, s);
	else if (pDoc->B.left < point.x &&point.x< pDoc->B.right &&pDoc->B.top< point.y &&point.y< pDoc->B.bottom)
		dc.TextOutW(point.x, point.y, ss);
	else if (pDoc->D.left < point.x&&point.x < pDoc->D.right&&pDoc->D.top < point.y&&point.y < pDoc->D.bottom)
	{
		pDoc->count1 += 1;
		switch (pDoc->count1)
		{
		case 1:
			dc.TextOutW(point.x, point.y, pDoc->m);
			break;
		case 2:
			dc.TextOutW(point.x, point.y, pDoc->n);
			break;
		case 3:
			dc.TextOutW(point.x, point.y, pDoc->p);
			break;
		case 4:
			dc.TextOutW(point.x, point.y, pDoc->q);
			break;

			break;
		}
	}
	else
		dc.TextOutW(point.x, point.y, cs);
	CView::OnLButtonDown(nFlags, point);
}


void Ctext12View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Ctext12Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->count2 += 1;
	CString s, s1, s2, s3, s4;
	s1.Format(_T("%d"), pDoc->a + pDoc->b);
	s2.Format(_T("%d"), pDoc->a - pDoc->b);
	s3.Format(_T("%d"), pDoc->a * pDoc->b);
	s4.Format(_T("%d"), pDoc->a / pDoc->b);
	if (pDoc->C.left < point.x &&point.x < pDoc->C.right  && pDoc->C.top < point.y &&point.y < pDoc->C.bottom)
	{
		switch (pDoc->count2)
		{
		case 1:
			dc.TextOutW(point.x, point.y, s1);
			break;
		case 2:
			dc.TextOutW(point.x, point.y, s2);
			break;
		case 3:
			dc.TextOutW(point.x, point.y, s3);
			break;
		case 4:
			dc.TextOutW(point.x, point.y, s4);
			break;

			break;
		}
	}

	CView::OnRButtonDown(nFlags, point);
}
