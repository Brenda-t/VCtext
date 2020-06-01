
// DBOCView.cpp : CDBOCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CDBOCView 构造/析构

CDBOCView::CDBOCView()
	: CRecordView(IDD_DBOC_FORM)
	, ID(0)
	, name(_T(""))
	, num(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CDBOCView::~CDBOCView()
{
}

void CDBOCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例

	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);    //通过记录集的指针连接其中相应的字段名,将记录集中相应的字段名显示在编辑控件中
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL CDBOCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDBOCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DBOCSet;
	CRecordView::OnInitialUpdate();

}


// CDBOCView 诊断

#ifdef _DEBUG
void CDBOCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDBOCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBOCDoc* CDBOCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBOCDoc)));
	return (CDBOCDoc*)m_pDocument;
}
#endif //_DEBUG


// CDBOCView 数据库支持
CRecordset* CDBOCView::OnGetRecordset()
{
	return m_pSet;      //记录集的指针
}



// CDBOCView 消息处理程序


void CDBOCView::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
