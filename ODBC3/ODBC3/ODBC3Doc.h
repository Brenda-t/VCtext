
// ODBC3Doc.h : CODBC3Doc ��Ľӿ�
//


#pragma once
#include "ODBC3Set.h"


class CODBC3Doc : public CDocument
{
protected: // �������л�����
	CODBC3Doc();
	DECLARE_DYNCREATE(CODBC3Doc)

// ����
public:
	CODBC3Set m_ODBC3Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CODBC3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
