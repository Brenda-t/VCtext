
// DBOCView.h : CDBOCView ��Ľӿ�
//

#pragma once

class CDBOCSet;

class CDBOCView : public CRecordView
{
protected: // �������л�����
	CDBOCView();
	DECLARE_DYNCREATE(CDBOCView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DBOC_FORM };
#endif
	CDBOCSet* m_pSet;

// ����
public:
	CDBOCDoc* GetDocument() const;

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
	virtual ~CDBOCView();
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
	afx_msg void OnEnChangeEdit4();
	CString name;
	CString num;
	CString age;
	CString phone;
};

#ifndef _DEBUG  // DBOCView.cpp �еĵ��԰汾
inline CDBOCDoc* CDBOCView::GetDocument() const
   { return reinterpret_cast<CDBOCDoc*>(m_pDocument); }
#endif

