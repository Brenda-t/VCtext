
// UsingLib4View.h : CUsingLib4View ��Ľӿ�
//

#pragma once


class CUsingLib4View : public CView
{
protected: // �������л�����
	CUsingLib4View();
	DECLARE_DYNCREATE(CUsingLib4View)

// ����
public:
	CUsingLib4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CUsingLib4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UsingLib4View.cpp �еĵ��԰汾
inline CUsingLib4Doc* CUsingLib4View::GetDocument() const
   { return reinterpret_cast<CUsingLib4Doc*>(m_pDocument); }
#endif

