
// ODBC3View.h : CODBC3View 类的接口
//

#pragma once

class CODBC3Set;

class CODBC3View : public CRecordView
{
protected: // 仅从序列化创建
	CODBC3View();
	DECLARE_DYNCREATE(CODBC3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ODBC3_FORM };
#endif
	CODBC3Set* m_pSet;

// 特性
public:
	CODBC3Doc* GetDocument() const;

// 操作
public:
	CString filepath, s, path;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	void draw_pic(CString file);
// 实现
public:
	virtual ~CODBC3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString pictrue;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // ODBC3View.cpp 中的调试版本
inline CODBC3Doc* CODBC3View::GetDocument() const
   { return reinterpret_cast<CODBC3Doc*>(m_pDocument); }
#endif

