// Lib4.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Lib4.h"
#define PI 3.14


// ���ǵ���������һ��ʾ��
LIB4_API int nLib4=0;

// ���ǵ���������һ��ʾ����
LIB4_API int fnLib4(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Lib4.h
CLib4::CLib4()
{
    return;
}

float FAC::convert(float deg)
{
	float s = ((float)PI*deg) / 180.0;
	return s;
}
