
// JPG02.h : JPG02 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CJPG02App:
// �йش����ʵ�֣������ JPG02.cpp
//

class CJPG02App : public CWinApp
{
public:
	CJPG02App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CJPG02App theApp;
