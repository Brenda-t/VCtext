
// text19Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// Ctext19Dlg 对话框
class Ctext19Dlg : public CDialogEx
{
// 构造
public:
	Ctext19Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXT19_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
