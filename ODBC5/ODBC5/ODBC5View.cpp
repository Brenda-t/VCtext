
// ODBC5View.cpp : CODBC5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CODBC5View 构造/析构

CODBC5View::CODBC5View()
	: CRecordView(IDD_ODBC5_FORM)
	, i(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CODBC5View::~CODBC5View()
{
}

void CODBC5View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CODBC5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CODBC5View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBC5Set;
	CRecordView::OnInitialUpdate();

}


// CODBC5View 诊断

#ifdef _DEBUG
void CODBC5View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBC5View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBC5Doc* CODBC5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBC5Doc)));
	return (CODBC5Doc*)m_pDocument;
}
#endif //_DEBUG


// CODBC5View 数据库支持
CRecordset* CODBC5View::OnGetRecordset()
{
	return m_pSet;
}



// CODBC5View 消息处理程序


void CODBC5View::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();        //删除当前记录
	m_pSet->MovePrev();      //光标移到前一个，定位在前一个
//删除记录后光标判断是否在第一，如果是则让其定位在第一
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CODBC5View::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD_Dlg dlg;
	int r = dlg.DoModal();
	if (r = IDOK)
	{
		long t = dlg.i;          //将点击增加按钮弹出的对话框中的编辑控件的变量i赋给长整型变量t
		m_pSet->AddNew();        //开启增加新纪录的状态
		m_pSet->m_1 = t;         //将变量t赋给编辑控件中的变量
		m_pSet->Update();        //更新数据库
		UpdateData(false);       //将新的变量值显示在编辑控件中
	}
}


void CODBC5View::OnBnClickedchange()
{
	// TODO: 在此添加控件通知处理程序代码
	ChangeDlg dlg;
	int r = dlg.DoModal();
	
	if (r = IDOK)
	{
		//编辑状态开启后，修改当前状态，并将修改后的变量值传到原来的编辑控件中
		/*long t1;
		t1 = m_pSet->m_1;
		dlg.i = t1;*/
		long t2;
		t2 = dlg.i;

		m_pSet->Edit();
		m_pSet->m_1 = t2;

		m_pSet->Update();         //更新数据库
		UpdateData(false);        //将修改后的变量值显现出来
		/*
		long t = dlg.i;          //将点击增加按钮弹出的对话框中的编辑控件的变量i赋给长整型变量t
		m_pSet->Edit();        //开启增加新纪录的状态
		m_pSet->m_1 = t;         //将变量t赋给编辑控件中的变量
		m_pSet->Update();        //更新数据库
		UpdateData(false);       //将新的变量值显示在编辑控件中*/
	}
}
