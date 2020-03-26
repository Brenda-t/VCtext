
// text9View.cpp : Ctext9View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text9.h"
#endif

#include "text9Doc.h"
#include "text9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext9View

IMPLEMENT_DYNCREATE(Ctext9View, CView)

BEGIN_MESSAGE_MAP(Ctext9View, CView)
	ON_COMMAND(ID_xian, &Ctext9View::Onxian)
	ON_COMMAND(ID_juxing, &Ctext9View::Onjuxing)
	ON_COMMAND(ID_tuoyuan, &Ctext9View::Ontuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Ctext9View ����/����

Ctext9View::Ctext9View()
{
	// TODO: �ڴ˴���ӹ������
	m_pt= 0;
	m_nd = 0;
}

Ctext9View::~Ctext9View()
{
}

BOOL Ctext9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext9View ����

void Ctext9View::OnDraw(CDC* pDC)
{
	Ctext9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
}


// Ctext9View ���

#ifdef _DEBUG
void Ctext9View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext9Doc* Ctext9View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext9Doc)));
	return (Ctext9Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext9View ��Ϣ�������


void Ctext9View::Onxian()
{
	// TODO: �ڴ���������������
	m_nd = 1;
}


void Ctext9View::Onjuxing()
{
	// TODO: �ڴ���������������
	m_nd = 2;
}


void Ctext9View::Ontuoyuan()
{
	// TODO: �ڴ���������������
	m_nd = 3;
	
}


void Ctext9View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_pt= point;

	CView::OnLButtonDown(nFlags, point);
}


void Ctext9View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	switch (m_nd)
	{
	case 1:
		dc.MoveTo(m_pt);
		dc.LineTo(point);
		break;
	case 2:
		dc.Rectangle(CRect(m_pt, point));
		break;
	case 3:
		dc.Ellipse(CRect(m_pt, point));
		break;

		break;
	}
}


void Ctext9View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
}
