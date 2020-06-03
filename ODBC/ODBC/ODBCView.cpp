
// ODBCView.cpp : CODBCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ODBC.h"
#endif

#include "ODBCSet.h"
#include "ODBCDoc.h"
#include "ODBCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBCView

IMPLEMENT_DYNCREATE(CODBCView, CRecordView)

BEGIN_MESSAGE_MAP(CODBCView, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CODBCView::OnBnClickedButton1)
//	ON_WM_PAINT()
END_MESSAGE_MAP()

// CODBCView ����/����

CODBCView::CODBCView()
	: CRecordView(IDD_ODBC_FORM)
	, ID(0)
	, name(_T(""))
	, age(0)
	, pictrue(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CODBCView::~CODBCView()
{
}

void CODBCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);

	
}

BOOL CODBCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CODBCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBCSet;
	CRecordView::OnInitialUpdate();

}


// CODBCView ���

#ifdef _DEBUG
void CODBCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBCDoc* CODBCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBCDoc)));
	return (CODBCDoc*)m_pDocument;
}
#endif //_DEBUG


// CODBCView ���ݿ�֧��
CRecordset* CODBCView::OnGetRecordset()
{
	return m_pSet;
}



// CODBCView ��Ϣ�������


void CODBCView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString s;
//	m_pSet->GetFieldValue(4, s);        //�Ӽ�¼����ǰ��¼����ȡ��2���ֶ�ֵ������s�� 
	GetDlgItemText(IDC_EDIT4, s);              //��ָ��ID�ŵı༭�ؼ��ж�ȡ�ֶε�����s��
	
	CImage img;
	img.Load(s);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();

	this->UpdateData(true);
	CString ss;
	ss = _T("123");
	pictrue = ss;
	UpdateData(false);
	

	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	
	/*
	//ʵ��ͼƬ�Ĳ�ʧ���������
	int w, h, sx, sy;
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	*/
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC,rect.top,rect.left, rect.right,rect.bottom);
//	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

	
}

