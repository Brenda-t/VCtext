
// text2View.cpp : Ctext2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text2.h"
#endif

#include "text2Doc.h"
#include "text2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext2View

IMPLEMENT_DYNCREATE(Ctext2View, CView)

BEGIN_MESSAGE_MAP(Ctext2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Ctext2View 构造/析构

Ctext2View::Ctext2View()
{
	// TODO: 在此处添加构造代码

}

Ctext2View::~Ctext2View()
{
}

BOOL Ctext2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext2View 绘制

void Ctext2View::OnDraw(CDC* pDC)
{
	Ctext2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}


// Ctext2View 诊断

#ifdef _DEBUG
void Ctext2View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext2Doc* Ctext2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext2Doc)));
	return (Ctext2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext2View 消息处理程序


void Ctext2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CClientDC ds(this);
	CString s = _T("左键正被按下");
	ds.TextOutW(100, 100, s);
	CView::OnLButtonDown(nFlags, point);
}


void Ctext2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC ds(this);
	CString s = _T("左键正在抬起");
	ds.TextOutW(500, 500, s);
	CView::OnLButtonUp(nFlags, point);
}
