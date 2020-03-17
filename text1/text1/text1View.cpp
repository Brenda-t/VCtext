
// text1View.cpp : Ctext1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text1.h"
#endif

#include "text1Doc.h"
#include "text1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext1View

IMPLEMENT_DYNCREATE(Ctext1View, CView)

BEGIN_MESSAGE_MAP(Ctext1View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext1View 构造/析构

Ctext1View::Ctext1View()
{
	// TODO: 在此处添加构造代码
}

Ctext1View::~Ctext1View()
{
}

BOOL Ctext1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext1View 绘制

void Ctext1View::OnDraw(CDC* pDC)
{
	Ctext1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	/*
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));*/
	CRect cr;
	this->GetClientRect(&cr);  //获取客户区信息
	CClientDC dc(this);    //构造客户区对象dc
	dc.Ellipse(cr);
}


// Ctext1View 诊断

#ifdef _DEBUG
void Ctext1View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext1Doc* Ctext1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext1Doc)));
	return (Ctext1Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext1View 消息处理程序


void Ctext1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	//实验1
	CRect cr;
	this->GetClientRect(&cr);  //获取客户区信息
	CClientDC dc(this);    //构造客户区对象dc
	dc.Ellipse(cr);
	this->Invalidate();    //强制重绘
	/*
	//实验二
	int a = rand() % 50 + 5;    //随机数0~54
	int b = rand() % 100 + 1;    //随机数0~50
	CRect cr(point.x-a,point.y-b,point.x+a,point.y+b);

	Ctext1Doc*pDoc = GetDocument();
	pDoc->ca.Add(cr);
	this->Invalidate();    //强制重绘
	*/

	CView::OnLButtonDown(nFlags, point);
}
