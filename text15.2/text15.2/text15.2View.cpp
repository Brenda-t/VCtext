
// text15.2View.cpp : Ctext152View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text15.2.h"
#endif

#include "text15.2Doc.h"
#include "text15.2View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext152View

IMPLEMENT_DYNCREATE(Ctext152View, CView)

BEGIN_MESSAGE_MAP(Ctext152View, CView)
	ON_COMMAND(ID_PopDialog, &Ctext152View::OnPopdialog)
END_MESSAGE_MAP()

// Ctext152View ����/����

Ctext152View::Ctext152View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext152View::~Ctext152View()
{
}

BOOL Ctext152View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext152View ����

void Ctext152View::OnDraw(CDC* /*pDC*/)
{
	Ctext152Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctext152View ���

#ifdef _DEBUG
void Ctext152View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext152View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext152Doc* Ctext152View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext152Doc)));
	return (Ctext152Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext152View ��Ϣ�������


void Ctext152View::OnPopdialog()
{
	// TODO: �ڴ���������������
	MyDialog dlg;
	int t = dlg.DoModal();
}
