
// UsingLib3.h : UsingLib3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CUsingLib3App:
// �йش����ʵ�֣������ UsingLib3.cpp
//

class CUsingLib3App : public CWinApp
{
public:
	CUsingLib3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUsingLib3App theApp;
