
// MFC4View.cpp : CMFC4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC4.h"
#endif

#include "MFC4Doc.h"
#include "MFC4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4View

IMPLEMENT_DYNCREATE(CMFC4View, CView)

BEGIN_MESSAGE_MAP(CMFC4View, CView)
//	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_HUAYUAN, &CMFC4View::OnHuayuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC4View ����/����

CMFC4View::CMFC4View()
{
	// TODO: �ڴ˴���ӹ������
	a = 10;
	set = false;
	CRect rect;
	
}

CMFC4View::~CMFC4View()
{
}

BOOL CMFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC4View ����

void CMFC4View::OnDraw(CDC* pDC)
{
	CMFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	SetTimer(a, 1500, NULL);
	if (set)
	{
		CClientDC dc(this);
		CRect clientRec;   //�������
		GetClientRect(&clientRec);  //ȡ�ÿͻ�����С
		m_pt.x = (clientRec.right - clientRec.left) / 2;
		m_pt.y = (clientRec.bottom - clientRec.top) / 2;
		
		pDC->Ellipse(m_pt.x - a, m_pt.y + a, m_pt.x + a, m_pt.y - a);
	}

}


// CMFC4View ���

#ifdef _DEBUG
void CMFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4Doc* CMFC4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4Doc)));
	return (CMFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4View ��Ϣ�������


void CMFC4View::OnHuayuan()
{
	// TODO: �ڴ���������������
	set = true;
	CClientDC dc(this);
	CRect clientRec;   //�������
	GetClientRect(&clientRec);  //ȡ�ÿͻ�����С
	m_pt.x = (clientRec.right - clientRec.left) / 2;
	m_pt.y = (clientRec.bottom - clientRec.top) / 2;
	dc.Ellipse(m_pt.x - a, m_pt.y + a, m_pt.x + a, m_pt.y - a);
}


void CMFC4View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	a += 2;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
