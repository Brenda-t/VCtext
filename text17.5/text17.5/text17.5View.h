
// text17.5View.h : Ctext175View ��Ľӿ�
//

#pragma once


class Ctext175View : public CView
{
protected: // �������л�����
	Ctext175View();
	DECLARE_DYNCREATE(Ctext175View)

// ����
public:
	Ctext175Doc* GetDocument() const;

// ����
public:
	int a, b;
	CPoint mpt;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext175View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopdialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // text17.5View.cpp �еĵ��԰汾
inline Ctext175Doc* Ctext175View::GetDocument() const
   { return reinterpret_cast<Ctext175Doc*>(m_pDocument); }
#endif

