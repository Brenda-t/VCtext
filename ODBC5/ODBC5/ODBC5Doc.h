
// ODBC5Doc.h : CODBC5Doc ��Ľӿ�
//


#pragma once
#include "ODBC5Set.h"


class CODBC5Doc : public CDocument
{
protected: // �������л�����
	CODBC5Doc();
	DECLARE_DYNCREATE(CODBC5Doc)

// ����
public:
	CODBC5Set m_ODBC5Set;

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
	virtual ~CODBC5Doc();
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
