
// UsingLib4View.cpp : CUsingLib4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "UsingLib4.h"
#endif

#include "UsingLib4Doc.h"
#include "UsingLib4View.h"
#include "Lib4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingLib4View

IMPLEMENT_DYNCREATE(CUsingLib4View, CView)

BEGIN_MESSAGE_MAP(CUsingLib4View, CView)
END_MESSAGE_MAP()

// CUsingLib4View ����/����

CUsingLib4View::CUsingLib4View()
{
	// TODO: �ڴ˴���ӹ������

}

CUsingLib4View::~CUsingLib4View()
{
}

BOOL CUsingLib4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CUsingLib4View ����

void CUsingLib4View::OnDraw(CDC* pDC)
{
	CUsingLib4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	FAC fac;
	s.Format(_T("%0.2f"), fac.convert(30.0));       //�������ط��������еĳ�Ա�����������ȴ�������������������øó�Ա����
	pDC->TextOutW(200, 100, s);
}


// CUsingLib4View ���

#ifdef _DEBUG
void CUsingLib4View::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLib4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLib4Doc* CUsingLib4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLib4Doc)));
	return (CUsingLib4Doc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLib4View ��Ϣ�������
