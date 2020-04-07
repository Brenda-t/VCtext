
// text13.1View.cpp : Ctext131View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text13.1.h"
#endif

#include "text13.1Doc.h"
#include "text13.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext131View

IMPLEMENT_DYNCREATE(Ctext131View, CView)

BEGIN_MESSAGE_MAP(Ctext131View, CView)
	ON_WM_CHAR()
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext131View 构造/析构

Ctext131View::Ctext131View()
{
	// TODO: 在此处添加构造代码
	A.left = 0;  A.top = 0;
	A.right = 400; A.bottom = 50;
	set = false;
}

Ctext131View::~Ctext131View()
{
}

BOOL Ctext131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext131View 绘制

void Ctext131View::OnDraw(CDC* pDC)
{
	Ctext131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(A);
}


// Ctext131View 诊断

#ifdef _DEBUG
void Ctext131View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext131Doc* Ctext131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext131Doc)));
	return (Ctext131Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext131View 消息处理程序


void Ctext131View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	m_strLine=m_strLine+ (char)nChar;  //将后面输入的字符串添加到字符串对象中
	dc.TextOut(5,5,m_strLine);
	
	if (set)
	{
		n_strLine = n_strLine + (char)nChar;
		CPoint point;
		CSize m_size = dc.GetTextExtent(m_strLine);
		point.x = m_pt.x + m_size.cx;
		point.y = m_pt.y;
		SetCaretPos(point);
		dc.TextOutW(m_pt.x, m_pt.y, m_strLine);
	}
		
	CView::OnChar(nChar, nRepCnt, nFlags);
}



