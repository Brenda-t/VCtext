
// text17.2View.h : Ctext172View ��Ľӿ�
//

#pragma once


class Ctext172View : public CView
{
protected: // �������л�����
	Ctext172View();
	DECLARE_DYNCREATE(Ctext172View)

// ����
public:
	Ctext172Doc* GetDocument() const;

// ����
public:
	CPoint mpt1,mpt2;
	CRect re;
	bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext172View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // text17.2View.cpp �еĵ��԰汾
inline Ctext172Doc* Ctext172View::GetDocument() const
   { return reinterpret_cast<Ctext172Doc*>(m_pDocument); }
#endif

