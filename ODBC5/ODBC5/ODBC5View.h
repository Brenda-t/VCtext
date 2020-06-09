
// ODBC5View.h : CODBC5View 类的接口
//

#pragma once

class CODBC5Set;

class CODBC5View : public CRecordView
{
protected: // 仅从序列化创建
	CODBC5View();
	DECLARE_DYNCREATE(CODBC5View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ODBC5_FORM };
#endif
	CODBC5Set* m_pSet;

// 特性
public:
	CODBC5Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CODBC5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long i;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedchange();
};

#ifndef _DEBUG  // ODBC5View.cpp 中的调试版本
inline CODBC5Doc* CODBC5View::GetDocument() const
   { return reinterpret_cast<CODBC5Doc*>(m_pDocument); }
#endif

