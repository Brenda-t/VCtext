
// ODBC3View.cpp : CODBC3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ODBC3.h"
#endif

#include "ODBC3Set.h"
#include "ODBC3Doc.h"
#include "ODBC3View.h"
#include "mydialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBC3View

IMPLEMENT_DYNCREATE(CODBC3View, CRecordView)

BEGIN_MESSAGE_MAP(CODBC3View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CODBC3View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CODBC3View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CODBC3View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CODBC3View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CODBC3View::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CODBC3View 构造/析构

CODBC3View::CODBC3View()
	: CRecordView(IDD_ODBC3_FORM)
	, pictrue(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("E:\\pictrue\\");
}

CODBC3View::~CODBC3View()
{
}

void CODBC3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CODBC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CODBC3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBC3Set;
	CRecordView::OnInitialUpdate();

}


// CODBC3View 诊断

#ifdef _DEBUG
void CODBC3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBC3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBC3Doc* CODBC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBC3Doc)));
	return (CODBC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CODBC3View 数据库支持
CRecordset* CODBC3View::OnGetRecordset()
{
	return m_pSet;
}



// CODBC3View 消息处理程序


void CODBC3View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	//调用InvalidateRect(picRect)来强制重绘
	//InvalidateRect(picrect);
	GetDlgItemText(IDC_EDIT1, s);             //获取编辑控件中的文件名到变量s中
	filepath = path + s;
	draw_pic(filepath);
}


void CODBC3View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	//调用InvalidateRect(picRect)来强制重绘
	//InvalidateRect(picrect);
	GetDlgItemText(IDC_EDIT1, s);             //获取编辑控件中的文件名到变量s中
	filepath = path + s;
	draw_pic(filepath);
}


void CODBC3View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	//调用InvalidateRect(picRect)来强制重绘
	//InvalidateRect(picrect);
	GetDlgItemText(IDC_EDIT1, s);             //获取编辑控件中的文件名到变量s中
	filepath = path + s;
	draw_pic(filepath);
}


void CODBC3View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	//调用InvalidateRect(picRect)来强制重绘
	//InvalidateRect(picrect);
	GetDlgItemText(IDC_EDIT1, s);             //获取编辑控件中的文件名到变量s中
	filepath = path + s;
	draw_pic(filepath);

}

void CODBC3View::draw_pic(CString file)
{
	CImage img;
	CRect picrect;
	//img.Load(filepath);
	img.Load(file);

	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	GetDlgItem(IDC_STATIC)->GetClientRect(&picrect);     //将图像控件的信息放到Picrect中		
/*
   //实现图像居中显示
	int w, h, sx, sy;
	float rect_ratio = 1.0*picrect.Width() / picrect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = picrect.Height();
		w = img_ratio*h;
		sx = (picrect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = picrect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (picrect.Height() - h) / 2;
	}
	*/
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, picrect.top, picrect.left, picrect.right, picrect.bottom);
//	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void CODBC3View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//在运行出对话框之前，将图片文件名传过去
	mydialog dlg;
	GetDlgItemText(IDC_EDIT1, s);
	filepath = path + s;
	dlg.ss = filepath;      //ss为对话框头文件中声明的变量，将文件名传给此变量
	dlg.DoModal();
}




void CODBC3View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()


	GetDlgItemText(IDC_EDIT1, s);              //从指定ID号的编辑控件中读取字段到变量s中
 //窗口出来后，会马上加载出第一张图片，onpaint函数可以要也可以不要！！！
	CImage img;
	CRect picrect;
	//img.Load(filepath);
	CString filepath = path + s;
	img.Load(filepath);

	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	GetDlgItem(IDC_STATIC)->GetClientRect(&picrect);     //将图像控件的信息放到Picrect中		
/*
   //实现图像的居中显示
	int w, h, sx, sy;
	float rect_ratio = 1.0*picrect.Width() / picrect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = picrect.Height();
		w = img_ratio*h;
		sx = (picrect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = picrect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (picrect.Height() - h) / 2;
	}
*/
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, picrect.top, picrect.left, picrect.right, picrect.bottom);
//	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
