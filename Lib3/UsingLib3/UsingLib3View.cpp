
// UsingLib3View.cpp : CUsingLib3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "UsingLib3.h"
#endif

#include "UsingLib3Doc.h"
#include "UsingLib3View.h"
#include "Lib3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingLib3View

IMPLEMENT_DYNCREATE(CUsingLib3View, CView)

BEGIN_MESSAGE_MAP(CUsingLib3View, CView)
END_MESSAGE_MAP()

// CUsingLib3View ����/����

CUsingLib3View::CUsingLib3View()
{
	// TODO: �ڴ˴���ӹ������

}

CUsingLib3View::~CUsingLib3View()
{
}

BOOL CUsingLib3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CUsingLib3View ����

void CUsingLib3View::OnDraw(CDC* pDC)
{
	CUsingLib3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	CString s;
	s.Format(_T("%d"), factorial(5));
	pDC->TextOutW(200, 100, s);
}


// CUsingLib3View ���

#ifdef _DEBUG
void CUsingLib3View::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLib3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLib3Doc* CUsingLib3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLib3Doc)));
	return (CUsingLib3Doc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLib3View ��Ϣ�������
