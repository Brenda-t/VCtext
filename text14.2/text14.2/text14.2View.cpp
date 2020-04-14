
// text14.2View.cpp : Ctext142View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text14.2.h"
#endif

#include "text14.2Doc.h"
#include "text14.2View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext142View

IMPLEMENT_DYNCREATE(Ctext142View, CView)

BEGIN_MESSAGE_MAP(Ctext142View, CView)
	ON_COMMAND(ID_PopDialog, &Ctext142View::OnPopdialog)
END_MESSAGE_MAP()

// Ctext142View 构造/析构

Ctext142View::Ctext142View()
{
	// TODO: 在此处添加构造代码

}

Ctext142View::~Ctext142View()
{
}

BOOL Ctext142View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext142View 绘制

void Ctext142View::OnDraw(CDC* /*pDC*/)
{
	Ctext142Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext142View 诊断

#ifdef _DEBUG
void Ctext142View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext142View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext142Doc* Ctext142View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext142Doc)));
	return (Ctext142Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext142View 消息处理程序


void Ctext142View::OnPopdialog()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dlg;
	int t = dlg.DoModal();
}
