
// text15.1View.cpp : Ctext151View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text15.1.h"
#endif

#include "text15.1Doc.h"
#include "text15.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext151View

IMPLEMENT_DYNCREATE(Ctext151View, CView)

BEGIN_MESSAGE_MAP(Ctext151View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_HUAJUXING, &Ctext151View::OnHuajuxing)
END_MESSAGE_MAP()

// Ctext151View ����/����

Ctext151View::Ctext151View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	m_point.x = 200;
	m_point.y = 300;
	
}

Ctext151View::~Ctext151View()
{
}

BOOL Ctext151View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext151View ����

void Ctext151View::OnDraw(CDC* pDC)
{
	Ctext151Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//�ػ�
	CClientDC dc(this);
	rect.left = m_point.x - 10;
	rect.top = m_point.y - 20;
	rect.right = m_point.x + 15;
	rect.bottom = m_point.y + 30;
	dc.Rectangle(&rect);
}


// Ctext151View ���

#ifdef _DEBUG
void Ctext151View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext151View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext151Doc* Ctext151View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext151Doc)));
	return (Ctext151Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext151View ��Ϣ�������


void Ctext151View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void Ctext151View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void Ctext151View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set)
	{
	//	if (rect.PtInRect(point))      //�ж������λ���Ƿ��ھ�����
		//{
			m_point = point;
			Invalidate();
		//}
	}
	CView::OnMouseMove(nFlags, point);
}


void Ctext151View::OnHuajuxing()
{
	// TODO: �ڴ���������������
	CClientDC dc(this);
	rect.left = m_point.x - 10;
	rect.top = m_point.y - 20;
	rect.right = m_point.x+ 15;
	rect.bottom = m_point.y + 30;
	dc.Rectangle(&rect);
}
