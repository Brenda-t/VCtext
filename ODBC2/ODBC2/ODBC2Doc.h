
// ODBC2Doc.h : CODBC2Doc ��Ľӿ�
//


#pragma once
#include "ODBC2Set.h"


class CODBC2Doc : public CDocument
{
protected: // �������л�����
	CODBC2Doc();
	DECLARE_DYNCREATE(CODBC2Doc)

// ����
public:
	CODBC2Set m_ODBC2Set;

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
	virtual ~CODBC2Doc();
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
