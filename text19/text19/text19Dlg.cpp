
// text19Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "text19.h"
#include "text19Dlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctext19Dlg 对话框



Ctext19Dlg::Ctext19Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEXT19_DIALOG, pParent)
	, s2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctext19Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, info);
	DDX_Text(pDX, IDC_EDIT1, s2);
}

BEGIN_MESSAGE_MAP(Ctext19Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &Ctext19Dlg::OnBnClickedButton1)
	
	ON_BN_CLICKED(IDOK, &Ctext19Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Ctext19Dlg 消息处理程序

BOOL Ctext19Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString filename;
	string s;
	CString f;
	a = "";      //初始化变量a

    filename = _T("D:\\studentinfo.txt");
	ifstream ifs(filename);    //c++方式读取txt文件
	while (ifs >> s)           //循环将字符串读入s中
	{
		f = CString(s.c_str());      //string转化为CString
		info.AddString(f);           //加入列表框
	}

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ctext19Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctext19Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctext19Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctext19Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonDown(nFlags, point);

	int n = info.GetCurSel();          //获得当前所选记录
	info.GetText(n, a);                //将获取到的记录存于字符变量a中
	//接收s中的字符串
	s2 =a;                             //a中的字符串赋给编辑控件中的变量s2
	UpdateData(false);     //将变量显示在编辑控件中
}



void Ctext19Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	CString ss = s2;                   //将编辑控件中的修改的字符串赋给变量ss
	int n = info.GetCurSel();          //获得当前所选记录
	info.DeleteString(n);              //删除列表框中选中的条目    
	info.InsertString(n, ss);          //将在编辑控件中修改的内容显示在删除的列表框条目的位置上
	
}



void Ctext19Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CString ss;
	ofstream ofs(_T("D:\\studentinfo.txt"));           //打开文件
//	int t = info.GetCurSel();          //获得当前所选记
//	info.GetText(t, ss);                //将获取到的记录存于字符变量ss中
	for(int i=0;i<info.GetCount();i++)     
	{
		info.GetText(i, ss);            //将列表框中的条目依次保存到变量ss中
		ofs<<CT2A(ss)<<endl;            //将ss中保存的字符串依次写入文件中保存
		
	}
	ofs.close();                        //关闭文件
	              //保存文件的代码可以放在对话框类的析构函数中！！！
}
