
// text8View.cpp : Ctext8View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text8.h"
#endif

#include "text8Doc.h"
#include "text8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext8View

IMPLEMENT_DYNCREATE(Ctext8View, CView)

BEGIN_MESSAGE_MAP(Ctext8View, CView)
END_MESSAGE_MAP()

// Ctext8View 构造/析构

Ctext8View::Ctext8View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

Ctext8View::~Ctext8View()
{
}

BOOL Ctext8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext8View 绘制

void Ctext8View::OnDraw(CDC* pDC)
{
	Ctext8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
}


// Ctext8View 诊断

#ifdef _DEBUG
void Ctext8View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext8Doc* Ctext8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext8Doc)));
	return (Ctext8Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext8View 消息处理程序
