
// UsingLibView.cpp : CUsingLibView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "UsingLib.h"
#endif

#include "UsingLibDoc.h"
#include "UsingLibView.h"
#include "w32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingLibView

IMPLEMENT_DYNCREATE(CUsingLibView, CView)

BEGIN_MESSAGE_MAP(CUsingLibView, CView)
END_MESSAGE_MAP()

// CUsingLibView ����/����

CUsingLibView::CUsingLibView()
{
	// TODO: �ڴ˴���ӹ������

}

CUsingLibView::~CUsingLibView()
{
}

BOOL CUsingLibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CUsingLibView ����

void CUsingLibView::OnDraw(CDC* pDC)
{
	CUsingLibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	s.Format(_T("%d"), factorial(5));
	pDC->TextOutW(200, 100, s);
}


// CUsingLibView ���

#ifdef _DEBUG
void CUsingLibView::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLibDoc* CUsingLibView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLibDoc)));
	return (CUsingLibDoc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLibView ��Ϣ�������
