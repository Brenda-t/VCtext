
// UsingLib3View.h : CUsingLib3View ��Ľӿ�
//

#pragma once


class CUsingLib3View : public CView
{
protected: // �������л�����
	CUsingLib3View();
	DECLARE_DYNCREATE(CUsingLib3View)

// ����
public:
	CUsingLib3Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CUsingLib3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UsingLib3View.cpp �еĵ��԰汾
inline CUsingLib3Doc* CUsingLib3View::GetDocument() const
   { return reinterpret_cast<CUsingLib3Doc*>(m_pDocument); }
#endif

