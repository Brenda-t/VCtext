
// text17.2View.cpp : Ctext172View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text17.2.h"
#endif

#include "text17.2Doc.h"
#include "text17.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext172View

IMPLEMENT_DYNCREATE(Ctext172View, CView)

BEGIN_MESSAGE_MAP(Ctext172View, CView)
//	ON_WM_MBUTTONDOWN()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
//ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Ctext172View ����/����

Ctext172View::Ctext172View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
}

Ctext172View::~Ctext172View()
{
}

BOOL Ctext172View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext172View ����

void Ctext172View::OnDraw(CDC* pDC)
{
	Ctext172Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(mpt1.x, mpt1.y, mpt2.x, mpt2.y);
}


// Ctext172View ���

#ifdef _DEBUG
void Ctext172View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext172View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext172Doc* Ctext172View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext172Doc)));
	return (Ctext172Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext172View ��Ϣ�������


void Ctext172View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//���������£���ʼ����Բ������¼����ʱ��λ��
	mpt1.x = point.x;
	mpt1.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void Ctext172View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	mpt2.x = point.x;             //��¼���̧��ʱ��λ�ã���λ��Ϊ����Բ�����½�
	mpt2.y = point.y;
	Invalidate();             //̧��ʱ�ػ棬ʹǰһ����������Բ��ʧ

	CView::OnLButtonUp(nFlags, point);
}

