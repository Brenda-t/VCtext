
// text16View.cpp : Ctext16View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "text16.h"
#endif

#include "text16Doc.h"
#include "text16View.h"
#include "MyDlg.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext16View

IMPLEMENT_DYNCREATE(Ctext16View, CView)

BEGIN_MESSAGE_MAP(Ctext16View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_PopDialog, &Ctext16View::OnPopdialog)
END_MESSAGE_MAP()

// Ctext16View ����/����

Ctext16View::Ctext16View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctext16View::~Ctext16View()
{
}

BOOL Ctext16View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext16View ����

void Ctext16View::OnDraw(CDC* /*pDC*/)
{
	Ctext16Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctext16View ���

#ifdef _DEBUG
void Ctext16View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext16View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext16Doc* Ctext16View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext16Doc)));
	return (Ctext16Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext16View ��Ϣ�������


void Ctext16View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDblClk(nFlags, point);

	Ctext16Doc *pDoc = ((Ctext16View *)((CFrameWnd *)AfxGetMainWnd())->GetActiveView())->GetDocument();
	CFileDialog cfd(true);
	int r = cfd.DoModal();
    pDoc->filename = cfd.GetPathName();    //��ȡѡ�е��ļ���
	
	CClientDC dc(this);
	dc.TextOutW(100, 200, pDoc->filename);
}


void Ctext16View::OnPopdialog()
{
	// TODO: �ڴ���������������
	
	MyDlg dlg;
	int t = dlg.DoModal();
	
}
