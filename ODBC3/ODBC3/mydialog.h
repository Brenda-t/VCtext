#pragma once


// mydialog �Ի���

class mydialog : public CDialogEx
{
	DECLARE_DYNAMIC(mydialog)

public:
	mydialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~mydialog();
	CString ss;
	void draw_pic(CString file);
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};