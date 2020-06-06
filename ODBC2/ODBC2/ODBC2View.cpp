
// ODBC2View.cpp : CODBC2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ODBC2.h"
#endif

#include "ODBC2Set.h"
#include "ODBC2Doc.h"
#include "ODBC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBC2View

IMPLEMENT_DYNCREATE(CODBC2View, CRecordView)

BEGIN_MESSAGE_MAP(CODBC2View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT3, &CODBC2View::OnEnChangeEdit3)

	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CODBC2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CODBC2View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CODBC2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CODBC2View::OnRecordLast)
END_MESSAGE_MAP()

// CODBC2View 构造/析构

CODBC2View::CODBC2View()
	: CRecordView(IDD_ODBC2_FORM)
	, ID(0)
	, name(_T(""))
	, age(0)
	, pictrue(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	
}

CODBC2View::~CODBC2View()
{
}

void CODBC2View::DoDataExchange(CDataExchange* pDX)
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

BOOL CODBC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CODBC2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBC2Set;
	CRecordView::OnInitialUpdate();


	

}


// CODBC2View 诊断

#ifdef _DEBUG
void CODBC2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBC2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBC2Doc* CODBC2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBC2Doc)));
	return (CODBC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CODBC2View 数据库支持
CRecordset* CODBC2View::OnGetRecordset()
{
	return m_pSet;
}



// CODBC2View 消息处理程序


void CODBC2View::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}




void CODBC2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	
	//	m_pSet->GetFieldValue(short(4), s);        //从记录集当前记录，读取第4个字段值，放入s中 
	GetDlgItemText(IDC_EDIT4, s);              //从指定ID号的编辑控件中读取字段到变量s中

	
	GetDlgItem(IDC_STATIC)->GetClientRect(&Picrect);     //将图像控件的信息放到Picrect中

	CImage img;
	img.Load(s);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();

	/*
	//实现图片的不失真居中缩放
	int w, h, sx, sy;
	float rect_ratio = 1.0*Picrect.Width() / Picrect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
	h = Picrect.Height();
	w = img_ratio*h;
	sx = (Picrect.Width() - w) / 2;
	sy = 0;
	}
	else
	{
	w = Picrect.Width();
	h = w / img_ratio;
	sx = 0;
	sy = (Picrect.Height() - h) / 2;
	}
	*/
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, Picrect.top, Picrect.left, Picrect.right, Picrect.bottom);
	//	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

}


void CODBC2View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	//调用InvalidateRect(picRect)来强制重绘
	InvalidateRect(Picrect);
	
}



void CODBC2View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	//调用InvalidateRect(picRect)来强制重绘
	InvalidateRect(Picrect);
}


void CODBC2View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	//调用InvalidateRect(picRect)来强制重绘
	InvalidateRect(Picrect);
}


void CODBC2View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	//调用InvalidateRect(picRect)来强制重绘
	InvalidateRect(Picrect);
}
