#pragma once


// ADD_Dlg 对话框

class ADD_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_Dlg)

public:
	ADD_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ADD_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long i;
};
