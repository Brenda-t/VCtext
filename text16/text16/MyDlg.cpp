// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "text16.h"
#include "MyDlg.h"
#include "afxdialogex.h"

#include "text16Doc.h"
#include "text16View.h"


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

	DDX_Control(pDX, IDC_LIST1, show);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//在对话框的初始化函数中，运行出对话框的时候就执行了以下代码，也可以用按钮控件来达到文件名显示在编辑控件和列表框中的目的
	Ctext16Doc *pDoc = ((Ctext16View *)((CFrameWnd *)AfxGetMainWnd())->GetActiveView())->GetDocument();
	SetDlgItemText(IDC_EDIT1, pDoc->filename);       //此函数的功能是设置对话框中控件的文本和标题（将文件名显示在编辑控件中）

//	s = pDoc->filename;           //将文件名赋给编辑控件的变量s
//	UpdateData(false);            //将s中的值在控件中显示出来

	show.AddString(pDoc->filename);           //AddString()是列表框中添加字符串的方法，show是控制变量（control）

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
