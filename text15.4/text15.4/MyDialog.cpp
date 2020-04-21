// MyDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "text15.4.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog �Ի���

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
	, y(0)
	, cs(_T(""))
{

}

MyDialog::~MyDialog()
{
	
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, cs);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDialog ��Ϣ�������


void MyDialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);     //���༭������ʾ����ֵ��������
	CString ss;
	ss.Format(_T("%d") , y);   //��int�ͱ���ת��Ϊcstring
	cs = s + ss;
	UpdateData(false);         //��������Ӧ��ֵ��ʾ�ڱ༭����
}


BOOL MyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	s = "hello";
	y = 21;
	UpdateData(false);   //ʹ��ʼ���ı���ֵ��ʾ�ڱ༭����
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
