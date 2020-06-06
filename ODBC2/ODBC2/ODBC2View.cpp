
// ODBC2View.cpp : CODBC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ODBC2.h"
#endif

#include "ODBC2Set.h"
#include "ODBC2Doc.h"
#include "ODBC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBC2View

IMPLEMENT_DYNCREATE(CODBC2View, CRecordView)

BEGIN_MESSAGE_MAP(CODBC2View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT3, &CODBC2View::OnEnChangeEdit3)

	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CODBC2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CODBC2View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CODBC2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CODBC2View::OnRecordLast)
END_MESSAGE_MAP()

// CODBC2View ����/����

CODBC2View::CODBC2View()
	: CRecordView(IDD_ODBC2_FORM)
	, ID(0)
	, name(_T(""))
	, age(0)
	, pictrue(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	
}

CODBC2View::~CODBC2View()
{
}

void CODBC2View::DoDataExchange(CDataExchange* pDX)
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

BOOL CODBC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CODBC2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBC2Set;
	CRecordView::OnInitialUpdate();


	

}


// CODBC2View ���

#ifdef _DEBUG
void CODBC2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBC2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBC2Doc* CODBC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBC2Doc)));
	return (CODBC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CODBC2View ���ݿ�֧��
CRecordset* CODBC2View::OnGetRecordset()
{
	return m_pSet;
}



// CODBC2View ��Ϣ�������


void CODBC2View::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}




void CODBC2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	
	//	m_pSet->GetFieldValue(short(4), s);        //�Ӽ�¼����ǰ��¼����ȡ��4���ֶ�ֵ������s�� 
	GetDlgItemText(IDC_EDIT4, s);              //��ָ��ID�ŵı༭�ؼ��ж�ȡ�ֶε�����s��

	
	GetDlgItem(IDC_STATIC)->GetClientRect(&Picrect);     //��ͼ��ؼ�����Ϣ�ŵ�Picrect��

	CImage img;
	img.Load(s);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();

	/*
	//ʵ��ͼƬ�Ĳ�ʧ���������
	int w, h, sx, sy;
	float rect_ratio = 1.0*Picrect.Width() / Picrect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
	h = Picrect.Height();
	w = img_ratio*h;
	sx = (Picrect.Width() - w) / 2;
	sy = 0;
	}
	else
	{
	w = Picrect.Width();
	h = w / img_ratio;
	sx = 0;
	sy = (Picrect.Height() - h) / 2;
	}
	*/
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, Picrect.top, Picrect.left, Picrect.right, Picrect.bottom);
	//	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

}


void CODBC2View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	//����InvalidateRect(picRect)��ǿ���ػ�
	InvalidateRect(Picrect);
	
}



void CODBC2View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	//����InvalidateRect(picRect)��ǿ���ػ�
	InvalidateRect(Picrect);
}


void CODBC2View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	//����InvalidateRect(picRect)��ǿ���ػ�
	InvalidateRect(Picrect);
}


void CODBC2View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	//����InvalidateRect(picRect)��ǿ���ػ�
	InvalidateRect(Picrect);
}
