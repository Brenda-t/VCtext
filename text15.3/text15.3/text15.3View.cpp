
// text15.3View.cpp : Ctext153View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text15.3.h"
#endif

#include "text15.3Doc.h"
#include "text15.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext153View

IMPLEMENT_DYNCREATE(Ctext153View, CView)

BEGIN_MESSAGE_MAP(Ctext153View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Ctext153View ����/����

Ctext153View::Ctext153View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	a = true;
//	CRect r;   //�������
//	GetClientRect(&r);  //ȡ�ÿͻ�����С
//	mpt.x = (r.bottom - r.top) / 2;      //��ȡ�����м���ߵ�λ�ã�mpt��λ�����ɻ��ǣ�0��0����û�и�ֵ�ɹ�����������ʱ�����߼�����
//	mpt.y = (r.right - r.left) / 4;
	
	mpt.x = 300;
	mpt.y = 300;
	rect.left = mpt.x - 30;      //��Ϊ����С����ƶ��������ƶ������Ի�Բ������ʱ��Ҫ�й������������һ�Բ��
	rect.right = mpt.x + 30;
	rect.top = mpt.y - 30;
	rect.bottom = mpt.y + 30;
}

Ctext153View::~Ctext153View()
{
}

BOOL Ctext153View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext153View ����

void Ctext153View::OnDraw(CDC* pDC)
{
	Ctext153Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

//	CRect rect(mpt.x - 30, mpt.y - 30, mpt.x + 30, mpt.y + 30);
	pDC->Ellipse(rect);
	SetTimer(1, rand() % 400 + 100, NULL);        //ΪС�����ö�ʱ��
}


// Ctext153View ���

#ifdef _DEBUG
void Ctext153View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext153View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext153Doc* Ctext153View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext153Doc)));
	return (Ctext153Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext153View ��Ϣ�������


void Ctext153View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	set = true;
	a = true;
	CView::OnLButtonDown(nFlags, point);
}


void Ctext153View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	CView::OnLButtonDblClk(nFlags, point);
}


void Ctext153View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnTimer(nIDEvent);
	int i = nIDEvent;
	CRect r;   //�������
	GetClientRect(&r);  //ȡ�ÿͻ�����С
	if (a)
	{
		if (set)
		{
			rect.left += 30;
			rect.right += 30;
			if (rect.right > r.right)
				a = false;
		}
	}
	else
	{
		rect.left -= 30;
		rect.right -= 30;
	}
	Invalidate();   //ǿ���ػ棬ʹԲ����
}
