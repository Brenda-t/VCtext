
// text17.1Dlg.h : ͷ�ļ�
//

#pragma once


// Ctext171Dlg �Ի���
class Ctext171Dlg : public CDialogEx
{
// ����
public:
	Ctext171Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXT171_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double x;
	double y;
	double z;
	afx_msg void add();
	afx_msg void cut();
	afx_msg void ride();
	afx_msg void remove();
	afx_msg void kaipingfang();
	afx_msg void qiudaoshu();
	double m;
};
