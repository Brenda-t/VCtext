
// text15.3View.h : Ctext153View ��Ľӿ�
//

#pragma once


class Ctext153View : public CView
{
protected: // �������л�����
	Ctext153View();
	DECLARE_DYNCREATE(Ctext153View)

// ����
public:
	Ctext153Doc* GetDocument() const;

// ����
public:
	CPoint mpt;
	CRect rect;
	bool set,a;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext153View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // text15.3View.cpp �еĵ��԰汾
inline Ctext153Doc* Ctext153View::GetDocument() const
   { return reinterpret_cast<Ctext153Doc*>(m_pDocument); }
#endif

