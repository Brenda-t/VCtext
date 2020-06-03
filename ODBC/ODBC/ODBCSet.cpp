
// ODBCSet.cpp : CODBCSet ���ʵ��
//

#include "stdafx.h"
#include "ODBC.h"
#include "ODBCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBCSet ʵ��

// ���������� 2020��6��2��, 20:42

IMPLEMENT_DYNAMIC(CODBCSet, CRecordset)

CODBCSet::CODBCSet(CDatabase* pdb)
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
CString CODBCSet::GetDefaultConnect()
{
	return _T("DSN=����Դ_ż��;DBQ=E:\\documents\\StudentInfo2.mdb;DefaultDir=E:\\documents;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CODBCSet::GetDefaultSQL()
{
	return _T("[ż��]");
}

void CODBCSet::DoFieldExchange(CFieldExchange* pFX)
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
// CODBCSet ���

#ifdef _DEBUG
void CODBCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CODBCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

