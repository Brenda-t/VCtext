
// text17.4View.cpp : Ctext174View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text17.4.h"
#endif

#include "text17.4Doc.h"
#include "text17.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext174View

IMPLEMENT_DYNCREATE(Ctext174View, CView)

BEGIN_MESSAGE_MAP(Ctext174View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext174View ����/����

Ctext174View::Ctext174View()
{
	// TODO: �ڴ˴���ӹ������
	mpt.x = 300;
	mpt.y = 300;
	a = rand() % 100 + 10;
	b = rand() % 50 + 5;
}

Ctext174View::~Ctext174View()
{
}

BOOL Ctext174View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext174View ����

void Ctext174View::OnDraw(CDC* pDC)
{
	Ctext174Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
//	CRect re(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
	pDC->Ellipse(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);                             //GetDC()->Ellipse(re);
}


// Ctext174View ���

#ifdef _DEBUG
void Ctext174View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext174View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext174Doc* Ctext174View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext174Doc)));
	return (Ctext174Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext174View ��Ϣ�������


void Ctext174View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//set = true;
	//Invalidate();
	
	CClientDC dc(this);
	CRect re(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
	if (re.PtInRect(point))
	{
	//	mpt=point;
		int color = RGB(0, 255, 0);
		CPen newpen(PS_DASH, 1, color);
		CPen *oldpen = dc.SelectObject(&newpen);
		dc.Rectangle(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
		dc.SelectObject(oldpen);

		dc.Ellipse(re);                             //GetDC()->Ellipse(re);
	}
	

	CView::OnLButtonDown(nFlags, point);
}
