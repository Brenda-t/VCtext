
// text15.4View.h : Ctext154View ��Ľӿ�
//

#pragma once


class Ctext154View : public CView
{
protected: // �������л�����
	Ctext154View();
	DECLARE_DYNCREATE(Ctext154View)

// ����
public:
	Ctext154Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext154View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // text15.4View.cpp �еĵ��԰汾
inline Ctext154Doc* Ctext154View::GetDocument() const
   { return reinterpret_cast<Ctext154Doc*>(m_pDocument); }
#endif

