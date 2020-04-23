
// text17.2View.cpp : Ctext172View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text17.2.h"
#endif

#include "text17.2Doc.h"
#include "text17.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext172View

IMPLEMENT_DYNCREATE(Ctext172View, CView)

BEGIN_MESSAGE_MAP(Ctext172View, CView)
//	ON_WM_MBUTTONDOWN()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
//ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Ctext172View 构造/析构

Ctext172View::Ctext172View()
{
	// TODO: 在此处添加构造代码
	set = false;
}

Ctext172View::~Ctext172View()
{
}

BOOL Ctext172View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext172View 绘制

void Ctext172View::OnDraw(CDC* pDC)
{
	Ctext172Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(mpt1.x, mpt1.y, mpt2.x, mpt2.y);
}


// Ctext172View 诊断

#ifdef _DEBUG
void Ctext172View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext172View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext172Doc* Ctext172View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext172Doc)));
	return (Ctext172Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext172View 消息处理程序


void Ctext172View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//鼠标左键按下，开始画椭圆，并记录按下时的位置
	mpt1.x = point.x;
	mpt1.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void Ctext172View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	mpt2.x = point.x;             //记录鼠标抬起时的位置，此位置为画椭圆的右下角
	mpt2.y = point.y;
	Invalidate();             //抬起时重绘，使前一个画出的椭圆消失

	CView::OnLButtonUp(nFlags, point);
}

