
// text14.2View.h : Ctext142View ��Ľӿ�
//

#pragma once


class Ctext142View : public CView
{
protected: // �������л�����
	Ctext142View();
	DECLARE_DYNCREATE(Ctext142View)

// ����
public:
	Ctext142Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext142View();
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

#ifndef _DEBUG  // text14.2View.cpp �еĵ��԰汾
inline Ctext142Doc* Ctext142View::GetDocument() const
   { return reinterpret_cast<Ctext142Doc*>(m_pDocument); }
#endif

