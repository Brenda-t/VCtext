
// UsingLib4.h : UsingLib4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CUsingLib4App:
// �йش����ʵ�֣������ UsingLib4.cpp
//

class CUsingLib4App : public CWinApp
{
public:
	CUsingLib4App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUsingLib4App theApp;
