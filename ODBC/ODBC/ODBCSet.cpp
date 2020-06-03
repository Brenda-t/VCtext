
// ODBCSet.cpp : CODBCSet 类的实现
//

#include "stdafx.h"
#include "ODBC.h"
#include "ODBCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBCSet 实现

// 代码生成在 2020年6月2日, 20:42

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
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CODBCSet::GetDefaultConnect()
{
	return _T("DSN=数据源_偶像;DBQ=E:\\documents\\StudentInfo2.mdb;DefaultDir=E:\\documents;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CODBCSet::GetDefaultSQL()
{
	return _T("[偶像]");
}

void CODBCSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[字段1]"), m_1);
	RFX_Long(pFX, _T("[字段2]"), m_2);
	RFX_Text(pFX, _T("[字段3]"), m_3);

}
/////////////////////////////////////////////////////////////////////////////
// CODBCSet 诊断

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

