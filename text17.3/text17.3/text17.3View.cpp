
// text17.3View.cpp : Ctext173View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text17.3.h"
#endif

#include "text17.3Doc.h"
#include "text17.3View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext173View

IMPLEMENT_DYNCREATE(Ctext173View, CView)

BEGIN_MESSAGE_MAP(Ctext173View, CView)
	ON_COMMAND(ID_PopDialog, &Ctext173View::OnPopdialog)
END_MESSAGE_MAP()

// Ctext173View ����/����

Ctext173View::Ctext173View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext173View::~Ctext173View()
{
}

BOOL Ctext173View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext173View ����

void Ctext173View::OnDraw(CDC* /*pDC*/)
{
	Ctext173Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctext173View ���

#ifdef _DEBUG
void Ctext173View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext173View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext173Doc* Ctext173View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext173Doc)));
	return (Ctext173Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext173View ��Ϣ�������


void Ctext173View::OnPopdialog()
{
	// TODO: �ڴ���������������
	MyDialog dlg;
	int t = dlg.DoModal();

	A = dlg.a;
	B = dlg.b;
	X = dlg.x;
	Y = dlg.y;
	if (t = IDOK)
	{
		CRect re(X - A, Y - B, X + A, Y + B);
		GetDC()->Ellipse(re);
	}

}
