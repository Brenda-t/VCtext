
// text13.1View.h : Ctext131View ��Ľӿ�
//

#pragma once


class Ctext131View : public CView
{
protected: // �������л�����
	Ctext131View();
	DECLARE_DYNCREATE(Ctext131View)

// ����
public:
	Ctext131Doc* GetDocument() const;

// ����
public:
	CRect A;                 //�������A
	CString m_strLine,n_strLine;       //����һ���ַ�����
	CPoint m_pt;
	bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // text13.1View.cpp �еĵ��԰汾
inline Ctext131Doc* Ctext131View::GetDocument() const
   { return reinterpret_cast<Ctext131Doc*>(m_pDocument); }
#endif

