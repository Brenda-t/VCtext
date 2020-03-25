
// text6View.cpp : Ctext6View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text6.h"
#endif

#include "text6Doc.h"
#include "text6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext6View

IMPLEMENT_DYNCREATE(Ctext6View, CView)

BEGIN_MESSAGE_MAP(Ctext6View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext6View ����/����

Ctext6View::Ctext6View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext6View::~Ctext6View()
{
}

BOOL Ctext6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext6View ����

void Ctext6View::OnDraw(CDC* /*pDC*/)
{
	Ctext6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctext6View ���

#ifdef _DEBUG
void Ctext6View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext6Doc* Ctext6View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext6Doc)));
	return (Ctext6Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext6View ��Ϣ�������


void Ctext6View::OnLButtonDown(UINT nFlags, CPoint point)
{
	Ctext6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	pDoc->count+=1;
	CView::OnLButtonDown(nFlags, point);
}


void Ctext6View::OnRButtonDown(UINT nFlags, CPoint point)
{
	Ctext6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	s.Format(_T("%d"), pDoc->count);
	dc.TextOutW(20, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
