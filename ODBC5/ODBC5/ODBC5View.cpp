
// ODBC5View.cpp : CODBC5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ODBC5.h"
#endif

#include "ODBC5Set.h"
#include "ODBC5Doc.h"
#include "ODBC5View.h"
#include "ADD_Dlg.h"
#include "ChangeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBC5View

IMPLEMENT_DYNCREATE(CODBC5View, CRecordView)

BEGIN_MESSAGE_MAP(CODBC5View, CRecordView)
	ON_BN_CLICKED(IDC_Delete, &CODBC5View::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_ADD, &CODBC5View::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_change, &CODBC5View::OnBnClickedchange)
END_MESSAGE_MAP()

// CODBC5View ����/����

CODBC5View::CODBC5View()
	: CRecordView(IDD_ODBC5_FORM)
	, i(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CODBC5View::~CODBC5View()
{
}

void CODBC5View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CODBC5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CODBC5View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBC5Set;
	CRecordView::OnInitialUpdate();

}


// CODBC5View ���

#ifdef _DEBUG
void CODBC5View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBC5View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBC5Doc* CODBC5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBC5Doc)));
	return (CODBC5Doc*)m_pDocument;
}
#endif //_DEBUG


// CODBC5View ���ݿ�֧��
CRecordset* CODBC5View::OnGetRecordset()
{
	return m_pSet;
}



// CODBC5View ��Ϣ�������


void CODBC5View::OnBnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();        //ɾ����ǰ��¼
	m_pSet->MovePrev();      //����Ƶ�ǰһ������λ��ǰһ��
//ɾ����¼�����ж��Ƿ��ڵ�һ������������䶨λ�ڵ�һ
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CODBC5View::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADD_Dlg dlg;
	int r = dlg.DoModal();
	if (r = IDOK)
	{
		long t = dlg.i;          //��������Ӱ�ť�����ĶԻ����еı༭�ؼ��ı���i���������ͱ���t
		m_pSet->AddNew();        //���������¼�¼��״̬
		m_pSet->m_1 = t;         //������t�����༭�ؼ��еı���
		m_pSet->Update();        //�������ݿ�
		UpdateData(false);       //���µı���ֵ��ʾ�ڱ༭�ؼ���
	}
}


void CODBC5View::OnBnClickedchange()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ChangeDlg dlg;
	int r = dlg.DoModal();
	
	if (r = IDOK)
	{
		//�༭״̬�������޸ĵ�ǰ״̬�������޸ĺ�ı���ֵ����ԭ���ı༭�ؼ���
		/*long t1;
		t1 = m_pSet->m_1;
		dlg.i = t1;*/
		long t2;
		t2 = dlg.i;

		m_pSet->Edit();
		m_pSet->m_1 = t2;

		m_pSet->Update();         //�������ݿ�
		UpdateData(false);        //���޸ĺ�ı���ֵ���ֳ���
		/*
		long t = dlg.i;          //��������Ӱ�ť�����ĶԻ����еı༭�ؼ��ı���i���������ͱ���t
		m_pSet->Edit();        //���������¼�¼��״̬
		m_pSet->m_1 = t;         //������t�����༭�ؼ��еı���
		m_pSet->Update();        //�������ݿ�
		UpdateData(false);       //���µı���ֵ��ʾ�ڱ༭�ؼ���*/
	}
}
