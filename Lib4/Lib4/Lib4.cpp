// Lib4.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Lib4.h"
#define PI 3.14


// 这是导出变量的一个示例
LIB4_API int nLib4=0;

// 这是导出函数的一个示例。
LIB4_API int fnLib4(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 Lib4.h
CLib4::CLib4()
{
    return;
}

float FAC::convert(float deg)
{
	float s = ((float)PI*deg) / 180.0;
	return s;
}
