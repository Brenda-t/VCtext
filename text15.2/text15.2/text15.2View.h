
// text15.2View.h : Ctext152View ��Ľӿ�
//

#pragma once


class Ctext152View : public CView
{
protected: // �������л�����
	Ctext152View();
	DECLARE_DYNCREATE(Ctext152View)

// ����
public:
	Ctext152Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext152View();
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

#ifndef _DEBUG  // text15.2View.cpp �еĵ��԰汾
inline Ctext152Doc* Ctext152View::GetDocument() const
   { return reinterpret_cast<Ctext152Doc*>(m_pDocument); }
#endif

