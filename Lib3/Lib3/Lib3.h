// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 LIB3_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// LIB3_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef LIB3_EXPORTS
#define LIB3_API __declspec(dllexport)
#else
#define LIB3_API __declspec(dllimport)
#endif

// 此类是从 Lib3.dll 导出的
class LIB3_API CLib3 {
public:
	CLib3(void);
	// TODO:  在此添加您的方法。
};

extern LIB3_API int nLib3;

LIB3_API int fnLib3(void);

LIB3_API int factorial(int n);     //声明函数
