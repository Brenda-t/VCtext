
// text15.1View.h : Ctext151View ��Ľӿ�
//

#pragma once


class Ctext151View : public CView
{
protected: // �������л�����
	Ctext151View();
	DECLARE_DYNCREATE(Ctext151View)

// ����
public:
	Ctext151Doc* GetDocument() const;

// ����
public:
	bool set;
	CPoint m_point;
	CRect rect;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext151View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnHuajuxing();
};

#ifndef _DEBUG  // text15.1View.cpp �еĵ��԰汾
inline Ctext151Doc* Ctext151View::GetDocument() const
   { return reinterpret_cast<Ctext151Doc*>(m_pDocument); }
#endif

