
// text14.2View.cpp : Ctext142View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text14.2.h"
#endif

#include "text14.2Doc.h"
#include "text14.2View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext142View

IMPLEMENT_DYNCREATE(Ctext142View, CView)

BEGIN_MESSAGE_MAP(Ctext142View, CView)
	ON_COMMAND(ID_PopDialog, &Ctext142View::OnPopdialog)
END_MESSAGE_MAP()

// Ctext142View ����/����

Ctext142View::Ctext142View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext142View::~Ctext142View()
{
}

BOOL Ctext142View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext142View ����

void Ctext142View::OnDraw(CDC* /*pDC*/)
{
	Ctext142Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctext142View ���

#ifdef _DEBUG
void Ctext142View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext142View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext142Doc* Ctext142View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext142Doc)));
	return (Ctext142Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext142View ��Ϣ�������


void Ctext142View::OnPopdialog()
{
	// TODO: �ڴ���������������
	MyDialog dlg;
	int t = dlg.DoModal();
}
