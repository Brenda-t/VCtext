
// UsingLib2.h : UsingLib2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CUsingLib2App:
// 有关此类的实现，请参阅 UsingLib2.cpp
//

class CUsingLib2App : public CWinApp
{
public:
	CUsingLib2App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUsingLib2App theApp;
