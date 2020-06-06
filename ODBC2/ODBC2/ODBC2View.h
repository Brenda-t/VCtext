
// ODBC2View.h : CODBC2View 类的接口
//

#pragma once

class CODBC2Set;

class CODBC2View : public CRecordView
{
protected: // 仅从序列化创建
	CODBC2View();
	DECLARE_DYNCREATE(CODBC2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ODBC2_FORM };
#endif
	CODBC2Set* m_pSet;

// 特性
public:
	CODBC2Doc* GetDocument() const;

// 操作
public:
	CRect Picrect;
	CString s;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CODBC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
//	afx_msg void OnBnClickedButton1();
	long ID;
	CString name;
	long age;
	CString pictrue;
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // ODBC2View.cpp 中的调试版本
inline CODBC2Doc* CODBC2View::GetDocument() const
   { return reinterpret_cast<CODBC2Doc*>(m_pDocument); }
#endif

