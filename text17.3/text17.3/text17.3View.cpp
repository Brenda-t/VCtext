
// text17.3View.cpp : Ctext173View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text17.3.h"
#endif

#include "text17.3Doc.h"
#include "text17.3View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext173View

IMPLEMENT_DYNCREATE(Ctext173View, CView)

BEGIN_MESSAGE_MAP(Ctext173View, CView)
	ON_COMMAND(ID_PopDialog, &Ctext173View::OnPopdialog)
END_MESSAGE_MAP()

// Ctext173View 构造/析构

Ctext173View::Ctext173View()
{
	// TODO: 在此处添加构造代码

}

Ctext173View::~Ctext173View()
{
}

BOOL Ctext173View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext173View 绘制

void Ctext173View::OnDraw(CDC* /*pDC*/)
{
	Ctext173Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext173View 诊断

#ifdef _DEBUG
void Ctext173View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext173View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext173Doc* Ctext173View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext173Doc)));
	return (Ctext173Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext173View 消息处理程序


void Ctext173View::OnPopdialog()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dlg;
	int t = dlg.DoModal();

	A = dlg.a;
	B = dlg.b;
	X = dlg.x;
	Y = dlg.y;
	if (t = IDOK)
	{
		CRect re(X - A, Y - B, X + A, Y + B);
		GetDC()->Ellipse(re);
	}

}
