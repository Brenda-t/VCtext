
// text15.4View.cpp : Ctext154View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text15.4.h"
#endif

#include "text15.4Doc.h"
#include "text15.4View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext154View

IMPLEMENT_DYNCREATE(Ctext154View, CView)

BEGIN_MESSAGE_MAP(Ctext154View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Ctext154View ����/����

Ctext154View::Ctext154View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext154View::~Ctext154View()
{
}

BOOL Ctext154View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext154View ����

void Ctext154View::OnDraw(CDC* /*pDC*/)
{
	Ctext154Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctext154View ���

#ifdef _DEBUG
void Ctext154View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext154View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext154Doc* Ctext154View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext154Doc)));
	return (Ctext154Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext154View ��Ϣ�������


void Ctext154View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	MyDialog dlg;
	int r = dlg.DoModal();
	CView::OnLButtonDblClk(nFlags, point);
}
