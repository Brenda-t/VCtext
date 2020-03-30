
// text11View.cpp : Ctext11View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text11.h"
#endif

#include "text11Doc.h"
#include "text11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext11View

IMPLEMENT_DYNCREATE(Ctext11View, CView)

BEGIN_MESSAGE_MAP(Ctext11View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext11View ����/����

Ctext11View::Ctext11View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext11View::~Ctext11View()
{
}

BOOL Ctext11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext11View ����

void Ctext11View::OnDraw(CDC* pDC)
{
	Ctext11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);

}


// Ctext11View ���

#ifdef _DEBUG
void Ctext11View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext11Doc* Ctext11View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext11Doc)));
	return (Ctext11Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext11View ��Ϣ�������


void Ctext11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Ctext11Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s, ss, cs;
	pDoc->m_pt = point;
	s.Format(_T("%d"), pDoc->a);             //
	ss.Format(_T("%d"), pDoc->b);
	cs = _T("�����Ч");
	if (pDoc->A.left < point.x &&point.x< pDoc->A.right  && pDoc->A.top< point.y &&point.y<pDoc->A.bottom)
		dc.TextOutW(point.x, point.y, s);
	else if (pDoc->B.left < point.x &&point.x< pDoc->B.right &&pDoc->B.top< point.y &&point.y< pDoc->B.bottom)
		dc.TextOutW(point.x, point.y, ss);
	else
		dc.TextOutW(point.x, point.y, cs);
	CView::OnLButtonDown(nFlags, point);
}


void Ctext11View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Ctext11Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s;
	s.Format(_T("%d"), pDoc->a + pDoc->b);
	if (pDoc->C.left < point.x &&point.x< pDoc->C.right  && pDoc->C.top < point.y &&point.y<pDoc->C.bottom)
		dc.TextOutW(point.x, point.y, s);
	CView::OnRButtonDown(nFlags, point);
}
