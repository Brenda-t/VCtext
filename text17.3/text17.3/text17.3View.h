
// text17.3View.h : Ctext173View ��Ľӿ�
//

#pragma once


class Ctext173View : public CView
{
protected: // �������л�����
	Ctext173View();
	DECLARE_DYNCREATE(Ctext173View)

// ����
public:
	Ctext173Doc* GetDocument() const;

// ����
public:
	int A, B, X, Y;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext173View();
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

#ifndef _DEBUG  // text17.3View.cpp �еĵ��԰汾
inline Ctext173Doc* Ctext173View::GetDocument() const
   { return reinterpret_cast<Ctext173Doc*>(m_pDocument); }
#endif

