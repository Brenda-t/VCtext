
// DBOCDoc.h : CDBOCDoc ��Ľӿ�
//


#pragma once
#include "DBOCSet.h"


class CDBOCDoc : public CDocument
{
protected: // �������л�����
	CDBOCDoc();
	DECLARE_DYNCREATE(CDBOCDoc)

// ����
public:
	CDBOCSet m_DBOCSet;

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
	virtual ~CDBOCDoc();
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
