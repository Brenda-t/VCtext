
// ODBC3View.cpp : CODBC3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ODBC3.h"
#endif

#include "ODBC3Set.h"
#include "ODBC3Doc.h"
#include "ODBC3View.h"
#include "mydialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBC3View

IMPLEMENT_DYNCREATE(CODBC3View, CRecordView)

BEGIN_MESSAGE_MAP(CODBC3View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CODBC3View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CODBC3View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CODBC3View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CODBC3View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CODBC3View::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CODBC3View ����/����

CODBC3View::CODBC3View()
	: CRecordView(IDD_ODBC3_FORM)
	, pictrue(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("E:\\pictrue\\");
}

CODBC3View::~CODBC3View()
{
}

void CODBC3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CODBC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CODBC3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBC3Set;
	CRecordView::OnInitialUpdate();

}


// CODBC3View ���

#ifdef _DEBUG
void CODBC3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBC3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBC3Doc* CODBC3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBC3Doc)));
	return (CODBC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CODBC3View ���ݿ�֧��
CRecordset* CODBC3View::OnGetRecordset()
{
	return m_pSet;
}



// CODBC3View ��Ϣ�������


void CODBC3View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	//����InvalidateRect(picRect)��ǿ���ػ�
	//InvalidateRect(picrect);
	GetDlgItemText(IDC_EDIT1, s);             //��ȡ�༭�ؼ��е��ļ���������s��
	filepath = path + s;
	draw_pic(filepath);
}


void CODBC3View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	//����InvalidateRect(picRect)��ǿ���ػ�
	//InvalidateRect(picrect);
	GetDlgItemText(IDC_EDIT1, s);             //��ȡ�༭�ؼ��е��ļ���������s��
	filepath = path + s;
	draw_pic(filepath);
}


void CODBC3View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	//����InvalidateRect(picRect)��ǿ���ػ�
	//InvalidateRect(picrect);
	GetDlgItemText(IDC_EDIT1, s);             //��ȡ�༭�ؼ��е��ļ���������s��
	filepath = path + s;
	draw_pic(filepath);
}


void CODBC3View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	//����InvalidateRect(picRect)��ǿ���ػ�
	//InvalidateRect(picrect);
	GetDlgItemText(IDC_EDIT1, s);             //��ȡ�༭�ؼ��е��ļ���������s��
	filepath = path + s;
	draw_pic(filepath);

}

void CODBC3View::draw_pic(CString file)
{
	CImage img;
	CRect picrect;
	//img.Load(filepath);
	img.Load(file);

	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	GetDlgItem(IDC_STATIC)->GetClientRect(&picrect);     //��ͼ��ؼ�����Ϣ�ŵ�Picrect��		
/*
   //ʵ��ͼ�������ʾ
	int w, h, sx, sy;
	float rect_ratio = 1.0*picrect.Width() / picrect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = picrect.Height();
		w = img_ratio*h;
		sx = (picrect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = picrect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (picrect.Height() - h) / 2;
	}
	*/
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, picrect.top, picrect.left, picrect.right, picrect.bottom);
//	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void CODBC3View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�����г��Ի���֮ǰ����ͼƬ�ļ�������ȥ
	mydialog dlg;
	GetDlgItemText(IDC_EDIT1, s);
	filepath = path + s;
	dlg.ss = filepath;      //ssΪ�Ի���ͷ�ļ��������ı��������ļ��������˱���
	dlg.DoModal();
}




void CODBC3View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()


	GetDlgItemText(IDC_EDIT1, s);              //��ָ��ID�ŵı༭�ؼ��ж�ȡ�ֶε�����s��
 //���ڳ����󣬻����ϼ��س���һ��ͼƬ��onpaint��������ҪҲ���Բ�Ҫ������
	CImage img;
	CRect picrect;
	//img.Load(filepath);
	CString filepath = path + s;
	img.Load(filepath);

	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	GetDlgItem(IDC_STATIC)->GetClientRect(&picrect);     //��ͼ��ؼ�����Ϣ�ŵ�Picrect��		
/*
   //ʵ��ͼ��ľ�����ʾ
	int w, h, sx, sy;
	float rect_ratio = 1.0*picrect.Width() / picrect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = picrect.Height();
		w = img_ratio*h;
		sx = (picrect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = picrect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (picrect.Height() - h) / 2;
	}
*/
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, picrect.top, picrect.left, picrect.right, picrect.bottom);
//	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
