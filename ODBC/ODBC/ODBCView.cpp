
// ODBCView.cpp : CODBCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ODBC.h"
#endif

#include "ODBCSet.h"
#include "ODBCDoc.h"
#include "ODBCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBCView

IMPLEMENT_DYNCREATE(CODBCView, CRecordView)

BEGIN_MESSAGE_MAP(CODBCView, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CODBCView::OnBnClickedButton1)
//	ON_WM_PAINT()
END_MESSAGE_MAP()

// CODBCView 构造/析构

CODBCView::CODBCView()
	: CRecordView(IDD_ODBC_FORM)
	, ID(0)
	, name(_T(""))
	, age(0)
	, pictrue(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CODBCView::~CODBCView()
{
}

void CODBCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);

	
}

BOOL CODBCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CODBCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBCSet;
	CRecordView::OnInitialUpdate();

}


// CODBCView 诊断

#ifdef _DEBUG
void CODBCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBCDoc* CODBCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBCDoc)));
	return (CODBCDoc*)m_pDocument;
}
#endif //_DEBUG


// CODBCView 数据库支持
CRecordset* CODBCView::OnGetRecordset()
{
	return m_pSet;
}



// CODBCView 消息处理程序


void CODBCView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CString s;
//	m_pSet->GetFieldValue(4, s);        //从记录集当前记录，读取第2个字段值，放入s中 
	GetDlgItemText(IDC_EDIT4, s);              //从指定ID号的编辑控件中读取字段到变量s中
	
	CImage img;
	img.Load(s);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();

	this->UpdateData(true);
	CString ss;
	ss = _T("123");
	pictrue = ss;
	UpdateData(false);
	

	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	
	/*
	//实现图片的不失真居中缩放
	int w, h, sx, sy;
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	*/
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC,rect.top,rect.left, rect.right,rect.bottom);
//	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

	
}

