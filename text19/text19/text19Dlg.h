
// text19Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// Ctext19Dlg �Ի���
class Ctext19Dlg : public CDialogEx
{
// ����
public:
	Ctext19Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXT19_DIALOG };
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
	CListBox info;
	CString a;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CString s2;
//	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedOk();
};
