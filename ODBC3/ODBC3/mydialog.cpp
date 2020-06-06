// mydialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ODBC3.h"
#include "mydialog.h"
#include "afxdialogex.h"


// mydialog 对话框

IMPLEMENT_DYNAMIC(mydialog, CDialogEx)

mydialog::mydialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

mydialog::~mydialog()
{
}

void mydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(mydialog, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// mydialog 消息处理程序


void mydialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()

	CString filepath;
	filepath = ss;
	draw_pic(filepath);

}

void mydialog::draw_pic(CString file)
{
	//实现相片的居中显示
	CImage img;
	CRect picrect;
	//img.Load(filepath);
	img.Load(file);

	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	GetDlgItem(IDC_STATIC)->GetClientRect(&picrect);     //将图像控件的信息放到Picrect中		

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

	pDC->SetStretchBltMode(HALFTONE);
	//img.Draw(pDC->m_hDC, Picrect.top, Picrect.left, Picrect.right, Picrect.bottom);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
