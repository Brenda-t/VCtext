// Lib3.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Lib3.h"


// ���ǵ���������һ��ʾ��
LIB3_API int nLib3=0;

// ���ǵ���������һ��ʾ����
LIB3_API int fnLib3(void)
{
    return 42;
}

//��Ӻ���
LIB3_API int factorial(int n)
{
	int s = 1;
	for (int i = 1; i < n; i++)
	{
		s = s*i;
	}
	return s;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Lib3.h
CLib3::CLib3()
{
    return;
}
