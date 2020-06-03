
// ODBCView.h : CODBCView 类的接口
//

#pragma once

class CODBCSet;

class CODBCView : public CRecordView
{
protected: // 仅从序列化创建
	CODBCView();
	DECLARE_DYNCREATE(CODBCView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ODBC_FORM };
#endif
	CODBCSet* m_pSet;

// 特性
public:
	CODBCDoc* GetDocument() const;

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
	virtual ~CODBCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	long age;
	CString pictrue;
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnPaint();
};

#ifndef _DEBUG  // ODBCView.cpp 中的调试版本
inline CODBCDoc* CODBCView::GetDocument() const
   { return reinterpret_cast<CODBCDoc*>(m_pDocument); }
#endif

