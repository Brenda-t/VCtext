
// ODBC2View.h : CODBC2View ��Ľӿ�
//

#pragma once

class CODBC2Set;

class CODBC2View : public CRecordView
{
protected: // �������л�����
	CODBC2View();
	DECLARE_DYNCREATE(CODBC2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ODBC2_FORM };
#endif
	CODBC2Set* m_pSet;

// ����
public:
	CODBC2Doc* GetDocument() const;

// ����
public:
	CRect Picrect;
	CString s;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CODBC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // ODBC2View.cpp �еĵ��԰汾
inline CODBC2Doc* CODBC2View::GetDocument() const
   { return reinterpret_cast<CODBC2Doc*>(m_pDocument); }
#endif

