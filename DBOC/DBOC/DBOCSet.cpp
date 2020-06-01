
// DBOCSet.cpp : CDBOCSet ���ʵ��
//

#include "stdafx.h"
#include "DBOC.h"
#include "DBOCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDBOCSet ʵ��

// ���������� 2020��6��1��, 21:52

IMPLEMENT_DYNAMIC(CDBOCSet, CRecordset)

CDBOCSet::CDBOCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_nFields = 5;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDBOCSet::GetDefaultConnect()
{
	return _T("DSN=����Դ_ѧ����Ϣ3;DBQ=C:\\Users\\\x8c2d\x96ea\x71d5\\Documents\\StudentInfo.mdb;DefaultDir=C:\\Users\\\x8c2d\x96ea\x71d5\\Documents;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CDBOCSet::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CDBOCSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);

}
/////////////////////////////////////////////////////////////////////////////
// CDBOCSet ���

#ifdef _DEBUG
void CDBOCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDBOCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

