
// MFC5View.cpp : CMFC5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC5.h"
#endif

#include "MFC5Doc.h"
#include "MFC5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC5View

IMPLEMENT_DYNCREATE(CMFC5View, CView)

BEGIN_MESSAGE_MAP(CMFC5View, CView)
	ON_COMMAND(ID_HUAYUAN, &CMFC5View::OnHuayuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC5View 构造/析构

CMFC5View::CMFC5View()
{
	// TODO: 在此处添加构造代码
	a = 5;
	set = false;
	red = 0, green = 0, blue = 0;
}

CMFC5View::~CMFC5View()
{
}

BOOL CMFC5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC5View 绘制

void CMFC5View::OnDraw(CDC* pDC)
{
	CMFC5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	SetTimer(a, 1000, NULL);
	if(set)
	{
		int color = RGB(red, green, blue);
		CBrush newBrush(blue);          //创建新画刷
		CBrush *oldBrush = pDC->SelectObject(&newBrush);    //载入新画刷并把旧画刷存入指针
		CRect clientRec;
		GetClientRect(&clientRec);  //获取客户区大小
		m_pt.x = (clientRec.right - clientRec.left) / 2;
		m_pt.y = (clientRec.bottom - clientRec.top) / 2;
		pDC->Ellipse(m_pt.x - a, m_pt.y - a, m_pt.x + a, m_pt.y + a);
		pDC->SelectObject(oldBrush);        //使用新画刷填充后，恢复旧画刷
	}
}


// CMFC5View 诊断

#ifdef _DEBUG
void CMFC5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC5Doc* CMFC5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC5Doc)));
	return (CMFC5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC5View 消息处理程序


void CMFC5View::OnHuayuan()
{
	// TODO: 在此添加命令处理程序代码
	set = true;
	CClientDC dc(this);
	CRect clientRec;
	GetClientRect(&clientRec);  //获取客户区大小
	m_pt.x = (clientRec.right - clientRec.left) / 2;
	m_pt.y = (clientRec.bottom - clientRec.top) / 2;
    dc.Ellipse(m_pt.x - a, m_pt.y - a, m_pt.x + a, m_pt.y + a);
}


void CMFC5View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	a += 5;
	red += 32;
	green += 16;
	blue += 8;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
