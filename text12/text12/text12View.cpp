
// text12View.cpp : Ctext12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text12.h"
#endif

#include "text12Doc.h"
#include "text12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext12View

IMPLEMENT_DYNCREATE(Ctext12View, CView)

BEGIN_MESSAGE_MAP(Ctext12View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext12View ����/����

Ctext12View::Ctext12View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext12View::~Ctext12View()
{
}

BOOL Ctext12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext12View ����

void Ctext12View::OnDraw(CDC* pDC)
{
	Ctext12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);
	pDC->Rectangle(pDoc->D);
}


// Ctext12View ���

#ifdef _DEBUG
void Ctext12View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext12Doc* Ctext12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext12Doc)));
	return (Ctext12Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext12View ��Ϣ�������


void Ctext12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Ctext12Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s, ss, cs;
	pDoc->m_pt = point;
	s.Format(_T("%d"), pDoc->a);             
	ss.Format(_T("%d"), pDoc->b);
	cs = _T("�����Ч");
	
	if (pDoc->A.left < point.x &&point.x< pDoc->A.right  && pDoc->A.top< point.y &&point.y<pDoc->A.bottom)
		dc.TextOutW(point.x, point.y, s);
	else if (pDoc->B.left < point.x &&point.x< pDoc->B.right &&pDoc->B.top< point.y &&point.y< pDoc->B.bottom)
		dc.TextOutW(point.x, point.y, ss);
	else if (pDoc->D.left < point.x&&point.x < pDoc->D.right&&pDoc->D.top < point.y&&point.y < pDoc->D.bottom)
	{
		pDoc->count1 += 1;
		switch (pDoc->count1)
		{
		case 1:
			dc.TextOutW(point.x, point.y, pDoc->m);
			break;
		case 2:
			dc.TextOutW(point.x, point.y, pDoc->n);
			break;
		case 3:
			dc.TextOutW(point.x, point.y, pDoc->p);
			break;
		case 4:
			dc.TextOutW(point.x, point.y, pDoc->q);
			break;

			break;
		}
	}
	else
		dc.TextOutW(point.x, point.y, cs);
	CView::OnLButtonDown(nFlags, point);
}


void Ctext12View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Ctext12Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->count2 += 1;
	CString s, s1, s2, s3, s4;
	s1.Format(_T("%d"), pDoc->a + pDoc->b);
	s2.Format(_T("%d"), pDoc->a - pDoc->b);
	s3.Format(_T("%d"), pDoc->a * pDoc->b);
	s4.Format(_T("%d"), pDoc->a / pDoc->b);
	if (pDoc->C.left < point.x &&point.x < pDoc->C.right  && pDoc->C.top < point.y &&point.y < pDoc->C.bottom)
	{
		switch (pDoc->count2)
		{
		case 1:
			dc.TextOutW(point.x, point.y, s1);
			break;
		case 2:
			dc.TextOutW(point.x, point.y, s2);
			break;
		case 3:
			dc.TextOutW(point.x, point.y, s3);
			break;
		case 4:
			dc.TextOutW(point.x, point.y, s4);
			break;

			break;
		}
	}

	CView::OnRButtonDown(nFlags, point);
}
