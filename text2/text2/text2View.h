
// text2View.h : Ctext2View ��Ľӿ�
//

#pragma once


class Ctext2View : public CView
{
protected: // �������л�����
	Ctext2View();
	DECLARE_DYNCREATE(Ctext2View)

// ����
public:
	Ctext2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext2View();
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
};

#ifndef _DEBUG  // text2View.cpp �еĵ��԰汾
inline Ctext2Doc* Ctext2View::GetDocument() const
   { return reinterpret_cast<Ctext2Doc*>(m_pDocument); }
#endif

