
// JPG02View.cpp : CJPG02View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "JPG02.h"
#endif

#include "JPG02Doc.h"
#include "JPG02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJPG02View

IMPLEMENT_DYNCREATE(CJPG02View, CView)

BEGIN_MESSAGE_MAP(CJPG02View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CJPG02View::OnFileOpen)
END_MESSAGE_MAP()

// CJPG02View ����/����

CJPG02View::CJPG02View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
}

CJPG02View::~CJPG02View()
{
}

BOOL CJPG02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CJPG02View ����

void CJPG02View::OnDraw(CDC* pDC)
{
	CJPG02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set)
	{
		CFileDialog cfd(true);   //�����ı���
		int r = cfd.DoModal();   //�����Ի���
		CClientDC dc(this);
		if (r == IDOK)           //����˳��Ի���ѡ��ΪOK�Ļ�
		{
			CString filename = cfd.GetPathName();
			CImage img;
			img.Load(filename);
			img.Draw(pDC->m_hDC, 100, 100, img.GetWidth(), img.GetHeight());
		}
	}
}


// CJPG02View ���

#ifdef _DEBUG
void CJPG02View::AssertValid() const
{
	CView::AssertValid();
}

void CJPG02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJPG02Doc* CJPG02View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJPG02Doc)));
	return (CJPG02Doc*)m_pDocument;
}
#endif //_DEBUG


// CJPG02View ��Ϣ�������


void CJPG02View::OnFileOpen()
{
	// TODO: �ڴ���������������
	set = true;
	Invalidate();
}
