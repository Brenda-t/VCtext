
// MFC0View.cpp : CMFC0View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC0.h"
#endif

#include "MFC0Doc.h"
#include "MFC0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC0View

IMPLEMENT_DYNCREATE(CMFC0View, CView)

BEGIN_MESSAGE_MAP(CMFC0View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC0View 构造/析构

CMFC0View::CMFC0View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	for (int i = 0; i < N; i++)
	{
		bool b = true;
		a.Add(b);
		int t = (i + 1) * 100;       //在数组中添加5个矩形
		CRect rect(t, 0, t + 30, 30);    //左上角坐标和右下角坐标
		cr.Add(rect);                    //得到了5个圆
	}
}

CMFC0View::~CMFC0View()
{
}

BOOL CMFC0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC0View 绘制

void CMFC0View::OnDraw(CDC* pDC)
{
	CMFC0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (set)               //计时器只能设置一次，但改变窗体时，都会再次调用ondraw函数，所以做如下改变
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL);   //5个计时器的时间是在范围内随机的100~500间
			set = false;
		}
	}
	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);    //画出圆
	}
}


// CMFC0View 诊断

#ifdef _DEBUG
void CMFC0View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC0Doc* CMFC0View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC0Doc)));
	return (CMFC0Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC0View 消息处理程序


void CMFC0View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//计时器时间到了调用此函数
	CRect clientRec;   //构造矩形
	GetClientRect(&clientRec);  //取得客户区大小
	int i = nIDEvent;   //第i个计时器
	if (a[i])
	{
		cr[i].top += 10;    //设置移动的圆，正在掉下的圆
		cr[i].bottom += 10;
		if (cr[i].bottom >= clientRec.bottom)
			a[i] = false;
	}
	else
	{
		cr[i].top -= 10;    //设置移动的圆，正在向上的圆
		cr[i].bottom -= 10;
	}
	Invalidate();    //强制重绘，使圆出现	
	CView::OnTimer(nIDEvent);
}
