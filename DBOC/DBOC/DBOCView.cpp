
// DBOCView.cpp : CDBOCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DBOC.h"
#endif

#include "DBOCSet.h"
#include "DBOCDoc.h"
#include "DBOCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDBOCView

IMPLEMENT_DYNCREATE(CDBOCView, CRecordView)

BEGIN_MESSAGE_MAP(CDBOCView, CRecordView)
	ON_EN_CHANGE(IDC_EDIT4, &CDBOCView::OnEnChangeEdit4)
END_MESSAGE_MAP()

// CDBOCView ����/����

CDBOCView::CDBOCView()
	: CRecordView(IDD_DBOC_FORM)
	, ID(0)
	, name(_T(""))
	, num(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CDBOCView::~CDBOCView()
{
}

void CDBOCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��

	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);    //ͨ����¼����ָ������������Ӧ���ֶ���,����¼������Ӧ���ֶ�����ʾ�ڱ༭�ؼ���
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL CDBOCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDBOCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DBOCSet;
	CRecordView::OnInitialUpdate();

}


// CDBOCView ���

#ifdef _DEBUG
void CDBOCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDBOCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBOCDoc* CDBOCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBOCDoc)));
	return (CDBOCDoc*)m_pDocument;
}
#endif //_DEBUG


// CDBOCView ���ݿ�֧��
CRecordset* CDBOCView::OnGetRecordset()
{
	return m_pSet;      //��¼����ָ��
}



// CDBOCView ��Ϣ�������


void CDBOCView::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
