
// text1View.h : Ctext1View ��Ľӿ�
//

#pragma once


class Ctext1View : public CView
{
protected: // �������л�����
	Ctext1View();
	DECLARE_DYNCREATE(Ctext1View)

// ����
public:
	Ctext1Doc* GetDocument() const;

// ����
public:
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext1View();
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
};

#ifndef _DEBUG  // text1View.cpp �еĵ��԰汾
inline Ctext1Doc* Ctext1View::GetDocument() const
   { return reinterpret_cast<Ctext1Doc*>(m_pDocument); }
#endif

