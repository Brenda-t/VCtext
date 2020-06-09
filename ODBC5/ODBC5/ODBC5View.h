
// ODBC5View.h : CODBC5View ��Ľӿ�
//

#pragma once

class CODBC5Set;

class CODBC5View : public CRecordView
{
protected: // �������л�����
	CODBC5View();
	DECLARE_DYNCREATE(CODBC5View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ODBC5_FORM };
#endif
	CODBC5Set* m_pSet;

// ����
public:
	CODBC5Doc* GetDocument() const;

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
	virtual ~CODBC5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long i;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedchange();
};

#ifndef _DEBUG  // ODBC5View.cpp �еĵ��԰汾
inline CODBC5Doc* CODBC5View::GetDocument() const
   { return reinterpret_cast<CODBC5Doc*>(m_pDocument); }
#endif

