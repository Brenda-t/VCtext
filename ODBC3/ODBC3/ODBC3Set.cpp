
// ODBC3Set.cpp : CODBC3Set ���ʵ��
//

#include "stdafx.h"
#include "ODBC3.h"
#include "ODBC3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBC3Set ʵ��

// ���������� 2020��6��6��, 21:29

IMPLEMENT_DYNAMIC(CODBC3Set, CRecordset)

CODBC3Set::CODBC3Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CODBC3Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_lyx;DBQ=E:\\documents\\StudentInfo4.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CODBC3Set::GetDefaultSQL()
{
	return _T("[lyx]");
}

void CODBC3Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CODBC3Set ���

#ifdef _DEBUG
void CODBC3Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CODBC3Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

