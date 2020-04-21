
// text17.1Dlg.h : 头文件
//

#pragma once


// Ctext171Dlg 对话框
class Ctext171Dlg : public CDialogEx
{
// 构造
public:
	Ctext171Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXT171_DIALOG };
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
