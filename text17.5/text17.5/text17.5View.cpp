
// text17.5View.cpp : Ctext175View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text17.5.h"
#endif

#include "text17.5Doc.h"
#include "text17.5View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext175View

IMPLEMENT_DYNCREATE(Ctext175View, CView)

BEGIN_MESSAGE_MAP(Ctext175View, CView)
	ON_COMMAND(ID_PopDialog, &Ctext175View::OnPopdialog)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext175View 构造/析构

Ctext175View::Ctext175View()
{
	// TODO: 在此处添加构造代码
	mpt.x = 300;
	mpt.y = 200;
	a = rand() % 100 + 10;
	b = rand() % 50 + 5;
}

Ctext175View::~Ctext175View()
{
}

BOOL Ctext175View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext175View 绘制

void Ctext175View::OnDraw(CDC* pDC)
{
	Ctext175Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
}


// Ctext175View 诊断

#ifdef _DEBUG
void Ctext175View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext175View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext175Doc* Ctext175View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext175Doc)));
	return (Ctext175Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext175View 消息处理程序


void Ctext175View::OnPopdialog()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{   
	//	this->UpdateData(true);       //退出后，填充选中的椭圆内部
		CClientDC dc(this);
		int color = RGB(dlg.x,dlg.y,dlg.z);
		CBrush newBrush(color);        //创建新画刷
		CBrush *oldBrush = dc.SelectObject(&newBrush);        //载入新画刷，把旧画刷存入指针
		dc.Ellipse(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
		dc.SelectObject(oldBrush);             //使用新画刷绘制后，恢复旧画刷
	}
}


void Ctext175View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect re(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
	if (re.PtInRect(point))
	{
		//	mpt=point;
		int color = RGB(0, 255, 0);
		CPen newpen(PS_DASH, 1, color);       //PS_DASH表示样式为虚线,构建新画笔
		CPen *oldpen = dc.SelectObject(&newpen);        //载入新画笔，把旧画笔存入指针
		dc.Rectangle(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
		dc.SelectObject(oldpen);             //使用新画笔绘制后，恢复旧画笔

		dc.Ellipse(re);                             //GetDC()->Ellipse(re);
	}
	CView::OnLButtonDown(nFlags, point);
}
