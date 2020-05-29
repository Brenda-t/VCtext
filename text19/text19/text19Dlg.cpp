
// text19Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Ctext19Dlg �Ի���



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


// Ctext19Dlg ��Ϣ�������

BOOL Ctext19Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString filename;
	string s;
	CString f;
	a = "";      //��ʼ������a

    filename = _T("D:\\studentinfo.txt");
	ifstream ifs(filename);    //c++��ʽ��ȡtxt�ļ�
	while (ifs >> s)           //ѭ�����ַ�������s��
	{
		f = CString(s.c_str());      //stringת��ΪCString
		info.AddString(f);           //�����б��
	}

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctext19Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ctext19Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctext19Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnLButtonDown(nFlags, point);

	int n = info.GetCurSel();          //��õ�ǰ��ѡ��¼
	info.GetText(n, a);                //����ȡ���ļ�¼�����ַ�����a��
	//����s�е��ַ���
	s2 =a;                             //a�е��ַ��������༭�ؼ��еı���s2
	UpdateData(false);     //��������ʾ�ڱ༭�ؼ���
}



void Ctext19Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	CString ss = s2;                   //���༭�ؼ��е��޸ĵ��ַ�����������ss
	int n = info.GetCurSel();          //��õ�ǰ��ѡ��¼
	info.DeleteString(n);              //ɾ���б����ѡ�е���Ŀ    
	info.InsertString(n, ss);          //���ڱ༭�ؼ����޸ĵ�������ʾ��ɾ�����б����Ŀ��λ����
	
}



void Ctext19Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	CString ss;
	ofstream ofs(_T("D:\\studentinfo.txt"));           //���ļ�
//	int t = info.GetCurSel();          //��õ�ǰ��ѡ��
//	info.GetText(t, ss);                //����ȡ���ļ�¼�����ַ�����ss��
	for(int i=0;i<info.GetCount();i++)     
	{
		info.GetText(i, ss);            //���б���е���Ŀ���α��浽����ss��
		ofs<<CT2A(ss)<<endl;            //��ss�б�����ַ�������д���ļ��б���
		
	}
	ofs.close();                        //�ر��ļ�
	              //�����ļ��Ĵ�����Է��ڶԻ���������������У�����
}
