
// text7View.cpp : Ctext7View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text7.h"
#endif

#include "text7Doc.h"
#include "text7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext7View

IMPLEMENT_DYNCREATE(Ctext7View, CView)

BEGIN_MESSAGE_MAP(Ctext7View, CView)
	ON_COMMAND(ID_SHOWNAME, &Ctext7View::OnShowname)
END_MESSAGE_MAP()

// Ctext7View 构造/析构

Ctext7View::Ctext7View()
{
	// TODO: 在此处添加构造代码

}

Ctext7View::~Ctext7View()
{
}

BOOL Ctext7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext7View 绘制

void Ctext7View::OnDraw(CDC* /*pDC*/)
{
	Ctext7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext7View 诊断

#ifdef _DEBUG
void Ctext7View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext7Doc* Ctext7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext7Doc)));
	return (Ctext7Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext7View 消息处理程序


void Ctext7View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("谭雪燕");
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);
}
