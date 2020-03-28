
// MFC5View.cpp : CMFC5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC5.h"
#endif

#include "MFC5Doc.h"
#include "MFC5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC5View

IMPLEMENT_DYNCREATE(CMFC5View, CView)

BEGIN_MESSAGE_MAP(CMFC5View, CView)
	ON_COMMAND(ID_HUAYUAN, &CMFC5View::OnHuayuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC5View ����/����

CMFC5View::CMFC5View()
{
	// TODO: �ڴ˴���ӹ������
	a = 5;
	set = false;
	red = 0, green = 0, blue = 0;
}

CMFC5View::~CMFC5View()
{
}

BOOL CMFC5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC5View ����

void CMFC5View::OnDraw(CDC* pDC)
{
	CMFC5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	SetTimer(a, 1000, NULL);
	if(set)
	{
		int color = RGB(red, green, blue);
		CBrush newBrush(blue);          //�����»�ˢ
		CBrush *oldBrush = pDC->SelectObject(&newBrush);    //�����»�ˢ���Ѿɻ�ˢ����ָ��
		CRect clientRec;
		GetClientRect(&clientRec);  //��ȡ�ͻ�����С
		m_pt.x = (clientRec.right - clientRec.left) / 2;
		m_pt.y = (clientRec.bottom - clientRec.top) / 2;
		pDC->Ellipse(m_pt.x - a, m_pt.y - a, m_pt.x + a, m_pt.y + a);
		pDC->SelectObject(oldBrush);        //ʹ���»�ˢ���󣬻ָ��ɻ�ˢ
	}
}


// CMFC5View ���

#ifdef _DEBUG
void CMFC5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC5Doc* CMFC5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC5Doc)));
	return (CMFC5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC5View ��Ϣ�������


void CMFC5View::OnHuayuan()
{
	// TODO: �ڴ���������������
	set = true;
	CClientDC dc(this);
	CRect clientRec;
	GetClientRect(&clientRec);  //��ȡ�ͻ�����С
	m_pt.x = (clientRec.right - clientRec.left) / 2;
	m_pt.y = (clientRec.bottom - clientRec.top) / 2;
    dc.Ellipse(m_pt.x - a, m_pt.y - a, m_pt.x + a, m_pt.y + a);
}


void CMFC5View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	a += 5;
	red += 32;
	green += 16;
	blue += 8;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
