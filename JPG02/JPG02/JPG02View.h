
// JPG02View.h : CJPG02View ��Ľӿ�
//

#pragma once


class CJPG02View : public CView
{
protected: // �������л�����
	CJPG02View();
	DECLARE_DYNCREATE(CJPG02View)

// ����
public:
	CJPG02Doc* GetDocument() const;

// ����
public:
	bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CJPG02View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // JPG02View.cpp �еĵ��԰汾
inline CJPG02Doc* CJPG02View::GetDocument() const
   { return reinterpret_cast<CJPG02Doc*>(m_pDocument); }
#endif

