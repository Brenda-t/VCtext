
// text15.4View.cpp : Ctext154View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text15.4.h"
#endif

#include "text15.4Doc.h"
#include "text15.4View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext154View

IMPLEMENT_DYNCREATE(Ctext154View, CView)

BEGIN_MESSAGE_MAP(Ctext154View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Ctext154View 构造/析构

Ctext154View::Ctext154View()
{
	// TODO: 在此处添加构造代码

}

Ctext154View::~Ctext154View()
{
}

BOOL Ctext154View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext154View 绘制

void Ctext154View::OnDraw(CDC* /*pDC*/)
{
	Ctext154Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext154View 诊断

#ifdef _DEBUG
void Ctext154View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext154View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext154Doc* Ctext154View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext154Doc)));
	return (Ctext154Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext154View 消息处理程序


void Ctext154View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MyDialog dlg;
	int r = dlg.DoModal();
	CView::OnLButtonDblClk(nFlags, point);
}
