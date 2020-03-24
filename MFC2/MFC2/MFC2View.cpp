
// MFC2View.cpp : CMFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC2.h"
#endif

#include "MFC2Doc.h"
#include "MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2View

IMPLEMENT_DYNCREATE(CMFC2View, CView)

BEGIN_MESSAGE_MAP(CMFC2View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC2View ����/����

CMFC2View::CMFC2View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC2View::~CMFC2View()
{
}

BOOL CMFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC2View ����

void CMFC2View::OnDraw(CDC* pDC)
{
	CMFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_crlRect);
}


// CMFC2View ���

#ifdef _DEBUG
void CMFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2Doc* CMFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2Doc)));
	return (CMFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2View ��Ϣ�������


void CMFC2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CMFC2Doc*pDoc = GetDocument();
	CRect clientRec;   //�������
	GetClientRect(&clientRec);  //ȡ�ÿͻ�����С
	switch (nChar)
	{
	case VK_LEFT:     //����������������
		if (pDoc->m_crlRect.left > 0)
		{
			pDoc->m_crlRect.left -= 5;
			pDoc->m_crlRect.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->m_crlRect.right <= (clientRec.right - clientRec.left))
		{
			pDoc->m_crlRect.left += 5;
			pDoc->m_crlRect.right += 5;
		}
		break;
	case VK_UP:
		if (pDoc->m_crlRect.top > 0)
		{
			pDoc->m_crlRect.top -= 5;
			pDoc->m_crlRect.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_crlRect.bottom <= (clientRec.bottom - clientRec.top))
		{
			pDoc->m_crlRect.top += 5;
			pDoc->m_crlRect.bottom += 5;
		}
		break;
	case VK_HOME:
		pDoc->m_crlRect.right += 8;
		pDoc->m_crlRect.bottom += 8;
		break;
	case VK_END:
		pDoc->m_crlRect.left += 8;
		pDoc->m_crlRect.top += 8;
		break;
	}
	InvalidateRect(NULL,TRUE);
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC2Doc*pDoc = GetDocument();
	pDoc->m_crlRect.left = 30;
	pDoc->m_crlRect.right = 80;
	pDoc->m_crlRect.top = 30;
	pDoc->m_crlRect.bottom = 80;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
