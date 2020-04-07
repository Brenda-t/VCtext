
// text14.1View.cpp : Ctext141View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text14.1.h"
#endif

#include "text14.1Doc.h"
#include "text14.1View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext141View

IMPLEMENT_DYNCREATE(Ctext141View, CView)

BEGIN_MESSAGE_MAP(Ctext141View, CView)
	ON_COMMAND(ID_POPDIALOG, &Ctext141View::OnPopdialog)
END_MESSAGE_MAP()

// Ctext141View 构造/析构

Ctext141View::Ctext141View()
{
	// TODO: 在此处添加构造代码

}

Ctext141View::~Ctext141View()
{
}

BOOL Ctext141View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext141View 绘制

void Ctext141View::OnDraw(CDC* /*pDC*/)
{
	Ctext141Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext141View 诊断

#ifdef _DEBUG
void Ctext141View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext141View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext141Doc* Ctext141View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext141Doc)));
	return (Ctext141Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext141View 消息处理程序


void Ctext141View::OnPopdialog()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		CClientDC dc(this);
		CString s = _T("你已退出对话框");
		dc.TextOutW(100, 200, s);
	}
}
