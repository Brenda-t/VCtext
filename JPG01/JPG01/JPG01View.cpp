
// JPG01View.cpp : CJPG01View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "JPG01.h"
#endif

#include "JPG01Doc.h"
#include "JPG01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJPG01View

IMPLEMENT_DYNCREATE(CJPG01View, CView)

BEGIN_MESSAGE_MAP(CJPG01View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CJPG01View::OnFileOpen)
END_MESSAGE_MAP()

// CJPG01View ����/����

CJPG01View::CJPG01View()
{
	// TODO: �ڴ˴���ӹ������

}

CJPG01View::~CJPG01View()
{
}

BOOL CJPG01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CJPG01View ����

void CJPG01View::OnDraw(CDC* /*pDC*/)
{
	CJPG01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CJPG01View ���

#ifdef _DEBUG
void CJPG01View::AssertValid() const
{
	CView::AssertValid();
}

void CJPG01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJPG01Doc* CJPG01View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJPG01Doc)));
	return (CJPG01Doc*)m_pDocument;
}
#endif //_DEBUG


// CJPG01View ��Ϣ�������


void CJPG01View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);   //�����ı���
	int r = cfd.DoModal();   //�����Ի���
	CClientDC dc(this);
	if (r == IDOK)           //����˳��Ի���ѡ��ΪOK�Ļ�
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
	}
}
