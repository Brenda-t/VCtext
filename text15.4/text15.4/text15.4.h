
// text15.4.h : text15.4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Ctext154App:
// �йش����ʵ�֣������ text15.4.cpp
//

class Ctext154App : public CWinApp
{
public:
	Ctext154App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctext154App theApp;
