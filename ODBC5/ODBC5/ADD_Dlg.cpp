// ADD_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ODBC5.h"
#include "ADD_Dlg.h"
#include "afxdialogex.h"


// ADD_Dlg �Ի���

IMPLEMENT_DYNAMIC(ADD_Dlg, CDialogEx)

ADD_Dlg::ADD_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, i(0)
{

}

ADD_Dlg::~ADD_Dlg()
{
}

void ADD_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, i);
}


BEGIN_MESSAGE_MAP(ADD_Dlg, CDialogEx)
END_MESSAGE_MAP()


// ADD_Dlg ��Ϣ�������
