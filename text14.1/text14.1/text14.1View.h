
// text14.1View.h : Ctext141View ��Ľӿ�
//

#pragma once


class Ctext141View : public CView
{
protected: // �������л�����
	Ctext141View();
	DECLARE_DYNCREATE(Ctext141View)

// ����
public:
	Ctext141Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext141View();
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
};

#ifndef _DEBUG  // text14.1View.cpp �еĵ��԰汾
inline Ctext141Doc* Ctext141View::GetDocument() const
   { return reinterpret_cast<Ctext141Doc*>(m_pDocument); }
#endif

