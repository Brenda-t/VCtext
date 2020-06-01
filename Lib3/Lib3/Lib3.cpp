// Lib3.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Lib3.h"


// 这是导出变量的一个示例
LIB3_API int nLib3=0;

// 这是导出函数的一个示例。
LIB3_API int fnLib3(void)
{
    return 42;
}

//添加函数
LIB3_API int factorial(int n)
{
	int s = 1;
	for (int i = 1; i < n; i++)
	{
		s = s*i;
	}
	return s;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 Lib3.h
CLib3::CLib3()
{
    return;
}
