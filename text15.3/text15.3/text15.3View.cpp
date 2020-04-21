
// text15.3View.cpp : Ctext153View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text15.3.h"
#endif

#include "text15.3Doc.h"
#include "text15.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext153View

IMPLEMENT_DYNCREATE(Ctext153View, CView)

BEGIN_MESSAGE_MAP(Ctext153View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Ctext153View 构造/析构

Ctext153View::Ctext153View()
{
	// TODO: 在此处添加构造代码
	set = false;
	a = true;
//	CRect r;   //构造矩形
//	GetClientRect(&r);  //取得客户区大小
//	mpt.x = (r.bottom - r.top) / 2;      //获取不了中间左边的位置，mpt的位置依旧会是（0，0），没有赋值成功，并在运行时出现逻辑错误
//	mpt.y = (r.right - r.left) / 4;
	
	mpt.x = 300;
	mpt.y = 300;
	rect.left = mpt.x - 30;      //因为后面小球的移动是左右移动，所以画圆操作的时候，要有关联到上下左右画圆。
	rect.right = mpt.x + 30;
	rect.top = mpt.y - 30;
	rect.bottom = mpt.y + 30;
}

Ctext153View::~Ctext153View()
{
}

BOOL Ctext153View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext153View 绘制

void Ctext153View::OnDraw(CDC* pDC)
{
	Ctext153Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

//	CRect rect(mpt.x - 30, mpt.y - 30, mpt.x + 30, mpt.y + 30);
	pDC->Ellipse(rect);
	SetTimer(1, rand() % 400 + 100, NULL);        //为小球设置定时器
}


// Ctext153View 诊断

#ifdef _DEBUG
void Ctext153View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext153View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext153Doc* Ctext153View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext153Doc)));
	return (Ctext153Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext153View 消息处理程序


void Ctext153View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	set = true;
	a = true;
	CView::OnLButtonDown(nFlags, point);
}


void Ctext153View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonDblClk(nFlags, point);
}


void Ctext153View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnTimer(nIDEvent);
	int i = nIDEvent;
	CRect r;   //构造矩形
	GetClientRect(&r);  //取得客户区大小
	if (a)
	{
		if (set)
		{
			rect.left += 30;
			rect.right += 30;
			if (rect.right > r.right)
				a = false;
		}
	}
	else
	{
		rect.left -= 30;
		rect.right -= 30;
	}
	Invalidate();   //强制重绘，使圆出现
}
