// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "text18.h"
#include "MyDlg.h"
#include "afxdialogex.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString filename;
	CFileDialog cfd(true);
	int d = cfd.DoModal();
	if (d == IDOK)
	{
		filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		CString f;
		while (ifs >> s);
		f = CString(s.c_str());
	
		CImage img;
		img.Load(f);
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
		float  sx ,sy,w,h ; 
		
		CRect rect;
		GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
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

		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
}


