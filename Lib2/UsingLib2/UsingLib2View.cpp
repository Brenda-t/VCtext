
// UsingLib2View.cpp : CUsingLib2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "UsingLib2.h"
#endif

#include "UsingLib2Doc.h"
#include "UsingLib2View.h"
#include "w33.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingLib2View

IMPLEMENT_DYNCREATE(CUsingLib2View, CView)

BEGIN_MESSAGE_MAP(CUsingLib2View, CView)
END_MESSAGE_MAP()

// CUsingLib2View ����/����

CUsingLib2View::CUsingLib2View()
{
	// TODO: �ڴ˴���ӹ������

}

CUsingLib2View::~CUsingLib2View()
{
}

BOOL CUsingLib2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CUsingLib2View ����

void CUsingLib2View::OnDraw(CDC* pDC)
{
	CUsingLib2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	FAC fac;
	s.Format(_T("%0.2f"), fac.convert(30.0));
	pDC->TextOutW(200, 100, s);
}


// CUsingLib2View ���

#ifdef _DEBUG
void CUsingLib2View::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLib2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLib2Doc* CUsingLib2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLib2Doc)));
	return (CUsingLib2Doc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLib2View ��Ϣ�������
