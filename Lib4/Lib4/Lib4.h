// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LIB4_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LIB4_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef LIB4_EXPORTS
#define LIB4_API __declspec(dllexport)
#else
#define LIB4_API __declspec(dllimport)
#endif

// �����Ǵ� Lib4.dll ������
class LIB4_API CLib4 {
public:
	CLib4(void);
	// TODO:  �ڴ�������ķ�����
};

//�����
class LIB4_API FAC {
public:
	float convert(float deg);     //��ĳ�Ա����
};

extern LIB4_API int nLib4;

LIB4_API int fnLib4(void);
