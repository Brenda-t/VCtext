// ChangeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ODBC5.h"
#include "ChangeDlg.h"
#include "afxdialogex.h"


// ChangeDlg �Ի���

IMPLEMENT_DYNAMIC(ChangeDlg, CDialogEx)

ChangeDlg::ChangeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, i(0)
{

}

ChangeDlg::~ChangeDlg()
{
}

void ChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, i);
}


BEGIN_MESSAGE_MAP(ChangeDlg, CDialogEx)
END_MESSAGE_MAP()


// ChangeDlg ��Ϣ�������
