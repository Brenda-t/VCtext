
// text2View.cpp : Ctext2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text2.h"
#endif

#include "text2Doc.h"
#include "text2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext2View

IMPLEMENT_DYNCREATE(Ctext2View, CView)

BEGIN_MESSAGE_MAP(Ctext2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Ctext2View ����/����

Ctext2View::Ctext2View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext2View::~Ctext2View()
{
}

BOOL Ctext2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext2View ����

void Ctext2View::OnDraw(CDC* pDC)
{
	Ctext2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
}


// Ctext2View ���

#ifdef _DEBUG
void Ctext2View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext2Doc* Ctext2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext2Doc)));
	return (Ctext2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext2View ��Ϣ�������


void Ctext2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CClientDC ds(this);
	CString s = _T("�����������");
	ds.TextOutW(100, 100, s);
	CView::OnLButtonDown(nFlags, point);
}


void Ctext2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC ds(this);
	CString s = _T("�������̧��");
	ds.TextOutW(500, 500, s);
	CView::OnLButtonUp(nFlags, point);
}
