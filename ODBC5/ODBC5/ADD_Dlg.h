#pragma once


// ADD_Dlg �Ի���

class ADD_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_Dlg)

public:
	ADD_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ADD_Dlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long i;
};
