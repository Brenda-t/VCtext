
// text13.1View.cpp : Ctext131View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text13.1.h"
#endif

#include "text13.1Doc.h"
#include "text13.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext131View

IMPLEMENT_DYNCREATE(Ctext131View, CView)

BEGIN_MESSAGE_MAP(Ctext131View, CView)
	ON_WM_CHAR()
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext131View ����/����

Ctext131View::Ctext131View()
{
	// TODO: �ڴ˴���ӹ������
	A.left = 0;  A.top = 0;
	A.right = 400; A.bottom = 50;
	set = false;
}

Ctext131View::~Ctext131View()
{
}

BOOL Ctext131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext131View ����

void Ctext131View::OnDraw(CDC* pDC)
{
	Ctext131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(A);
}


// Ctext131View ���

#ifdef _DEBUG
void Ctext131View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext131Doc* Ctext131View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext131Doc)));
	return (Ctext131Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext131View ��Ϣ�������


void Ctext131View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	m_strLine=m_strLine+ (char)nChar;  //������������ַ�����ӵ��ַ���������
	dc.TextOut(5,5,m_strLine);
	
	if (set)
	{
		n_strLine = n_strLine + (char)nChar;
		CPoint point;
		CSize m_size = dc.GetTextExtent(m_strLine);
		point.x = m_pt.x + m_size.cx;
		point.y = m_pt.y;
		SetCaretPos(point);
		dc.TextOutW(m_pt.x, m_pt.y, m_strLine);
	}
		
	CView::OnChar(nChar, nRepCnt, nFlags);
}



