
// text14.1View.cpp : Ctext141View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text14.1.h"
#endif

#include "text14.1Doc.h"
#include "text14.1View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext141View

IMPLEMENT_DYNCREATE(Ctext141View, CView)

BEGIN_MESSAGE_MAP(Ctext141View, CView)
	ON_COMMAND(ID_POPDIALOG, &Ctext141View::OnPopdialog)
END_MESSAGE_MAP()

// Ctext141View ����/����

Ctext141View::Ctext141View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext141View::~Ctext141View()
{
}

BOOL Ctext141View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext141View ����

void Ctext141View::OnDraw(CDC* /*pDC*/)
{
	Ctext141Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctext141View ���

#ifdef _DEBUG
void Ctext141View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext141View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext141Doc* Ctext141View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext141Doc)));
	return (Ctext141Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext141View ��Ϣ�������


void Ctext141View::OnPopdialog()
{
	// TODO: �ڴ���������������
	MyDialog dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		CClientDC dc(this);
		CString s = _T("�����˳��Ի���");
		dc.TextOutW(100, 200, s);
	}
}
