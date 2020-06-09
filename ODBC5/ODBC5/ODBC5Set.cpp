
// ODBC5Set.cpp : CODBC5Set ���ʵ��
//

#include "stdafx.h"
#include "ODBC5.h"
#include "ODBC5Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBC5Set ʵ��

// ���������� 2020��6��8��, 23:06

IMPLEMENT_DYNAMIC(CODBC5Set, CRecordset)

CODBC5Set::CODBC5Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CODBC5Set::GetDefaultConnect()
{
	return _T("DSN=����Դ_���ݱ�;DBQ=E:\\documents\\StudentInfo5.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CODBC5Set::GetDefaultSQL()
{
	return _T("[���ݱ�]");
}

void CODBC5Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CODBC5Set ���

#ifdef _DEBUG
void CODBC5Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CODBC5Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

