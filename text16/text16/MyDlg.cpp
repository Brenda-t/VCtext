// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "text16.h"
#include "MyDlg.h"
#include "afxdialogex.h"

#include "text16Doc.h"
#include "text16View.h"


// MyDlg �Ի���

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

	DDX_Control(pDX, IDC_LIST1, show);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
END_MESSAGE_MAP()


// MyDlg ��Ϣ�������


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//�ڶԻ���ĳ�ʼ�������У����г��Ի����ʱ���ִ�������´��룬Ҳ�����ð�ť�ؼ����ﵽ�ļ�����ʾ�ڱ༭�ؼ����б���е�Ŀ��
	Ctext16Doc *pDoc = ((Ctext16View *)((CFrameWnd *)AfxGetMainWnd())->GetActiveView())->GetDocument();
	SetDlgItemText(IDC_EDIT1, pDoc->filename);       //�˺����Ĺ��������öԻ����пؼ����ı��ͱ��⣨���ļ�����ʾ�ڱ༭�ؼ��У�

//	s = pDoc->filename;           //���ļ��������༭�ؼ��ı���s
//	UpdateData(false);            //��s�е�ֵ�ڿؼ�����ʾ����

	show.AddString(pDoc->filename);           //AddString()���б��������ַ����ķ�����show�ǿ��Ʊ�����control��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
