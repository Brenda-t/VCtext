
// DBOCView.h : CDBOCView 类的接口
//

#pragma once

class CDBOCSet;

class CDBOCView : public CRecordView
{
protected: // 仅从序列化创建
	CDBOCView();
	DECLARE_DYNCREATE(CDBOCView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DBOC_FORM };
#endif
	CDBOCSet* m_pSet;

// 特性
public:
	CDBOCDoc* GetDocument() const;

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
	virtual ~CDBOCView();
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
	afx_msg void OnEnChangeEdit4();
	CString name;
	CString num;
	CString age;
	CString phone;
};

#ifndef _DEBUG  // DBOCView.cpp 中的调试版本
inline CDBOCDoc* CDBOCView::GetDocument() const
   { return reinterpret_cast<CDBOCDoc*>(m_pDocument); }
#endif

