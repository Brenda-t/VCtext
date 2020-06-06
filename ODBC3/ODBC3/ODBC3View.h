
// ODBC3View.h : CODBC3View ��Ľӿ�
//

#pragma once

class CODBC3Set;

class CODBC3View : public CRecordView
{
protected: // �������л�����
	CODBC3View();
	DECLARE_DYNCREATE(CODBC3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ODBC3_FORM };
#endif
	CODBC3Set* m_pSet;

// ����
public:
	CODBC3Doc* GetDocument() const;

// ����
public:
	CString filepath, s, path;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	void draw_pic(CString file);
// ʵ��
public:
	virtual ~CODBC3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // ODBC3View.cpp �еĵ��԰汾
inline CODBC3Doc* CODBC3View::GetDocument() const
   { return reinterpret_cast<CODBC3Doc*>(m_pDocument); }
#endif

