
// text17.4.h : text17.4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Ctext174App:
// �йش����ʵ�֣������ text17.4.cpp
//

class Ctext174App : public CWinApp
{
public:
	Ctext174App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctext174App theApp;
