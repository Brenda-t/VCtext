
// ODBC2Doc.h : CODBC2Doc 类的接口
//


#pragma once
#include "ODBC2Set.h"


class CODBC2Doc : public CDocument
{
protected: // 仅从序列化创建
	CODBC2Doc();
	DECLARE_DYNCREATE(CODBC2Doc)

// 特性
public:
	CODBC2Set m_ODBC2Set;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CODBC2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
