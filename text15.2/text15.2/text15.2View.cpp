
// text15.2View.cpp : Ctext152View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text15.2.h"
#endif

#include "text15.2Doc.h"
#include "text15.2View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext152View

IMPLEMENT_DYNCREATE(Ctext152View, CView)

BEGIN_MESSAGE_MAP(Ctext152View, CView)
	ON_COMMAND(ID_PopDialog, &Ctext152View::OnPopdialog)
END_MESSAGE_MAP()

// Ctext152View 构造/析构

Ctext152View::Ctext152View()
{
	// TODO: 在此处添加构造代码

}

Ctext152View::~Ctext152View()
{
}

BOOL Ctext152View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext152View 绘制

void Ctext152View::OnDraw(CDC* /*pDC*/)
{
	Ctext152Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext152View 诊断

#ifdef _DEBUG
void Ctext152View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext152View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext152Doc* Ctext152View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext152Doc)));
	return (Ctext152Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext152View 消息处理程序


void Ctext152View::OnPopdialog()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dlg;
	int t = dlg.DoModal();
}
