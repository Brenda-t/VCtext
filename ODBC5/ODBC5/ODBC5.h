
// ODBC5.h : ODBC5 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CODBC5App:
// �йش����ʵ�֣������ ODBC5.cpp
//

class CODBC5App : public CWinApp
{
public:
	CODBC5App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CODBC5App theApp;
