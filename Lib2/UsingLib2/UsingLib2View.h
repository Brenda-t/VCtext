
// UsingLib2View.h : CUsingLib2View ��Ľӿ�
//

#pragma once


class CUsingLib2View : public CView
{
protected: // �������л�����
	CUsingLib2View();
	DECLARE_DYNCREATE(CUsingLib2View)

// ����
public:
	CUsingLib2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CUsingLib2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UsingLib2View.cpp �еĵ��԰汾
inline CUsingLib2Doc* CUsingLib2View::GetDocument() const
   { return reinterpret_cast<CUsingLib2Doc*>(m_pDocument); }
#endif

