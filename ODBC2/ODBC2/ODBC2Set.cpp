
// ODBC2Set.cpp : CODBC2Set ���ʵ��
//

#include "stdafx.h"
#include "ODBC2.h"
#include "ODBC2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBC2Set ʵ��

// ���������� 2020��6��3��, 23:20

IMPLEMENT_DYNAMIC(CODBC2Set, CRecordset)

CODBC2Set::CODBC2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = 0;
	m_3 = L"";
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CODBC2Set::GetDefaultConnect()
{
	return _T("DSN=����Դ_ѧ����Ϣ��4;DBQ=E:\\documents\\StudentInfo3.mdb;DefaultDir=E:\\documents;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CODBC2Set::GetDefaultSQL()
{
	return _T("[��Ϣ��]");
}

void CODBC2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Long(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);

}
/////////////////////////////////////////////////////////////////////////////
// CODBC2Set ���

#ifdef _DEBUG
void CODBC2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CODBC2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

