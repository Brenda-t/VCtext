
// ODBCView.h : CODBCView ��Ľӿ�
//

#pragma once

class CODBCSet;

class CODBCView : public CRecordView
{
protected: // �������л�����
	CODBCView();
	DECLARE_DYNCREATE(CODBCView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ODBC_FORM };
#endif
	CODBCSet* m_pSet;

// ����
public:
	CODBCDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CODBCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // ODBCView.cpp �еĵ��԰汾
inline CODBCDoc* CODBCView::GetDocument() const
   { return reinterpret_cast<CODBCDoc*>(m_pDocument); }
#endif

