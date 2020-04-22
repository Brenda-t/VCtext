
// text17.5View.cpp : Ctext175View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text17.5.h"
#endif

#include "text17.5Doc.h"
#include "text17.5View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext175View

IMPLEMENT_DYNCREATE(Ctext175View, CView)

BEGIN_MESSAGE_MAP(Ctext175View, CView)
	ON_COMMAND(ID_PopDialog, &Ctext175View::OnPopdialog)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext175View ����/����

Ctext175View::Ctext175View()
{
	// TODO: �ڴ˴���ӹ������
	mpt.x = 300;
	mpt.y = 200;
	a = rand() % 100 + 10;
	b = rand() % 50 + 5;
}

Ctext175View::~Ctext175View()
{
}

BOOL Ctext175View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext175View ����

void Ctext175View::OnDraw(CDC* pDC)
{
	Ctext175Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
}


// Ctext175View ���

#ifdef _DEBUG
void Ctext175View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext175View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext175Doc* Ctext175View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext175Doc)));
	return (Ctext175Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext175View ��Ϣ�������


void Ctext175View::OnPopdialog()
{
	// TODO: �ڴ���������������
	MyDialog dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{   
	//	this->UpdateData(true);       //�˳������ѡ�е���Բ�ڲ�
		CClientDC dc(this);
		int color = RGB(dlg.x,dlg.y,dlg.z);
		CBrush newBrush(color);        //�����»�ˢ
		CBrush *oldBrush = dc.SelectObject(&newBrush);        //�����»�ˢ���Ѿɻ�ˢ����ָ��
		dc.Ellipse(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
		dc.SelectObject(oldBrush);             //ʹ���»�ˢ���ƺ󣬻ָ��ɻ�ˢ
	}
}


void Ctext175View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CRect re(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
	if (re.PtInRect(point))
	{
		//	mpt=point;
		int color = RGB(0, 255, 0);
		CPen newpen(PS_DASH, 1, color);       //PS_DASH��ʾ��ʽΪ����,�����»���
		CPen *oldpen = dc.SelectObject(&newpen);        //�����»��ʣ��Ѿɻ��ʴ���ָ��
		dc.Rectangle(mpt.x - a, mpt.y - b, mpt.x + a, mpt.y + b);
		dc.SelectObject(oldpen);             //ʹ���»��ʻ��ƺ󣬻ָ��ɻ���

		dc.Ellipse(re);                             //GetDC()->Ellipse(re);
	}
	CView::OnLButtonDown(nFlags, point);
}
